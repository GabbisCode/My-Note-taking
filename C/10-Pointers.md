# 10-Pointers

## Overview

### Indirection

Pointers are very similar to the concept of indirection that you employ in your everyday life.

Suppose you need to buy a new ink cartridge for your printer. All purchases are handled by the purchasing department. You call Joe in purchasing and ask him to order the new cartridge for you. Joe then calls the local supply store to order the cartridge. You are not ordering the cartridge directly from the supply store yourself (indirection).

In programming languages, indirection is the ability to reference something using a name, reference, or container, instead of the value itself. The most common form of indirection is the act of manipulating a value through its memory address.

A pointer provides an indirect means of accessing the value of a particular data item. It is a variable whose value is a memory address. Its value is the address of another location in memory that can contain a value.

Just as there are reasons why it makes sense to go through the purchasing department to order new cartridges (you don't have to know which particular store the cartridges are being ordered from). There are good reasons why it makes sense to use pointers in C.

Using pointers in your program is one of the most powerful tools available in the C language. Pointers are also one of the most confusing concepts of the C language. It is important you get this concept figured out in the beginning and maintain a clear idea of what is happening as you dig deeper.

The compiler must know the type of data stored in the variable to which it points.

You need to know how much memory is occupied or how to handle the contents of the memory to which it points. Every pointer will be associated with a specific variable type. It can be used only to point to variables of that type. Pointers of type "pointer to int" can point only to variables of type int; Pointers of type "pointer to float" can point only to variables of type float.

![](image/pointers01.png)

The value of &number is the address where number is located. This value is used to initialize pnumber in the second statement.

### Why use pointers?

Accessing data by means of only variables is very limiting. With pointers, you can access any location (you can treat any position of memory as a variable for example) and perform arithmetic with pointers.

Pointers in C make it easier to use arrays and strings.

Pointers allow you to refer to the same space in memory from multiple locations, which means that you can update memory in one location and the change can be seen from another location in your program. It can also save space by being able to share components in your data structures.

Pointers allow functions to modify data passed to them as variables. This is pass by reference - passing arguments to function in way they can be changed by function.

It can also be used to optimize a program to run faster or use less memory than it would otherwise.

Pointers allow us to get multiple values from the function. A function can return only one value but by passing arguments as pointers we can get more than one values from the pointer.

With pointers dynamic memory can be created according to the program use. We can save memory from static (compile time) declarations.

Pointers allow us to design and develop complex data structures like a stack, queue, or linked list.

Pointers provide direct memory access.

## Defining Pointers

### Declaring pointers

Pointers are not declared like normal variables

```c
pointer ptr; // not the way to declare a pointer/
```

It is not enough to say that a variable is a pointer. You also have to specify the kind of variable to which the pointer points. Different variable types take up different amounts of storage. Some pointer operations require knowledge of that storage size.

You declare a pointer to a variable of type int with:

```c
int *pnumber;
```

The type of the variable with the name pnumber is int*. It can store the address of any variable of type int.

```c
int * pi;             // pi is a pointer to an integer variable
char * pc;            // pc is a pointer to a character variable
float * pf, pg;       // pf, pg are pointers to float variables
```

The space between the * and the pointer name is optional. Programmers use the space in a declaration and omit it when dereferencing a variable.

The value of a pointer is an address, and it is represented internally as an unsigned integer on most systems. However, you shouldn't think of a pointer as an integer type. Things you can do with integers that you can not do with pointers, and vice versa. You can multiply one integer by another, but you can not multiply one pointer by another.

A pointer really is a new type, not an integer type. %p represents the format specifier for pointers.

The previous declarations creates the variable but does not initialize it. It's dangerous when pointers are not initialized. You should always initialize a pointer when you declare it.

### NULL Pointers

You can initialize a pointer so that it does not point to anything:

```c
int *number = NULL;
```

NULL is a constant that is defined in the standard library. It is the equivalent of zero for a pointer.

NULL is a value that is guaranteed not to point to any location in memory. What it means is that it implicitly prevents the accidental overwriting of memory by using a pointer that does not point to anything specific.

We need to add an #include directive for stddef.h to your source file, if we want to use the NULL..

### Address of operator

If you want to initialize your variable with the address of a variable you have already declared, use the address of operator, &.

```c
int number = 99;

int *pnumber = &number;
```

The initial value of number is the address of the variable number. The declaration of number must precede the declaration of the pointer that stores its address. Compiler must have already allocated space and thus an address for number to use it to initialize pnumber.

### Be careful

There is nothing special about the declaration of a pointer. You can declare regular variables and pointers in the same statement.

```c
double value, *pVal, fnum;  // only the second variable, pVal, is a pointer

int *p, q;      // declares a pointer, p of type int*, and a variable, q, that is of type int
```

It's a common mistake to think that both p and q are pointers.

Also, it is a good idea to use names beginning with p as pointer names.

## Accessing Pointers

### Accessing pointer values

You use the indirection operator, *, to access the value of the variable pointed to by a pointer. It also referred to as the dereference operator because you use it to "dereference" a pointer.

```c
int number = 15;
int *pointer = &number;
int result = 0;
```

The pointer variable contains the address of the variable number. You can use this in an expression to calculate a new value for result.

```c
result = *pointer + 5;
```

The expression *pointer will evaluate to the value stored at the address contained in the pointer. The value stored in number, 15, so result will be set to 15 + 5, which is 20.

The indirection operator, *, is also the symbol for multiplication, and it is used to specify pointer types. It depends on where the asterisk appears, the compiler will understand whether it should interpret it as an indirection operator, as a multiplication sign, or as part of a type specification. The context determines what it means in any instance.

```c
int main (void)
{
	int count = 10, X;
	int *int_pointer;

	int_pointer = &count;
	x= *int_pointer;

	printf ("count = %i, x = %i\n", count, x);

	return 0;
}
```

### Displaying a pointers value

To output the address of a variable, you use the output format specifier %p. It outputs a pointer value as a memory address in hexadecimal form.

```c
int number = 0;       // A variable of type int initialized to 0
int *pnumber = NULL;  // A pointer that can point to type int

number = 10;
pnumber = &number;
printf("pnumber's value: %p\n", pnumber);  // Output the value (an address)
```

Pointers occupy 8 bytes and the addresses have 16 hexadecimal digits. if a machine has a 64-bit operating system and my compiler supports 64-bit addresses. Some compilers only support 32-bit addressing, in which case addresses will be 32-bit addresses.

```c
printf("number's address: %p\n", &number);              // Output the address
printf("pnumber's address: %p\n", (void*)&pnumber);     // Output the address
```

Remember, a pointer itself has an address, just like any other variable. You use %p as the conversion specifier to display an address. You use the & (address of) operator to reference the address that the number variable occupies.

The cast to void* is to prevent a possible warning from the compiler. The %p specification expects the value to be some kind of pointer type, but the type of &pnumber is "pointer to pointer to int".

### Displaying the number of bytes a pointer is using

You use the sizeof operator to obtain the number of bytes a pointer occupies. On my machine this shows that a pointer occupies 8 bytes. A memory address on my machine is 64 bits.

You may get a compiler warning when using sizeof this way. size_t is an implementation-defined integer type. To prevent the warning, you could cast the argument to type int like this:

```c
printf("pnumber's size: %d bytes\n", (int)sizeof(pnumber));  // Output the size
```

```c
it main(void)
{
	int number = 0;        // A variable of type int initialized to 0
	int *pnumber = NULL;    // A pointer that can point to type int

	number = 10;
	printf("number's address: %p\n", &number);   // Output the address
	printf("number's value: %d\n\n", number);    // Output the value

	pnumber = &number;   // Store the address of number in pnumber

	printf("pnumber's address: %p\n", (void*)&pnumber);        // Output the address
	printf("pnumber's size: %zd bytes\n", sizeof(pnumber));    // Output the size
	printf("pnumber's value: %p\n", pnumber);	// Output the value (an address)
	printf("value pointed to: %d\n", *pnumber);	// Value at the address

	return O;
}
```



Overview

•C offers several basic operations you can perform on pointers

•you can assign an address to a pointer

•assigned value can be an array name, a variable preceded by address operator (&), or another second pointer.

•you can dereference a pointer

•the * operator gives the value stored in the pointed-to location

•you can take a pointer address

•the & operator tells you where the pointer itself is stored

•you can perform pointer arithmetic

•use the + operator to add an integer to a pointer or a pointer to an integer (integer is multiplied by the number

of bytes in the pointed-to type and added to the original address)

•Increment a pointer by one (useful in arrays when moving to the next element)

•use the - operator to subtract an integer from a pointer (integer is multiplied by the number of bytes in the

pointed-to type and subtracted from the original address

•decrementing a pointer by one (useful in arrays when going back to the previous element)

Overview

•you can find the difference between two pointers

•you do this for two pointers to elements that are in the same array to find out how far

apart the elements are

•you can use the relational operators to compare the values of two pointers

•pointers must be the same type

•remember, there are two forms of subtraction

•you can subtract one pointer from another to get an integer

•you can subtract an integer from a pointer and get a pointer

•be careful when incrementing or decrementing pointers and causing an array

"out of

bounds" error

•computer does not keep track of whether a pointer still points to an array element

pointers used in expressions

• the value referenced by a pointer can be used in an arithmetic expressions

• if a variable is defined to be of type "pointer to integer" then it is evaluated using the rules of

integer arithmetic

int number = o:

int *number = NULL;

number = 10;

pnumber=&number;

*number += 25;

// A variable of type int initialized to o

// A pointer that can point to type int

// Store the address of number in pnumber

• increments the value of the number variable by 25

• * indicates you are accessing the contents to which the variable called pnumber is pointing to

•if a pointer points to a variable x

•that pointer has been defined to be a pointer to the same data type as is x

•use of *pointer in an expression is identical to the use of x in the same expression

pointers in expressions (cont'd)

•a variable defined as a "pointer to int" can store the address of any variable of type int

int value = 999;

pnumber = &value:

*number += 25;

•the statement will operate with the new variable, value

•the new contents of value will be 1024

•a pointer can contain the address of any variable of the appropriate type

•you can use one pointer variable to change the values of many different variables

•as long as they are of a type compatible with the pointer type

Example

int main(void)

{

long num1 = oL;

long num2 = oL;

long *num = NULL;

pnum = &num1:

*pnum = zL;

++num2;

num2 +=

*pnum;

pnum = &num2;

++*pnum;

// Get address of num1

// Set num1 to 2

// Increment numa

// Add num1 to num2

// Get address of numz

// Increment num indirectly

printf("num1 = %ld num2 = %ld *num = %ld

*pnum + num2 = %ld\n",

num1, numz, *pnum, *pnum + num2);

return o;

1

when receiving Input

•when we have used scanf() to input values, we have used the & operator to obtain the

address of a variable

• on the variable that is to store the input (second argument)

•when you have a pointer that already contains an address, you can use the pointer name

as an argument for scanf()

int value = 0;

int *value = &value;

// Set pointer to refer to value

printf ("Input an integer: ");

scanf(" %d", pvalue);

// Read into value via the pointer

printf("You entered %d. \n", value);

// Output the value entered

Testing for NULL

•there is one rule you should burn into your memory

•do not dereference an uninitialized pointer

int * pt; // an uninitialized pointer

*pt = 5; // a terrible error

•second line means store the value 5 in the location to which pt points

•pt has a random value, there is no knowing where the 5 will be placed

•It might go somewhere harmless, it might overwrite data or code, or it might cause the program to crash

•creating a pointer only allocates memory to store the pointer itself

•it does not allocate memory to store data

•before you use a pointer, it should be assigned a memory location that has already been allocated

•assign the address of an existing variable to the pointer

• or you can use the malloc() function to allocate memory first

Testing for NULL (cont'd)

•we already know that when declaring a pointer that does not point to anything, we should initialize it to

NULL

int *value = NULL;

•NULL is a special symbol in C that represents the pointer equivalent to o with ordinary numbers

•the below also sets a pointer to null using o

int *pvalue = 0;

•because NULL is the equivalent of zero, if you want to test whether pvalue is NULL, you can do this:

•or you can do it explicitly by using == NULL

if(!pvalue)

•you want to check for NULL before you dereference a pointer

•often when pointers are passed to functions

Keep practicing

•stay with me

•pointers can be confusing :)

•you can work with addresses

•you can work with values

•you can work with pointers

•you can work with variables

•sometimes it is hard to work out what exactly is going on

•the best thing to understand this concept of a pointer is to keep writing short programs that use

pointers

•getting values using pointers

•changing values using pointers

•printing addresses, etc.

•this is the only way to really get confident about using pointers, practice!!!!

Overview

•when we use the const modifier on a variable or an array it tells the compiler that the contents of the variable/array

will not be changed by the program

•with pointers, we have to consider two things when using the const modifier

•whether the pointer will be changed

•whether the value that the pointer points to will be changed

•you can use the const keyword when you declare a pointer to indicate that the value pointed to must not be changed

long value = 9999L;

const long *value = &value;

/I defines a pointer to a constant

•you have declared the value pointed to by pvalue to be const

•the compiler will check for any statements that attempt to modify the value pointed to by pvalue and flag such

statements as an error

•the following statement will now result in an error message from the compiler

•*value = 8888L;

// Error - attempt to change const location

pointers to constants

•you can still modify value (you have only applied const to the pointer)

value = 7777L

•the value pointed to has changed, but you did not use the pointer to make the change

•the pointer itself is not constant, so you can still change what it points to:

long number = 8888L;

value = &number;

// OK - changing the address in pvalue

• will change the address stored in pvalue to point to number

• still cannot use the pointer to change the value that is stored

•you can change the address stored in the pointer as much as you like

•using the pointer to change the value pointed to is not allowed, even after you have changed the address

stored in the pointer.

constant pointers

•you might also want to ensure that the address stored in a pointer cannot be changed

•you can do this by using the const keyword in the declaration of the pointer

int count = 43;

int *const pcount = &count;

// Defines a constant pointer

•the above ensures that a pointer always points to the same thing

•indicates that the address stored must not be changed

•compiler will check that you do not inadvertently attempt to change what the pointer points to elsewhere in

your code

int item = 34;

pcount = &item;

// Error - attempt to change a constant pointer

•it is all about where you place the const keyword, either before the type or after the type

•const int

// value can not be changed

•int *const

// pointer address cannot change

constant pointers (cont'd)

•you can still change the value that pcount points to using pcount

*count = 345;

// OK - changes the value of count

•references the value stored in count through the pointer and changes its value to 345

•you can create a constant pointer that points to a value that is also constant:

int item = 25;

const int *const pitem = &item;

•the pitem is a constant pointer to a constant so everything is fixed

•cannot change the address stored in pitem

•cannot use pitem to modify what it points to

•you can still change the value of item directly

•if you wanted to make everything not change, you could specify item as const as well

Overview

•the type name void means absence of any type

• a pointer of type void* can contain the address of a data item of any type

• void* is often used as a parameter type or return value type with functions that deal with

data in a type-independent way

•any kind of pointer can be passed around as a value of type void*

•the void pointer does not know what type of object it is pointing to, so, it cannot be

dereferenced directly

•the void pointer must first be explicitly cast to another pointer type before it is

dereferenced

• the address of a variable of type int can be stored in a pointer variable of type void*

• when you want to access the integer value at the address stored in the void* pointer, you

must first cast the pointer to type int*

Example

int i= 10;

float {= 2.34;

char ch = 'k'.

void *vptr;

votr=&i;

printf("Value of i = %d\n", *(int *)vptr);

votr=&f:

printf("Value of f = %.2f\ n", *(float *)vptr);

votr=&ch:

printf("Value of ch = %c\n", *(char *)vptr);

Overview

• an array is a collection of objects of the same type that you can refer to using a single name

• a pointer is a variable that has as its value a memory address that can reference another variable or

constant of a given type

• you can use a pointer to hold the address of different variables at different times (must be same

type)

• arrays and pointers seem quite different, but, they are very closely related and can sometimes be used

interchangeably

• one of the most common uses of pointers in C is as pointers to arrays

•the main reasons for using pointers to arrays are ones of notational convenience and of program

efficiency

•pointers to arrays generally result in code that uses less memory and executes faster

Arrays and Pointers

• if you have an array of 100 integers

int values[100];

• you can define a pointer called valuesPtr, which can be used to access the integers contained in this array

int *valuesPtr;

• when you define a pointer that is used to point to the elements of an array, you do not designate the pointer as type "pointer to

array"

• you designate the pointer as pointing to the type of element that is contained in the array

• to set valuesPtr to point to the first element in the values array, you write

valuesPtr = values:

• the address operator is not used

• the C compiler treats the appearance of an array name without a subscript as a pointer to the array

• specifying values without a subscript has the effect of producing a pointer to the first element of values

Arrays and Pointers

•an equivalent way of producing a pointer to the start of values is to apply the address

operator to the first element of the array

valuesPtr=&values[0];

•So, you can use the above example or the one on the previous slide

valuesPtr = values;

Summary

•the two expressions ar[i] and *(ar+i) are equivalent in meaning

• both work if ar is the name of an array, and both work if ar is a pointer variable

•using an expression such as ar++ only works if ar is a pointer variable

pointer arithmetic

•the real power of using pointers to arrays comes into play when you want to sequence through the elements of

an array

*valuesPtr // can be used to access the first integer of the values array, that is, values[o]

•to reference values[3] through the valuesPtr variable, you can add 3 to valuesPtr and then apply the indirection

operator

*(valuesPtr + 3)

•the expression, *(valuesPtr + i) can be used to access the value contained in values[ i]

•to set values[10] to 27, you could do the following

values[10] = 27;

•or, using valuesPtr, you could

*(valuesPtr + 10) = 27;

pointer arithmetic (cont'd)

•to set valuesPtr to point to the second element of the values array, you can apply the

address operator to values[1] and assign the result to valuesptr

valuesPtr = &values 11:

•If valuesPtr points to values[ o], you can set it to point to values[1] by simply adding 1 to

the value of valuesPtr

valuesPtr += 1:

•this is a perfectly valid expression in C and can be used for pointers to any data type

pointer arithmetic (cont'd)

•the increment and decrement operators ++ and -- are particularly useful when dealing with

pointers

•using the increment operator on a pointer has the same effect as adding one to the pointer

•using the decrement operator has the same effect as subtracting one from the pointer

++valuesPtr;

•sets valuesPtr pointing to the next integer in the values array (values[1])

--textPtr;

•sets valuesPtr pointing to the previous integer in the values array, assuming that valuesPtr was

not pointing to the beginning of the values array

Example

int arraySum (int array[], const int n)

{

int sum = o, *ptr;

int * const arrayEnd = array + n;

for (ptr = array; ptr < arrayEnd; ++ptr )

sum +=

*ptr;

return sum;

7

void main (void)

{

int arraySum (int array[], const int n);

int values[10] = {3, 7, -9, 3, 6, -1, 7, 9, 1, -5 };

printf ("The sum is %i\n", arraySum (values, 10));

}

Example (cont'd)

•to pass an array to a function, you simply specify the name of the array

•to produce a pointer to an array, you need only specify the name of the array

• this implies that in the call to the array Sum() function, what was passed to the function was actually a pointer to the array

values

• explains why you are able to change the elements of an array from within a function

•so, you might wonder why the formal parameter inside the function is not declared to be a pointer

int arraySum (int *array, const int n)

•the above is perfectly valid

•pointers and arrays are intimately related in C

•this is why you can declare array to be of type "array of ints" inside the array Sum function or to be of type "pointer to int."

•if you are going to be using index numbers to reference the elements of an array that is passed to a function, declare the

corresponding formal parameter to be an array

•more correctly reflects the use of the array by the function

Example with pointer notation

int arraySum (int *array, const int n)

{

int sum= 0;

int * const arrayEnd = array + n;

for (; array < arrayEnd; ++array )

sum +=

*array;

return sum;

7

void main (void)

{

int arraySum (int

*array, const int n);

int values[10] = {3, 7, -9, 3, 6, -1, 7, 9, 1, -5 };

printf ("The sum is %i\n", arraySum (values, 10));

1

Summary

int urn[ 3];

int * ptr1, * ptra;

![](https://app.yinxiang.com/shard/s46/res/30302f3d-b8be-4d9f-8bc4-18a2a4c9319d/Image%2020220829%20141302.png?resizeSmall&width=813 "Attachment")

Summary (cont'd)

•functions that process arrays actually use pointers as arguments

•you have a choice between array notation and pointer notation for writing array.

processing functions

•using array notation makes it more obvious that the function is working with arrays

•array notation has a more familiar look to programmers versed in FORTRAN, Pascal,

Modula-2, or BASIC

•other programmers might be more accustomed to working with pointers and might find

the pointer notation more natural

•closer to machine language and, with some compilers, leads to more efficient code

Example

This program demonstrates the effect of adding an integer value to a pointer.

#include <stdio.h>

#include <string.h>

int main(void)

char multiple[1 =

"a string";

char *p = multiple;

for(int i = o; i < strnlen(multiple, sizeof(multiple)) ; ++i)

printf ("multiple[%d] = %C *(p+%d) = %c &multiple[%d] = %p p+%d = %p\n"',

i, multiple[i], i, *(p+i), i, &multiple[i], i, p+i);

return o;

Another Example

#include <stdio.h>

int main(void)

{

long multiple[] = {154, 25L, 35L, 45L};

long

*p = multiple:

for(int i = o ; i < sizeof(multiple)/sizeof(multiple[o]) ; ++i)

printf("address p+%d (&multiple[%d]): %llu

i, i, (unsigned long long)(p+i), i, *(p+i));

*(p+%d) value: %d\n".

printf("\n Type long occupies: %d bytes\n", (int)sizeof(long));

return O:

Overview

•we now know how arrays relate to pointers and the concept of pointer arithmetic

•these concepts can be very useful when applied to character arrays (strings)

•one of the most common applications of using a pointer to an array is as a pointer to a character

string

•the reasons are one of notational convenience and efficiency

•using a variable of type pointer to char to reference a string gives you a lot of flexibility

•lets look at an example that uses an array to copy a string

Example (array parameter vs char * parameter)

void copyString (char to[], char from[l)

{

int i

for (i =0; from[i] != '10'; ++i)

toll = fromi;

to[i] = 10';

void copyString (char *to, char

*from)

{

for;

*from != '10'; ++from, ++to)

*to = *from;

*to = '10':

char arrays as pointers

•if you have an array of characters called text, you could similarly define a pointer to be used to

point to elements in text

char *textPtr:

•if textPtr is set pointing to the beginning of an array of chars called text

++textPtr:

•the above sets textPtr pointing to the next character in text, which is text[1]

--textPtr;

•the above sets textPtr pointing to the previous character in text, assuming that textPtr was not

pointing to the beginning of text prior to the execution of this statement

Example optimized

void copyString (char *to, char *from)

{

while (*from ) // the null character is equal to the value O, so will jump out then

*to++ = *from+t:

*to = 10'

int main (void)

{

char string1[] = "A string to be copied.";

char string2[50];

copyString (string2, string1);

printf ("%s\n", string2);

Requirements

• In this challenge, you are going to write a program that tests your understanding of pointer

arithmetic and the const modifier

•write a function that calculates the length of a string

•the function should take as a parameter a const char pointer

•the function can only determine the length of the string using pointer arithmetic

•incrementation operator (++pointer) to get to the end of the string

•you are required to use a while loop using the value of the pointer to exit

•the function should subtract two pointers (one pointing to the end of the string and one

pointing to the beginning of the string)

•the function should return an int that is the length of the string passed into the function

pass by value

•there are a few different ways you can pass data to a function

•pass by value

•pass by reference

•pass by value is when a function copies the actual value of an argument into the formal parameter of

the function

•changes made to the parameter inside the function have no effect on the argument

•C programming uses call by value to pass arguments

•means the code within a function cannot alter the arguments used to call the function

•there are no changes in the values, though they had been changed inside the function

Example, pass by value

/* function definition to swap the values */

void swap(int x, int y) {

int temp;

temp = x; /* save the value of x */

X = Y;

/* put y into x */

y = temp; /* put temp into y */

return;

}

Example (cont'd)

int main () {

/* local variable definition */

int a = 100;

int b = 200;

printf("Before swap, value of a : %dn", a );

printf("Before swap, value of b : %din", b );

/* calling a function to swap the values */

swap(a, b);

printf("After swap, value of a : %din", a );

printf("After swap, value of b : %din", b );

return O;

Passing data using copies of pointers

•pointers and functions get along quite well together

•you can pass a pointer as an argument to a function and you can also have a function return a

pointer as its result

•pass by reference copies the address of an argument into the formal parameter

•the address is used to access the actual argument used in the call

•means the changes made to the parameter affect the passed argument

•to pass a value by reference, argument pointers are passed to the functions just like any other

value

•you need to declare the function parameters as pointer types

•changes inside the function are reflected outside the function as well

•unlike call by value where the changes do not reflect outside the function

Example using pointers to pass data (cont'd)

int main () {

/* local variable definition */

int a = 100;

int b = 200;

printf("Before swap, value of a : %dIn",

, a);

printf("Before swap, value of b : %dIn", b );

swap(&a, &b);

printf("After swap, value of a : %dln", a );

printf("After swap, value of b : %din", b );

return O:

Summary of syntax

•you can communicate two kinds of information about a variable to a function

function1(x);

•you transmit the value of x and the function must be declared with the same type as x

int function 1 (int num)

function2(&x);

• you transmit the address of x and requires the function definition to include a pointer to the correct

type

int function2(int * ptr)

cost pointer parameters

• you can qualify a function parameter using the const keyword

• indicates that the function will treat the argument that is passed for this parameter as a constant

• only useful when the parameter is a pointer

• you apply the const keyword to a parameter that is a pointer to specify that a function will not change the value to which the argument points

bool SendMessage(const char* pmessage)

I Code to send the message

return true;

• the type of the parameter, pmessage, is a pointer to a const char.

• it is the char value that's const, not its address.

• you could specify the pointer itself as const too, but this makes little sense because the address is passed by value

• you cannot change the original pointer in the calling function

• the compiler knows that an argument that is a pointer to constant data will be safe

• If you pass a pointer to constant data as the argument for a parameter then the parameter must be a use the above

returning pointers from a function

•returning a pointer from a function is a particularly powerful capability

•it provides a way for you to return not just a single value, but a whole set of values

•you would have to declare a function returning a pointer

int * myFunction0) {

•be careful though, there are specific hazards related to returning a pointer

•use local variables to avoid interfering with the variable that the argument points to

Requirements

• In this challenge, you are going to write a program that tests your understanding of pass by

reference

•write a function that squares a number by itself

•the function should define as a parameter an it pointer

Overview

•whenever you define a variable in C, the compiler automatically allocates the correct amount of

storage for you based on the data type

•it is frequently desirable to be able to dynamically allocate storage while a program is running

•if you have a program that is designed to read in a set of data from a file into an array in memory, you

have three choices

•define the array to contain the maximum number of possible elements at compile time

•use a variable-length array to dimension the size of the array at runtime

• allocate the array dynamically using one of C's memory allocation routines

Dynamic memory allocation

• with the first approach, you have to define your array to contain the maximum number of

elements that would be read into the array

Int dataArray [10001;

•the data file cannot contain more that 1000 elements, if it does, your program will not work

•If it is larger that 1000 you must go back to the program, change the size to be larger and

recompile it

•no matter what value you select, you always have the chance of running into the same

problem again in the future

•using the dynamic memory allocation functions, you can get storage as you need it

•this approach enables you to allocate memory as the program is executing

Dynamic memory allocation

• dynamic memory allocation depends on the concept of a pointer and provides a strong incentive

to use pointers in your code

• dynamic memory allocation allows memory for storing data to be allocated dynamically when your

program executes

•allocating memory dynamically is possible only because you have pointers available

•the majority of production programs will use dynamic memory allocation

•allocating data dynamically allows you to create pointers at runtime that are just large enough to

hold the amount of data you require for the task

Heap vs. Stack

• dynamic memory allocation reserves space in a memory area called the heap

•the stack is another place where memory is allocated

•function arguments and local variables in a function are stored here

•when the execution of a function ends, the space allocated to store arguments and local

variables is freed

•the memory in the heap is different in that it is controlled by you

•when you allocate memory on the heap, it is up to you to keep track of when the memory you

have allocated is no longer required

•you must free the space you have allocated to allow it to be reused

malloc

• the simplest standard library function that allocates memory at runtime is called malloc()

• need to include the stdlib.h header file

• you specify the number of bytes of memory that you want allocated as the argument

• returns the address of the first byte of memory that it allocated

• because you get an address returned, a pointer is the only place to put it

int *Number = (int*)malloc(100);

• in the above, you have requested 100 bytes of memory and assigned the address of this memory block to pNumber

• Number will point to the first int location at the beginning of the 100 bytes that were allocated.

• can hold 25 int values on my computer, because they require 4 bytes each

• assumes that type int requires 4 bytes

• it would be better to remove the assumption that ints are 4 bytes

int *Number = (int*)malloc(25*sizeof(int));

• the argument to malloc() above is clearly indicating that sufficient bytes for accommodating 25 values of type int should be made available

• also notice the cast (int*), which converts the address returned by the function to the type pointer to int

• malloc returns a pointer of type pointer to void, so you have to cast

malloc (cont'd)

• you can request any number of bytes

• if the memory that you requested can not be allocated for any reason

• malloc() returns a pointer with the value NULL

• It is always a good idea to check any dynamic memory request immediately using an if statement to make

sure the memory is actually there before you try to use it

int *Number = (int*)malloc(25*sizeof(int));

if(!pNumber)

{

Il code to deal with memory allocation failure

• you can at least display a message and terminate the program

• much better than allowing the program to continue and crash when it uses a NULL address to store somethir

releasing memory

•when you allocate memory dynamically, you should always release the memory when it is no

longer required

•memory that you allocate on the heap will be automatically released when your program ends

• better to explicitly release the memory when you are done with it, even if it's just before you exit

from the program

• a memory leak occurs when you allocate some memory dynamically and you do not retain the

reference to it, so you are unable to release the memory

•often occurs within a loop

•because you do not release the memory when it is no longer required, your program consumes

more and more of the available memory on each loop iteration and eventually may occupy it all

•to free memory that you have allocated dynamically, you must still have access to the address

that references the block of memory

releasing memory (cont'd)

•to release the memory for a block of dynamically allocated memory whose address you have

stored in a pointer

free(pNumber);

Number = NULL;

•the free() function has a formal parameter of type void*

•you can pass a pointer of any type as the argument

• as long as Number contains the address that was returned when the memory was allocated, the

entire block of memory will be freed for further use

calloc

•the calloc() function offers a couple of advantages over malloc()

•it allocates memory as a number of elements of a given size

•it initializes the memory that is allocated so that all bytes are zero

•calloc() function requires two argument values

• number of data items for which space is required

•size of each data item

•is declared in the stdlib.h header

int *Number = (int*) calloc(75, sizeof(int));

•the return value will be NULL if it was not possible to allocate the memory requested

• very similar to using malloc(), but the big plus is that you know the memory area will be initialized

to 0

realloc

•the realloc() function enables you to reuse or extend memory that you previously allocated using

malloc() or calloc()

• expects two argument values

• a pointer containing an address that was previously returned by a call to malloc(), calloc()

•the size in bytes of the new memory that you want allocated

•allocates the amount of memory you specify by the second argument

transfers the contents of the previously allocated memory referenced by the pointer that you

supply as the first argument to the newly allocated memory

•returns a void* pointer to the new memory or NULL if the operation fails for some reason

•the most important feature of this operation is that realloc() preserves the contents of the original

memory area

Example

int main () {

char *str:

/* Initial memory allocation */

str = (char *) malloc(15);

strcpy(str, "jason");

printf(" String = %s, Address = %uln", str, str);

/* Reallocating memory */

str = (char *) realloc(str, 25);

strcat(str,

".com");

printf("String = %S, Address = %uln", str, str);

free(str);

return(0);

quidelines

•avoid allocating lots of small amounts of memory

•allocating memory on the heap carries some overhead with it

•allocating many small blocks of memory will carry much more overhead than allocating fewer

larger blocks

•only hang on to the memory as long as you need it

•as soon as you are finished with a block of memory on the heap, release the memory

•always ensure that you provide for releasing memory that you have allocated

•decide where in your code you will release the memory when you write the code that allocates it

•make sure you do not inadvertently overwrite the address of memory you have allocated on the

heap before you have released it

•will cause a memory leak

•be especially careful when allocating memory within a loop

Requirements

•In this challenge, you are going to write a program that tests your understanding of dynamic

memory allocation

•write a program that allows a user to input a text string. The program will print the text that

was inputted. The program will utilize dynamic memory allocation.

•the user can enter the limit of the string they are entering

•you can use this limit when invoking malloc

•the program should create a char pointer only, no character arrays

•be sure to release the memory that was allocated
