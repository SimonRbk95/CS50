import os
import string

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    table = []
    total = 0

    # dictionary with stocks and total quantites owned
    stocks_owned = db.execute(
        "SELECT symbol, SUM(quantity) AS 'quantity' FROM portfolio WHERE user_id = (?) GROUP BY symbol", session["user_id"])

    for stock in stocks_owned:
        quote = lookup(stock["symbol"])
        total += quote["price"]*stock["quantity"]
        table.append({
                    "symbol": stock["symbol"],
                    "quantity": stock["quantity"],
                    "price": quote["price"],
                    "value": stock["quantity"]*quote["price"],
                    })

    cash_dict = db.execute("SELECT cash FROM users WHERE id = (?)", session["user_id"])
    cash_balance = cash_dict[0]["cash"]

    # cash balance
    # grand total
    return render_template("index.html", table=table, total=total, cash_balance=cash_balance)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    if request.method == "POST":
        symbol = request.form.get("symbol")
        quote = lookup(symbol)

        if quote == None:
            return apology("This stock symbol does not exist.", 400)

        try:
            shares = int(request.form.get("shares"))
        except:
            return apology("shares must be positive integers.", 400)

        if shares <= 0:
            return apology("shares of stocks to be purchased must be positive.", 400)

        # look up prices
        price = quote["price"]

        cash = db.execute("SELECT cash FROM users WHERE id = (?)", (session["user_id"]))
        budget = cash[0]["cash"]

        purchase = price * shares
        if purchase > budget:
            return apology("Not enough money", 403)
        # insert into the table:
        else:
            db.execute("INSERT INTO portfolio (user_id, symbol, quantity, price) VALUES(?, ?, ?, ?)", session["user_id"], symbol, shares, price)
            # adjust user's budget
            db.execute("UPDATE users SET cash = cash - (?) WHERE id = (?)", purchase, session["user_id"])
        return redirect("/")
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    transactions = db.execute("SELECT symbol, quantity, price, Timestamp FROM portfolio WHERE user_id = (?)", session["user_id"])
    if transactions == None:
        return apology("No transactions yet.", 403)
    return render_template("history.html", transactions=transactions)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        quote = lookup(request.form.get("symbol"))
        if quote == None:
            return apology("Inavlid stock symbol", 400)
        else:
            return render_template("quoted.html", quote=quote)
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")
        # if username already exsits
        if db.execute("SELECT username FROM users WHERE username = %s", (username, )):
            # appropriate apology message
            return apology("The username already exists", 400)

            # check if password matches the requirements
        pCounter = 0
        dCounter = 0
        # require that the password be at least 8 characters long
        if len(password) < 8:
            return apology("The password is too short", 400)
        for char in password:
            if char in string.punctuation:
                pCounter += 1
            elif char.isdigit():
                dCounter += 1
        # require that the password include at least 2 digits and 1 special character
        if not (pCounter >= 1 and dCounter >= 2):
            return apology("Your password does not contain at least 2 digits and 1 special character", 400)
        # check if the password has been repeated correctly
        elif password != confirmation:
            return apology("Your passwords don't match", 400)
        # if password checks out
        else:
            db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", username, generate_password_hash(password))
            return redirect("/login")
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

    if request.method == "POST":
        pass
        # submitted data by user
        symbol = request.form.get("symbol")

        try:
            number = int(request.form.get("shares"))
        except:
            return apology("Invalid entry.", 400)

        # current stock data
        quote = lookup(symbol)
        price = quote["price"]

        # user db stock data
        stocks_owned = db.execute(
            "SELECT symbol, SUM(quantity) AS 'quantity' FROM portfolio WHERE user_id = (?) AND symbol = (?)", session["user_id"], symbol)

        quantity = stocks_owned[0]["quantity"]

        # validate input data
        if quote == None:
            return apology("symbol does not exist", 400)
        elif number <= 0:
            return apology("Invalid number. Number must be a positive integer", 400)
        # check if user owns the stock and if number is less or equal than quantity
        elif quantity == None:
            return apology(f"Invalid entry. You don't own any '{symbol}' stock.", 400)

        elif number > quantity:
            return apology("Invalid number. You can't sell more than you own.", 400)

        # record the transacation
        db.execute("INSERT INTO portfolio (user_id, quantity, price, symbol) VALUES (?, ?, ?, ?)",
                   session["user_id"], -(number), price, symbol)
        # update the user's cash balance
        db.execute("UPDATE users SET cash = cash + (?) WHERE id = (?)", price*number, session["user_id"])

        return redirect("/")

    else:
        # shares owned to be displayed in drop down menu
        stocks_owned = db.execute("SELECT DISTINCT symbol FROM portfolio WHERE user_id = (?)", session["user_id"])
        return render_template("sell.html", symbols=stocks_owned)

