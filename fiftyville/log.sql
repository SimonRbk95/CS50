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
-- names of owners ban be looked up based upon license plate numbers



-- 2nd lead: earlier in the morning of the same day, the thief was seen at an ATM on Legett Street withdrawing
-- try to find possibe suspect's transaction and his account number
SELECT account_number
FROM atm_transactions
WHERE year = 2021 AND month = 07 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw";
-- gives account number of the people who withdrew money. names can be looked up



-- 3rd lead: on the phone, the thief talked about taking the earliest flight out of Fiftyville on the next day (07/29/21)
-- thief asked the other guy on the phone to purchase the tickets
-- we have:
-- 1. airport name
-- 2. the day of the booking
-- 3. the day of the phone call
-- 4. the person on the receiving end of the call booked the tickets
-- match phone number, license plate number, passport_number to get right name

-- get passport number of people that flew to fif
SELECT passport_number
FROM passengers
JOIN flights
ON passengers.flight_id = flights.id
JOIN airports
ON flights.origin_airport_id = airports.id
WHERE airports.name = "Fiftyville"
AND flights.year = 2021 AND flights.month = 7 AND flights.day = 29;

-- destinations that correspond to flights that depart from Fiftyville
SELECT full_name
FROM airports
WHERE id = (SELECT destination_aiport_ID
       FROM flights
       WHERE origin_airport_id = "Fiftyville" AND year = 2021 AND month = 7 AND day = 29);
