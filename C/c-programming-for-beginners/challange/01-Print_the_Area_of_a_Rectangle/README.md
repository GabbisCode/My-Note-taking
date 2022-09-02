In this challenge, you are to create a C program that displays the perimeter and area of a rectangle. The program should create 4 variables of type double:

* one variable to store the width of the rectangle
* one variable to store the height of the rectangle
* one variable to store the perimeter of the rectangle
* one variable to store the area of the rectangle

The program should perform the calculation for the perimeter of a rectangle. Use the + operator addition and the * operator for multiplication. Perimeter is calculated by adding the height and width and then multiplying by two. Area is calculated by multiplying the width * height variables.

# Requirements

The program should display the height, width, and perimeter variables in the correct format in one print statement.

The program should display the height, width, and area variables in the correct format in one print statement.

# Code by Jason

```c
/* Author: Jason Fedin
   Purpose:  This program is going to calculate the area of a rectangle
   */

#include <stdio.h>
#include <stdlib.h>

int main()
{
   // declaring variables
   double width = 34.2;
   double height = 65.5;
   double perimeter = 0.0;
   double area = 0.0;

   // performing perimeter calculation
   perimeter = 2.0 * (height + width);
   area = width * height;

   // displaying input
   printf("Width is:  %.2f, Height is: %.2f, Perimeter is: %f\n", width, height, perimeter);
   printf("Area is: %f\n", area);

   return 0;
}

```
