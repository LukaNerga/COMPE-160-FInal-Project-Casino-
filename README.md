# Casino Console Game

A terminal-based casino simulation in C with Slots, Roulette, and Aviator.

## Features
- Budget management
- Randomized game outcomes
- Slots, Roulette, Aviator

## How to Run
1. Compile with `gcc main.c -o casino`
2. Run `./casino`

## Screenshot
![Game Screenshot](screenshots/demo.png)


## Game Logic (Pseudocode)

Initialize budget = 1000

WHILE budget > 0
    Display budget
    Show motivational quote
    Ask player to choose game:
        1. Slots
        2. Roulette
        3. Aviator
        4. Exit
    Get player's bet
    Play chosen game:
        - Slots → random symbols, check matches, adjust budget
        - Roulette → spin, check number/color/odd-even, adjust budget
        - Aviator → multiplier grows, cash out or crash, adjust budget
    Update budget
END WHILE

IF budget <= 0
    Show bankruptcy message
