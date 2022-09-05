# 11-Structures

## Creating and Using Structures

Structures in C provide another tool for grouping elements together.

Suppose you want to store a date inside a program. We could create variables for month, day, and year to store the date:

```c
int month = 9, day = 25, year = 2015;
```

Suppose your program also needs to store the date of purchase of a particular item. You must keep track of three separate variables for each date that you use in the program. These variables are logically related and should be grouped together.

It would be much better if you could somehow group these sets of three variables together. This is precisely what the structure in C allows you to do.

### Creating a structure

A structure declaration describes how a structure is put together, what elements are inside the structure.

The struct keyword enables you to define a collection of variables of various types called a structure that you can treat as a single unit.

```c
struct date
{
	int month;
	int day;
	int year;
};
```

The above statement defines what a date structure looks like to the C compiler. There is no memory allocation for this declaration.

The variable names within the date structure, month, day, and year, are called **members** or **fields**. Members of the structure appear between the braces that follow the struct tag name date.

### Using a structure

The definition of date defines a new type in the language. Variables can now be declared to be of type struct date.

```c
struct date today;
```

You can now declare more variables of type struct date

```c
struct date purchaseDate;
```

The above statement declares a variable to be of type struct date. Memory is now allocated for the variables above. Memory is allocated for three integer values for each variable.

Be certain you understand the difference between defining a structure and declaring variables of the particular structure type.

### Accessing members in a struct

Now that you know how to define a structure and declare structure variables, you need to be able to refer to the members of a structure.

A structure variable name is not a pointer, so you need a special syntax to access the members.

You could refer to a member of a structure by writing the variable name followed by a period, followed by the member variable name. The period between the structure variable name and the member name is called the member selection operator. There are no spaces permitted between the variable name, the period, and the member name.

To set the value of the day in the variable today to 25, you write:

```c
today.day = 25;
today.year = 2015;
```

To test the value of month to see if it is equal to 12:

```c
if (today.month == 12 )
	nextMonth = 1;
```

```c
struct date
{
	int month;
	int day;
	int year;
};

	struct date today;

	today.month = 9;
	today.day = 25;
	today.year = 2015;

	printf ("Today's date is %i/%i/%.2i.\n", today.month, today.day, today.year % 100);
```

### Structures in expressions

When it comes to the evaluation of expressions, structure members follow the same rules as ordinary variables do. Division of an integer structure member by another integer is performed as an integer division.

```c
century = today.year / 100 + 1;
```

### Defining the structure and variable at the same time

You do have some flexibility in defining a structure. It is valid to declare a variable to be of a particular structure type at the same time that the structure is defined. Include the variable name (or names) before the terminating semicolon of the structure definition. You can also assign initial values to the variables in the normal fashion.

```c
struct date
{
	int month;
	int day;
	int year;
} today;
```

In the above, an instance of the structure, called today, is declared at the same time that the structure is defined. today is a variable of type date.

### Un-named Structures

You also do not have to give a structure a tag name. If all of the variables of a particular structure type are defined when the structure is defined, the structure name can be omitted.

```c
struct
{			// Structure declaration and...
	int day;
	int year;
	int month:
} today;		// …structure variable declaration combined
```

A disadvantage of the above is that you can no longer define further instances of the structure in another statement. All the variables of this structure type that you want in your program must be defined in the one statement.

### Initializing Structures

Initializing structures is similar to initializing arrays. The elements are listed inside a pair of braces, with each element separated by a comma. The initial values listed inside the curly braces must be constant expressions.

```c
struct date today = { 7, 2, 2015 };
```

Just like an array initialization, fewer values might be listed than are contained in the structure:

```c
struct date date1 = { 12, 10 };
```

It sets date1.month to 12 and date1.day to 10 but gives no initial value to date.year.

You can also specify the member names in the initialization list, which enables you to initialize the members in any order, or to only initialize specified members.

```c
//.member = value

struct date date1 = { .month = 12, .day = 10 };
```

This set just the year member of the date structure variable today to 2015:

```c
struct date today = { .year = 2015 };
```

### Assignment with compound literals

You can assign one or more values to a structure in a single statement using what is known as compound literals.

```c
today = (struct date) { 9, 25, 2015 ); //C11
```

This statement can appear anywhere in the program. It is not a declaration statement. The type cast operator is used to tell the compiler the type of the expression. The list of values follows the cast and are to be assigned to the members of the structure, in order, so it's listed in the same way as if you were initializing a structure variable.

You can also specify values using the member notation:

```c
today = (struct date) { .month = 9, .day = 25, .year = 2015 };
```

The advantage of using this approach is that the arguments can appear in any order.

## Structures and Arrays

### Arrays of structures

You have seen how useful a structure is in enabling you to logically group related elements together. For example, it is only necessary to keep track of one variable, instead of three, for each date that is used by the program. To handle 10 different dates in a program, you only have to keep track of 10 different variables, instead of 30.

A better method for handling the 10 different dates involves the combination of two powerful features of the C programming language----structures and arrays. It is perfectly valid to define an array of structures. The concept of an array of structures is a very powerful and important one in C.

Declaring an array of structures is like declaring any other kind of array:

```c
struct date myDates[10];
```

This defines an array called myDates, which consists of 10 elements. Each element inside the array is defined to be of type struct date.

To identify members of an array of structures, you apply the same rule used for individual structures. You follow the structure name with the dot operator and then with the member name. Referencing a particular structure element inside the array is quite natural. To set the second date inside the myDates array to August 8, 1986:

```c
myDates[1].month = 8:
myDates[1].day = 8;
myDates[1].year = 1986;
```

#### Initializing an array of structures

Initialization of arrays containing structures is similar to initialization of multidimensional arrays.

```c
struct date myDates[5] = { {12, 10, 1975}, {12, 30, 1980}, {11, 15, 2005} };
```

This sets the first three dates in the array myDate to 12/10/1975, 12/30/1980, and 11/15/2005. The inner pairs of braces are optional.

```c
struct date myDates[5] = { 12, 10, 1975, 12, 30, 1980, 11, 15, 2005 };
```

If you just want to initialize just the 3rd element of the array to the specified value:

```c
struct date myDates[5] = { [2] = {12, 10, 1975} };
```

If you want to set just the month and day of the second element of the myDates array to 12 and 30:

```c
struct date myDates[5] = { [1].month = 12, [1].day = 30 };
```

### Structures containing arrays

It is also possible to define structures that contain arrays as members. Most common use is to set up an array of characters inside a structure.

Suppose you want to define a structure called month that contains as its members the number of days in the month as well as a three-character abbreviation for the month name:

```c
struct month
{
	int numberOfDays;
	char name[3];
};
```

This sets up a month structure that contains an integer member called numberOfDays and a character member called name. Member name is actually an array of three characters.

You can now define a variable to be of type struct month and set the proper fields inside aMonth for January.

```c
struct month aMonth;
aMonth.numberOfDays=31;
aMonth.name[0] = 'J';
aMonth.name[1] = 'a';
aMonth.name[2] = 'n';
```

You can also initialize this variable to the same values:

```c
struct month aMonth = {31, {'J', 'a', 'n' }};
```

You can set up 12-month structures inside an array to represent each month of the year:

```c
struct month months[12];
```

## Nested Structures

C allows you to define a structure that itself contains other structures as one or more of its members. You have seen how it is possible to logically group the month, day, and year into a structure called date.

How about grouping the hours, minutes, and seconds into a structure called time:

```c
struct time
{
	int hours;
	int minutes;
	int seconds;
};
```

In some applications, you might have the need to group both a date and a time together. You might need to set up a list of events that are to occur at a particular date and time.

You want to have a convenient way to associate both the date and the time together. You can define a new structure, called, for example, dateAndTime, which contains as its members two elements:

* date and time

```c
struct dateAndTime
{
	struct date sdate;
	struct time stime;
};
```

The 1st member of this structure is of type struct date and is called sdate. The 2nd member of the dateAndTime structure is of type struct time and is called stime.

Variables can now be defined to be of type struct dateAndTime.

```c
struct dateAndTime event;
```

### Accessing members in a nested structure

To reference the date structure of the variable event, the syntax is the same as referencing any member:

```c
event.sdate
```

To reference a particular member inside one of these structures, a period followed by the member name is tacked on the end. The below statement sets the month of the date structure contained within event to October, and adds one to the seconds contained within the time structure:

```c
event.sdate.month = 10;
++event.stime.seconds;
```

The event variable can be initialized just like normal. The below sets the date in the variable event to February 1, 2015, and sets the time to 3:30:00

```c
struct dateAndTime event = { {2, 1, 2015 }, { 3, 30, 0 } };
```

You can use members' names in the initialization

```c
struct dateAndTime event
{ 
	{ .month = 2, .day = 1, .year = 2015 },
	{ .hour = 3, minutes = 30, seconds = 0 }

};
```

### An array of nested structures

It is also possible to set up an array of dateAndTime structures:

```c
struct dateAndTime events[100];
```

The array events is declared to contain 100 elements of type struct dateAndTime. The fourth dateAndTime contained within the array is referenced in the usual way as events[3].

To set the first time in the array to noon:

```c
events[0].stime.hour = 12;
events[0].stime.minutes = 0;
events[0].stime.seconds = 0;
```

### Declaring a structure within a structure

You can define the Date structure within the time structure definition

```c
struct Time
{
	struct Date
	{
		int day;
		int month;
		int year;
	} dob;

	int hour;
	int minutes;
	int seconds;
};
```

The declaration is enclosed within the scope of the Time structure definition. It does not exist outside it. It becomes impossible to declare a Date variable external to the Time structure.

## Structures and Pointers

C allows for pointers to structures.

Pointers to structures are easier to manipulate than structures themselves. In some older implementations, a structure cannot be passed as an argument to a function, but a pointer to a structure can. Even if you can pass a structure as an argument, passing a pointer is more efficient. Many data representations use structures containing pointers to other structures.

### Declaring a struct as a pointer

You can define a variable to be a pointer to a struct:

```c
struct date *datePtr;
```

The variable datePtr can be assigned just like other pointers. You can set it to point to todaysDate with the assignment statement.

```c
datePtr = &todaysDate;
```

You can then indirectly access any of the members of the date structure pointed to by datePtr

```c
(*datePtr).day = 21;
```

The above has the effect of setting the day of the date structure pointed to by datePtr to 21. Parentheses are required because the structure member operator. has higher precedence than the indirection operator.

### Using structs as pointers

To test the value of month stored in the date structure pointed to by datePtr

```c
if ( (*datePtr).month == 12 )
	...
```

Pointers to structures are so often used in C that a special operator exists.

The structure pointer operator ->, which is the dash followed by the greater than sign, permits.

```c
(*x).y
```

To be more clearly expressed as:

```c
x->y
```

The previous if statement can be conveniently written as:

```c
if ( datePtr->month == 12 )
	...
```

Example

```c
struct date
{
	int month;
	int day;
	int year;
};

int main (void)
{
	struct date today, *datePtr;

	datePtr=&today;

	datePtr->month = 9;
	datePtr->day = 25;
	datePtr->year = 2015;

	printf ("Today's date is %i/%i/%.2i.\n", datePtr->month, datePtr->day, datePtr->year % 100);

	return 0;
}

```

### Structures containing pointers

A pointer also can be a member of a structure:

```c
struct intPtrs
{
	int *p1;
	int *p2;
};
```

A structure called intPtrs is defined to contain two integer pointers. The first one called p1; the second one p2.

You can define a variable of type struct intPtrs.

```c
struct intPtrs pointers;
```

The variable pointers can now be used just like other structs. Pointers itself is not a pointer, but a structure variable that has two pointers as its members.

```c
struct intPtrs
{
	int *p1;
	int *p2;
};

struct intPtrs pointers;
int i1 = 100, i2;

pointers.p1 = &i1;
pointers.p2 = &i2;

*pointers.p2 = -97;

printf ("i1 = %i, (*pointers).p1 = %i\n", i1, *pointers.p1);
printf ("i2 = %i, (*pointers).p2 = %i\n", i2, *pointers.p2);
```

### Character arrays or character pointers??

```c
struct names {
	char first[20];
	char last[20];
};

//OR

struct pnames {
	char * first;
	char * last;
};
```

You can do both, however, you need to understand what is happening here.

```c
struct names veep = {"Talia", "Summers"};
struct pnames treas = {"Brad", "Fallingjaw"};

printf("%s and %s\n", veep.first, treas.first);
```

The struct names variable veep: Strings are stored inside the structure. Structure has allocated a total of 40 bytes to hold the two names.

The struct pnames variable treas: Strings are stored wherever the compiler stores **string constants**. The structure holds the two addresses, which takes a total of 16 bytes on our system. The struct pnames structure allocates no space to store strings. It can be used only with strings that have had space allocated for them elsewhere, such as string constants or strings in arrays. The pointers in a pnames structure should be used **only** to manage strings that were created and allocated elsewhere in the program.

One instance in which it does make sense to use a pointer in a structure to handle a string is if you are dynamically allocating that memory. So you want to use a pointer to store the address. This has the advantage that you can ask malloc() to allocate just the amount of space that is needed for a string.

```c
struct namect {
char * fname; // using pointers instead of arrays
char * lname;
int letters;
};
```

The two strings are not stored in the structure. They stored in the chunk of memory managed by malloc(). The addresses of the two strings are stored in the structure. Addresses are what string-handling functions typically work with.

```c
void getinfo (struct namect * pst)
{
	char temp[SLEN];
	printf("Please enter your first name. \n");
	s_gets(temp, SLEN);

	// allocate memory to hold name
	pst-›fname = (char *) malloc(strlen(temp) + 1);

	// copy name to allocated memory
	strcpy(pst->fname, temp);

	printf("Please enter your last name. \n");
	s_gets(temp, SLEN);
	pst-›lname = (char *) malloc (strlen(temp) + 1);
	strcpy(pst->lname, temp);
}
```

## Structures and Functions

### Structures as arguments to functions

After declaring a structure named Family, how do we pass this structure as an argument to a function?

```c
struct Family {
char name[20];
int age;
char father[20];
char mother[20];
};

bool siblings(struct Family member1, struct Family member2) {
	if(strcmp(member1.mother, member2.mother) == 0)
		return true;
	else
		return false;
}
```

### Pointers to Structures as function arguments

You should use a pointer to a structure as an argument. It can take quite a bit of time to copy large structures as arguments, as well as requiring whatever amount of memory to store the copy of the structure. Pointers to structures avoid the memory consumption and the copying time (only a copy of the pointer argument is made).

```c
bool siblings(struct Family *pmember1, struct Family *member2)
{
	if(strcmp(pmember1->mother, pmember2->mother) == 0)
		return true;
	else

	return false;
}
```

You can also use the const modifier to not allow any modification of the members of the struct (what the struct is pointing to):

```c
bool siblings( struct Family const *pmember1, Family const *pmember2)
{
	if(strcmp(pmember1->mother, pmember2->mother) == 0)
		return true;
	else
		return false;
}
```

You can also use the const modifier to not allow any modification of the pointers address. Any attempt to change those structures will cause an error message during compilation.

```c
bool siblings(Family *const pmember1, Family *const pmember2)
{
	if(strcmp(pmember1->mother, pmember2->mother) == 0)
		return true;
	else
		return false;
}
```

The indirection operator in each parameter definition is now in front of the const keyword. It's not in front of the parameter name. You cannot modify the addresses stored in the pointers. Its the pointers that are protected here, not the structures to which they point.

### Returning a structure from a function

The function prototype has to indicate this return value in the normal way.

```c
struct Date my fun(void);
```

This is a prototype for a function taking no arguments that returns a structure of type Date.

It is often more convenient to return a pointer to a structure. When returning a pointer to a structure, it should be created on the heap.

```c
struct funds {
	char bank[FUNDLEN];
	double bankfund;
	char save[FUNDLEN];
	double savefund;
}

double sum(struct funds moolah)
{
	return(moolah.bankfund + moolah.savefund);
};

int main(void)
{
	struct funds stan = { 
				"Garlic-Melon Bank", 
				4032.27, 
				"Lucky's Savings and Loan", 
				8543.94
	};

	printf("Stan has a total of $%.2f.\n", sum(stan));

	return 0:
}
```

### Reminder

You should always use pointers when passing structures to a function. It works on older as well as newer C implementations and that it is quick (you just pass a single address).

However, you have less protection for your data. Some operations in the called function could inadvertently affect data in the original structure. You can use const qualifier solves that problem.

Advantages of passing structures as arguments:

The function works with copies of the original data, which is safer than working with the original data. The programming style tends to be clearer.

Main disadvantages to passing structures as arguments:

Older implementations might not handle the code. It wastes time and space. and it is especially wasteful to pass large structures to a function that uses only one or two members of the structure.

**Programmers use structure pointers as function arguments for reasons of efficiency and use const when necessary.**

Passing structures by value is most often done for structures that are small.
