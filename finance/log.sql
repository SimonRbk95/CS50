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




ALTER TABLE portfolio ADD quantity_sold INTEGER NOT NULL;