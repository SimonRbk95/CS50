SELECT name FROM people WHERE id = (SELECT id FROM movies);
SELECT name FROM people WHERE id = (SELECT id FROM movies WHERE title = "%Toy Story%");
