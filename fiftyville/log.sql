-- Keep a log of any SQL queries you execute as you solve the mystery.

-- check all descriptions
SELECT description FROM crime_scene reports;

-- get descriptions of instances where stuff got stolen
-- examining cases with keyword "theft" first
SELECT description, year, month, day
FROM crime_scene_reports
WHERE description LIKE"%Theft%"
-- Found theft of CS50 duck
-- 28th of July at 10:15am at Humphrey Street bakery, three witnesses, each interview metions bakery

-- check interviews
SELECT transcript
FROM interviews
WHERE transcript LIKE "%bakery%";
-- each statement gives great insights, need to pursue each one of them

-- 1st lead: car that left within 10 minutes of the theft.
-- Look at parking lot security footage in that time frame
-- check license plate numbers of the cars in the time frame:
SELECT activity, hour, minute, license_plate
FROM bakery_security_logs
WHERE hour = 10
AND activity = "exit"
AND minute BETWEEN 15 AND 20
ORDER BY minute;



-- 2nd lead: earlier in the morning of the same day, the thief was seen at an ATM on Legett Street
-- try to find possibe suspect's transaction and his account number
SELECT transaction_type, account number
FROM atm_transactions
WHERE year = 2021 AND month = 07 AND day = 28 AND atm_location = "Legett Street";

-- 3rd lead: on the phone, the thief talked about taking the earliest flight out of Fiftyville on the next day (07/29/21)
-- thief asked the other guy on the phone to purchase the tickets


