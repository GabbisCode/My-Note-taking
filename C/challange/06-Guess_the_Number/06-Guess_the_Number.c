/**
 * @file 06-Guess_the_Number.c
 * @author Gabbi (gabbi.huang@outlook.com)
 * @date 2022-08-13 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t t;
    int usersNumber;
    int randomNumber;

    srand((unsigned)time(&t));
    randomNumber = rand() % 21;

    printf("This is a guessing game.\n");
    printf("I have chosen a number between 0 and 20 which you must guess.\n");

    for (int count = 5; count >= 1; --count)
    {
        printf("You have %d tries left.\n", count);
        printf("Enter a guess:");
        scanf("%d", &usersNumber);

        if (usersNumber > randomNumber)
        {
            printf("Sorry, %d is wrong. My number is more than that.", usersNumber);
        }
        else if (usersNumber < randomNumber)
        {
            printf("Sorry, %d is wrong. My number is less than that.", usersNumber);
        }
        else
        {
            printf("Congratulations. You guessed it!");
            break;
        }
    }

    return 0;
}