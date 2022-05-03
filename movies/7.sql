SELECT title, year FROM movies WHERE year = 2010 ORDER BY (SELECT )
SELECT movies.title FROM movies INNER JOIN ratings ON ratings.movie_id = movies.id ORDER BY (SELECT DISTINCT rating FROM ratings);