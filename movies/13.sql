SELECT name FROM people JOIN stars ON people.id = stars.person_id JOIN movies ON movies.id = stars.movies_id WHERE name IN (SELECT name )