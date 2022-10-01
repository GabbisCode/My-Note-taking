/**
 * @file 15-Using_Pointers_as_parameters.c
 * @author Gabbi (gabbi@outlook.com)
 * @brief Write a function that squares a number by itself
 * @date 2022-09-03
 */

#include<stdio.h>
#include<stdlib.h>

void squareNum(int * address);

int main(void)
{
    int Num = 9;
    printf("The Value of Num is: %d.\n", Num);

    squareNum(&Num);
    printf("The sqaure of Num is: %d.\n", Num);

    return 0;
}

void squareNum(int *address)
{
    (*address) *= (*address);
}