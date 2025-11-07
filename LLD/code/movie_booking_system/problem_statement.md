# Movie Ticket Booking System

## Problem

There are various movies playing at given theaters at different time slots.

The aim is to come up with an object-oriented solution to determine the price of tickets for two types of customers.

| Customer | Price ($) |
| -------- | --------- |
| VIP      | 12.50     |
| Guest    | 15.00     |

| Slot | Time             |
| ---- | ---------------- |
| T1   | 10 AM            |
| T2   | 1 PM             |
| T3   | 4 PM             |
| T4   | 8 PM             |
| T5   | 11 PM (VIP only) |

> Given the theater = "AMC-Dinein", movie = "Spiderman", timeslot = "T4", numtickets = "5" and customerType="Guest", the total price for the tickets if this is a valid purchase would be "75.00".

## Requirement 1

The table at the top indicates movies played at specified screens for specified time slots.

The table at the bottom indicates the maximum number of seats per screen.

| Theater    | Movie        | Screen | Time Slot  |
| ---------- | ------------ | ------ | ---------- |
| AMC-DineIn | Cold Pursuit | 1      | T1, T5     |
| AMC-DineIn | Cold Pursuit | 2      | T2, T3     |
| AMC-DineIn | Spiderman    | 1      | T2, T3, T4 |
| AMC-DineIn | Spiderman    | 2      | T1, T4     |
| Jordon     | RobinHood    | 1      | T1, T2     |
| Jordon     | RobinHood    | 2      | T4, T5     |
| Jordon     | Cold Pursuit | 1      | T3, T4, T5 |
| Jordon     | Cold Pursuit | 2      | T1, T2     |

| Theater    | Screen | Number of seats |
| ---------- | ------ | --------------- |
| AMC-DineIn | 1      | 45              |
| AMC-DineIn | 2      | 60              |
| Jordon     | 1      | 80              |
| Jordon     | 2      | 15              |

## Requirement 2

If the purchase cannot be made successfully, it is expected to display the appropriate error code corresponding to the reason as described in the following table.

| Customer  | Error Code | Description                                                                                                                                                |
| --------- | ---------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------- |
| VIP/Guest | 1          | Customer has chosen a theater where the requested movie is not screened, irrespective of the number of tickets and time slot                               |
| VIP/Guest | 2          | Customer has requested for tickets, more than the number of available seats for the correct theater, movie and time slot                                   |
| VIP/Guest | 3          | Customer has requested an invalid time slot for a specific movie in the right theater, irrespective of the number of tickets                               |
| Guest     | 4          | Guest customer has requested for an exclusive time slot (which is available for VIP customers alone), for the right theater, movie and the number of seats |
| VIP       | 5          | VIP customer has requested for an exclusive time slot, but with an incorrect choice of theater or movie or the number of tickets                           |

### Constraints

- 0 < numTickets < 100
- If a valid purchase can be made then the cost should be rounded to two decimal places.
  - Example: If the cost is $12.5, it should be 12.50. If the cost is $15, it should be 15.00
- In case of a purchase cannot be made the error code is displayed as it is without any decimal.
  - Example: If the error code is 1, then output should simply be 1. If the error code is 3, then output should simply be 3

## Test Cases

| Case # | Input                           | Output |
| ------ | ------------------------------- | ------ |
| 1      | AMC-DineIn Spiderman T4 5 Guest | 75.00  |
| 2      | Jordon RobinHood T3 5 VIP       | 3      |

### Explanations

For case #1, the purchase is valid since:

- Spiderman movie is screened in AMC-Dineln theater
- Customer, who is a guest has requested a valid time slot
- Requested seats are available

For case #2, the purchase is invalid since:

- Customer has requested an invalid time slot, irrespective of type of customer and number of tickets.
- But RobinHood movie is screened in Jordon theater
