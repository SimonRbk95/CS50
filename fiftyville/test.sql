SELECT name FROM people WHERE phone_number IN (Select caller FROM phone_calls WHERE year = 2021 AND month = 07 AND day = 28) ORDER BY name;
