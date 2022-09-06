<stddef.h> - contains some standard definitions

Define

Meaning

NULL

A null pointer constant

offsetof (structure,

member)

The offset in bytes of the member member from the start of the

structure structure; the type of the result is size t

Dtrdiff t

The type of integer produced by subtracting two pointers

size t

The type of integer produced by the sizeof operator

wchar t

The type of the integer required to hold a wide character (see

Appendix A.

"C Language Summary")

limits.h

<limits.h>

- contains various implementation-defined limits for character and integer data types

Define

CHAR BIT

CHAR MAX

CHAR MIN

SCHAR MAX

SCHAR MIN

UCHAR MAX

SHRT_MAX

SHRT MIN

USHRT MAX

INT MAX

INT MIN

UINT MAX

LONG MAX

LONG MIN

ULONG MAX

LLONG MAX

LLONG_MIN

Meaning

Number of bits in a char (8)

Maximum value for object of type char (127 if sign extension is done on

chars, 255 otherwise)

Minimum value for object of type char (-127 if sign extension is done on

chars, 0 otherwise)

Maximum value for object of type signed char (127)

Minimum value for object of type signed char (-127)

Maximum value for object of type unsigned char (255)

Maximum value for object of type short int (32767)

Minimum value for object of type short int (-32767)

Maximum value for object of type unsigned short int (65535)

Maximum value for object of type int (32767)

Minimum value for object of type int (-32767)

Maximum value for object of type unsigned int (65535)

Maximum value for object of type long int (2147483647)

Minimum value for object of type long int (-2147483647)

Maximum value for object of type unsigned long int (4294967295)

Maximum value for object of type long long int

(9223372036854775807)

Minimum value for object of type long long int

(-9223372036854775807)

ULLONG MAX

Maximum value for object of type unsigned long long int

(18446744073709551615)

stdbool.h

<stdbool.h> - file contains definitions for working with Boolean variables (type Bool)

Define

Meaning

bool

Substitute name for the basic Bool data type

true

Defined as 1

false

Defined as 0

Various functions

I wanted to remind you of some of the various functions from the C standard library that we have

already addressed

String functions

• to use any of these functions, you need to include the header file <string.h>

• char *strcat (s1, s2)

• concatenates the character string s2 to the end of s1, placing a null character at the end of the final string. The function returns s1

• char *strchr (s, c)

• searches the string s for the first occurrence of the character c. If it is found, a pointer to the character is returned; otherwise, a null

pointer is returned

• int stremp (s1, s2)

• compares strings s1 and s2 and returns a value less than zero if s1 is less than s2, equal to zero if s1 is equal to s2, and greater

than zero if s1 is greater than s2

• char *stropy (s1, s2)

• copies the string s2 to s1, returning s1

• size t strlen (s)

• returns the number of characters in s, excluding the null character

String functions

• char *strncat (s1, s2. n)

• copies s2 to the end of s1 until either the null character is reached or n characters have been copied. whichever occurs first. Returns s1

• int strncmp (S1, s2, n)

• performs the same function as stremp, except that at most n characters from the strings are compared

• char *strncpy (s1, s2, n)

• copies s2 to s1 until either the null character is reached or n characters have been copied, whichever occurs first. Returns s1

• char *strrchr (s, c)

is returned

• searches the string s for the last occurrence of the character c. If found, a pointer to the character in s is returned; otherwise, the null pointer

• char *strstr (s1. s2)

• searches the string s1 for the first occurrence of the string s2. If found, a pointer to the start of where s2 is located inside s1 is returned;

otherwise, if s2 is not located inside s1, the null pointer is returned

• char *strtok (s1, s2)

• breaks the string s1 into tokens based on delimiter characters in s2

character functions

•to use these character functions, you must include the file <ctype.h>

•isalnum, isalpha, isblank, iscntrl, isdigit, isgraph, slower, isspace, ispunct, isupper, isxdigit

•int tolower(c)

•returns the lowercase equivalent of c. If c is not an uppercase letter, c itself is returned

•int toupper(c)

•returns the uppercase equivalent of c. If c is not a lowercase letter, c itself is returned.

1/0 functions

•to use the most common I/0 functions from the C library you should include the header file <stdio.h>

•included in this file are declarations for the I/O functions and definitions for the names EOF, NULL, stdin,

stout, stderr (all constant values), and FILE

• int close (filePtr)

occurs

• closes the file identified by filePtr and returns zero if the close is successful, or returns OF if an error

•int feof (filePtr)

• returns nonzero if the identified file has reached the end of the file and returns zero otherwise

• int flush (filePtr)

•flushes (writes) any data from internal buffers to the indicated file, returning zero on success and the

value EOF if an error occurs

1/O functions

• int fgetc (filePtr)

• returns the next character from the file identified by filePtr, or the value EOF if an end-of-file condition occurs.

(Remember that this function returns an int)

• int fgetpos (filePtr, fpos)

• gets the current file position for the file associated with filePtr, storing it into the pos_t(defined in <stdio.h>) variable

pointed to by fpos. fgetpos returns zero on success, and returns nonzero on failure

• char *gets (buffer, i, filePtr)

• reads characters from the indicated file, until either i - 1 characters are read or a newline character is read, whichever

occurs first

• FILE *open (fileName, accessMode)

• opens the specified file with the indicated access mode

• int fprintf (filePtr, format, arg1, arg2,

-, argn)

• writes the specified arguments to the file identified by filePtr, according to the format specified by the character string

format

1/O functions

• int fputc (c, filePtr)

• writes the value of c to the file identified by filePtr, returning c if the write is successful, and the value EOF

otherwise

• int fputs (buffer, filePtr)

• writes the characters in the array pointed to by buffer to the indicated file until the terminating null character in

buffer is reached

• int fscanf (filePtr, format, arg1, arg2,

, argn)

• reads data items from the file identified by filePtr, according to the format specified by the character string format

• int seek (filePtr, offset, mode)

• positions the indicated file to a point that is offset (a long int) bytes from the beginning of the file, from the current

position in the file, or from the end of the file, depending upon the value of mode (an integer)

• int fsetpos (filePtr, fpos)

• sets the current file position for the file associated with filePtr to the value pointed to by fpos, which is of type

fpos_t (defined in <stdio.h>). Returns zero on success, and nonzero on failure

1/O functions

• long fell (filePtr)

• returns the relative offset in bytes of the current position in the file identified by filePtr, or -1L on error

•int print (format, arg1, arg2,

.., argn)

•writes the specified arguments to stout, according to the format specified by the character string.

Returns the number of characters written.

•int remove (fileName)

•removes the specified file. A nonzero value is returned on failure

•int rename (fileName1, fileName2)

• renames the file fileName1 to fileName2, returning a nonzero result on failure.

•int scanf (format, arg1, arg2,

..., argn)

•reads items from stdin according to the format specified by the string format

Conversion functions

•to use these functions that convert character strings to numbers you must include the header file

<stdlib.h>

•double atof (s)

•converts the string pointed to by s into a floating-point number, returning the result

•int atoi (s)

•converts the string pointed to by s into an int, returning the result

•int atol (S)

•converts the string pointed to by s into a long int, returning the result

•int atoll (s)

•converts the string pointed to by s into a long long int, returning the result

Dynamic Memory functions

• to use these function that allocate and free memory dynamically you must include the stolib.h header file

• void *calloc (n, size)

• allocates contiguous space for n items of data, where each item is size bytes in length. The allocated space is

initially set to all zeroes. On success, a pointer to the allocated space is returned; on failure, the null pointer is

returned

• void free (pointer)

• returns a block of memory pointed to by pointer that was previously allocated by a calloc(), malloc(), or realloc() call

• void *malloc (size)

• allocates contiguous space of size bytes, returning a pointer to the beginning of the allocated block if successful, and

the null pointer otherwise

• void *realloc (pointer, size)

• changes the size of a previously allocated block to size bytes, returning a pointer to the new block (which might have

moved), or a null pointer if an error occurs

Math functions

•to use common math functions you must include the math.h header file and link to the math library

•double acosh (x)

• returns the hyperbolic arccosine of x, x ≥ 1

•double asin (x)

•returns the arcsine of x as an angle expressed in radians in the range [-T/2, T1/2]. x is in the range

[-1, 1]

• double atan (x)

•returns the arctangent of x as an angle expressed in radians in the range [-T/2, TT/2]

•double ceil (x)

• returns the smallest integer value greater than or equal to x. Note that the value is returned as a

double

Math functions

• double cos (r)

• returns the cosine of r

• double floor (x)

• returns the largest integer value less than or equal to x. Note that the value is returned as a double

• double log (x)

• returns the natural logarithm of x, x ≥ 0

• double nan (s)

• returns a NaN, if possible, according to the content specified by the string pointed to by s

• double pow (x, y)

• returns xy. If x is less than zero, y must be an integer. If x is equal to zero, y must be greater than zero

• double remainder (x, y)

• returns the remainder of x divided by y

Math functions

•double round (x)

•returns the value of x rounded to the nearest integer in floating-point format. Halfway values are

always rounded away from zero (so 0.5 always rounds to 1.0)

•double sin (r)

• returns the sine of r

•double sart (x)

•returns the square root of x, x ≥ 0

•double tan (r)

•returns the tangent of r

•And so many more

•complex arithmetic

Utility functions

•to use these routines, include the header file (stdlib.h>

•int abs (n)

•returns the absolute value of its int argument n

•void exit (n)

•terminates program execution, closing any open files and returning the exit status specified by its int

argument n

•EXIT SUCCESS and EXIT FAILURE, defined in (stdlib.h>

•other related routines in the library that you might want to refer to are abort and atexit

•char *getenv (s)

•returns a pointer to the value of the environment variable pointed to by s, or a null pointer if the variable

doesn't exist

•used to get environment variables

Utility functions

• void qsort (arr, n, size, comp fn)

• sorts the data array pointed to by the void pointer arr

•there are n elements in the array, each size bytes in length. n and size are of type size t

• the fourth argument is of type

"pointer to function that returns int and that takes two void pointers as arguments

• sort calls this function whenever it needs to compare two elements in the array, passing it pointers to the elements to

compare

• int rand (void)

of 32767

• returns a random number in the range [0, RAND MAX], where RAND MAX is defined in (stdlib.h) and has a minimum value

• void sand (seed)

• seeds the random number generator to the unsigned int value seed

• int system (s)

• gives the command contained in the character array pointed to by s to the system for execution, returning a system-

defined value

•system ("mkdir/usr/tmp/data");

Assert Library

•the assert library, supported by the assert.h header file, is a small one designed to help with debugging

programs

•it consists of a macro named assert()

•it takes as its argument an integer expression

•If the expression evaluates as false (nonzero), the assert() macro writes an error message to the

standard error stream (stderr) and calls the abort() function, which terminates the program

z=x*x-y*y; /* should be + */

assert(z >=0); // asserts that z is greater than or equal to 0

Other useful header files

•time.h

• defines macros and functions supporting operations with dates and times

•errno.h

•locale.h

• defines macros for the reporting of errors

•defines functions and macros to assist with formatting data such as monetary units for different countries

• signal.h

• defines facilities for dealing with conditions that arise during program execution, including error conditions

•stdarg.h

• defines facilities that enable a variable number of arguments to be passed to a function
