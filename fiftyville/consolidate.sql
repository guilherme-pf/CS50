-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Checking the crime reports on the day and location of the theft
-- Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery, witnesses mention the bakery
SELECT *
FROM crime_scene_reports
WHERE day = 28 AND month = 7 AND street = "Humphrey Street";

-- checking for the interviews of the day of the crime
-- "Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame."
-- "I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money."
-- "As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket."
SELECT *
FROM interviews
WHERE month = 7 AND day = 28;

-- getting the logs for of exiting cars from the bakery whithin 10 minutes after the roberry
SELECT *
FROM bakery_security_logs
WHERE month = 7 AND day = 28 AND hour = 10 AND minute > 15 AND minute < 25;

-- getting the logs for withdraws from leggett street atm on the 28th of July
SELECT *
FROM atm_transactions
WHERE month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw";

-- getting the earliest flight on the next day of the robbery, which is id = 36, from airport 8 (fiftyville) to airport 4 (laguardia- new york)
SELECT *
FROM flights
WHERE month = 7 AND day = 29
ORDER BY hour ASC
LIMIT 1;

-- getting the passengers of flight 36
SELECT *
FROM passengers
WHERE flight_id = 36;

-- getting the calls that lasted less 1 minute July 28th
SELECT *
FROM phone_calls
WHERE month = 7 AND day = 28 AND duration < 60;

--consolidate all querys to find out the thief is Bruce
SELECT *
FROM phone_calls
JOIN people ON phone_calls.caller = people.phone_number
JOIN passengers ON people.passport_number = passengers.passport_number
JOIN bakery_security_logs ON people.license_plate = bakery_security_logs.license_plate
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON bank_accounts.person_id
WHERE phone_calls.month = 7 AND phone_calls.day = 28 AND phone_calls.duration < 60 AND passengers.flight_id = 36
AND bakery_security_logs.month = 7 AND bakery_security_logs.day = 28 AND bakery_security_logs.hour = 10 AND bakery_security_logs.minute > 15 AND bakery_security_logs.minute < 25
AND atm_transactions.month = 7 AND atm_transactions.day = 28 AND atm_transactions.atm_location = "Leggett Street" AND atm_transactions.transaction_type = "withdraw";

-- Getting the accomplince name as Robin
SELECT *
FROM people
WHERE phone_number = "(375) 555-8161";
