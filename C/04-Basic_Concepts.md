# 04-Basic_Concepts

## Comments

Comments are used in a program to document a program and to enhance its readability. They are there to remind you, or someone else reading your code, what the program does or what a particular line of code is doing. Comments are ignored by the compiler.

Comments are very useful. A programmer may return to a program that he coded six months ago and may not remember the purpose of a particular function or line of code. A simple comment can save a significant amount of time otherwise wasted on having to re-understand the code Syntax.

### Syntax

There are two ways to add comments into a C program.

#### Multi-line comment

By using the two characters / and \* marks the beginning of the comment. These types of comments have to be terminated. To end the comment, the characters \* and / are used without any embedded spaces. All characters included between the opening /\* and the closing \*/ are treated as part of the comment.

```c
/*
*Written by Jason Fedin
*Copyright 2017
*/
```

You can also embellish comments to make them stand out:

```c
/*******************************************
*This is a very important comment	*
*so please read this.	*
********************************************/
```

#### Single line comment

By using two consecutive slash characters //. Any characters that follow these slashes up to the end of the line are ignored by the compiler.

You can add a comment at the end of a line of code

```c
printf("Hello, nope!"); // This line displays a quotation
```

### Example

```c
/* This program adds two integer values and displays the results */

#include <stdio.h>

int main (void)
{
  // Declare variables
  int value1, value2, sum;

  // Assign values and calculate their sum 
  value1 = 50;
  value2 = 25;
  sum = value1 + value2;

  // Display the result
  printf ("The sum of %i and %i is %i\n", value1, value2, sum);

  return 0;
}
```

### Use of Comments

It is possible to insert so many comments into a program that the readability of the program is actually degraded instead of improved! You need to intelligently use comments. It is a good idea to get into the habit of inserting comment statements into the program as the program is being written or typed in. It is also easier to document the program while the particular program logic is still fresh in your mind. You can reap the benefits of the comments during the debug phase, when program logic errors are being isolated and debugged. A comment can helps you read through the program, but it can also help point the way to the source of the logic mistake. You can self document comments by using meaningful names.

## The preprocessor

The preprocessor is another unique feature of the C language that is not found in many other higher-level programming languages. It allows for programs to be easier to develop, easier to read, easier to modify, and easier to port to different computer systems.

It's part of the C compilation process that recognizes special statements. So it analyzes these statements before analysis of the C program itself takes place. It gives an instruction to your compiler to do something before compiling the source code. The preprocessor commands could be anywhere in your code.

**Preprocessor statements are identified by the presence of a pound sign, #**,which must be the first non-space character on the line.

We will utilize the preprocessor to:

* create are own constants and macros with the **#define** statement
* build your own library files with the **#include** statement
* make more powerful programs with the conditional **#ifdef, #endif, #else, and #ifndef** Statements.

### #include Statement

the #include statement is a preprocessor directive

```c
#include <stdio.h>
```

It is not strictly part of the executable program, however, the program won't work without it.

The symbol # indicates this is a preprocessing directive, which is an instruction to your compiler to do something before compiling the source code. There are many preprocessing directives. The directives are usually some at the beginning of the program source file, but they can be anywhere. The #include is very similar to the import statement in java.

### Header Files

In the above example, the compiler is instructed to "include" in your program the contents of the file with the name *stdio.h*

**.h extension** called a header file because it is usually included at the head of a program source file. Header files define information about some of the functions that are provided by that file.

**stdio.h** is the standard C library header and provides functionality for displaying output, among many other things. We need to include this file in a program when using the *printf()* function from the standard library. *stdio.h* contains the information that the compiler needs to understand what
*printf()* means, as well as other functions that deal with input and output. *stdio*, is short for standard input/output.

#### Syntax

Header files specify information that the compiler uses to integrate any predefined functions within a program. **Header file names are case sensitive** on some systems, so you should always write them **in lowercase**.

Two ways to #include header files in a program

1. Using angle brackets (*#include <Jason.h>*)
   tells the preprocessor to look for the file in one or more standard system directories
2. Using double quotes (*#include "Jason.h"*)
   double quotes usually mean it's a user-defined header file
   tells the preprocessor to first look in the current directory

Every C compiler that conforms to the C11 standard will have a set of standard header files supplied with it. You should use *#ifndef* and *#define* to protect against multiple inclusions of a header file.

```c
// some header
```

```c
// typedefs
typedef struct names_st names;
```

```c
// function prototypes
void get_names(names *);
void show names(const names *);
char * s_gets(char * st, int n);
```

header files includes many different things:
#define directives
structure declarations
typedef statements
function prototypes

Executable code normally goes into a source code file, not a header file.

## printf() Function

```c
printf("Hi, my name is Jason"); //this line does end with a semicolon
```

*printf()* is a standard library function. It outputs information to the command line (the standard output stream, which is the command line by default). The information displayed is in based on what appears between the parentheses that immediately follow the function name (printf).

*printf()* is probably the most common function used in C. It provides an easy and convenient means to display program results. Not only can simple phrases be displayed, but the values of variables and the results of computations can also be displayed. And *printf()* is also used for **debugging**.

## scanf() Function

It's very useful to ask the user to enter data into a program via the terminal/console. The C library contains several input functions, and *scanf()* is the most general of them.

scanf() can read a variety of formats. It reads the input from the standard input stream **stdin** and scans that input according to the **format** provided. Format can be a simple constant string, but you can specify **%s, %d, %c, %f,** etc., to read **strings, integer, character or floats**. If the stdin is input from the keyboard then text is read in because the keys generate text characters: letters, digits, and punctuation. When you enter the integer 2014, you type the characters 2 0 1 and 4. If you want to store that as a numerical value rather than as a string, your program has to convert the string character-by-character to a numerical value and this is the job of the scanf function.

Like *printf()*, *scanf()* uses a control string followed by a list of arguments. Control string indicates the destination data types for the input stream of characters.

The printf() function uses variable names, constants, and expressions as its argument list. The scanf() function is different, because it uses pointers to variables.

Remember these 3 rules about scanf:

* returns the number of items that it successfully reads
* If you use *scanf()* to read a value for the basic variable types, precede the variable name with an **&**
* If you use *scanf()* to read a string into a character array, don't use an **&**

The *scanf()* function uses whitespace (newlines, tabs, and spaces) to decide how to divide the input into separate fields.

*scanf()* is the inverse of *printf()*, which converts integers, floating-point, numbers, characters, and C strings to text that is to be displayed onscreen.

### Example

```c
#include <stdio.h>
int main() {

  char str[100];
  int i;

  printf("Enter a value :");
  scanf("%s %d", str, &i);

  printf( "\nYou entered: %s %d ", str, i);

  return 0;
}
```

When a program uses scanf to gather input from the keyboard, it waits for you to input some text. When you enter some text and press enter, then program proceeds and reads the input. Remember, *scanf()* expects input in the same format as you provided %s and %d, you have to provide valid inputs like "string integer".
