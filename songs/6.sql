SELECT songs.name FROM songs WHERE artists.name = "Post Malone";
SELECT songs.name FROM songs INNER JOIN artists ON artists.id = songs.artist_id WHERE artists.name = "Post Malone";