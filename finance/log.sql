CREATE TABLE portfolio(
   id INTEGER PRIMARY KEY,
   user_id INTEGER,
   symbol TEXT NOT NULL,
   quantity INTEGER NOT NULL,
   price INTEGER NOT NULL,
   purchase BOOLEAN NOT NULL CHECK (purchase IN (0,1)),
   Timestamp DATETIME DEFAULT CURRENT_TIMESTAMP,
   FOREIGN KEY (user_id)
      REFERENCES users (id)
         ON DELETE CASCADE
         ON UPDATE NO ACTION
);


