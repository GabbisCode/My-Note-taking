# 09-Debugging

## Overview

Debugging is the process of finding and fixing errors in a program (usually logic errors, but, can also include compiler/syntax errors). For syntax errors, understand what the compiler is telling you. You'll always focus on fixing the first problem detected.

Debugging can range in complexity from fixing simple errors to collecting large amounts of data for analysis. The ability to debug by a programmer is an essential skill (problem solving) that can save you tremendous amounts of time (and money).

The maintenance phase is the most expensive phase of the software life cycle.

Understand though that bugs are unavoidable, all software have bugs. Nobody can write perfect code. And it's not even necessarily about writing perfect code, it's just things change over time, so that may result in bugs as well. You have to understand that just because software has bugs does not mean it's poorly written code, it's kind of unavoidable. So it's okay to have bugs. when you find and fix them, it's even greater because you actually feel like you're accomplishing something.

### Common Problems

* Logic Errors
* Syntax Errors
* Memory Corruption
* Performance / Scalability
* Lack of Cohesion
* Tight Coupling (dependencies)

### Debugging Process

**Understand the problem**

sit down with tester, understand requirements

**Reproduce the problem**

Once you understand the bug, try to reproduce it. Sometimes very difficult as problems can be intermittent or only happen in very rare circumstances, e.g. Parallel processes or threading problems.

**Simplify the problem / Divide and conquer / isolate the source**

* Remove parts of the original test case
* Comment out code / back out changes
* Turn a large program into a lot of small programs (unit testing)

**Identify origin of the problem (in the code)**

* Use Debugging Tools if necessary

**Solve the problem**

* Experience and practice
* Sometimes includes redesign or refactor of code

**Test! Test! Test!**

### Techniques and Tools

**Tracing / using print statements**

* Output values of variables at certain points of a program
* Show the flow of execution
* Can help isolate the error

Debuggers, monitor the execution of a program, stop it, restart it, set breakpoints and watch variables in memory.

Log Files can be used for analysis, add "good" log statements to your code.

Monitoring Software, run-time analysis of memory usage, network traffic, thread and obiect information.

### Common Debugging Tools

Exception Handling helps a great deal to identify catastrophic errors.

Static Analyzers - analyze source code for specific set of known problems. It is a semantic checker and does not analyze syntax. It can detect things like uninitialized variables, memory leaks, unreachable code, deadlocks or race conditions.

Test Suites - run a set of comprehensive system end-to-end tests.

Debugging the program after it has crashed:

* Analyze the call stack
* Analyze memory dump (core file)

### Preventing Errors

Write high quality code (follow good design principles and good programming practices).

Unit Tests - automatically executed when compiling. It helps avoid regression. Regression is when you write new code and you introduce a bug on something that was previously working. You broke old code. Unit test can help do that because unit tests will run on that old code and we'll say hey this was working now it's failing. It also finds errors in new code before it is delivered. TDD (Test Driven Development) is where you write your tests first and then you develop your code after. And the goal is when you write your first test, your test is failing. And then you write the code to get it to pass.

Provide good documentation and proper planning (write down design on paper and utilize pseudocode).

Work in small Steps and constantly test after each step:

* Avoid too many changes at once
* When making changes, apply them incrementally. Add one change, then test thoroughly before starting the next step
* Helps reduce the possible sources of bugs, limits problem set

## Understanding the call stack

A stack trace (call stack) is generated whenever your app crashes because of a fatal error.

A stack trace shows a list of the function calls that lead to the error. It includes the filenames and line numbers of the code that cause the exception or error to occur. Top of the stack contains the last call that caused the error (nested calls). Bottom of the stack contains the first call that started the chain of calls to cause the error. So you need to find the call in your application that is causing the crash.

A programmer can also dump the stack trace.

## Common C Mistakes

**1. Misplacing a semicolon**

```c
if (j == 100);
	j= 0;
```

In this case the value of j will always be set to 0 due to the misplaced semicolon after the closing parenthesis. Semicolon is syntactically valid (it represents the null statement), and, therefore, no error is produced by the compiler. Same type of mistake is frequently made in while and for loops.

**2. Confusing the operator = with the operator ==**

```c
if (a = 2)  //should be a == 2
	printf ("Your turn.\n");
```

Usually made inside an if, while, or do statement. Perfectly valid and has the effect of assigning 2 to a and then executing the printf() call. printf() function will always be called because the value of the expression contained in the if statement will always be nonzero.

**3. omitting prototype declarations**

```c
result = squareRoot(2);
```

In this example, if squareRoot is defined later in the program, or in another file, and is not explicitly declared otherwise, the compiler assumes that the function returns an int. It's always safest to include a prototype declaration for all functions that you call (either explicitly yourself or implicitly by including the correct header file in your program).

**4. failing to include the header file that includes the definition for a C-programming library function being used in the program**

```c
double answer = sqrt(value1);
```

If this program does not #include the <math.h> file, this will generate an error that sqrt() is undefined.

**5. confusing a character constant and a character string**

```c
text = 'a'; // a single character is assigned to text

text = "a"; // a pointer to the character string "a" is assigned to text
```

In the first case, text is normally declared to be a char variable. In the second case, it should be declared to be of type "pointer to char".

**6. using the wrong bounds for an array**

```c
int a[100], i, sum = 0;
...
for (i=1; i <= 100; ++i)
	sum += a[i];
```

Valid subscripts of an array range from 0 through the number of elements minus one. The preceding loop is incorrect because the last valid subscript of a is 99 and not 100. It is also probably intended to start with the first element of the array; therefore, i should have been initially set to 0.

**7. forgetting to reserve an extra location in an array for the terminating null character of a string**

When declaring character arrays they need to be large enough to contain the terminating null character. The character string "hello" would require six locations in a character array if you wanted to store a null at the end.

**8. confusing the operator > with the operator. when referencing structure members**

The operator. is used for structure variables. The operator > is used for structure pointer variables.

**9. omitting the ampersand before nonpointer variables in a scanf() call**

```c
int number:
scanf ("%i", number); // &number
```

All arguments appearing after the format string in a scanf() call must be pointers.

**10. using a pointer variable before it's initialized**

```c
char *char_pointer;
*char_pointer = 'X';
```

You can only apply the indirection operator to a pointer variable after you have set the variable pointing somewhere. char-pointer is never set pointing to anything, so the assignment is not meaningful.

**11. omitting the break statement at the end of a case in a switch statement**

If a break is not included at the end of a case, then execution continues into the next case.

**12. inserting a semicolon at the end of a preprocessor definition**

Usually happens because it becomes a matter of habit to end all statements with semicolons

```c
#define END_OF_DATA 999;   //leads to a syntax error if used in an expression such as:

if (value == END_OF_DATA ) 
//the compiler will see this statement after preprocessing
if (value == 999; )
```

**13. omitting a closing parenthesis or closing quotation marks on any statement**

```c
total_earning = (cash + (investments * inv_interest) + (savings * sav_interest);
printf("Your total money to date is %.2f, total_earning);
```

The use of embedded parentheses to set apart each portion of the equation makes for a more readable line of code. However, there is always the possibility of missing a closing parenthesis (or in some occasions, adding one too many).

The second line is missing a closing quotation mark for the string being sent to the printf() function.

Both of these will generate a compiler error. Sometimes the error will be identified as coming on a different line, depending on whether the compiler uses a parenthesis or quotation mark on a subsequent line to complete the expression which moves the missing character to a place later in the program.

## Understanding Compiler Errors and Warning

It is sometimes very hard to understand what the compiler is complaining about. You need to understand compiler errors in order to fix them. It is sometimes difficult to identify the true reason behind a compiler error.

The compiler makes decisions about how to translate the code that the programmer has not written in the code. This is convenient because the programs can be written more succinctly (only expert programmers take advantage of this feature).

You should use an option for the compiler to notify all cases where there are implicit decisions. This option is -Wall.

The compiler shows two types of problems:

* **errors**

A condition that prevents the creation of a final program. No executable is obtained until all the errors have been corrected. The first errors shown are the most reliable because the translation is finished but there are some errors that may derive from previous ones. Fix the first errors are first, it is recommended to compile again and see if other later errors also disappeared.

* **warnings**

Messages that the compiler shows about "special" situations in which an anomaly has been detected. They are non-fatal errors. The final executable program may be obtained with any number of warning.

Compile always with the -Wall option and do not consider the program correct until all warnings have been eliminated.

### most common compiler messages

**'variable' undeclared (first use in this function)**

This is one of the most common and easier to detect. The symbol shown at the beginning of the message is used but has not been declared.



**warning: implicit declaration of function '...'**

This warning appears when the compiler finds a function used in the code but no previous information has been given about it. To solve this, always declare a function prototype at the top.



**warning: control reaches end of non-void function**

This warning appears when a function has been defined as returning a result but no return statement has been included to return this result. Either the function is incorrectly defined or the statement is missing.



**warning: unused variable '...'**

This warning is printed by the compiler when a variable is declared but not used in the code. Message disappears if the declaration is removed.



**undefined reference to '...'**

This appears when there is a function invoked in the code that has not been defined anywhere. The compiler is telling us that there is a reference to a function with no definition. Check which function is missing and make sure its definition is compiled.



**error: conflicting types for '...'**

Two definitions of a function prototype have been found. One is the prototype (the result type, name, parenthesis including the parameters, and a semicolon). The other is the definition with the function body. The information in both places is not identical, and a conflict has been detected. The compiler shows you in which line the conflict appears and the previous definition that caused the contradiction.

### runtime errors

The execution of C programs may terminate abruptly (crash) when a run-time error is detected.

C programs only print the succinct message Segmentation fault. It usually results in a core file depending on the signal that has been thrown. You can analyze the core file and the call stack.
