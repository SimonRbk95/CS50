-- Keep a log of any SQL queries you execute as you solve the mystery.

-- check all descriptions
SELECT description FROM crime_scene reports

-- get descriptions of instances where stuff got stolen
-- examining cases with keyword "theft" first
SELECT description
FROM crime_scene_reports
WHERE description LIKE"%Theft%"
-- Found theft of CS50 duck
-- 10:15am at Humphrey Street bakery, three witnesses, each interview metions bakery

-- check interviews
SELECT transcript
FROM interviews
WHERE id = (SELECT )

