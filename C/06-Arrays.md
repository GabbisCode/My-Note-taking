for example (flexibility)
unsigned long long sum = OLL;
unsigned int count = 0;
I/ Stores the sum of the integers
I1 The number of integers to be summed
I Read the number of integers to be summed
printf(" nEnter the number of integers you want to sum: ");
scanf(" %u", &count);
I/ Sum integers from 1 to count
for(unsigned int i = 1 ; i <= count; ++i)
Sum += I:
// OR
for(unsigned int i = 1 ; i <= count; sum += i++);
printf("In Total of the first %u numbers is %lluln", count, sum);

Infinite loop
•you have no obligation to put any parameters in the for loop statement
for(;: )
{
/* statements */
•the condition for continuing the loop is absent, the loop will continue
indefinitely
•sometimes useful for monitoring data or listening for connections

While loop
•the mechanism for repeating a set of statements allows execution to continue for as long as a
specified logical expression evaluates to true
While this condition is true
Keep on doing this
OR
While you are hungry
Eat sandwiches
• The general syntax for the while loop is as follows (one statement in body):
while( expression)
statement1:
or
while (expression)
{
statement1:
statement2:

While loop (cont'd)
•the condition for continuation of the while loop is tested at the start (top of the loop)
•pre-test loop
•if expression starts out false, none of the loop statements will be executed
•If you answer the first question "No, I'm not hungry,'
" then you don't get to eat any sandwiches at
all, and you move straight to the coffee
•if the loop condition starts out as true, the loop body must contain a mechanism for changing this if
the loop is to end

Counter Controlled While loop Example
I/ Program to introduce the while statement
#include <stdio.h>
int main (void)
{
int count = 1;
while ( count <= 5 ) {
printf ("%i\n", count);
++count;
}
return O;
}

Logic controlled while loop example
int num = 0;
scanf("%d", &num);
while (num != -1)
{
/* loop actions */
scanf("%d", &num);

do-while loop
•In the while loop, the body is executed while the condition is true
•the do-while loop is a loop where the body is executed for the first time unconditionally
•always guaranteed to execute at least once
•condition is at the bottom (post-test loop)
• After initial execution, the body is only executed while the condition is true
do
statement
while (expression);
do
{
prompt for password
read user input
} while (input not equal to password);

do-while loop example
do
scanf("%d", &number);
while (number != 20);
Or counter controlled
int number = 4;
do
{
printf("lnNumber = %d", number);
number++:
while (number < 4);

which loop to use??
• First, decide whether you need an pre or post test loop
• usually will be a pre test loop (for or while), a bit better option in most cases
• it is better to look before you leap (or loop) than after
• easier to read if the loop test is found at the beginning of the loop
• in many uses, it is important that the loop be skipped entirely if the test is not initially
met
• So, should you use a for or a while
• a matter of taste, because what you can do with one, you can do with the other
• To make a for loop like a while, you can omit the first and third expressions
for (;test; )
is the same as
while (test)

do-while loop example
•To make a while like a for, preface it with an initialization and include update
statements
initialize;
while (test)
{
body;
update;
}
is the same as
for (initialize; test; update)
body;

do-while loop example
• a for loop is appropriate when the loop involves initializing and updating a
variable
•a while loop is better when the conditions are otherwise
•I usually use the while loop for logic controlled loops and the for loop for
counter controlled loops
while (scanf("%)", &num) == 1)
for (count = 1; count <= 100; count++)

Nested Loops
• Sometimes you may want to place one loop inside another
• You might want to count the number of occupants in each house on a street
•step from house to house, and for each house you count the number of occupants
•Going through all the houses could be an outer loop, and for each iteration of the outer loop you
would have an inner loop that counts the occupants

Example
for(int i = 1 ; i <= count; ++i)
{
sum = 0;
// Initialize sum for the inner loop
// Calculate sum of integers from 1 to i
for(int j= 1;j<= i; ++j)
sum +=j;
printf("'\n%d\t%d", i, sum);
// Output sum of 1 to i

Another Example (while inside a for)
for(int i = 1 ; i <= count; ++i)
{
sum = 1;
=1:
printf("\n1");
I/ Initialize sum for the inner loop
I/ Initialize integer to be added
I/ Calculate sum of integers from 1 to i
while(j<1)
{
sum += ++i;
printf(" + %d", i);
I/ Output + - on the same line
}
printf(" = %d", sum);
// Output = sum

Continue statements
•Sometimes a situation arises where you do not want to end a loop, but you want to skip the
current iteration
• The continue statement in the body of a loop does this
• All you need to do is use the keyword "continue;" in the body of the loop
• An advantage of using continue is that it can sometimes eliminate nesting or additional blocks of
code
•can enhance readability when the statements are long or are deeply nested already

Continue Example
enum Day { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};
for(enum Day day = Monday; day
<= Sunday ; ++day)
{
if(day == Wednesday)
continue;
printf("It's not Wednesday!In");
/* Do something useful with day */

Break statement
•normally, after the body of a loop has been entered, a program executes all the statements in the
body before doing the next loop test
•we learned how continue works
•another statement named break alters this behavior
•the break statement causes the program to immediately exit from the loop it is executing
• statements in the loop are skipped, and execution of the loop is terminated
•if the break statement is inside nested loops, it affects only the innermost loop containing it
•use the keyword "break;"
•break is often used to leave a loop when there are two separate reasons to leave
•break is also used in switch statements

Break example
while (p > 0)
{
printf("%d\n", p);
scanf("%d", &q);
while( q > 0)
{
printf("%dIn",p*q);
if (q > 100)
break:
scanf("%d", &q);
// break from inner loop
}
if (q > 100)
break;
scanf("%d", &p);
// break from outer l00p
}

![1660052585950](image/Array.jfif)

Array out of bounds
•if you use an expression or a variable for an index value that is outside the range for the array,
your program may crash or the array can contain garbage data
•referred to as an out of bounds error
•the compiler cannot check for out of bounds errors so your program will still compile
•very important to ensure that your array indexes are always within bounds

Assigning values to an Array
• a value can be stored in an element of an array simply by specifying the array element on the left
side of an equal sign
grades[100] = 95;
•the value 95 is stored in element number 100 of the grades array
•can also use variables to assign values to an array

Example of using an array
int main(void)
int grades[10];
int count = 10;
long sum = 0;
float average = 0.0f;
I Array storing 10 values
// Number of values to be read
I/ Sum of the numbers
I Average of the numbers
printf("\nEnter the 10 grades:ln");
Il Prompt for the input
I Read the ten numbers to be averaged
for(int i = 0 ; i < count; ++i)
{
printf("%2u> "i + 1);
scan("%d", &grades[i]);
sum += grades[i];
I/ Read a grade
I/ Add it to sum
average = (float)sum/count:
I/ average
printf("InAverage of the ten grades entered is:
%.2fn", average);
return O:

Initializing an array
you will want to assign initial values for the elements of your array most of the time
defining initial values for array elements makes it easier to detect when things go wrong
just as you can assign initial values to variables when they are declared, you can also assign initial values to an array's
elements
to initialize an array's values, simply provide the values in a list
values in the list are separated by commas and the entire list is enclosed in a pair of braces
int counters[5] = {0, 0, 0, 0, 0 J;
declares an array called counters to contain five integer values and initializes each of these elements to zero
int integers[5] = { 0, 1, 2, 3, 4};
declares an array named integers and sets the value of integers[0] to 0, integers[1] to 1, integers[2] to 2, and so on

Initializing an array (cont'd)
It is not necessary to completely initialize an entire array
If fewer initial values are specified, only an equal number of elements are
initialized
remaining values in the array are set to zero
float sample_data[500] = { 100.0, 300.0, 500.5 f;
initializes the first three values of sample_data to 100.0, 300.0, and 500.5, and
sets the remaining 497 elements to zero

Designated Initializers
C99 added a feature called designated initializers
allows you to pick and choose which elements are initialized
by enclosing an element number in a pair of brackets, specific array elements
can be initialized in any order
float sample_ data[500= {[21=500.5, [1] = 300.0, [O] = 100.0};
initializes the sample_data array to 100.0, 300.0, and 500.5 for the first three
values
int arr[6] = {151 = 212 // initialize arr[5] to 212

Example of traditional initialization
#define MONTHS 12
int main(void)
{
int days[MONTHS] = {31,28,31,30,31,30,31,31,30,31,30,31}
int index;
for (index = 0; index < MONTHS; index++)
printf("Month %d has %2d days. In", index +1, days[index]);
return O:
}

Example using designated initializers
#include <stdio.h>
#define MONTHS 12
int main(void)
{
int days[MONTHS] = {31,28, [4] = 31,30,31, [1] = 29};
int i:
for (i = 0; i < MONTHS; it+)
printf("%2d %d\n", i + 1, days[i]);
return O:
}

Repeating an initial value
C does not provide any shortcut mechanisms for initializing array elements
no way to specify a repeat count
if it were desired to initially set all 500 values of sample data to 1, all 500
would have to be explicitly assigned
to solve this problem, you will want to initialize the array inside the program
using a loop

Initializing all elements to the same value
int main (void)
{
int array_values[10] = {0, 1, 4, 9, 16 };
int i:
for (i=5; i<10; ++i)
array_values[i] = i* i:
for (i = 0; i < 10; ++i)
printf ("array_values[%i] = %i\n", i, array_values[i]);
return 0;

• the types of arrays that you have been exposed to so far are all linear arrays
• a single dimension
• the C language allows arrays of any dimension to be defined
• two dimensional arrays are the most common
• you can visualize a two-dimensional array as a rectangular arrangement like rows and columns in a spreadsheet
• one of the most natural applications for a two-dimensional array arises in the case of a matrix
•two-dimensional arrays are declared the same way that one-dimensional arrays are
it matrix[4][5];
• declares the array matrix to be a two-dimensional array consisting of 4 rows and 5 columns, for a total of 20 elements
• note how each dimension is between its own pair of square brackets

Initializing a two dimensional array
•two-dimensional arrays can be initialized in the same manner of a one-dimensional array
• When listing elements for initialization, the values are listed by row
•the difference is that you put the initial values for each row between braces, 1, and then enclose all the
rows between braces
int numbers[3][4] = {
{ 10, 20, 30, 40 },
{15, 25, 35, 45 }.
{47, 48, 49, 50 }
}:
// Values for first row
// Values for second row
// Values for third row
•commas are required after each brace that closes off a row, except in the case of the final row
•the use of the inner pairs of braces is actually optional, but, should be used for readability

Initializing a 2D array
•as with one-dimensional arrays, it is not required that the entire array be initialized
int matrix[4][5] = {
{10, 5, -3},
{ 9, 0, 0}
{32, 20, 1}
{0, 0, 8}
};
•only initializes the first three elements of each row of the matrix to the indicated values
•remaining values are set to 0.
•in this case, the inner pairs of braces are required to force the correct initialization

Designated initializers
•subscripts can also be used in the initialization list, in a like manner to single-dimensional arrays
int matrix[4](3] = ( [O][0] = 1, (1][1] = 5, [2](2] = 9 };
•initializes the three indicated elements of matrix to the specified values
•unspecified elements are set to zero by default
•each set of values that initializes the elements in a row is between braces
•the entire initialization goes between another pair of braces
•the values for a row are separated by commas
•each set of row values is separated from the next set by a comma

Other dimensions
•everything mentioned so far about two-dimensional arrays can be generalized to three-dimensional
arrays and further
•you can declare a three-dimensional array this way:
int box[10][201 301;
•you can visualize a one-dimensional array as a row of data
•you can visualize a two-dimensional array as a table of data, matrix, or a spreadsheet
• you can visualize a three-dimensional array as a stack of data tables
•typically, you would use three nested loops to process a three-dimensional array, four nested loops to
process a four-dimensional array, and so on

Initializing an array of more than 2 dimensions
• for arrays of three or more dimensions, the process of initialization is extended
• a three-dimensional array will have three levels of nested braces, with the inner level containing sets of initializing
values for a row
int numbers[2][3][4] = {
{
// First block of 3 rows
{10, 20, 30, 40 J,
{15, 25, 35, 45 },
{47, 48, 49, 50 }
了，
{
// Second block of 3 rows
{ 10, 20, 30, 40 },
{15, 25, 35, 45 },
{47, 48, 49, 50 }
}；

Processing elements in a n dimensional array
• you need a nested loop to process all the elements in a multidimensional array
•the level of nesting will be the number of array dimensions
•each loop iterates over one array dimension
int sum = 0:
for(inti=0;i<2;++i)
{
for(int j= 0 ;j <3 ; ++i)
{
{
for(int k = 0 ; k < 4; ++k)
sum += numbers ( ok;

Variable length arrays
•so far, all the sizes of an array have been specified using a number
•the term variable in variable-length array does not mean that you can modify the length of the
array after you create it
•a VLA keeps the same size after creation
•variable length arrays allow you to specify the size of an array with a variable when creating an
array
•Cg introduced variable-length arrays primarily to allow C to become a better language for
numerical computing
•VAs make it easier to convert existing libraries of FORTRAN numerical calculation routines to
C
•you can not initialize a VLA in its declaration

Valid and invalid declarations of an array
int n = 5;
int m= 8;
Not a1[5];
// yes
Noat a2[5*2 + 11;
// yes
float a3[sizeof(int) + 11; // yes
float a4[-41;
// no, size must be > o
noat a5[0];
// no, size must be > o
float a6[2.51;
// no, size must be an integer
float a7[ (int)2.5];
// yes, typecast float to int constant
float a8[n];
// not allowed before C9g, VLA
float ag[m];
// not allowed before C99, VLA
