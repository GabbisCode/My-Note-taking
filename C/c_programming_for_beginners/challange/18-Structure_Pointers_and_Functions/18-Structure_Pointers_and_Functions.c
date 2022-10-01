/**
 * @file 18-Structure_Pointers_and_Functions.c
 * @author gabbi (gabbi@outlook.com)
 * @date 2022-09-05
 */

#include <stdio.h>
#include <stdlib.h>

struct itemInfo
{
    char *itemName;
    int qty;
    float price;
    float amount;
};

void readItem (struct itemInfo *ptr); 
void printItem (struct itemInfo const *ptr);

int main(void)
{
    struct itemInfo item;
    struct itemInfo *pitem;

    pitem = &item;

    pitem->itemName = (char *)malloc(20 * sizeof(char));

    readItem(pitem);
    printItem(pitem);

    free(pitem->itemName);
    pitem->itemName = NULL;

    return 0;
}

void readItem (struct itemInfo *ptr)
{
    printf("Name: ");
    scanf("%s", ptr->itemName);

    printf("Quantity: ");
    scanf("%d", &ptr->qty);

    printf("Price: ");
    scanf("%f", &ptr->price );

    ptr->amount = (float)(ptr->qty) * (ptr->price); //因为qty是int，所以需要转换成type float。
}

void printItem (struct itemInfo const *ptr)
{
    printf("\nThe name of the item: %s.\n", ptr->itemName);
    printf("The quantity of the item: %d.\n", ptr->qty);
    printf("The price of the item: %.2f.\n", ptr->price);
    printf("The amount of the item: %.2f.\n", ptr->amount);
}

/***********************************************************************
 * 一开始直接写了struct itemInfo *pitem;是错误的。
 * 需要先给这个指针在内存中申请一个空间，所以需要先struct itemInfo item; 
 * 再struct itemInfo *pitem; 然后赋值。
 * 要确保pitem不为0
 * if(pItem == NULL)
        exit(-1);
 ***********************************************************************/