SELECT name FROM people
JOIN stars ON people.id = stars.person_id JOIN movies ON movies.id = stars.movie_id
WHERE movies.id IN
(SELECT )


(SELECT id FROM movies WHERE people.name = "Kevin Bacon" AND people.birth = 1958);