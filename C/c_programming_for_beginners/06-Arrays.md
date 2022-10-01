# 06-Arrays

## Creating and Using Arrays

It is very common to in a program to store many data values of a specified type.

In a sports program, you might want to store the scores for all games or the scores for each player. You could write a program that does this using a different variable for each score. If there are a lot of games to store then this is very tedious. Using an array will solve this problem.

Arrays allow you to group values together under a single name. You do not need separate variables for each item of data. An array is a fixed number of data items that are all of the same type.

### Declaring an Array

The data items in an array are referred to as **elements**. The elements in an array have to be the **same type** (int, long, double, etc). You cannot "mix" data types, no such thing as a single array of ints and doubles.

Declaring to use an array in a program is similar to a normal variable that contains a single value. Difference is that you need a number between square brackets [] following the name.

long numbers [10];

The number between square brackets defines how many elements the array contains. It is called the size of the array or the array dimension.

### Accessing an array's elements

Each of the data items stored in an array is accessed by the same name. You select a particular element by using an index (subscript) value between square brackets following the array name.

Index values are sequential integers that start from zero. Index values for elements in an array of size 10 would be from 0-9. Arrays are zero based. 0 is the index value for the first array element. For an array of 10 elements, index value 9 refers to the last element. It is a very common mistake to assume that arrays start from one. This is referred to as the off-by-one error. You can use a simple integer to explicitly reference the element that you want to access. To access the fourth value in an array, you use the expression arrayName[3].

You can also specify an index for an array element by an expression in the square brackets following the array name. The expression must result in an integer value that corresponds to one of the possible index values. It is very common to use a loop to access each element in an array.

```c
for (i = 0; i < 10; ++i)
    print("Number is %d", numbers[i]);
```

![Array](image/Array.jfif)

#### Array out of bounds

If you use an expression or a variable for an index value that is outside the range for the array, your program may crash or the array can contain garbage data. This is referred to as an out of bounds error. The compiler cannot check for out of bounds errors so your program will still compile. It is very important to ensure that your array indexes are always within bounds.

### Assigning values to an Array

A value can be stored in an element of an array simply by specifying the array element on the left side of an equal sign.

```c
grades[100] = 95; //the value 95 is stored in element number 100 of the grades array
```

You can also use variables to assign values to an array.

### Using an array

```c
int main(void)
{
	int grades[10]; // Array storing 10 values
	int count = 10; // Number of values to be read
	long sum = 0; // Sum of the numbers
	float average = 0.0f; //Average of the numbers

	printf("\nEnter the 10 grades:\n"); // Prompt for the input

	// Read the ten numbers to be averaged
	for(int i = 0; i < count; ++i)
	{
		printf("%2u> ", i + 1);
		scan("%d", &grades[i]); //Read a grade
		sum += grades[i]; // Add it to sum
	}
	average = (float)sum/count; //average
	printf("\nAverage of the ten grades entered is: %.2f\n", average);

	return 0;
}
```

## Initializing an array

You will want to assign initial values for the elements of your array most of the time. Defining initial values for array elements makes it easier to detect when things go wrong. Just as you can assign initial values to variables when they are declared, you can also assign initial values to an array's elements.

To initialize an array's values, simply provide the values in a list. Values in the list are separated by commas and the entire list is enclosed in a pair of braces.

```c
//declaring an array called counters to contain five integer values and initializing each of these elements to zero
int counters[5] = { 0, 0, 0, 0, 0 }; 
```

```c
// declares an array named integers and sets the value of integers[0] to 0, integers[1] to 1, integers[2] to 2, and so on
int integers[5] = { 0, 1, 2, 3, 4 };
```

It is not necessary to completely initialize an entire array. If fewer initial values are specified, only an equal number of elements are initialized and the remaining values in the array are set to zero.

```c
// initializing the first three values of sample_data to 100.0, 300.0, and 500.5, and setting the remaining 497 elements to zero
float sample_data[500] = { 100.0, 300.0, 500.5 };
```

### Designated Initializers

C99 added a feature called designated initializers, which allows you to pick and choose which elements are initialized. By enclosing an element number in a pair of brackets, specific array elements can be initialized in any order.

```c
// initializing the sample_data array to 100.0, 300.0, and 500.5 for the first three values
float sample_ data[500] = { [2] = 500.5, [1] = 300.0, [0] = 100.0 };
```

```c
int arr[6] = {[5] = 212 }; // initialize arr[5] to 212
```

```c
#include <stdio.h>
#define MONTHS 12

int main(void)
{
	int days[MONTHS] = {31,28, [4] = 31,30,31, [1] = 29};
	int i;

	for (i = 0; i < MONTHS; i++)
		printf("%2d %d\n", i + 1, days[i]);

	return 0;
}
```

### traditional initialization

```c
#define MONTHS 12

int main(void)
{
	int days[MONTHS] = {31,28,31,30,31,30,31,31,30,31,30,31}
	int index;

	for (index = 0; index < MONTHS; index++)
		printf("Month %d has %2d days.\n", index +1, days[index]);

	return 0:
}
```

### Initializing all elements to the same value

C does not provide any shortcut mechanisms for initializing array elements. In C89 and C99 there is no way to specify a repeat count.

If it were desired to initially set all 500 values of sample data to 1, all 500 would have to be explicitly assigned. To solve this problem, you will want to initialize the array inside the program using a loop.

```c
int main (void)
{
	int array_values[10] = { 0, 1, 4, 9, 16 };
	int i;

	for (i=5; i<10; ++i)
		array_values[i] = i * i;

	for (i = 0; i < 10; ++i)
		printf ("array_values[%i] = %i\n", i, array_values[i]);

	return 0;
}
```

## Multidimensional arrays

### Overview

The types of arrays that you have been exposed to so far are all linear arrays, which is a single dimension array.

The C language allows arrays of any dimension to be defined.

Two dimensional arrays are the most common. You can visualize a two-dimensional array as a rectangular arrangement like rows and columns in a spreadsheet. One of the most natural applications for a two-dimensional array arises in the case of a matrix. Two-dimensional arrays are declared the same way that one-dimensional arrays are.

```c
// declaring the array matrix to be a two-dimensional array consisting of 4 rows and 5 columns, for a total of 20 elements
// note how each dimension is between its own pair of square brackets
int matrix[4][5];
```

### Initializing a 2D array

Two-dimensional arrays can be initialized in the same manner of a one-dimensional array.

When listing elements for initialization, the values are listed by row. The difference is that you put the initial values for each row between braces, {}, and then enclose all the rows between braces.

```c
int numbers[3][4] = {
	{ 10, 20, 30, 40 }, // Values for first row
	{ 15, 25, 35, 45 }, // Values for second row
	{ 47, 48, 49, 50 }  // Values for third row
};
```

Commas are required after each brace that closes off a row, except in the case of the final row. The use of the inner pairs of braces is actually optional, but, should be used for readability.

As with one-dimensional arrays, it is not required that the entire array be initialized.

```c
int matrix[4][5] = {
	{ 10, 5, -3 },
	{ 9, 0, 0 },
	{ 32, 20, 1 },
	{ 0, 0, 8 }
};
```

The code only initializes the first three elements of each row of the matrix to the indicated values. The remaining values are set to 0. In this case, the inner pairs of braces are required to force the correct initialization.

### Designated initializers

Subscripts can also be used in the initialization list, in a like manner to single-dimensional arrays.

```c
int matrix[4][3] = { [0][0] = 1, [1][1] = 5, [2][2] = 9 };
```

This initializes the three indicated elements of matrix to the specified values. The unspecified elements are set to zero by default. Each set of values that initializes the elements in a row is between braces. The entire initialization goes between another pair of braces. The values for a row are separated by commas. Each set of row values is separated from the next set by a comma.

### Other dimensions

Everything mentioned so far about two-dimensional arrays can be generalized to three-dimensional arrays and further. You can declare a three-dimensional array this way:

```c
int box[10][20][30];
```

You can visualize a one-dimensional array as a row of data; a two-dimensional array as a table of data, matrix, or a spreadsheet; a three-dimensional array as a stack of data tables.

Typically, you would use three nested loops to process a three-dimensional array, four nested loops to process a four-dimensional array, and so on.

#### Initializing an array of more than 2 dimensions

For arrays of three or more dimensions, the process of initialization is extended.A three-dimensional array will have three levels of nested braces, with the inner level containing sets of initializing values for a row.

```c
int numbers[2][3][4] = 
{
	{		// First block of 3 rows
		{ 10, 20, 30, 40 },
		{ 15, 25, 35, 45 },
		{ 47, 48, 49, 50 }
	}，
	{		// Second block of 3 rows
		{ 10, 20, 30, 40 },
		{ 15, 25, 35, 45 },
		{ 47, 48, 49, 50 }
	}
}；
```

#### Processing elements in an dimensional array

You need a nested loop to process all the elements in a multidimensional array. 

The level of nesting will be the number of array dimensions. Each loop iterates over one array dimension.

```c
int sum = 0;
for(int i=0; i<2; ++i)
{
	for(int j= 0 ;j <3 ; ++i)
	{
		for(int k = 0 ; k < 4; ++k)
		{
			sum += numbers[i][j][k];
		}
	}
}
```

## Variable length arrays

So far, all the sizes of an array have been specified using a number. The term variable in variable-length array does not mean that you can modify the length of the array after you create it, so a VLA(variable length arrays) keeps the same size after creation.

The variable length arrays allow you to specify the size of an array with a variable when creating an array.

C99 introduced variable-length arrays primarily to allow C to become a better language for numerical computing. VLAs make it easier to convert existing libraries of FORTRAN numerical calculation routines to C.

You can not initialize a VLA in its declaration.

Valid and invalid declarations of an array

```c
int n = 5;
int m= 8;
float a1[5];		// yes
float a2[5*2 + 1];		// yes
float a3[sizeof(int) + 1];		// yes
float a4[-4];		// no, size must be > o
float a5[0];		// no, size must be > o
float a6[2.5];		// no, size must be an integer
float a7[(int)2.5];		// yes, typecast float to int constant
float a8[n];		// not allowed before C99, VLA
float a9[m];		// not allowed before C99, VLA
```
