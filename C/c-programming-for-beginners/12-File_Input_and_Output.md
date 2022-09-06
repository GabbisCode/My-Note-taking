Overview

• up until this point, all data that our program accesses is via memory

•scope and variety of applications you can create is limited

• all serious business applications require more data than would fit into main memory

• also depend on the ability to process data that is persistent and stored on an external device

such as a disk drive

•C provides many functions in the header file stdio.h for writing to and reading from external devices

• the external device you would use for storing and retrieving data is typically a disk drive

•however, the library will work with virtually any external storage device

• with all the examples up to now, any data that the user enters is lost once the program ends

• if the user wants to run the program with the same data, he or she must enter it again each time

• very inconvenient and limits programming

• referred to as volatile memory

Files

•programs need to store data on permanent storage

•non-volatile

• continues to be maintained after your computer is turned off

• a file can store non-volatile data and is usually stored on a disk or a solid-state device

•a named section of storage

•stdio.h is a file containing useful information

•C views a file as a continuous sequence of bytes

•each byte can be read individually

•corresponds to the file structure in the Unix environment

![](https://app.yinxiang.com/shard/s46/res/a4d149bf-1bc8-4338-ab80-8cfc85cdc9f5/Image%2020220906%20113200.png?resizeSmall&width=813 "Attachment")

• a file has a beginning and an end and a current position (defined as so many bytes from the

beginning)

• the current position is where any file action (read/write) will take place

• you can move the current position to any point in the file (even the end)

Text and binary files

•there are two ways of writing data to a stream that represents a file

•text

• binary

•text data is written as a sequence of characters organized as lines (each line ends with a newline)

•binary data is written as a series of bytes exactly as they appear in memory

•image data, music encoding - not readable

• you can write any data you like to a file

• once a file has been written, it just consists of a series of bytes

• you have to understand the format of the file in order to read it

• a sequence of 12 bytes in a binary file could be 12 characters, 12 8-bit signed integers, 12 8-bit

unsigned integers, etc.

•in binary mode, each and every byte of the file is accessible

Streams

• C programs automatically open three files on your behalf

• standard input - the normal input device for your system, usually your keyboard

• standard output - usually your display screen

• standard error - usually your display screen

• standard input is the file that is read by getchar() and scanf()

• standard output is used by putchar(), puts(), and printf()

• redirection causes other files to be recognized as the standard input or standard output.

• the purpose of the standard error output file is to provide a logically distinct place to send error messages

• a stream is an abstract representation of any external source or destination for data

• the keyboard, the command line on your display, and files on a disk are all examples of things you can work with

as streams

• the C library provides functions for reading and writing to or from data streams

• you use the same input/output functions for reading and writing any external device that is mapped to a stream

Accessing Files

• files on disk have a name and the rules for naming files are determined by your operating system

• You may have to adjust the names depending on what OS your program is running

• a program references a file through a file pointer (or stream pointer, since it works on more than a file)

• you associate a file pointer with a file programmatically when the program is run

• pointers can be reused to point to different files on different occasions

• a file pointer points to a struct of type FILE that represents a stream

• contains information about the file

•whether you want to read or write or update the file

• the address of the buffer in memory to be used for data

• a pointer to the current position in the file for the next operation

•the above is all set via input/output file operations

• if you want to use several files simultaneously in a program, you need a separate file pointer for each file

• there is a limit to the number of files you can have open at one time

• defined as FOPEN MAX in stdio.h

Opening a File

• you associate a specific external file name with an internal file pointer variable through a process referred to as opening a file

• via the fopen() function

• returns the file pointer for a specific external file

• the fopen() function is defined in stdio.h

FILE *open(const char * restrict name, const char * restrict mode);

• The first argument to the function is a pointer to a string that is the name of the external file you want to process

• you can specify the name explicitly or use a char pointer that contains the address of the character string that defines the file name

• you can obtain the file name through the command line, as input from the user, or defined as a constant in your program

• the second argument to the fopen() function is a character string that represents the file mode

• specifies what you want to do with the file

• a file mode specification is a character string between double quotes

• assuming the call to fopen() is successful, the function returns a pointer of type FILE* that you can use to reference the file in further

input/output operations using other functions in the library

• if the file cannot be opened for some reason, fopen() returns NULL

![](https://app.yinxiang.com/shard/s46/res/53883153-f60d-4159-bf8e-e904a58f7eb5/Image%2020220906%20113529.png?resizeSmall&width=813 "Attachment")

Write Mode

• If you want to write to an existing text file with the name myfile.txt

FILE *pfile = NULL;

char *filename = "myfile.text".

pfile = fopen(filename, "W"); // Open myfile. txt to write it

If(pfile != NULL)

printf("Failed to open %s.In", filename);

• opens the file and associates the file with the name myfile.txt with your file pointer pfile

• the mode as "w" means you can only write to the file

• you cannot read it

• If a file with the name myfile.txt does not exist. the call to fopen() will create a new file with this name

• if you only provide the file name without any path specification, the file is assumed to be in the current directory

• you can also specify a string that is the full path and name for the file

• on opening a file for writing, the file length is truncated to zero and the position will be at the beginning of any existing data for the first operation

• any data that was previously written to the file will be lost and overwritten by any write operations

Append Mode

•If you want to add to an existing text file rather than overwrite it

•specify mode "a"

•the append mode of operation.

•this positions the file at the end of any previously written data

•If the file does not exist, a new file will be created

pFile = fopen("myfile.txt", "a"); // Open myfile. txt to add to it

• do not forget that you should test the return value for null each time

•when you open a file in append mode

•all write operations will be at the end of the data in the file on each write operation

• all write operations append data to the file and you cannot update the existing contents in this

mode

Read Mode

•if you want to read a file

•open it with mode argument as "p"

•you can not write to this file

pFile = fopen("myfile.txt", "r"):

•this positions the file to the beginning of the data

•if you are going to read the file

•it must already exist

•If you try to open a file for reading that does not exist, fopen() will return a file pointer of NULL

•you always want to check the value returned from fopen

Renaming a file

• renaming a file is very easy

• use the rename() function

int rename(const char *oldname, const char *newname);

• the integer that is returned will be O if the name change was successful and nonzero otherwise

• the file must not be open when you call rename(), otherwise the operation will fail

if(rename ( "C:Iltempllmyfile.txt", "C:Iltempl\myfile_copy.txt"))

printf("Failed to rename file.");

else

printf("File renamed successfully.");

• this will change the name of myfile. txt in the temp directory on drive C to myfile copy.txt

• if the file path is incorrect or the file does not exist, the renaming operation will fail

Closing a file

• when you have finished with a file, you need to tell the operating system so that it can free up the file

• you can do this by calling the close() function

• close() accepts a file pointer as an argument

• returns EOF (int) if an error occurs

• OF is a special character called the end-of-file character

• defined in stdio.h as a negative integer that is usually equivalent to the value -1

• O if successful

fclose(pfile);

pfile = NULL:

I Close the file associated with pfile

• the result of calling close() is that the connection between the pointer, pfile, and the physical file is broken

• pfile can no longer be used to access the file

• if the file was being written, the current contents of the output buffer are written to the file to ensure that data is not lost

• It is good programming practice to close a file as soon as you have finished with it

• protects against output data loss

Deleting a file

•you can delete a file by invoking the remove() function

•declared in stdio.h

remove("myfile.txt");

• will delete the file that has the name myfile. txt from the current directory

•the file cannot be open when you try to delete it

•you should always double check with operations that delete files

•you could wreck your system if you do not

Reading characters from a text file

• the fgetc() function reads a character from a text file that has been opened for reading

•takes a file pointer as its only argument and returns the character read as type int

int mchar = fgetc(pfile);

// Reads a character into mchar with pfile a File pointer

• the mchar is type int because EOF will be returned if the end of the file has been reached

• the function getc(), which is equivalent to fgetc(), is also available

• requires an argument of type FILE* and returns the character read as type int

• virtually identical to fgetc()

• only difference between them is that getc() may be implemented as a macro, whereas fgetc() is a function

• you can read the contents of a file again when necessary

• the rewind() function positions the file that is specified by the file pointer argument at the beginning

rewind (pfile);

Example

#include <stdio.h>

int main () {

FILE *fp;

int C;

fp=fopen("file.txt","'");

if(fp == NULL)

perror("Error in opening file");

return(-1);

Il read a single char

while((c = fgetc(p)) != EOF)

printf("%c", C);

fclose(fp);

fp = NULL;

return(0);

} // return from main

Reading a string from a text file

•you can use the gets() function to read from any file or stream

char *gets(char *str, int nchars, FILE *stream)

•the function reads a string into the memory area pointed to by str, from the file specified by stream

•characters are read until either a '\n' is read or nchars-1 characters have been read from the

stream, whichever occurs first

•if a newline character is read, it's retained in the string

• a 10' character will be appended to the end of the string

•if there is no error, fgets) returns the pointer, str

•if there is an error, NULL is returned

•reading EOF causes NULL to be returned

Example

#include <stdio.h>

int main () {

FILE *fp;

char str[601;

/* opening file for reading */

fp = fopen("file.txt", "r");

if(fp == NULL) f

perror("Error opening file");

return(-1);

if( gets (str, 60, fp)!=NULL)f

/* writing content to stdout*/

printf("%S", Str);

1

fclose(fp);

fo = NULL:

return(0);

1 // end main

Reading formatted input from a file

•you can get formatted input from a file by using the standard fscanf() function

int fscanf(FILE *stream, const char *format, ...)

• the first argument to this function is the pointer to a FILE object that identifies the stream

•the second argument to this function is the format

•a C string that contains one or more of the following items

•whitespace character

• non-whitespace character

•format specifiers

•usage is similar to scanf, but, from a file

Overview

#include <stdio.h>

#include <stdlib.h>

int main () {

char str1[10], str2[10], str3[10];

int year;

FILE * fp;

fp = fopen ("file.txt", "w+");

if (fp != NULL)

fputs("Hello how are you", fp);

rewind(fp);

fscanf(fp, "%s %s %s %d", str1, str2, str3, &year);

printf("Read String1 (%s/In", str1 );

printf("Read String2 I%s/In", str2 );

printf("Read String3 I%s/In", str3 );

printf("Read Integer I%d/In", year );

fclose(fp);

return(0);

} // end of main

Writing characters to a text file

the simplest write operation is provided by the function fputc()

writes a single character to a text file

int fputc(int ch, FILE *pfile);

the function writes the character specified by the first argument to the file identified by the second argument (file pointer)

returns the character that was written if successful

Return OF if failure

In practice, characters are not usually written to a physical file one by one

extremely inefficient

the putc() function is equivalent to fputc()

requires the same arguments and the return type is the same

difference between them is that putc() may be implemented in the standard library as a macro, whereas fputc() is a

function

Example

#include <stdio.h>

int main 0) {

FILE *fp;

int ch;

fp = fopen("file.txt", "W+");

for( ch = 33; ch <= 100; ch++ ) {

fputc(ch, fp);

}

fclose(fp);

return(0);

Writing a string to a text file

• you can use the fputs() function to write to any file or stream

int fputs(const char * str, FILE * pfile);

• the first argument is a pointer to the character string that is to be written to the file

• the second argument is the file pointer

• this function will write characters from a string until it reaches a '10' character

• does not write the null terminator character to the file

can complicate reading back variable-length strings from a file that have been

written by fouts()

• expecting to write a line of text that has a newline character at the end

Example

#include <stdio.h>

int main 0) {

FILE *filePointer:

filePointer = fopen("file.txt", "W+");

puts("This is Jason Fedin Course.", filePointer);

fputs("I am happy to be here", filePointer);

fclose(filePointer);

return(O);

Writing formatted output to a file

the standard function for formatted output to a stream is forintf()

int fprintf(FILE *stream, const char *format, ...)

the first argument to this function is the pointer to a FILE object that identifies the stream

the second argument to this function is the format

a C string that contains one or more of the following items

whitespace character

non-whitespace character

format specifiers

usage is similar to printf, but, to a file

if successful, the total number of characters written is returned otherwise, a negative number is returned

Example

#include <stdio.h>

#include <stdlib.h>

int main () {

FILE * fp;

fp = fopen ("file.txt", "W+");

fprintf(fp, "%s %s %s %s %d", "Hello", "my", "number", "is", 555);

fclose(fp);

return(0);

File Positioning

•for many applications, you need to be able to access data in a file other than sequential

order

•there are various functions that you can use to access data in random sequence

•there are two aspects to file positioning

•finding out where you are in a file

•moving to a given point in a file

•you can access a file at a random position regardless of whether you opened the file

Finding out where you are

•you have two functions to tell you where you are in a file

•ftell®)

•fgetpos()

long fell(FILE *pfile);

•this function accepts a file pointer as an argument and returns a long integer value

that specifies the current position in the file

long fpos = fell (pfile);

•the fpos variable now holds the current position in the file and you can use this to

return to this position at any subsequent time

•value is the offset in bytes from the beginning of the file

fell() example

FILE *fp;

int len;

fp = fopen("file.txt", "r");

if( fp == NULL) {

perror ("Error opening file");

return(-1);

fseek(fp, 0, SEEK END);

len = (tell(tp);

fclose(fp);

printf/"Total size of file. txt = %d bytesIn", len);

getpos()

• the second function providing information on the current file position is a little more complicated

int fgetpos(FILE * pfile, fpos_‡* position);

• the first parameter is a file pointer

• the second parameter is a pointer to a type that is defined in stdio.h

• fpos t- a type that is able to record every position within a file

• the fgetpos() function is designed to be used with the positioning function fsetpos()

• the fgetpos() function stores the current position and file state information for the file in position and returns 0 if the operation is successful

• returns a nonzero integer value for failure

fpos there;

fgetpos(pfile,&here);

• the above records the current file position in the variable here

• you must declare a variable of type fpos_t

• cannot declare a pointer of type fpost* because there will not be any memory allocated to store the position data

fgetpos() example

FILE *fp:

fpos t position;

fp = fopen("file.txt" ."W+");

fgetpos(fp,&position);

fputs("Hello, World!", fp);

fclose(fp);

Setting a position in a file

• as a complement to fell(), you have the seek() function

int fseek(FILE *pfile, long offset, int origin);

• the first parameter is a pointer to the file you are repositioning

• the second and third parameters define where you want to go in the file

• second parameter is an offset from a reference point specified by the third parameter

• reference point can be one of three values that are specified by the predefined names

• SEEK_SET - defines the beginning of the file

• SEEK CUR - defines the current position in the file

• SEEK END - defines the end of the file

• for a text mode file, the second argument must be a value returned by ftell()

• the third argument for text mode files must be SEEK SET.

• for text files, all operations with seek() are performed with reference to the beginning of the file

• for binary files, the offset argument is simply a relative byte count

• can therefore supply positive or negative values for the offset when the reference point is specified as SEEK CUR

seek() example

#include <stdio.h>

int main () {

FILE *fp;

fo = fopen("file.txt"."W+");

fouts ("This is Jason", fp);

fseek( fp, 7, SEEK SET );

fouts(" Hello how are you", fp);

fclose(fp);

return(0);

fsetpos()

• you have the fsetpos() function to go with fgetpos()

int fsetpos(FILE *pfile, const fpos t *position);

• the first parameter is a pointer to the open file

• the second is a pointer of the fpos_t type

• the position that is stored at the address was obtained by calling fgetpos()

fsetpos(pfile,&here);

• the variable here was previously set by a call to fgetpos()

•the fsetpos() returns a nonzero value on error or 0 when it succeeds

• this function is designed to work with a value that is returned by fgetpos()

• you can only use it to get to a place in a file that you have been before

• seek() allows you to go to any position just by specifying the appropriate offset

fgetpos() example

#include <stdio.h>

int main () {

FILE *fp;

fpos_t position;

p = fopen("file.txt","W+");

fgetpos(fp,&position);

fouts("Hello, World!", fp);

fsetpos(fp,&position);

fouts("This is going to override previous content", fp);

fclose(fp);

return(0);

Requirements

•write a program to find the total number of lines in a text file

•create a file that contains some lines of text

•open your test file

•use the fetc function to parse characters in a file until you get to the EOF

•If EOF increment counter

•display as output the total number of lines in the file

Requirements

•write a program that converts all characters of a file to uppercase and write the results out to a

temporary file. Then rename the temporary file to the original filename and remove the temporary

filename

•use the fgetc and fputc functions

•use the rename and remove functions

•use the slower function

•can covert a character to upper case by subtracting 32 from it

•display the contents of the original file to standard output

•in uppercase

Requirements

•write a program that will print the contents of a file in reverse order

• use the seek function to seek to the end of the file

•use the fell function to get the position of the file pointer

•display as output the file in reverse order
