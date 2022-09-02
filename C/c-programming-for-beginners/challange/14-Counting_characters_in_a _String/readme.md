# 14-Counting_characters_in_a _String

## Requirements

In this challenge, you are going to write a program that tests your understanding of pointer arithmetic and the const modifier.

Write a function that calculates the length of a string:

* the function should take as a parameter a const char pointer
* the function can only determine the length of the string using pointer arithmetic, incrementation operator (++pointer) to get to the end of the string
* you are required to use a while loop using the value of the pointer to exit
* the function should subtract two pointers (one pointing to the end of the string and one pointing to the beginning of the string)
* the function should return an int that is the length of the string passed into the function pass by value

## Codes by Jason

```c
#include <stdio.h>
#include <stdlib.h>

int stringLength(const char *string);

int main()
{
   printf("%d \n", stringLength("stringLength test"));
   printf("%d \n", stringLength(""));
   printf("%d \n", stringLength("jason"));

    return 0;
}

int stringLength(const char *string)
{
    const char *lastAddress = string;

    while (*lastAddress)
        ++lastAddress;

    return lastAddress - string;
}

```
