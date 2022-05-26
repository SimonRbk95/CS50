CREATE TABLE portfolio(
   id INTEGER PRIMARY KEY,
   user_id INTEGER,
   symbol TEXT NOT NULL,
   quantity INTEGER NOT NULL,
   purchase_price INTEGER NOT NULL,
   Timestamp DATETIME DEFAULT CURRENT_TIMESTAMP,
   FOREIGN KEY (user_id)
      REFERENCES users (id)
         ON DELETE CASCADE
         ON UPDATE NO ACTION
);

("INSERT INTO portfolio (symbol, quantity, purchase_price, purchase_date) VALUES(?,?,?,?) WHERE user_id = (?)", ())
(INSERT INTO portfolio)




   purchase_price INTEGER NOT NULL,
   purchase_date INTEGER NOT NULL,

       List = []
    db.execute("SELECT symbol, quantity FROM users WHERE user_id")
    # stocks owned dictionary:
        # symbol
        # quantity
        # current price
        # total value of the shares owned

    # cash balance
    # grand total

    return render_template("index.html", #TODO)