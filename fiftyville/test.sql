-- Keep a log of any SQL queries you execute as you solve the mystery.

-- check all descriptions
SELECT
       description
FROM
       crime_scene reports;


-- get descriptions of instances where stuff got stolen
-- examining cases with keyword "theft" first
SELECT
       description, year, month, day
FROM
       crime_scene_reports
WHERE
       description LIKE "%Theft%";
-- Found theft of CS50 duck
-- 28th of July at 10:15am at Humphrey Street bakery, three witnesses, each interview metions bakery

-- check interviews
SELECT
    transcript
FROM
    interviews
WHERE
    year = 2021
    AND month = 07
    AND day = 28
    AND transcript LIKE "%bakery%";
-- each statement gives great insights, need to pursue each one of them

-- 1st lead: car that left within 10 minutes of the theft.
-- Look at parking lot security footage in that time frame
-- check license plate numbers of the cars in the time frame:
SELECT
    license_plate,hour, minute
FROM
    bakery_security_logs
WHERE
    year = 2021
    AND month = 07
    AND day = 28
    AND hour = 10
    AND activity = "exit"
    AND minute BETWEEN 15 AND 20
    ORDER BY minute;
-- names of owners ban be looked up based upon license plate numbers
