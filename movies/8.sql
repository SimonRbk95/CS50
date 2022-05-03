SELECT name from people WHERE id = (SELECT person_id FROM stars WHERE movie_id = (SELECT id FROM movies WHERE title = "Toy Story"));
SELECT people.name FROM people JOIN people ON people.id = stars.person_id JOIN stars ON movies.movie_id = stars.movie_id WHERE movies.title = "Toy Story";
