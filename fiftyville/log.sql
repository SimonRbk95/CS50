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
WHERE transcripts LIKE "%bakery%";
-- each statement gives great insights, need to pursue each one of them

-- 1st lead: car that left within 10 minutes of the theft.
-- Look at parking lot security footage in that time frame
SELECT activity, hour
FROM bakery_security_logs



-- 2nd lead: earlier in the morning of the same day, the thief was seen at an ATM on Legett Street

-- 3rd lead: on the phone, the thief talked about taking the earliest flight out of Fiftyville on the next day
-- thief asked the other guy on the phone to purchase the tickets


