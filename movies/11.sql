SELECT title FROM movies JOIN ratings ON movies.id = ratings.movie_id JOIN stars ON movies.id = stars.movie_id JOIN people ON stars.person_id = people.id WHERE people.name = "Chadwick Bosemann" ORDER BY ratings.rating LIMIT 5;

WHERE people.name = "Chadwick Bosemann"
SELECT title FROM movies WHERE name IN (SELECT people )