-- Keep a log of any SQL queries you execute as you solve the mystery.

-- check all descriptions
SELECT description FROM crime_scene reports

-- get descriptions of instances where stuff got stolen
SELECT description
FROM crime_scene_reports
WHERE description IN ("%theft%", "%burglary%, %Shoplifiting)
