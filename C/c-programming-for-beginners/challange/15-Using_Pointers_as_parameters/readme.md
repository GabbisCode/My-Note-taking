# 15-Using_Pointers_as_parameters

## Requirements

In this challenge, you are going to write a program that tests your understanding of pass by reference:

Write a function that squares a number by itself. The function should define as a parameter an it pointer.

## Codes by Jason

```c
#include <stdio.h>
#include <stdlib.h>

void square(int * x);

int main()
{
   int num = 5;

   square(&num);
   printf("The square of the given number is %d\n", num);

   return 0;
}

void square(int * x)
{
    *x = (*x) * (*x);
}

```
