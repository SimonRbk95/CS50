CREATE TABLE portfolio(
   id INTEGER PRIMARY KEY,
   user_id INTEGER,
   symbol TEXT NOT NULL,
   quantity INTEGER NOT NULL,
   purchase_price INTEGER NOT NULL,
   purchase_date INTEGER NOT NULL,
   FOREIGN KEY (user_id)
      REFERENCES users (id)
         ON DELETE CASCADE
         ON UPDATE NO ACTION
);

("INSERT INTO portfolio (symbol, quantity, purchase_price, purchase_date) VALUES(?,?,?,?)", ())
(INSERT INTO portfolio)




   purchase_price INTEGER NOT NULL,
   purchase_date INTEGER NOT NULL,