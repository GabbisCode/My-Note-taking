# 04-Basic_Concepts

## Comments

## The preprocessor

another **unique feature of the C language** tgithat is not found in many other higher-level programming languages

allows for programs to be easier to develop, easier to read, easier to modify, and easier to port to different computer systems

part of the C compilation process that recognizes special statements

analyzes these statements before analysis of the C program itself takes place

an instruction to your compiler to do something before compiling the source code

could be anywhere in your code

Preprocessor statements are identified by the presence of a pound sign, #, which must be the first non-space character on the line

We will utilize the preprocessor to:

* create are own constants and macros with the #define statement
* build your own library files with the #include statement
* make more powerful programs with the conditional #ifdef, #endif, #else, and #ifndef Statements.

## The #include statement

the #include statement is a preprocessor directive

#include <stdio.h>

It is not strictly part of the executable program, however, the program won't work without it

The symbol # indicates this is a preprocessing directive

an instruction to your compiler to do something before compiling the source code

there are many preprocessing directives

are usually some at the beginning of the program source file, but they can be anywhere

similar to the import statement in java

### sytax

## Displaying Output

## Reading input from the terminal
