# 07-Functions

## Basics

A function is a self-contained unit of program code designed to accomplish a particular task. Syntax rules define the structure of a function and how it can be used. A function in C is the same as subroutines or procedures in other programming languages.

Some functions cause an action to take place.

* printf() causes data to be printed on your screen.

Some functions find a value for a program to use.

* strlen() tells a program how long a certain string is.

### Advantages of Functions

Functions allow for the divide and conquer strategy, because it is very difficult to write an entire program as a single large main function, which is difficult to test, debug and maintain.

With divide and conquer, tasks can be divided into several independent subtasks, which reduce the overall complexity. Separate functions are written for each subtask. We can further divide each subtask into smaller subtasks, further reducing the complexity. Functions reduce duplication of code. It saves you time when writing, testing, and debugging code and it reduces the size of the source code. The divide and conquer approach also allows the parts of a program to be developed, tested and debugged independently. It reduces the overall development time. It also helps with readability because program is better organized. It's easier to read and easier to change or fix.

If you have to do a certain task several times in a program, you only need to write an appropriate function once. Program can then use that function wherever needed. You can also use the same function in different programs (printf). The functions developed for one program can be used in another program, e.g. software reuse.

Many programmers like to think of a function as a "black box": information that goes in (its input) and the value or action it produces (its output). Using this "black box" thinking helps you concentrate on the program's overall design rather than the details, e.g. what the function should do and how it relates to the program as a whole before worrying about writing the code.

### Examples

You have already used built-in functions such as printf() and scanf(). You should have noticed how to invoke these functions and pass data to them: arguments between parentheses following the function name.

e.g.

printf(): first argument is usually a string literal, and the succeeding arguments (of which there may be none) are a series of variables or expressions whose values are to be displayed.

You also should have noticed how you can receive information back from a function in two ways:

* through one of the function arguments (scanf): the input is stored in an address that you supply as an argument
* as a return value

```c
#define SIZE 50

int main(void)

{

	float list[SIZE];

	readlist(list, SIZE);
	sort(list, SIZE);
	average(list, SIZE);

return 0;
}
```

### Implementing functions

Remember, just calling functions does not work unless we implement the function itself. We can create our user defined functions. We would have to write the code for the three functions readlist(), sort(), and average() in our previous examples.

When you implemente the functions, you should always use descriptive function names to make it clear what the program does and how it is organized. If you can make the functions general enough, you can reuse them in other programs.

In the upcoming lectures we will understand:

* how to define them
* how to invoke them
* how to pass and return data from them

### main() function

As a reminder, the main() is a specially recognized name in the C system. It indicates where the program is to begin execution. All C programs must always have a main(). The main() can take data when you pass to it (command line arguments), or doesn't have to take data. It also have optional data that can return. You'll notice that we use main() that return 0, usually that choose when you wanna return error code.

## Defining Functions

When you create a function, you specify the function header as the first line of the function definition, and you follow that with **{ the executable code }**

The block of code between braces following the function header is called **the function body**.

The function header defines the name of the function. In that function header, you can have the **name** of the function, **parameters** (which specify the number and types of values that are passed to the function when it's called) and the type for the value that the function **returns**.

The function body contains the statements that are executed when the function is called. The function body itself would have access to any values that are passed as arguments to the function.

```c
Return _type Function_name( Parameters - separated by commas )
{
	// Statements...
}
```

The first line of a function definition tells the compiler (in order from left to right) three things about the function

* the type of value it returns
* Its name
* the arguments it takes

Choosing meaningful function names is just as important as choosing meaningful variable names. It greatly affects the program's readability.

```c
void printMessage (void)
{
	printf ("Programming is fun.\n");
}
```

The first line of the printMessage () function definition tells the compiler that the function returns no value(keyword void). Next is its name: printMessage. After that is that it takes no arguments (the second use of the keyword void).

The statements in the function body can be absent, but the braces must be present. If there are no statements in the body of a function, the return type must be void, and the function will not do anything.

Defining a function with an empty body is often useful during the testing phase of a complicated program. It allows you to run the program with only selected functions actually doing something. You can then add the detail for the function bodies step by step, testing at each stage, until the whole thing is implemented and fully tested.

### Naming functions

The name of a function can be any legal name.  You can not use a reserved word (such as int, double, sizeof, and so on). You can not use the same name as another function in your program. You can not have the same name as any of the standard library functions. The compiler would prevent you from using the library function.

A legal name has the same form as that of a variable, starting of with a sequence of letters and digits. First character must be a letter. Underline character counts as a letter. The name that you choose should be meaningful and relevant to what the function does.

You will often define function names (and variable names, too) that consist of more than one word. There are three common approaches you can adopt. You can pick any one you want, but, use the same approach throughout your program:

* separate each of the words in a function name with an underline character
* capitalize the first letter of each word
* capitalize words after the first (e.g. camelCase)

### Function prototypes

A function prototype is a statement that defines a function.

It defines its name, its return value type, and the type of each of its parameters. It provides all the external specifications for the function.

You can write a prototype for a function exactly the same as the function header. The only difference is that you add a semicolon at the end.

```c
void printMessage (void);
```

A function prototype enables the compiler to generate the appropriate instructions at each point where you call the function. It also checks that you are using the function correctly in each invocation.

When you include a standard header file in a program, the header file adds the function prototypes for that library to your program. The header file stdio.h contains function prototypes for printf(), among others.

Function prototypes generally appear at the beginning of a source file prior to the implementations of any functions or in a header file. It allows any of the functions in the file to call any function regardless of where you have placed the implementation of the functions.

Parameter names do not have to be the same as those used in the function definition. It's not required to include the names of parameters in a function prototype.

It's good practice to always include declarations for all of the functions in a program source file, regardless of where they are called. It will help keep your programs more consistent in design and prevent any errors from occurring if, at any stage, you choose to call a function from another part of your program.

```c
// #include & #define directives..

// Function prototypes
double Average(double data_values[], size_t count);
double Sum(double *x, size_t n);
size t GetData(double*, size t);

int main(void)
{
	// Code in main()...
}
// Definitions/implementations for Average(), Sum() and GetData().
```

## Arguments and parameters

A parameter is a variable in a function declaration and function definition/implementation. When a function is called, the arguments are the data you pass into the functions parameters, the actual value of a variable that gets passed to the function.

Function parameters are defined within the function header. They are placeholders for the arguments that need to be specified when the function is called.

The parameters for a function are a list of parameter names with their types. Each parameter is separated by a comma. The entire list of parameters is enclosed between the parentheses that follow the function name. A function can have no parameters, in which case you should put void between the parentheses.

Parameters provide the means to pass data to a function, data passed from the calling function to the function that is called.

The names of the parameters are local to the function. They will assume the values of the arguments that are passed when the function is called. The body of the function should use these parameters in its implementation. A function body may have additional locally defined variables that are needed by the function's implementation.

When passing an array as an argument to a function, you must also pass an additional argument specifying the size of the array. The function has no means of knowing how many elements there are in the array.

### Example

When the printf() function is called, you always supply one or more values as arguments

* first value being the format string
* the remaining values being any variables to displayed

Parameters greatly increase the usefulness and flexibility of a function: the printf() function displays whatever you tell it to display via the parameters and arguments passed.

It is a good idea to add comments before each of your own function definitions. Comments help explain what the function does and how the arguments are to be used.

```c
#include <stdio.h>

void multiply TwoNumbers (int x, int y)
{
	int retult = x * y;
	printf ("The product of %d multiplied by %d is: %dn", ×, y, result);
}

int main (void)
{
	multiplyTwoNumbers (10, 20);
	multiplyTwoNumbers (20, 30);
	multiplyTwoNumbers (50, 2);

	return 0:
}
```

## Returning Data from Functions

In our prior example of multiply two numbers, our multiply function displayed the results of the calculation at the terminal.

You might not always want to have the results of your calculations displayed. Functions can return data using specific syntax. We should be familiar from previous experience with the main function.

Let's take another look at the general form of a function

```c
Return_type Function_name(List of Parameters - separated by commas)
{
// Statements...
}
```

The Return_type specifies the type of the value returned by the function. You can specify the type of value to be returned by a function as any of the legal types in C, includes enumeration types and pointers. The return type can also be type void which means no value is returned.

### The return statement

The return statement provides the means of exiting from a function.

```c
return;
```

This form of the return statement is used exclusively in a function where the return type has been declared as void. It does not return a value.

The more general form of the return statement is:

```c
return expression;
```

This form of return statement must be used when the return value type for the function has been declared as some type other than void

The value that is returned to the calling program is the value that results when expression is evaluate. The value should be of the return type specified for the function.

### Returning data

A function that has statements in the function body but does not return a value must have the return type as void. You will get an error message if you compile a program that contains a function with a void return type that tries to return a value.

A function that does not have a void return type must return a value of the specified return type. You will get an error message from the compiler if return type is different than specified.  If expression results in a value that's a different type from the return type in the function header, the compiler will insert a conversion from the type of expression to the one required. If conversion is not possible then the compiler will produce an error message.

There can be more than one return statement in a function. Each return statement must supply a value that is convertible to the type specified in the function header for the return value.

### Invoking a function

You call a function by using the function name followed by the arguments to the function between parentheses. When you call the function, the values of the arguments that you specify in the call will be assigned to the parameters in the function. When the function executes, the computation proceeds using the values you supplied as arguments. The arguments you specify when you call a function should agree in type, number, and sequence with the parameters in the function header.

### Invoking a function and assigning data returned

If the function is used as the right side of an assignment statement, the return value supplied by the function will be substituted for the function. It will also work with an expression.

```c
int x = myFunctionCall();
```

The calling function doesn't have to recognize or process the value returned from a called function. It's up to you how you use any values returned from function calls.

```c
int multiplyTwoNumbers (int x, int y)
{
	int retult = x * y;
	return result;
}

int main (void)
{
	int result = 0;
	result = multiplyTwoNumbers (10, 20);

	printf("result is %d\n", result);
	return 0;
}
```

## Local and Global Variables

### Local Variables

Variables defined inside a function are known as automatic local variables.

They are automatically "created" each time the function is called. Their values are local to the function. The value of a local variable can only be accessed by the function in which the variable is defined. It cannot be accessed by any other function.

If an initial value is given to a variable inside a function, that initial value is assigned to the variable each time the function is called.

You can use the **auto** keyword to be more precise, but, not necessary, as the compiler adds this by default.

Local variables are also applicable to any code where the variable is created in a block (loops, if statements)

### Global Variables

Global Variable is the opposite of a local variable. Its value can be accessed by any function in the program.

A global variable has the lifetime of the program.

Global variables are declared outside of any function (usually at the top of the sourcefile)and they does not belong to any particular function.

Any function in the program can change the value of a global variable, because they have access to it and they can modify it.

If there is a local variable declared in a function with the same name, then, within that function the local variable will mask the global variable and the global variable is not accessible and prevent it from being accessed normally.

```c
int myglobal = 0; // global variable

int main ()
{
	int myLocalMain = 0; // local variable
	// can access my global and myLocal
	return 0;
}

void myFunction()
{
	int X; // local variable
	// can access myGlobal and x, cannot access myLocal
}
```

### Avoid using global variables

In general, global variables are a "bad" thing and should be avoided, because it promotes coupling between functions (dependencies); it's hard to find the location of a bug in a program and hard to fix a bug once its found.

Instead of using global data, use parameters in functions instead. If it's a lot of data, use a struct.
