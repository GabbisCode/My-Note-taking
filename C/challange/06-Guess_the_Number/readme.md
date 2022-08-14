# 06-Guess_the_Number

## Requirements

In this challenge, you are going to create a "Guess the Number" C program

Your program will generate a random number from 0 to 20. You will then ask the user to guess it. User should only be able to enter numbers from 0-20. The program will indicate to the user if each guess is too high or too low. The player wins the game if they can guess the number within five tries.

### Sample Output

This is a guessing game.
I have chosen a number between 0 and 20 which you must guess.

You have 5 tries left.
Enter a guess: 12
Sorry, 12 is wrong. My number is less than that.

You have 4 tries left.
Enter a guess: 8
Sorry, 8 is wrong. My number is less than that.

You have 3 tries left.
Enter a guess: 4
Sorry, 4 is wrong. My number is less than that.

You have 2 tries left.
Enter a guess: 2
Congratulations. You guessed it!

### Generating a random number

To generate a random number from 0-20

Include the correct system libraries:

```c
#include <stdlib.h>
#include <time.h>
```

Create a time variable:

```c
time_t t;
```

Initialize the random number generator:

```c
srand ((unsigned) time(&t));
```

Get the random number (0-20) and store in an int variable:

```c
int randomNumber = rand() % 21;
```

## Codes of Jason

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>  // for random number generator seed

int main()
{
    int randomNumber = 0;
    int guess = 0;
    int numberOfGuesses;
    time_t t;

    // Initialization of random number generator
    srand((unsigned) time(&t));

    // get the random number
    randomNumber = rand() % 21;

    printf("\nThis is a guessing game.");
    printf("\nI have chosen a number between 0 and 20, which you must guess. \n");

    for(numberOfGuesses = 5; numberOfGuesses > 0; --numberOfGuesses)
    {
        printf("\nYou have %d tr%s left.", numberOfGuesses, numberOfGuesses == 1 ? "y" : "ies");
        printf("\nEnter a guess: ");
        scanf("%d", &guess);

        if(guess == randomNumber)
        {
            printf("\nCongratulations.  You guessed it!\n");
            break;
        }
        else if(guess < 0 || guess > 20)  // checking for an invalid guess
            printf("I said the number is between 0 and 20.\n");
        else if(randomNumber > guess)
            printf("Sorry, %d is wrong.  My number is greater than that.\n", guess);
        else if(randomNumber < guess)
            printf("Sorry, %d is wrong.  My number is less than that.\n", guess);
    }
    printf("\nYou have had five tries and failed. The number was %d\n",randomNumber);

    return 0;
}

```
