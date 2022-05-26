CREATE TABLE portfolio(
   id INTEGER PRIMARY KEY,
   user_id INTEGER,
   symbol TEXT NOT NULL,
   quantity INTEGER NOT NULL,
   purchase_price INTEGER NOT NULL,
   pruchase_date INTEGER NOT NULL,
   FOREIGN KEY (user_id)
      REFERENCES users (id)
         ON DELETE CASCADE
         ON UPDATE NO ACTION
);

INSERT INTO portfolio (symbol)