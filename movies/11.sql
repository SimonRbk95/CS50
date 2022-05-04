SELECT title FROM movies JOIN ratings ON movies.id = ratings.movie_id JOIN stars ON movies.id = stars.movie_id JOIN people ON stars.person_id = people.id WHERE people.id = "Chadwick Bosemann" AND WHERE (SELECT TOP 5 FROM ratings.rating);

WHERE people.name = "Chadwick Bosemann"
SELECT title FROM movies WHERE name IN (SELECT people )