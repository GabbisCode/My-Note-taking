Overview

•debugging is the process of finding and fixing errors in a program (usually logic errors,

but, can also include compiler/syntax errors)

•for syntax errors, understand what the compiler is telling you

• always focus on fixing the first problem detected

•can range in complexity from fixing simple errors to collecting large amounts of data for

analysis

•the ability to debug by a programmer is an essential skill (problem solving) that can save

you tremendous amounts of time (and money )

• maintenance phase is the most expensive phase of the software life cycle

•understand that bugs are unavoidable

Common Problems

•Logic Errors

• Syntax Errors

•Memory Corruption

•Performance / Scalability

•Lack of Cohesion

• Tight Coupling (dependencies)

Debugging Process

•Understand the problem (sit down with tester, understand requirements)

• Reproduce the problem

• Sometimes very difficult as problems can be intermittent or only happen in very rare

circumstances

•Parallel processes or threading problems

•Simplify the problem / Divide and conquer / isolate the source

•Remove parts of the original test case

•Comment out code / back out changes

• Turn a large program into a lot of small programs (unit testing)

Debugging Process (cont'd)

•Identify origin of the problem (in the code)

•Use Debugging Tools if necessary

•Solve the problem

•Experience and practice

•Sometimes includes redesign or refactor of code

•Test! Test! Test!

Techniques and Tools

•Tracing / using print statements

•Output values of variables at certain points of a program

• Show the flow of execution

•Can help isolate the error

•Debuggers

- monitor the execution of a program, stop it, restart it, set breakpoints and

watch variables in memory

•Log Files - can be used for analysis, add "good" log statements to your code

•Monitoring Software - run-time analysis of memory usage, network traffic, thread and

obiect information

Common Debugging Tools

•Exception Handling helps a great deal to identify catastrophic errors

•Static Analyzers - analyze source code for specific set of known problems

•Semantic checker, does not analyze syntax

•Can detect things like uninitialized variables, memory leaks, unreachable code,

deadlocks or race conditions

•Test Suites - run a set of comprehensive system end-to-end tests

•Debugging the program after it has crashed

• Analyze the call stack

• Analyze memory dump (core file)

Preventing Errors

write high quality code (follow good design principles and good programming practices)

• Unit Tests - automatically executed when compiling

• Helps avoid regression

• Finds errors in new code before it is delivered

• TDD (Test Driven Development)

Provide good documentation and proper planning (write down design on paper and utilize

pseudocode)

Work in Steps and constantly test after each step

• Avoid too many changes at once

• When making changes, apply them incrementally. Add one change, then test thoroughly before

starting the next step

• Helps reduce the possible sources of bugs, limits problem set

Overview

•A stack trace (call stack) is generated whenever your app crashes because of a fatal

error

• A stack trace shows a list of the function calls that lead to the error

•Includes the filenames and line numbers of the code that cause the exception or error

to occur

• Top of the stack contains the last call that caused the error (nested calls)

•Bottom of the stack contains the first call that started the chain of calls to cause the

error

• You need to find the call in your application that is causing the crash

•A programmer can also dump the stack trace

Common C Mistakes

• misplacing a semicolon

if (j==100);

¡= 0;

•the value of j will always be set to o due to the misplaced semicolon after the closing parenthesis

•semicolon is syntactically valid (it represents the null statement), and, therefore, no error is produced by the

compiler

•same type of mistake is frequently made in while and for loops

•confusing the operator = with the operator ==

•usually made inside an if, while, or do statement

•perfectly valid and has the effect of assigning 2 to a and then executing the printf() call

•printf() function will always be called because the value of the expression contained in the if statement will

always be nonzero

if (a=2)

printf ("Your turn.\n");

Common C Mistakes

•omitting prototype declarations

result = squareRoot(2);

•If squareRoot is defined later in the program, or in another file, and is not explicitly declared

otherwise

•compiler assumes that the function returns an int

•always safest to include a prototype declaration for all functions that you call (either explicitly

yourself or implicitly by including the correct header file in your program)

•failing to include the header file that includes the definition for a C-programming library function

being used in the program

double answer = sqrt(value1);

•if this program does not #include the <math.h> file, this will generate an error that sqrt() is

undefined

Common C Mistakes

•confusing a character constant and a character string

text = a:

•a single character is assigned to text

text = "a":

•a pointer to the character string "a" is assigned to text

•in the first case, text is normally declared to be a char variable

•in the second case, it should be declared to be of type "pointer to char"

Common C Mistakes

•using the wrong bounds for an array

int a[100], i, sum = 0;

for (i=1; i<=100; +ti)

sum += alil;

•valid subscripts of an array range from o through the number of elements minus one

•the preceding loop is incorrect because the last valid subscript of a is 99 and not 100

•also probably intended to start with the first element of the array; therefore, i should have been initially

set to o

•forgetting to reserve an extra location in an array for the terminating null character of a string

•when declaring character arrays they need to be large enough to contain the terminating null characte

•the character string "hello" would require six locations in a character array if you wanted to store a null

at the end

Common C Mistakes

•confusing the operator > with the operator. when referencing structure members.

•the operator. is used for structure variables

•the operator > is used for structure pointer variables

•omitting the ampersand before nonpointer variables in a scanf0) call

int number:

scanf ("%i", number);

•all arguments appearing after the format string in a scanf() call must be pointers

Common C Mistakes

•using a pointer variable before it's initialized

char

*char_pointer;

*char_pointer = 'X'.

•you can only apply the indirection operator to a pointer variable after you have set the

variable pointing somewhere

•char-pointer is never set pointing to anything, so the assignment is not meaningful

•omitting the break statement at the end of a case in a switch statement

•if a break is not included at the end of a case, then execution continues into the next

case

Common C Mistakes

•inserting a semicolon at the end of a preprocessor definition

•usually happens because it becomes a matter of habit to end all statements with semicolons

#define END_OF_DATA 999;

•leads to a syntax error if used in an expression such as

if (value == END_OF_DATA )

•the compiler will see this statement after preprocessing

if (value == 999; )

Common C Mistakes

•omitting a closing parenthesis or closing quotation marks on any statement

total_earning = (cash + (investments * inv _interest) + (savings * sav_interest);

printf("Your total money to date is %.2f, total_earning);

•the use of embedded parentheses to set apart each portion of the equation makes for a more

readable line of code

•however, there is always the possibility of missing a closing parenthesis (or in some occasions,

adding one too many)

•the second line is missing a closing quotation mark for the string being sent to the printf() function

• both of these will generate a compiler error

•sometimes the error will be identified as coming on a different line

• depending on whether the compiler uses a parenthesis or quotation mark on a subsequent line to

complete the expression which moves the missing character to a place later in the program

Overview

•it is sometimes very hard to understand what the compiler is complaining about

•need to understand compiler errors in order to fix them

•it is sometimes difficult to identify the true reason behind a compiler error

•the compiler makes decisions about how to translate the code that the programmer has

not written in the code

•is convenient because the programs can be written more succinctly (only expert

programmers take advantage of this feature)

•you should use an option for the compiler to notify all cases where there are implicit

decisions

•this option is -Wall

Overview

•the compiler shows two types of problems

•errors

•a condition that prevents the creation of a final program

•no executable is obtained until all the errors have been corrected

• The first errors shown are the most reliable because the translation is finished but there are some

errors that may derive from previous ones

•Fix the first errors are first, it is recommended to compile again and see if other later errors also

disappeared.

•warnings

•messages that the compiler shows about "special" situations in which an anomaly has been detected

•non-fatal errors

•the final executable program may be obtained with any number of warning

•compile always with the -Wall option and do not consider the program correct until all warnings have

been eliminated

most common compiler messages

'variable' undeclared (first use in this function)

•this is one of the most common and easier to detect

•the symbol shown at the beginning of the message is used but has not been declared

•warning: implicit declaration of function

.,

• this warning appears when the compiler finds a function used in the code but no

previous information has been given about it

•need to declare a function prototype

• warning: control reaches end of non-void function

•this warning appears when a function has been defined as returning a result but no

return statement has been included to return this result

•either the function is incorrectly defined or the statement is missing

most common compiler messages

•warning: unused variable

•this warning is printed by the compiler when a variable is declared but not used in the code

•message disappears if the declaration is removed

•undefined reference to

•appears when there is a function invoked in the code that has not been defined anywhere

•compiler is telling us that there is a reference to a function with no definition

•check which function is missing and make sure its definition is compiled

•error: conflicting types for

•two definitions of a function prototype have been found

•one is the prototype (the result type, name, parenthesis including the parameters, and a semicolon)

•the other is the definition with the function body

•the information in both places is not identical, and a conflict has been detected

• the compiler shows you in which line the conflict appears and the previous definition that caused the

contradiction

runtime errors

•the execution of C programs may terminate abruptly (crash) when a run-time error is

detected

•C programs only print the succinct message Segmentation fault

•usually results in a core file depending on the signal that has been thrown

•can analyze the core file and the call stack
