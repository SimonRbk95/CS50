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
    license_plate
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
-- names of owners ban be looked up based upon license plate numbers:

SELECT
    name
FROM
    people
WHERE
    license_plate IN
    (
        SELECT
            license_plate
        FROM
            bakery_security_logs
        WHERE
            year = 2021
            AND month = 07
            AND day = 28
            AND hour = 10
            AND activity = "exit"
            AND minute BETWEEN 15 AND 20
            ORDER BY minute
    )
INTERSECT
-- 2nd lead: earlier in the morning of the same day, the thief was seen at an ATM on Legett Street withdrawing
-- try to find possibe suspect's transaction and his account number
SELECT
    name
FROM
    people
JOIN
    bank_accounts
ON
    bank_accounts.person_id = people.id
WHERE
    account_number IN
    (
    SELECT
        account_number
    FROM
        atm_transactions
    WHERE
        year = 2021
        AND month = 07
        AND day = 28
        AND atm_location = "Leggett Street"
        AND transaction_type = "withdraw"
    )
INTERSECT
-- gives account number of the people who withdrew money. names can be looked up
SELECT
    name
FROM
    people
JOIN
    passengers
ON
    people.passport_number = passengers.passport_number
WHERE
    passengers.flight_id =
    (
        SELECT
            id
        FROM
            flights
        WHERE
            year = 2021
            AND month = 07
            AND day = 29
            Order by
                hour, minute
            LIMIT
                1
    )
INTERSECT
SELECT
    name
FROM
    people
WHERE
    phone_number
IN
    (
    Select
        caller
    FROM
        phone_calls
    WHERE
        year = 2021
        AND month = 07
        AND day = 28
        AND duration < 60
    )
ORDER BY
    name;

-- accomplice
SELECT
    name
FROM
    people
JOIN
    phone_calls
ON
    phone_calls.receiver = people.phone_number
WHERE
    phone_number =
    (
        SELECT
            receiver
        FROM
            phone_calls
        WHERE
            caller =
                (
                    SELECT
                        phone_number
                    FROM
                        people
                    WHERE
                        name = "Bruce"
                )
            AND year = 2021
            AND day = 28
            AND month = 07
            AND duration < 60
    );

-- find where the city of escape

SELECT
    city
FROM
    airports
WHERE
    id =
    (
        SELECT
            destination_airport_id
        FROM
            flights
        WHERE
            origin_airport_id =
                (
                    SELECT
                        id
                    FROM
                        airports
                    WHERE
                        city = "Fiftyville"
                )
            AND year = 2021
            AND month = 07
            AND day = 29
        ORDER BY
            hour, minute
        )
        LIMIT 1
;






