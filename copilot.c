#include <stdio.h>

int main() {
    int secret = 7;
    int guess;
    int tries = 0;

    printf("I'm thinking of a number between 1 and 10.\n");

    while (tries < 3) {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        if (guess == secret) {
            printf("Correct! You win!\n");
            return 0;
        } else if (guess < secret) {
            printf("Too low.\n");
        } else {
            printf("Too high.\n");
        }

        tries++;
    }

    printf("Sorry, you lose. The number was %d.\n", secret);
    return 0;
}
