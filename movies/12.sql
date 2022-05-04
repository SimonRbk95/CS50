SELECT titles FROM movies
JOiN stars
ON movies.id = stars.movie_id
JOIN people
ON people.id = stars.person_id
