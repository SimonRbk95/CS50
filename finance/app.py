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
    return apology("TODO")


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    if request.method == "POST":
        symbol = request.form.get("symbol")
        number = request.form.get("number")
        if not symbol:
            return apology("This stock symbol does not exist.", 400)
        elif number < 0:
            return apology("Number of stocks to be purchased must be positive", 400)
        # look up prices
        quote = lookup(symbol)
        price = quote["price"]
        # work with SQLite database table to:
        # check the user's budget
        # apology if user cannot afford prices
        budget = db.execute("SELECT cash FROM users WHERE id = (?)", (session["user_id"]))
        purchase = price * number
        if purchase > budget:
            return apology("Not enough money", 403)
        # insert into the table:
        else:
            db.execute(("INSERT INTO portfolio (symbol, quantity, purchase_price) VALUES(?,?,?) WHERE user_id = (?)", (symbol, number, price), ())
)

            # increment the number of stocks of purchased by User
            # adjust user's budget
            #
        #
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


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
        if quote:
            return render_template("quoted.html", quote = quote)
        else:
            return apology("Inavlid stock symbol", 403)
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")
        password_repeat = request.form.get("password_repeat")
        # if username already exsits
        if db.execute("SELECT username FROM users WHERE username = %s", (username, )):
            # appropriate apology message
            return apology("The username already exists", 403)

            # check if password matches the requirements
        pCounter = 0
        dCounter = 0
        # require that the password be at least 8 characters long
        if len(password) < 8:
            return apology("The password is too short", 403)
        for char in password:
            print(char)
            if char in string.punctuation:
                pCounter += 1
            elif char.isdigit():
                dCounter += 1
        # require that the password includes at least 2 digits and 1 special character
        if not (pCounter >= 1 and dCounter >= 2):
            print(dCounter)
            return apology("Your password does not contain at least 2 digits and 1 special character", 403)
        # check if the password has been repeated correctly
        elif password != password_repeat:
            print("no match")
            return apology("Your passwords don't match", 403)
        # if password checks out
        else:
            print("validated")
            db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", username, generate_password_hash(password))
            return redirect("/login")
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    return apology("TODO")











