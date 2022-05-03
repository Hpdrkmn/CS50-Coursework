-- Keep a log of any SQL queries you execute as you solve the mystery.

-- First query ran based on last known reports and only information given to us
SELECT description FROM crime_scene_reports
WHERE year = 2021 AND month = 7 AND day = 28 AND street = "Humphrey Street";

-- we find out the theft took place at 10:15am, 3 witnesses present, (all interviews mention bakery) littering took place 16:36. no witnesses.
SELECT transcripts FROM interviews
WHERE year = 2021 AND month = 7 AND day = 28 AND transcript LIKE "%bakery%";

-- The transcripts gave me possible leads to go on for, license plate logs, possbile ATM transactions, and earliest flights.
-- bakery security license logs query

SELECT name FROM people
JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND minute <=25
AND activity = "exit";

-- Possible Suspects: Vanessa, BRUCE, Barry, LUCA, SOFIA, IMAN, DIANA, KELSEY (recurring potential suspects in BOLD)
-- ATM transactions query

SELECT name FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = "Leggett Street" AND
transaction_type = "withdraw";

-- new suspects: BRUCE, DIANA, Brooke, KENNY, IMAN, LUCA, Taylor, Benista (recurring potential suspects in BOLD)
-- fiftyville airport id query

SELECT name FROM people
JOIN passengers ON passengers.passport_number = people.passport_number
WHERE passengers.flight_id = (
SELECT id FROM flights
WHERE year = 2021 AND month = 7 AND day = 29 AND origin_airport_id = (
SELECT id FROM airports WHERE city = "Fiftyville")
ORDER BY hour,minute
LIMIT BY 1);

--suspects list: Doris, SOFIA, BRUCE, Edward, KELSEY, Taylor, KENNY, LUCA (recurring potential suspects in BOLD)
--suspects in all 3 queries: BRUCE, LUCA

--phone call query
SELECT name FROM people
JOIN phone_calls ON phone_calls.caller = people.phone_number
WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60;
-- sofia, kelsey, kelsey, taylor, diana, carina, kenny, benista, BRUCE (is the only match and therefore is thief)

--Flight logs query
SELECT city FROM airports
WHERE id = (SELECT destination_airport_id FROM flights
WHERE year = 2021 AND month = 7 AND day = 29 AND origin_airport_id = (
    SELECT id FROM airports WHERE city = "Fiftyville")
    ORDER BY hour, minute
    LIMIT 1);
-- New York City was the destination of earliest flight

--finding who bruce called to find accomplice
SELECT phone_number FROM people WHERE name = "Bruce";
-- Bruce phone number is (367) 555-5533

-- use phone number to find accomplice

SELECT name FROM people
WHERE phone_number = (
SELECT receiver FROM phone_calls
WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60 AND caller = "(367) 555-5533");
-- BRUCE called Robin