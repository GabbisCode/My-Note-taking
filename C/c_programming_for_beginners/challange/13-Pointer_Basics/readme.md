# 13-Pointer_Basics

## Requirements

In this challenge, you are going to learn how to create, initialize, assign, and access a pointer.

Write a program that creates an integer variable with a hard-coded value. Assign that variable's address to a pointer variable.

Display as output the address of the pointer, the value of the pointer, and the value of what the pointer is pointing to.

## Codes by Jason

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num = 150;
    int *pNum = NULL;

    pNum = #

    printf("num address is:  %p\n", &num);
    printf("Address of pNum: %p\n", &pNum);
    printf("value of the pNum: %p\n", pNum);
    printf("value of what pNum is pointing to: %d\n", *pNum);

    return 0;
}

```
