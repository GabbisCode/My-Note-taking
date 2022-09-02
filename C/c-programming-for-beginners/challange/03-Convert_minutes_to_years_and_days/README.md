# Requirements

In this challenge, you are to create a C program that converts the number of minutes to days and years. The program should ask the user to enter the number of minutes via the terminal. The program should display as output the minutes and then its equivalent in years and days. The program should create variables to store (should all be of type double).

* minutes (int)
* minutes in year
* Years
* Days

Need to perform a calculation and use arithmetic operators. You have to figure out the conversions.

# Code by Jason

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int minutesEntered = 0;
    double years = 0.0;
    double days = 0.0;
    double minutesInYear = 0;

    printf("Please enter the number of minutes: ");

    // get input from user
    scanf("%d", &minutesEntered);

    minutesInYear = (60 * 24 * 365);

    years = (minutesEntered / minutesInYear);
    days = (minutesEntered / 60.0) / 24.0;

    printf("%d minutes is approximately %f years and %f days\n", minutesEntered, years, days);

    return 0;
}

```
