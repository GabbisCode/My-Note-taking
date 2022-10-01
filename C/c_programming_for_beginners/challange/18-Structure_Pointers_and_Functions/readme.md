# 18-Structure_Pointers_and_Functions

## Requirements

Write a C program that creates a structure pointer and passes it to a function.

Create a structure named **item** with the following members:

* itemName - pointer
* quantity - int
* price - float
* amount - float (stores quantity * price)

Create a function named **readltem** that takes a structure pointer of type item as a parameter

* this function should read in (from the user) a product name, price, and quantity
* the contents read in should be stored in the passed in structure to the function

Create a function named **printItem** that takes as a parameter a structure pointer of type item

* function prints the contents of the parameter

The main function should declare an item and a pointer to the item

* you will need to allocate memory for the itemName pointer
* the item pointer should be passed into both the read and print item functions

## Codes by Jason

```
#include <stdio.h>
#include <stdlib.h>

struct item
{
    char *itemName;
    int qty;
    float price;
    float amount;
};

void readItem(struct item *i);
void printItem(struct item *i);

int main()
{
    struct item itm;
    struct item *pItem;

    pItem = &itm;

    pItem->itemName = (char *) malloc(30 * sizeof(char));

    if(pItem == NULL)
        exit(-1);

    // read item
    readItem(pItem);

    // print item
    printItem(pItem);

    free(pItem->itemName);

    return 0;
}

void readItem(struct item *i)
{
    printf("Enter product name: ");
    scanf("%s", i->itemName);

    printf("\nEnter price: ");
    scanf("%f", &i->price);

    printf("\nEnter quantity: ");
    scanf("%d", &i->qty);

    i->amount = (float)i->qty * i->price;
}

void printItem(struct item *i)
{
    /*print item details*/
	printf("\nName: %s",i->itemName);
	printf("\nPrice: %.2f",i->price);
	printf("\nQuantity: %d",i->qty);
	printf("\nTotal Amount: %.2f",i->amount);
}

```
