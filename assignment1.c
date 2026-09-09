/*
 * Program Name: EECS 348 Assignment 1
 * Description: A number guessing game where the user has up to
 *              three valid attempts to guess a randomly generated
 *              number between 1 and 10.
 * Inputs: The user's guesses entered through the keyboard.
 * Output: Messages indicating whether the guess is too high,
 *         too low, correct, invalid, and the number of tries remaining.
 * Collaborators: None
 * Other Sources: Google Gemini and Microsoft Copilot
 * Author: [Your Full Name]
 * Creation Date: September 8, 2026
 * Revision Date: September 8, 2026
 * Revisions: Added a random secret number, range checking,
 *            remaining-tries messages, and detailed comments.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    // Initialize the random number generator using the current time.
    srand(time(NULL));

    // Generate a random secret number between 1 and 10.
    int secret = rand() % 10 + 1;

    // Store the user's current guess.
    int guess;

    // Store the maximum number of valid guesses allowed.
    int max_tries = 3;

    // Store the number of valid guesses the user has made.
    int tries = 0;

    // Track whether the user has correctly guessed the secret number.
    int won = 0;

    // Continue asking for guesses until the user wins or uses all
    // three valid attempts.
    while (tries < max_tries) {

        // Ask the user to enter a number between 1 and 10.
        printf("Attempt %d of %d - Enter your guess (1-10): ",
               tries + 1, max_tries);

        // Read the user's input and check whether it is an integer.
        if (scanf("%d", &guess) != 1) {

            // Display an error message for non-integer input.
            printf("Invalid input. Please enter an integer between 1 and 10.\n");

            // Clear the invalid characters from the input buffer.
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {
                // Remove invalid characters from the input buffer.
            }

            // Do not increase tries because the input was not a valid guess.
            continue;
        }

        // Check whether the guess is outside the valid range.
        if (guess < 1 || guess > 10) {

            // Tell the user that the guess must be between 1 and 10.
            printf("Invalid guess. Please enter a number between 1 and 10.\n");

            // Do not increase tries because the guess was out of range.
            continue;
        }

        // Increase the number of attempts only after receiving
        // a valid guess between 1 and 10.
        tries++;

        // Check whether the user's guess is correct.
        if (guess == secret) {

            // Tell the user that they guessed the number correctly.
            printf("Correct! You win!\n");

            // Record that the user won the game.
            won = 1;

            // Stop the loop immediately after a correct guess.
            break;
        }

        // Check whether the guess is lower than the secret number.
        else if (guess < secret) {

            // Tell the user that the guess is too low.
            printf("Too low.\n");
        }

        // If the guess is not correct or too low, it must be too high.
        else {

            // Tell the user that the guess is too high.
            printf("Too high.\n");
        }

        // Display the number of valid attempts remaining.
        printf("You have %d %s remaining.\n",
               max_tries - tries,
               (max_tries - tries == 1) ? "try" : "tries");
    }

    // Check whether the user failed to guess the secret number.
    if (!won) {

        // Display the final losing message and reveal the secret number.
        printf("You lose! The secret number was %d.\n", secret);
    }

    // End the program successfully.
    return 0;
}
