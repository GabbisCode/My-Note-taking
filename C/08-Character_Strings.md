Strings

we have learned all about the char data type

contains a single character.

to assign a single character to a char variable, the character is enclosed within a pair of single quotation marks

plusSign = 't';

you have also learned that there is a distinction made between the single quotation and double quotation marks

plusSign = "+"; // incorrect if plusSign is a char

a string constant or string literal is a sequence of characters or symbols between a pair of double-quote characters

anything between a pair of double quotes is interpreted by the compiler as a string

includes any special characters and embedded spaces

Strings (cont'd)

every time you have displayed a message using the printf() function, you have defined the message as a string

constant

printf("This is a string.");

printf("This is on\ntwo lines!");

printf("For )" you write WI".");

understand the difference between single quotation and double quotation marks

both are used to create two different types of constants in C

for the third example above, you must specify a double quote within a string as the escape sequence I"

the compiler will interpret an explicit double quote without a preceding backslash as a string delimiter

also, you must also use the escape sequence I when you want to include a backslash in a string

a backslash in a string always signals the start of an escape sequence to the compiler

String in Memory

![](https://app.yinxiang.com/shard/s46/res/a945fc70-cd39-44bf-aeea-d52d39436e0d/IMG_0167.JPEG?resizeSmall&width=813 "Attachment")

Null Character

a special character with the code value O is added to the end of each string to mark where it ends

this character is known as the null character and you write it as 10

a string is always terminated by a null character, so the length of a string is always one greater than the number of

characters in the string

don't confuse the null character with NULL

null character is a string terminator

NULL is a symbol that represents a memory address that doesn't reference anything

you can add a 10 character to the end of a string explicitly

this will create two strings

Null Character Example

#include <stdio.h>

int main(void)

{

printf("The character \0 is used to terminate a string.");

return 0;

If you compile and run this program, you'll get this output:

The character

only the first part of the string has been displayed

output ends after the first two words because the function stops outputting the string when it reaches the first

null character

the second 10 at the end of the string will never be reached

The first 10 that's found in a character sequence always marks the end of the string

Character Strings

• C has no special variable type for strings

• this means there are no special operators in the language for processing strings

• the standard library provides an extensive range of functions to handle strings

• strings in C are stored in an array of type char

•characters in a string are stored in adjacent memory cells, one character per cell

•to declare a string in C, simply use the char type and the brackets to indicate the size

char myString[20];

• this variable can accommodate a string that contains up to 19 characters

• you must allow one element for the termination character (null character)

• when you specify the dimension of an array that you intend to use to store a string, it must be at least one greater

than the number of characters in the string that you want to store

• the compiler automatically adds 10 to the end of every string constant

Initializing a String

•You can initialize a string variable when you declare it

char word (= ('H', 'e', "l', "I', 'o', "I"};

•to initialize a string, it is the same as any other array

initialization

•in the absence of a particular array size, the C compiler

automatically computes the number of elements in the

array

•based upon the number of initializers

•this statement reserves space in memory for exactly

seven characters

• automatically adds the null terminator

![](https://app.yinxiang.com/shard/s46/res/f537f4cb-1b76-46ee-930e-0a55fb33c9ff/IMG_0168.JPEG?resizeSmall&width=813 "Attachment")

Initializing a String (cont'd)

• you can specify the size of the string explicitly, just make sure you leave enough space for the terminating null character

char word[7] = { "Hello!" };

• If the size specified is too small, then the compiler can't fit a terminating null character at the end of the array, and it doesn't put one

there (and it doesn't complain about it either)

char word[6] = { "Hello!" };

• So....., do not specify the size, let the compiler figure out, you can be sure it will be correct

• you can initialize just part of an array of elements of type char with a string

char str40] = "To be":

• the compiler will initialize the first five elements, str[0] to str[4], with the characters of the string constant

• str[5] will contain the null character, 10'

• space is allocated for all 40 elements of the array

Assigning a value to a string after initializing

• since you can not assign arrays in C, you can not assign strings either

• the following is an error:

char s[100]; // declare

S

: "hello"; I/ initalize - DOESN'T WORK ('Ivalue required' error)

• you are performing an assignment operation, and you cannot assign one array of characters to another array of characters like this

• you have to use strncpy() to assign a value to a char array after it has been declared or initialized

• The below is perfectly valid

S[O] = "h';

s[1] = 'e';

s[2] = "l';

S[3] = "":

S[4] = 'o';

S[5] = 10°

Displaying a string

•when you want to refer to a string stored in an array, you just use the array name by itself

•to display a string as output using the printf function, you do the following

print("'InThe message is: %s", message);

•the %s format specifier is for outputting a null-terminated string

•the printf() function assumes when it encounters the %s format characters that the corresponding

argument is a character string that is terminated by a null character

Inputting a string

•to input a string via the keyboard, use the scan function

char input[10];

printf("Please input your name: ");

scanf("%s", input);

•the %s format specifier is for inputting string

•no need to use the & (address of operator) on a string

Testing if two strings are equal

•you cannot directly test two strings to see if they are equal with a statement such as

if ( string1 == string2 )

•the equality operator can only be applied to simple variable types, such as floats, ints, or chars

•does not work on structures or arrays

•to determine if two strings are equal, you must explicitly compare the two character strings character by

character

•we will discuss as easier way with the stremp function

• Reminder::

•the string constant "x" is not the same as the character constant 'x'

•'x' is a basic type (char)

•"x" is a derived type, an array of char

• "x" really consists of two characters, 'x' and '10', the null character

Example

#include `<stdio h>`

int main(void)

char str1[1 = "To be or not to be":

char str2l) = " that is the question"

unsigned int count = 0;

I Stores the string length

while (str1(count] != '10')

++count;

Il Increment count till we reach the

// terminating character.

printf("The length of the string I"%s)" is %d characters.In", str1, count);

count = 0:

while (str2[count] != '10')

++count:

I Reset count for next string

// Count characters in second string

printf("The length of the string I"%s)" is %d characters. In", str2, count);

return O;

Constant Strings

• sometimes you need to use a constant in a program

circumference = 3.14159 * diameter:

• the constant 3.14159 represents the world-famous constant pi (TT)

• there are good reasons to use a symbolic constant instead of just typing in the number

• a name tells you more than a number does

owed = 0.015 * housevalue;

owed = taxrate

* housevalue;

• If you read through a long program, the meaning of the second version is plainer.

• suppose you have used a constant in several places, and it becomes necessary to change its value

• you only need to alter the definition of the symbolic constant, rather than find and change every occurrence of the

constant in the program

#define

•the preprocessor lets you define constants

#define TAXRATE 0.015

•when your program is compiled, the value 0.015 will be

substituted everywhere you have used TAXRATE

•compile-time substitution

•a defined name is not a variable

•you cannot assign a value to it

•notice that the #define statement has a special syntax

•no equal sign used to assign the value 0.015 to

TAXRATE

•no semicolon

#define (cont'd)

• #define statements can appear anywhere in a program

• no such thing as a local define

• most programmers group their #define statements at the beginning of the program (or inside an include file)

where they can be quickly referenced and shared by more than one source file

•the #define statement helps to make programs more portable

• it might be necessary to use constant values that are related to the particular computer on which the program is

running

•the #define statement can be used for character and string constants

#define BEEP 'la'

#define TEE 'T'

#define ESC '\033'

#define OOPS "Now you have done it!"

const

•C90 added a second way to create symbolic constants

•using the const keyword to convert a declaration for a variable into a declaration for a constant

const int MONTHS = 12; // MONTHS a symbolic constant for 12

•const makes MONTHS into a read-only value

•you can display MONTHS and use it in calculations

•you cannot alter the value of MONTHS

•const is a newer approach and is more flexible than using #define

•it lets you declare a type

•it allows better control over which parts of a program can use the constant

•C has yet a third way to create symbolic constants

•enums

const (cont'd)

•initializing a char array and declaring it as constant is a good way of handling standard messages

const char message!] = "The end of the world is nigh.";

•because you declare message as const, it's protected from being modified explicitly within the

program

•any attempt to do so will result in an error message from the compiler

•this technique for defining standard messages is particularly useful if they are used in many places

within a program

•prevents accidental modification of such constants in other parts of the program

String Functions

•you already know that a character string is a char array terminated with a null character (10)

•character strings are commonly used

•C provides many functions specifically designed to work with strings

•some of the more commonly performed operations on character strings include

•getting the length of a string

•Strien

•copying one character string to another

• strcpy() and strncpy()

•combining two character strings together (concatenation)

•strcat() and strncat()

•determining if two character strings are equal

• stremp() and strncmp()

• the C library supplies these string-handling function prototypes in the string.h header file

Getting the length of a string

•the strlen() function finds the length of a string

• returned as a size t

#include <stdio.h>

#include <string.h>

int main(X

char my Stringll = "my string";

printf("The length of this string is: %d", strlen(myString));

return O:

• this function does change the string

• the function header does not use const in declaring the formal parameter string

Copying strings

•since you can not assign arrays in C, you can not assign strings either

char s[100]; // declare

s= "hello"; I/ initalize - DOESN'T WORK ('value required' error)

•you can use the strepy() function to copy a string to an existing string

•the string equivalent of the assignment operator

char sc[50], dest[50];

stropy(src,

"This is source");

stropy(dest, "This is destination");

Copying strings (cont'd)

•the strepy() function does not check to see whether the source string actually fits in the target string

• safer way to copy strings is to use strncpy()

• strncpy() takes a third argument

•the maximum number of characters to copy

char src|401:

char dest[12];

memset(dest, '10', sizeof(dest));

strepy(sc, "Hello how are you doing");

strncpy(dest, src, 10);

String concatenation

• the streat() function takes two strings for arguments

• a copy of the second string is tacked onto the end of the first

• this combined version becomes the new first string

• the second string is not altered

• it returns the value of its first argument

• the address of the first character of the string to which the second string is appended

char myStringl] = "my string";

char input 80];

printf("Enter a string to be concatenated: ");

scanf("%s", input);

printf("In The string %s concatenated with %s is.In", myString, input);

printf("%s", strcat(input, myString));

String concatenation (cont'd)

• the streat() function does not check to see whether the second string will fit in the first array

• if you fail to allocate enough space for the first array, you will run into problems as excess characters overflow into adjacent memory

locations

• use strncat() instead

• takes a second argument indicating the maximum number of characters to add

• for example, strncat(bugs, addon, 13) will add the contents of the addon string to bugs, stopping when it reaches 13 additional

characters or the null character, whichever comes first

char sc[50], dest[50];

strepy(src,

"This is source");

strepy(dest, "This is destination");

strncat(dest, src, 15);

printf("Final destination string : [%sl", dest);

comparing Strings

•suppose you want to compare someone response to a stored string

•cannot use ==, will only check to see if the string has the same address

•there is a function that compares string contents, not string addresses

•it is the stremp() (for string comparison) function

•does not compare arrays, so it can be used to compare strings stored in arrays of different sizes

•does not compare characters

•you can use arguments such as

"apples" and "A", but you cannot use character arguments, such

as 'A'

•this function does for strings what relational operators do for numbers

•it returns O if its two string arguments are the same and nonzero otherwise

•if return value < 0 then it indicates str1 is less than str2

•if return value > 0 then it indicates str2 is less than str1

comparing strings (cont'd)

•the stremp() function compares strings until it finds corresponding characters that differ

• could take the search to the end of one of the strings

• the strncmp() function compares the strings until they differ or until it has compared a number of characters

specified by a third argument

•if you wanted to search for strings that begin with "astro", you could limit the search to the first five characters

if (strncmp ("astronomy", "astro", 5) =:

= 0)

{

printf("Found: astronomy");

if (strncmp ("astounding" ,"astro", 5) == 0)

{

printf("Found: astounding");

Overview

•lets discuss some more string functions

•searching a string

•the string.h header file declares several string-searching functions for finding a single character or

a substring

• strchr() and strstr()

•tokenizing a string

•a token is a sequence of characters within a string that is bounded by a delimiter (space, comma,

period, etc)

•breaking a sentence into words is called tokenizing

• Strtok()

•analyzing strings

•slower(), supper(), isalpha(), isdigit(), etc.

concept of a pointer

• we are going to discuss in detail, the concept of a pointer in an upcoming section

• however, in order to understand some of these string functions, I want to give you a quick peek on this concept

• C provides a remarkably useful type of variable called a pointer

• a variable that stores an address

• its value is the address of another location in memory that can contain a value

• we have used addresses in the past with the scanf() function

int Number = 25;

int *Number = &Number;

• above, we declared a variable, Number, with the value 25

• we declared a pointer, Number, which contains the address of Number

• asterisk used in declaring a pointer

• to get the value of the variable Number, you can use the asterisk to dereference the pointer

*Number = 25

• * is the dereference operator, and its effect is to access the data stored at the address specified by a pointer

![](https://app.yinxiang.com/shard/s46/res/5a5c1891-1ad1-4cbe-8a2e-e13f8333a443/IMG_0169.JPEG?resizeSmall&width=813 "Attachment")

•the value of &Number is the address where

Number is located

•this value is used to initialize Number in the

second statement

Value

25

1000

•many of the string functions return pointers

•this is why I wanted to briefly mention them

• do not worry if this concept does not sink in

right now, we are going to cover points in a ton

of detail in an upcoming section

Searching a string for a character

•the strchr() function searches a given string for a specified character

•first argument to the function is the string to be searched (which will be the address of a char array)

•second argument is the character that you are looking for

•the function will search the string starting at the beginning and return a pointer to the first position in

the string where the character is found

• the address of this position in memory

•is of type char* described as the

"pointer to char."

•to store the value that's returned, you must create a variable that can store the address of a

character

•if the character is not found, the function returns a special value NULL

•NULL is the equivalent of O for a pointer and represents a pointer that does not point to anything

strehr()

•you can use the strchr() function like this

char stri] = "The quick brown fox":

char ch = 'q';

char *Got char = NULL;

pGot_ char = strchr(str, ch);

I1 The string to be searched

I/ The character we are looking for

I/ Pointer initialized to NULL

I/ Stores address where ch is found

•the first argument to strchr() is the address of the first location to be searched

•second argument is the character that is sought (ch, which is of type char)

• expects its second argument to be of type int, so the compiler will convert the value of ch to this

type

•could just as well define ch as type int (int ch = 'q':)

•Got char will point to the value ("quick brown fox")

searching for a substring

• the strstr() function is probably the most useful of all the searching functions

• searches one string for the first occurrence of a substring

• returns a pointer to the position in the first string where the substring is found

• if no match, returns NULL

• the first argument is the string that is to be searched

• the second argument is the substring you're looking for

char text] = "Every dog has his day",

char word] =

"dog":

char *Found = NULL;

pFound = strstr(text, word);

• searches text for the first occurrence of the string stored in word

• the string "dog" appears starting at the seventh character in text

• Found will be set to the address text + 6 ("dog has his day")

• search is case sensitive, "Dog" will not be found

Tokenizing a string

• a token is a sequence of characters within a string that is bound by a delimiter

• a delimiter can be anything, but, should be unique to the string

•spaces, commas, and a period are good examples

•breaking a sentence into words is called tokenizing

•the strtok() function is used for tokenizing a string

•It requires two arguments

•string to be tokenized

•a string containing all the possible delimiter characters

strtok example

int main () {

char str[80] = "Hello how are you - my name is - jason";

const char s[2] = ".";

char *token;

I* get the first token */

token = strtok(str, s);

I* walk through other tokens */

while( token != NULL) {

printf(" %sln", token );

token = strtok(NULL, s);

1

return(0);

![](https://app.yinxiang.com/shard/s46/res/2a8a711f-989e-46af-b21b-8cec151cc4e6/IMG_0170.JPEG?resizeSmall&width=813 "Attachment")

• the argument to each of these

functions is the character to be tested

• all these functions return a nonzero

value of type int if the character is

within the set that's being tested for

isblank()

• these return values convert to true

and false, respectively, so you can use

them as Boolean values.

Converting Strings

• it is very common to convert character case

• to all upper case or all lower case

• the toupper() function converts from lowercase to uppercase

• the tolower() function converts from uppercase to lowercase

• both functions return either the converted character or the same character for characters that are already in the correct case or are not

convertible such as punctuation characters

• this is how you convert a string to uppercase

for(int i = 0 ; (buffi] = (char)toupper(buffi])) != '10' ; ++i);

• this loop will convert the entire string in the buf array to uppercase by stepping through the string one character at a ti

• loop stops when it reaches the string termination character 10

• the cast to type char is there because toupper() returns type int

• you can use the function topper() in combination with the strstr() function to find out whether one string occurs in another, ignoring

case

Case conversion example

char text[100];

char substring[40];

/l Input buffer for string to be searched

I Input buffer for string sought

printf("Enter the string to be searched (less than %d characters): In", 100);

scanf("%s", text);

printf("InEnter the string sought (less than %d characters): In", 40);

scanf("%s", substring);

printf("'InFirst string entered:In%sln", text);

print("Second string entered: In%sIn", substring);

I Convert both strings to uppercase.

for(i = 0 ; (text[i] = (char )toupper(text[i])) != '10' ; ++i);

for(i = 0 ; (substring[i] = (char )toupper(substring[i])) != '10' ; ++i);

printf("The second string %s found in the first. In", ((strstr(text, substring) == NULL) ? "was not : "was"));

the stdlib.h header file declares functions that you can use to convert a string to a numerical value

![](https://app.yinxiang.com/shard/s46/res/e2c9c183-abc6-4aef-8bc6-d6aee0e880ba/IMG_0171.JPEG?resizeSmall&width=813 "Attachment")

Taken from Beginning C,

Horton

For all four functions, leading

whitespace is ignored

char value stril = "98.4";

double value = atof(value str);

![](https://app.yinxiang.com/shard/s46/res/e89b8a96-40b9-4304-acb9-5fe25f632257/IMG_0172.JPEG?resizeSmall&width=813 "Attachment")

Example

double value = 0;

char stri] = "3.5 2.5 1.26".

char *pstr = str;

char *ptr = NULL;

I The string to be converted

I/ Pointer to the string to be converted

/I Pointer to character position after conversion

while (true)

{

value = strtod(pstr, &ptr); // Convert starting at pstr

if(pstr == ptr)

/I pstr stored if no conversion.

break;

//..so we are done

else

{

printf(" %f", value);

pstr = ptr;

I/ Output the resultant value

I Store start for next conversion

Requirements

• In this challenge, you are going to write a program that tests your understanding of char arrays

• write a function to count the number of characters in a string (length)

• cannot use the strlen library function

• function should take a character array as a parameter

• should return an int (the length)

• write a function to concatenate two character strings

• cannot use the streat library function

• function should take 3 parameters

• char resulti

• const char str1l

• const char str20

• can return void

• write a function that determines if two strings are equal

• cannot use stremp library function

• function should take two const char arrays as parameters and return a Boolean of true if they are equal and false otherwise

Requirements

•this challenge will help you better understand how to use the most common string functions in the

string library

•write a program that displays a string in reverse order

•should read input from the keyboard

•need to use the strlen string function

•write a program that sorts the strings of an array using a bubble sort

•need to use the stremp and stropy functions

Input number of strings :3

Input string 3 :

zero

one

two

Expected Output :

The strings appears after sorting:

one

two

zero
