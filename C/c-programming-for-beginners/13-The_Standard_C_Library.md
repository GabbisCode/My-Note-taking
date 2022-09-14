# 13-The_Standard_C_Library

## Standard Header Files

### stddef.h

<stddef.h> - contains some standard definitions

| Define                       | Meaning                                                                                                              |
| ---------------------------- | -------------------------------------------------------------------------------------------------------------------- |
| NULL                         | A null pointer constant                                                                                              |
| offsetof (structure, member) | The offset in bytes of the member member from the start of the structure structure; the type of the result is size t |
| ptrdiff_t                    | The type of integer produced by subtracting two pointers                                                             |
| size_t                       | The type of integer produced by the sizeof operator                                                                  |
| wchar_t                      | The type of the integer required to hold a wide character (see Appendix A. "C Language Summary")                     |

### limits.h

<limits.h> - contains various implementation-defined limits for character and integer data types

| Define     | Meaning                                                                                       |
| ---------- | --------------------------------------------------------------------------------------------- |
| CHAR_BIT   | Number of bits in a char (8)                                                                  |
| CHAR_MAX   | Maximum value for object of type char (127 if sign extension is done on chars, 255 otherwise) |
| CHAR_MIN   | Minimum value for object of type char (-127 if sign extension is done on chars, 0 otherwise)  |
| SCHAR_MAX  | Maximum value for object of type signed char (127)                                            |
| SCHAR_MIN  | Minimum value for object of type signed char (-127)                                           |
| UCHAR_MAX  | Maximum value for object of type unsigned char (255)                                          |
| SHRT_MAX   | Maximum value for object of type short int (32767)                                            |
| SHRT_MIN   | Minimum value for object of type short int (-32767)                                           |
| USHRT_MAX  | Maximum value for object of type unsigned short int (65535)                                   |
| INT_MAX    | Maximum value for object of type int (32767)                                                  |
| INT_MIN    | Minimum value for object of type int (-32767)                                                 |
| UINT_MAX   | Maximum value for object of type unsigned int (65535)                                         |
| LONG_MAX   | Maximum value for object of type long int (2147483647)                                        |
| LONG_MIN   | Minimum value for object of type long int (-2147483647)                                       |
| ULONG_MAX  | Maximum value for object of type unsigned long int (4294967295)                               |
| LLONG_MAX  | Maximum value for object of type long long int (9223372036854775807)                          |
| LLONG_MIN  | Minimum value for object of type long long int (-9223372036854775807)                         |
| ULLONG_MAX | Maximum value for object of type unsigned long long int (18446744073709551615)                |

### stdbool.h

<stdbool.h> - file contains definitions for working with Boolean variables (type_Bool)

| Define | Meaning                                                      |
| ------ | ------------------------------------------------------------ |
| bool   | Substitute name for the basic Bool data type _Bool data type |
| true   | Defined as 1                                                 |
| false  | Defined as 0                                                 |

## Various functions

### String functions

To use any of these functions, you need to include the header file <string.h>

```c
char *strcat (s1, s2)
```

The function concatenates the character string s2 to the end of s1, placing a null character at the end of the final string. The function returns s1.

```c
char *strchr (s, c)
```

searches the string s for the first occurrence of the character c. If it is found, a pointer to the character is returned; otherwise, a null pointer is returned

```c
int strcmp (s1, s2)
```

compares strings s1 and s2 and returns a value less than zero if s1 is less than s2, equal to zero if s1 is equal to s2, and greater than zero if s1 is greater than s2.

```c
char *strcpy (s1, s2)
```

copies the string s2 to s1, returning s1.

```c
size_t strlen (s)
```

returns the number of characters in s, **excluding the null character.**

```c
char *strncat (s1, s2, n)
```

copies s2 to the end of s1 until either the null character is reached or n characters have been copied. whichever occurs first. Returns s1.

```c
int strncmp (S1, s2, n)
```

performs the same function as strcmp, except that at most n characters from the strings are compared.

```c
char *strncpy (s1, s2, n)
```

copies s2 to s1 until either the null character is reached or n characters have been copied, whichever occurs first. Returns s1.

```c
char *strrchr (s, c)
```

searches the string s for the last occurrence of the character c. If found, a pointer to the character in s is returned; otherwise, the null pointer is return.

```c
char *strstr (s1, s2)
```

searches the string s1 for the first occurrence of the string s2. If found, a pointer to the start of where s2 is located inside s1 is returned; otherwise, if s2 is not located inside s1, the null pointer is returned.

```c
char *strtok (s1, s2)
```

breaks the string s1 into tokens based on delimiter characters in s2 character functions.

### Character functions

To use these character functions, you must include the file <ctype.h>:

* isalnum, isalpha, isblank, iscntrl, isdigit, isgraph, islower, isspace, ispunct, isupper, isxdigit

```c
int tolower(c)
```

returns the lowercase equivalent of c. If c is not an uppercase letter, c itself is returned.

```c
int toupper(c)
```

returns the uppercase equivalent of c. If c is not a lowercase letter, c itself is returned.

### I/O functions

To use the most common I/O functions from the C library you should include the header file <stdio.h>. Included in this file are declarations for the I/O functions and definitions for the names EOF, NULL, stdin, stdout, stderr (all constant values), and FILE.

```c
int fclose (filePtr)
```

closes the file identified by filePtr and returns zero if the close is successful, or returns EOF if an error occurs.

```c
int feof (filePtr)
```

returns nonzero if the identified file has reached the end of the file and returns zero otherwise.

```c
int fflush (filePtr)
```

flushes (writes) any data from internal buffers to the indicated file, returning zero on success and the value EOF if an error occurs.

```c
int fgetc (filePtr)
```

returns the next character from the file identified by filePtr, or the value EOF if an end-of-file condition occurs. (Remember that this function returns an int).

```c
int fgetpos (filePtr, fpos)
```

gets the current file position for the file associated with filePtr, storing it into the pos_t (defined in <stdio.h>) variable pointed to by fpos. fgetpos returns zero on success, and returns nonzero on failure.

```c
char *fgets (buffer, i, filePtr)
```

reads characters from the indicated file, until either i - 1 characters are read or a newline character is read, whichever occurs first.

```c
FILE *open (fileName, accessMode)
```

opens the specified file with the indicated access mode.

```c
int fprintf (filePtr, format, arg1, arg2, …, argn)
```

writes the specified arguments to the file identified by filePtr, according to the format specified by the character string format.

```c
int fputc (c, filePtr)
```

writes the value of c to the file identified by filePtr, returning c if the write is successful, and the value EOF otherwise.

```c
int fputs (buffer, filePtr)
```

writes the characters in the array pointed to by buffer to the indicated file until the terminating null character in buffer is reached.

```c
int fscanf (filePtr, format, arg1, arg2, …, argn)
```

reads data items from the file identified by filePtr, according to the format specified by the character string format

```c
int fseek (filePtr, offset, mode)
```

positions the indicated file to a point that is offset (a long int) bytes from the beginning of the file, from the current position in the file, or from the end of the file, depending upon the value of mode (an integer).

```c
int fsetpos (filePtr, fpos)
```

sets the current file position for the file associated with filePtr to the value pointed to by fpos, which is of type fpos_t (defined in <stdio.h>). Returns zero on success, and nonzero on failure.

```c
long ftell (filePtr)
```

returns the relative offset in bytes of the current position in the file identified by filePtr, or -1L on error.

```c
int print (format, arg1, arg2, …, argn)
```

writes the specified arguments to stout, according to the format specified by the character string. Returns the number of characters written.

```c
int remove (fileName)
```

removes the specified file. A nonzero value is returned on failure.

```c
int rename (fileName1, fileName2)
```

renames the file fileName1 to fileName2, returning a nonzero result on failure.

```c
int scanf (format, arg1, arg2, …, argn)
```

reads items from stdin according to the format specified by the string format.

### Conversion functions

To use these functions that convert character strings to numbers you must include the header file <stdlib.h>.

```c
double atof (s)
```

converts the string pointed to by s into a floating-point number, returning the result.

```c
int atoi (s)
```

converts the string pointed to by s into an int, returning the result.

```c
int atol (S)
```

converts the string pointed to by s into a long int, returning the result.

```c
int atoll (s)
```

converts the string pointed to by s into a long long int, returning the result

### Dynamic Memory functions

To use these function that allocate and free memory dynamically you must include the stdlib.h header file

```
void *calloc (n, size)
```

allocates contiguous space for n items of data, where each item is size bytes in length. The allocated space is initially set to all zeroes. On success, a pointer to the allocated space is returned; on failure, the null pointer is returned

```c
void free (pointer)
```

returns a block of memory pointed to by pointer that was previously allocated by a calloc(), malloc(), or realloc() call.

```c
void *malloc (size)
```

allocates contiguous space of size bytes, returning a pointer to the beginning of the allocated block if successful, and the null pointer otherwise.

```c
void *realloc (pointer, size)
```

changes the size of a previously allocated block to size bytes, returning a pointer to the new block (which might have moved), or a null pointer if an error occurs.

### Math functions

To use common math functions you must include the math.h header file and link to the math library.

```c
double acosh (x)
```

returns the hyperbolic arccosine of x, x ≥ 1

```c
double asin (x)
```

returns the arcsine of x as an angle expressed in radians in the range [-π/2, π/2]. x is in the range [-1, 1]

```c
double atan (x)
```

returns the arctangent of x as an angle expressed in radians in the range [-π/2, π/2]

```c
double ceil (x)
```

returns the smallest integer value greater than or equal to x. Note that the value is returned as a double.

```c
double cos (r)
```

returns the cosine of r

```c
double floor (x)
```

returns the largest integer value less than or equal to x. Note that the value is returned as a double.

```c
double log (x)
```

returns the natural logarithm of x, x ≥ 0.

```c
double nan (s)
```

returns a NaN, if possible, according to the content specified by the string pointed to by s.

```c
double pow (x, y)
```

returns xy. If x is less than zero, y must be an integer. If x is equal to zero, y must be greater than zero.

```c
double remainder (x, y)
```

returns the remainder of x divided by y.

```c
double round (x)
```

returns the value of x rounded to the nearest integer in floating-point format. Halfway values are always rounded away from zero (so 0.5 always rounds to 1.0).

```c
double sin (r)
```

returns the sine of r.

```c
double sart (x)
```

returns the square root of x, x ≥ 0.

```c
double tan (r)
```

returns the tangent of r

### Utility functions

To use these routines, include the header file (stdlib.h>

```c
int abs (n)
```

returns the absolute value of its int argument n.

```c
void exit (n)
```

terminates program execution, closing any open files and returning the exit status specified by its int argument n. EXIT_SUCCESS and EXIT_FAILURE, defined in (stdlib.h>. Other related routines in the library that you might want to refer to are abort and atexit.

```c
char *getenv (s)
```

returns a pointer to the value of the environment variable pointed to by s, or a null pointer if the variable doesn't exist; used to get environment variables.

```c
void qsort (arr, n, size, comp_fn)
```

sorts the data array pointed to by the void pointer arr. There are n elements in the array, each size bytes in length. n and size are of type size_t. The fourth argument is of type "pointer to function that returns int and that takes two void pointers as arguments". qsort calls this function whenever it needs to compare two elements in the array, passing it pointers to the elements to compare.

```c
int rand (void)
```

returns a random number in the range [0, RAND_MAX], where RAND_MAX is defined in (stdlib.h) and has a minimum value of 32767.

```c
void srand (seed)
```

seeds the random number generator to the unsigned int value seed

```c
int system (s)
```

gives the command contained in the character array pointed to by s to the system for execution, returning a system-defined value.

* system ("mkdir/usr/tmp/data");

## Assert Library

The assert library, supported by the assert.h header file, is a small one designed to help with debugging programs. It consists of a macro named assert(). It takes as its argument an integer expression. If the expression evaluates as false (nonzero), the assert() macro writes an error message to the standard error stream (stderr) and calls the abort() function, which terminates the program.

```c
z = x * x - y * y; /* should be + */
assert(z >=0); // asserts that z is greater than or equal to 0
```

## Other useful header files

**time.h**

defines macros and functions supporting operations with dates and times.

**errno.h**

defines macros for the reporting of errors.

**locale.h**

defines functions and macros to assist with formatting data such as monetary units for different countries.

**signal.h**

defines facilities for dealing with conditions that arise during program execution, including error conditions.

**stdarg.h**

defines facilities that enable a variable number of arguments to be passed to a function.
