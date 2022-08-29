# 11-Structures

Overview

• structures in C provide another tool for grouping elements together

• a powerful concept that you will use in many C programs that you develop

•suppose you want to store a date inside a program

•we could create variables for month, day, and year to store the date

int month = 9, day = 25, year = 2015;

•suppose your program also needs to store the date of purchase of a particular item

•you must keep track of three separate variables for each date that you use in the program

•these variables are logically related and should be grouped together

•it would be much better if you could somehow group these sets of three variables together

•this is precisely what the structure in C allows you to do

Creating a structure

• a structure declaration describes how a structure is put together

• what elements are inside the structure

• the struct keyword enables you to define a collection of variables of various types called a structure that

you can treat as a single unit

struct date

{

int month;

int day;

int year;

3;

•the above statement defines what a date structure looks like to the C compiler

•there is no memory allocation for this declaration

• the variable names within the date structure, month, day, and year, are called members or fields

• members of the structure appear between the braces that follow the struct tag name date

Using a structure

•the definition of date defines a new type in the language

•variables can now be declared to be of type struct date

struct date today;

•you can now declare more variables of type struct date

struct date purchaseDate;

•the above statement declares a variable to be of type struct date

•memory is now allocated for the variables above

•memory is allocated for three integer values for each variable

•be certain you understand the difference between defining a structure and declaring

variables of the particular structure type

Accessing members in a struct

• now that you know how to define a structure and declare structure variables, you need to be able to refer to the members of a

structure

• a structure variable name is not a pointer

• you need a special syntax to access the members

• you refer to a member of a structure by writing the variable name followed by a period, followed by the member variable name

• the period between the structure variable name and the member name is called the member selection operator

• there are no spaces permitted between the variable name, the period, and the member name

• to set the value of the day in the variable today to 25, you write

today.day = 25;

today.year = 2015;

• to test the value of month to see if it is equal to 12

if (today.month == 12 )

nextMonth = 1;

Example

struct date

{

int month;

int day;

int year;

struct date today;

today.month = 9;

today.day = 25;

today.year = 2015;

printf ("Today's date is %/%i/%.2i.In", today.month, today.day, today.year % 100);

Structures in expressions

•when it comes to the evaluation of expressions, structure members follow the same rules as

ordinary variables do

•division of an integer structure member by another integer is performed as an integer division

century = today.year / 100 + 1;

Defining the structure and variable at the same time

• you do have some flexibility in defining a structure

•it is valid to declare a variable to be of a particular structure type at the same time that the structure is

defined

•include the variable name (or names) before the terminating semicolon of the structure definition

• you can also assign initial values to the variables in the normal fashion

struct date

int month;

int day;

int year;

I today;

• in the above, an instance of the structure, called today, is declared at the same time that the structure is

defined

•today is a variable of type date

Unnamed Structures

•you also do not have to give a structure a tag name

•If all of the variables of a particular structure type are defined when the structure is defined,

the structure name can be omitted

struct

{

int day;

int year;

int month:

I today;

I Structure declaration and...

// …structure variable declaration combined

•a disadvantage of the above is that you can no longer define further instances of the structure in

another statement

• all the variables of this structure type that you want in your program must be defined in the one

statement

Initializing Structures

•initializing structures is similar to initializing arrays

•the elements are listed inside a pair of braces, with each element separated by a comma

•the initial values listed inside the curly braces must be constant expressions

struct date today = { 7, 2, 2015 };

•just like an array initialization, fewer values might be listed than are contained in the structure

struct date date1 = { 12, 10 };

•sets date1. month to 12 and date1 .day to 10 but gives no initial value to date.year

Initializing structures

•you can also specify the member names in the initialization list

•enables you to initialize the members in any order, or to only initialize specified members

member = value

struct date date1 = { .month = 12, day = 10 };

•set just the year member of the date structure variable today to 2015

struct date today = {.year = 2015 };

Assignment with compound literals

• you can assign one or more values to a structure in a single statement using what is known as compound

literals

today = (struct date) { 9, 25, 2015 );

• this statement can appear anywhere in the program

• it is not a declaration statement

• the type cast operator is used to tell the compiler the type of the expression

• the list of values follows the cast and are to be assigned to the members of the structure, in order

• listed in the same way as if you were initializing a structure variable

• you can also specify values using the member notation

today = (struct date) { month = 9, .day = 25, .year = 2015 };

• the advantage of using this approach is that the arguments can appear in any order

Arrays of structures

• you have seen how useful a structure is in enabling you to logically group related elements together

• for example, it is only necessary to keep track of one variable, instead of three, for each date that is used

by the program

• to handle 10 different dates in a program, you only have to keep track of 10 different variables, instead of

30

• a better method for handling the 10 different dates involves the combination of two powerful features of the

C programming language

• structures and arrays.

• it is perfectly valid to define an array of structures

• the concept of an array of structures is a very powerful and important one in C

• declaring an array of structures is like declaring any other kind of array

struct date myDates[10];

• defines an array called myDates, which consists of 10 elements

• each element inside the array is defined to be of type struct date

Array of structures

•to identify members of an array of structures, you apply the same rule used for

individual structures

•follow the structure name with the dot operator and then with the member name

•referencing a particular structure element inside the array is quite natural

•to set the second date inside the myDates array to August 8, 1986

myDates[1].month = 8:

myDates[1].day

=8;

myDates[1].year = 1986;

Initializing an array of structures

• initialization of arrays containing structures is similar to initialization of multidimensional arrays

struct date myDates[5] = { {12, 10, 1975}, {12, 30, 1980}, {11, 15, 2005} };

• sets the first three dates in the array myDate to 12/10/1975, 12/30/1980, and 11/15/2005

• the inner pairs of braces are optional

struct date myDates[5] = { 12, 10, 1975, 12, 30, 1980, 11, 15, 2005 };

• initializes just the third element of the array to the specified value

struct date myDates[5] = { [2] = {12, 10, 1975} };

• sets just the month and day of the second element of the myDates array to 12 and 30

struct date myDates[5] = {[1]. month = 12, [1].day = 30 };

Structures containing arrays

•it is also possible to define structures that contain arrays as members

•most common use is to set up an array of characters inside a structure

• suppose you want to define a structure called month that contains as its members the

number of days in the month as well as a three-character abbreviation for the month name

struct month

{

int numberOfDays;

char name[3];

};

•this sets up a month structure that contains an integer member called numberOfDays and a

character member called name

•member name is actually an array of three characters

Structures containing arrays

• you can now define a variable to be of type struct month and set the proper fields inside Month for January

struct month aMonth;

aMonth.numberOfDays=31;

aMonth.name[0]=

aMonth.name[1] = 'a';

aMonth.name[2] = 'n';

• you can also initialize this variable to the same values

struct month aMonth = {31, {'J', 'a', 'n' }};

• you can set up 12-month structures inside an array to represent each month of the year

struct month months[12];

Nested Structures

•C allows you to define a structure that itself contains other structures as one or more of its members

• you have seen how it is possible to logically group the month, day, and year into a structure called

date

• how about grouping the hours, minutes, and seconds into a structure called time

struct time

int hours;

int minutes;

int seconds;

};

• in some applications, you might have the need to group both a date and a time together

• you might need to set up a list of events that are to occur at a particular date and time

Nested Structures

• you want to have a convenient way to associate both the date and the time together

• define a new structure, called, for example, dateAndTime, which contains as its members two elements

• date and time

struct dateAndTime

{

struct date sdate;

struct time stime;

};

• the first member of this structure is of type struct date and is called sdate

• the second member of the dateAnd Time structure is of type struct time and is called stime

• variables can now be defined to be of type struct dateAndTime

struct dateAndTime event;

Accessing members in a nested structure

•to reference the date structure of the variable event, the syntax is the same as referencing

any member

event.sdate

•to reference a particular member inside one of these structures, a period followed by the

member name is tacked on the end

•the below statement sets the month of the date structure contained within event to

October, and adds one to the seconds contained within the time structure

event.sdate.month = 10;

+tevent.stime.seconds;

Accessing members in a nested structure

•the event variable can be initialized just like normal

• sets the date in the variable event to February 1, 2015, and sets the time to 3:30:00.

struct dateAndTime event = {{2, 1, 2015 }, { 3, 30, 0 } };

•you can use members' names in the initialization

struct dateAndTime event

{{.month = 2, .day = 1, year = 2015 },

{.hour = 3, minutes = 30, seconds = 0 }

1;

An array of nested structures

•it is also possible to set up an array of dateAndTime structures

struct dateAndTime events[100];

•the array events is declared to contain 100 elements of type struct dateAndTime

•the fourth dateAndTime contained within the array is referenced in the usual way as events[3]

•to set the first time in the array to noon

events[0].stime.hour

= 12:

events[0].stime.minutes = 0;

events[0].stime.seconds = 0;

Declaring a structure within a structure

• you can define the Date structure within the time structure definition

struct Time

{

struct Date

int day;

int month;

int year;

} dob;

int hour:

int minutes;

int seconds;

};

• the declaration is enclosed within the scope of the Time structure definition

• it does not exist outside it

• it becomes impossible to declare a Date variable external to the Time structure

Structures and Pointers

•C allows for pointers to structures

•pointers to structures are easier to manipulate than structures themselves

•in some older implementations, a structure cannot be passed as an argument to a function,

but a pointer to a structure can.

•even if you can pass a structure as an argument, passing a pointer is more efficient

•many data representations use structures containing pointers to other structures

Declaring a struct as a pointer

• you can define a variable to be a pointer to a struct

struct date *datePtr;

•the variable datePtr can be assigned just like other pointers

• you can set it to point to todaysDate with the assignment statement

datePtr=&todaysDate;

• you can then indirectly access any of the members of the date structure pointed to by datePtr

(*datePtr).day = 21;

•the above has the effect of setting the day of the date structure pointed to by datePtr to 21

• parentheses are required because the structure member operator. has higher precedence than the

indirection operator

Using structs as pointers

• to test the value of month stored in the date structure pointed to by datePtr

if ( (*datePtr).month == 12 )

• pointers to structures are so often used in C that a special operator exists

• the structure pointer operator ->, which is the dash followed by the greater than sign, permits

(*x).y

to be more clearly expressed as

X->Y

• the previous if statement can be conveniently written as

if ( datePtr->month == 12 )

Example

struct date

{

int month;

int day;

int year;

struct date today, *datePtr;

datePtr=&today;

datePtr->month = 9;

datePtr->day = 25;

datePtr->year = 2015;

printf ("Today's date is %i/%/%.2i.ln", datePtr->month, datePtr->day, datePtr->year % 100);

Structures containing pointers

• a pointer also can be a member of a structure

struct intPtrs

{

int

*p1;

int *p2;

};

• a structure called intPtrs is defined to contain two integer pointers

• the first one called p1

• the second one p2

• you can define a variable of type struct intPtrs

struct intPtrs pointers;

• the variable pointers can now be used just like other structs

• pointers itself is not a pointer, but a structure variable that has two pointers as its members

Example

struct intPtrs

{

int *p1;

int *p2;

3;

struct intPtrs pointers;

int i1 = 100, 12;

pointers.p1 = &i1;

pointers.p2 = &i2;

*pointers.p2 = -97;

printf ("1 = %i,

*pointers.p1 = %iln", i1,

*pointers.p1);

printf ("i2 = %i, *pointers.p2 = %iln", i2,

*pointers.p2);

Character arrays or character pointers??

struct names {

char first[20];

char last[20];

1;

OR

struct pnames {

char * first:

char * last:

f;

•you can do both, however, you need to understand what is happening here

Character arrays or character pointers??

struct names veep = ("Talia",

"Summers"};

struct pnames treas = ("Brad".

"Fallingjaw"};

printf("%s and %s\n", veep.first, treas.first);

• the struct names variable veep

• strings are stored inside the structure

• structure has allocated a total of 40 bytes to hold the two names

•the struct pnames variable treas

• strings are stored wherever the compiler stores string constants

• the structure holds the two addresses, which takes a total of 16 bytes on our system

•the struct pnames structure allocates no space to store strings

• it can be used only with strings that have had space allocated for them elsewhere

• such as string constants or strings in arrays

the pointers in a pnames structure should be used only to manage strings that were created and allocated

elsewhere in the program

Character arrays or character pointers??

• one instance in which it does make sense to use a pointer in a structure to handle a string is if you are dynamically

allocating that memory

• use a pointer to store the address

• has the advantage that you can ask malloc() to allocate just the amount of space that is needed for a string

Example

struct namect {

char * fame; // using pointers instead of arrays

char * Iname;

int letters;

3;

• understand that the two strings are not stored in the structure

• stored in the chunk of memory managed by malloc()

• the addresses of the two strings are stored in the structure

• addresses are what string-handling functions typically work with

Example

void getinfo (struct namect * pst)

{

char temp[SLEN];

printf("Please enter your first name. In");

S_gets(temp, SLEN);

I/ allocate memory to hold name

pst-›fame = (char *) malloc(strlen(temp) + 1);

/I copy name to allocated memory

strcpy(pst->fname, temp);

printf("Please enter your last name. In");

S_gets(temp, SLEN);

pst-›Iname = (char *) malloc (strlen(temp) + 1);

strcpy(pst->Iname, temp);

}

Structures as arguments to functions

• after declaring a structure named Family, how do we pass this structure as an argument to a function?

struct Family {

char name[20];

int age;

char father[20];

char mother[20];

3;

bool siblings(struct Family member1, struct Family member2) {

if(strcmp(member1.mother, member2.mother) == 0)

return true;

else

return false;

Pointers to Structures as function arguments

• you should use a pointer to a structure as an argument

• it can take quite a bit of time to copy large structures as arguments, as well as requiring whatever amount of memory to store the copy of the

structure.

• pointers to structures avoid the memory consumption and the copying time (only a copy of the pointer argument is made)

bool siblings(struct Family *pmember1, struct Family *member2)

if(stremp(pmember1->mother, pmember2->mother) == 0)

return true;

else

return false:

• you can also use the const modifier to not allow any modification of the members of the struct (what the struct is pointing to)

bool siblings(Family const *pmember1, Family const *omember2)

if(stremp(pmember1->mother, pmember2->mother) == 0)

return true;

else

return false:

Pointers to Structures as function arguments

•you can also use the const modifier to not allow any modification of the pointers address

•any attempt to change those structures will cause an error message during compilation

bool siblings(Family *const pmember1, Family *const pmember2)

{

if(strcmp(pmember1->mother, pmember2->mother) == 0)

return true;

else

return false;

}

•the indirection operator in each parameter definition is now in front of the const keyword

• not in front of the parameter name

•you cannot modify the addresses stored in the pointers

•its the pointers that are protected here, not the structures to which they point

Returning a structure from a function

•the function prototype has to indicate this return value in the normal way

struct Date my fun(void);

•this is a prototype for a function taking no arguments that returns a structure of type Date

•it is often more convenient to return a pointer to a structure

•when returning a pointer to a structure, it should be created on the heap

Example

struct funds {

char bank[FUNDLEN];

double bankfund;

char save[FUNDLEN];

double savefund:

int main(void)

{

struct funds stan = {

"Garlic-Melon Bank",

4032.27

"Lucky's Savings and Loan".

8543.94

f;

{

double sum(struct funds moolah)

return(moolah.bankfund + moolah.savefund);

3;

printf("Stan has a total of $%.2f.ln".

sum(stan));

return 0:

7

Reminder

• I mentioned earlier that you should always use pointers when passing structures to a function

• it works on older as well as newer C implementations and that it is quick (you just pass a single address)

• however, you have less protection for your data

• some operations in the called function could inadvertently affect data in the original structure

• use const qualifier solves that problem

• advantages of passing structures as arguments

• the function works with copies of the original data, which is safer than working with the original data

• the programming style tends to be clearer

• main disadvantages to passing structures as arguments

• older implementations might not handle the code

• wastes time and space

• especially wasteful to pass large structures to a function that uses only one or two members of the structure

• programmers use structure pointers as function arguments for reasons of efficiency and use const when necessary

• passing structures by value is most often done for structures that are small

Requirements

•write a program that declares a structure and prints out it's content

•create an employee structure with 3 members

•name (character array)

•hireDate (int)

•salary (float)

•declare and initialize an instance of an employee type

•read in a second employee from the console and store it in a structure of type employee

•print out the contents of each employee

Requirements

• write a C program that creates a structure pointer and passes it to a function

• create a structure named item with the following members

•itemName - pointer

•quantity - int

• price - float

• amount - float (stores quantity * price)

• create a function named readltem that takes a structure pointer of type item as a parameter

• this function should read in (from the user) a product name, price, and quantity

• the contents read in should be stored in the passed in structure to the function

• create a function named print item that takes as a parameter a structure pointer of type item

• function prints the contents of the parameter

•the main function should declare an item and a pointer to the item

• you will need to allocate memory for the itemName pointer

• the item pointer should be passed into both the read and print item functions
