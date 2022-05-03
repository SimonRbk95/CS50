SELECT name FROM people WHERE id = (SELECT id FROM movies);
SELECT name FROM people WHERE id = (SELECT id FROM movies WHERE title = "%Toy Story%");
(SELECT person_id FROM stars WHERE movie_id = (SELECT id FROM movies WHERE title = "Toy Story"))
