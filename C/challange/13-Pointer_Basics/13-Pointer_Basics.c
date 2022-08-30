#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int age = 25;
    int * page = NULL; //改成pAge会更好，直观！
    
    page = &age;

    // printf("The address of age is %p.\n", &age);
    printf("The address of the pointer is %p.\n", (void*)&page);
    printf("The value of the pointer is %p.\n", page);
    printf("The value of what the pointer is pointing to is %d.\n", *page);

    return 0;
}