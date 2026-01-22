#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define INITIAL_BUDGET 1000

// Function to print the casino header
void printCasinoHeader() {
    printf("***************************\n");
    printf("*        Casino C         *\n");
    printf("***************************\n\n");
}

// Function to print a random motivational quote
void printMotivationalQuote() {
    const char *quotes1[] = {
        "Keep pushing your luck!",
        "The next spin could be the big one!",
        "You can't win if you don't play!",
        "The thrill is just one bet away!",
        "The house always wins, but today might be your day!",
        "It's all about the right timing!",
        "A little luck goes a long way!",
        "Today could be the day you change your life!",
        "You can win big with just one spin!",
        "Keep going; your winning streak is just around the corner!"
    };
    // Generate a random index to choose a quote
    int quoteIndex = rand() % 10;
    printf("\nQuote: %s\n\n", quotes1[quoteIndex]);
}

// Function to print a random bankruptcy message
void printBankruptcyMessage() {
    const char *messages[] = {
        "Good news! You get a fresh start tomorrow!",
        "Don't worry, we won't tell anyone about your 'donation' to the casino.",
        "No worries, you're just contributing to someone else's jackpot!"
    };
    // Generate a random index to choose a message
    int messageIndex = rand() % 3;
    printf("\n%s\n", messages[messageIndex]);
}

// Function to get a valid bet from the user
int getValidBet(int budget) {
    int bet = 0;
    printf("Choose your bet amount (50, 100, 500, All in (0)): ");
    if (scanf("%d", &bet) != 1) {
        printf("Invalid input. Please enter a valid number.\n");
        return -1;
    }
    if (bet == 0) {
        bet = budget;
    } else if (bet != 50 && bet != 100 && bet != 500) {
        printf("Invalid bet amount!\n");
        return -1;
    }
    if (bet > budget) {
        printf("You don't have enough budget!\n");
        return -1;
    }
    return bet;
}

// Function to play the slots game
void slots(int *budget) {
    int bet = getValidBet(*budget);
    if (bet == -1) {
        return;
    }

    // Deduct the bet amount from the budget
    *budget -= bet;

    // Simulate slot machine spin
    printf("\nSpinning the slots...\n");
    sleep(1);
    
    // Symbols for the slot machine
    const char *symbols[] = {"Cherry", "Lemon", "Orange", "Bell", "Seven"};
    int slot1 = rand() % 5;
    int slot2 = rand() % 5;
    int slot3 = rand() % 5;

    // Display the results of the spin
    printf("\n[ %s ] [ %s ] [ %s ]\n", symbols[slot1], symbols[slot2], symbols[slot3]);

    // Check for winning conditions
    if (slot1 == slot2 && slot2 == slot3) {
        printf("Congratulations! You hit the jackpot!\n");
        *budget += bet * 10; // Jackpot payout
    } else if (slot1 == slot2 || slot1 == slot3 || slot2 == slot3) {
        printf("You won a smaller prize!\n");
        *budget += bet * 2; // Partial match prize
    } else {
        printf("Sorry, you didn't win this time.\n");
    }
}

// Function to play the roulette game
void roulette(int *budget) {
    int bet = getValidBet(*budget);
    if (bet == -1) {
        return;
    }

    // Deduct the bet amount from the budget
    *budget -= bet;

    // Simulate roulette spin
    printf("\nSpinning the roulette wheel...\n");
    sleep(1);
    int winningNumber = rand() % 37; // Winning number between 0 and 36

    // Ask the player for their chosen number, color, and odd/even bets
    int chosenNumber, colorBet, oddEvenBet;
    printf("Enter your chosen number (0-36): ");
    if (scanf("%d", &chosenNumber) != 1 || chosenNumber < 0 || chosenNumber > 36) {
        printf("Invalid chosen number!\n");
        return;
    }

    printf("Bet on color? (1 for Red, 2 for Black, -1 for None): ");
    if (scanf("%d", &colorBet) != 1 || (colorBet != 1 && colorBet != 2 && colorBet != -1)) {
        printf("Invalid color bet!\n");
        return;
    }

    printf("Bet on odd/even? (1 for Odd, 2 for Even, -1 for None): ");
    if (scanf("%d", &oddEvenBet) != 1 || (oddEvenBet != 1 && oddEvenBet != 2 && oddEvenBet != -1)) {
        printf("Invalid odd/even bet!\n");
        return;
    }

    // Determine if the player wins any bets
    int win = 0;

    // Check chosen number
    if (chosenNumber == winningNumber) {
        printf("You won on your chosen number!\n");
        *budget += bet * 36; // Payout 35 to 1
        win = 1;
    }

    // Check color bet
    if (colorBet == 1 && winningNumber % 2 == 1) {
        printf("You won on your chosen color!\n");
        *budget += bet * 2; // Payout 1 to 1 for Red
        win = 1;
    } else if (colorBet == 2 && winningNumber % 2 == 0) {
        printf("You won on your chosen color!\n");
        *budget += bet * 2; // Payout 1 to 1 for Black
        win = 1;
    }

    // Check odd/even bet
    if ((oddEvenBet == 1 && winningNumber % 2 == 1) || (oddEvenBet == 2 && winningNumber % 2 == 0)) {
        printf("You won on your chosen odd/even bet!\n");
        *budget += bet * 2; // Payout 1 to 1
        win = 1;
    }

    // If no winning conditions were met
    if (!win) {
        printf("Sorry, you didn't win this time.\n");
    }
}

void aviator(int *budget) {
    int bet = getValidBet(*budget);
    if (bet == -1) {
        return;
    }

    // Deduct the bet amount from the budget
    *budget -= bet;

    // Simulate the Aviator game
    printf("\nStarting the Aviator game...\n");
    sleep(1);

    // Initialize multiplier and cash-out flag
    double multiplier = 1.0;
    int cashOut = 0;
    char choice;

    // Adjust the probability of crashing
    // Define a threshold value for crashing based on the multiplier
    // This can be fine-tuned for better game balance
    double crashThreshold = 1.0;

    while (1) {
        // Calculate a more dynamic jump in the multiplier
        double jump = (rand() % 10 + 1) / 10.0;
        if (multiplier < 2.0) {
            // Small jump in multiplier when under 2.0
            multiplier += jump;
        } else {
            // Larger jump after 2.0 multiplier
            multiplier += jump * 2.0;
        }

        // Display the current multiplier
        printf("\rCurrent multiplier: x%.2f", multiplier);
        fflush(stdout);
        sleep(1); // Delay for realism

        // Prompt user to cash out or continue
        printf("\nDo you want to cash out? (y/n): ");
        if (scanf(" %c", &choice) != 1) {
            printf("Invalid input!\n");
            return;
        }

        // Check user choice
        if (choice == 'y' || choice == 'Y') {
            cashOut = 1;
            break;
        }

        // Check if the game crashes based on a calculated crash threshold
        // Increase the crash threshold as the multiplier increases
        crashThreshold += 0.5; // Increase the threshold each round

        // Generate a random value between 0 and 1
        double randomValue = (double)rand() / RAND_MAX;

        // If the random value is less than the crash threshold, the game crashes
        if (randomValue < crashThreshold / 100.0) {
            printf("\nGame crashed! Multiplier: x%.2f\n", multiplier);
            cashOut = 0;
            break;
        }
    }

    // Calculate winnings or losses
    if (cashOut) {
        int winnings = (int)(bet * multiplier);
        printf("\nCongratulations! You cashed out at x%.2f and won $%d\n", multiplier, winnings);
        *budget += winnings;
    } else {
        printf("\nSorry, you lost your bet!\n");
    }
}


// Function to print the player's budget
void printBudget(int budget) {
    printf("Your current budget is $%d\n", budget);
}

// Main function
int main() {
    srand(time(NULL));
    int budget = INITIAL_BUDGET;

    // Print the casino header
    printCasinoHeader();

    while (budget > 0) {
        printBudget(budget);
        printMotivationalQuote();

        // Prompt the player to choose a game
        printf("Choose a game:\n");
        printf("1. Slots\n");
        printf("2. Roulette\n");
        printf("3. Aviator\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        int choice;
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a valid number.\n");
            // Clear the input buffer
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                slots(&budget);
                break;
            case 2:
                roulette(&budget);
                break;
            case 3:
                aviator(&budget);
                break;
            case 4:
                printf("Thank you for playing! Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    // If the player goes bankrupt
    printBankruptcyMessage();
    printf("\nYou ran out of budget!\n");

    return 0;
}
