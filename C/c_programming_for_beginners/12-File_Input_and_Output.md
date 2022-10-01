# 12-File_Input_and_Output

## Overview

Up until this point, all data that our program accesses is via memory, however, the scope and variety of applications you can create is limited.

All serious business applications require more data than would fit into main memory and also depend on the ability to process data that is persistent and stored on an external device such as a disk drive.

C provides many functions in the header file stdio.h for writing to and reading from external devices. The external device you would use for storing and retrieving data is typically a disk drive. However, the library will work with virtually any external storage device.

With all the examples up to now, any data that the user enters is lost once the program ends. If the user wants to run the program with the same data, he or she must enter it again each time. It's very inconvenient and limits programming. This referred to as volatile memory.

### Files

Programs need to store data on permanent storage. This refers to non-volatile memory, which continues to be maintained after your computer is turned off.

A file can store non-volatile data and is usually stored on a disk or a solid-state device. It's a named section of storage. stdio.h is a file containing useful information.

C views a file as a continuous sequence of bytes. And each byte can be read individually. This corresponds to the file structure in the Unix environment.

![image](image/File_Input_and_Output1.png)

A file has a beginning and an end and a current position (defined as so many bytes from the

beginning). The current position is where any file action (read/write) will take place. You can move the current position to any point in the file (even the end).

### Text and binary files

There are two ways of writing data to a stream that represents a file: text and binary.

Text data is written as a sequence of characters organized as lines (each line ends with a newline).

Binary data is written as a series of bytes exactly as they appear in memory. Example files are image data, music encoding. Binary file is not readable.

You can write any data you like to a file. Once a file has been written, it just consists of a series of bytes.

You have to understand the format of the file in order to read it. A sequence of 12 bytes in a binary file could be 12 characters, 12 8-bit signed integers, 12 8-bit unsigned integers, etc. In binary mode, each and every byte of the file is accessible.

### Streams

A stream can represent a file, but a stream is a more generic term that can represent any kind of input. So it could represent the keyboard, it could represent the console, it could represent a file, it could represent a socket. If you're used to networking, streams are a more generic term.

C programs automatically open three files (streams) on your behalf.

* standard input - the normal input device for your system, usually your keyboard
* standard output - usually your display screen
* standard error - usually your display screen

Standard input is the file that is read by getchar() and scanf(). Standard output is used by putchar(), puts(), and printf().

You can also redirect files on the system to be recognized as a standard input and output. This is redirection, this is an operating system concept where you can redirect data, send the output to a file, for example, or get input from a file as opposed to standard archive. Redirection causes other files to be recognized as the standard input or standard output.

The purpose of the standard error output file is to provide a logically distinct place to send error messages.

A stream is an abstract representation of any external source or destination for data, the keyboard, the command line on your display, and files on a disk are all examples of things you can work with as streams. The C library provides functions for reading and writing to or from data streams. You use the same input/output functions for reading and writing any external device that is mapped to a stream.

## Accessing Files

Files on disk have a name and the rules for naming files are determined by your operating system. You may have to adjust the names depending on what OS your program is running.

A program references a file through a file pointer (or stream pointer, since it works on more than a file). You associate a file pointer with a file programmatically when the program is run. Pointers can be reused to point to different files on different occasions.

A file pointer points to a struct of type FILE that represents a stream, which contains information about the file, whether you want to read or write or update the file; the address of the buffer in memory to be used for data; a pointer to the current position in the file for the next operation. The above is all set via input/output file operations.

If you want to use several files simultaneously in a program, you need a separate file pointer for each file. There is a limit to the number of files you can open at one time, which defined as FOPEN_MAX in stdio.h.

### Opening a File

You associate a specific external file name with an internal file pointer variable through a process referred to as opening a file via the fopen() function. It returns the file pointer for a specific external file. The fopen() function is defined in stdio.h

```c
FILE *fopen(const char * restrict name, const char * restrict mode);
```

The 1st argument to the function is a pointer to a string that is the name of the external file you want to process. You can specify the name explicitly or use a char pointer that contains the address of the character string that defines the file name. You can obtain the file name through the command line, as input from the user, or defined as a constant in your program.

The 2nd argument to the fopen() function is a character string that represents the file mode This specifies what you want to do with the file. A file mode specification is a character string between double quotes.

Sssuming the call to fopen() is successful, the function returns a pointer of type FILE* that you can use to reference the file in further input/output operations using other functions in the library. If the file cannot be opened for some reason, fopen() returns NULL

### File Modes (only apply to text files)

| Mode | Description                                                                                                                                        |
| ---- | -------------------------------------------------------------------------------------------------------------------------------------------------- |
| "w"  | Open a text file for write operations. If the file exists, its current contents are discarded.                                                    |
| "a"  | Open a text file for append operations. All writes are to the end of the file.                                                                    |
| "r"  | Open a text file for read operations.                                                                                                              |
| "w+" | Open a text file for update (reading and writing), first truncating the file to zero length if it exists or creating the file it it does not exist |
| "a+" | Open a text file for update (reading and writing) appending to the end of the existing file, or creating the file if it does not yet exist.        |
| "r+" | Open a text file for update (for both reading and writing)                                                                                         |

### Write Mode

If you want to write to an existing text file with the name myfile.txt

```c
FILE *pfile = NULL;
char *filename = "myfile.text";
pfile = fopen(filename, "w"); // Open myfile. txt to write it
if(pfile == NULL)
	printf("Failed to open %s.\n", filename);
```

It opens the file and associates the file with the name myfile.txt with your file pointer pfile. The mode as "w" means you can only write to the file and you cannot read it.

If a file with the name myfile.txt does not exist. the call to fopen() will create a new file with this name.

If you only provide the file name without any path specification, the file is assumed to be in the current directory. You can also specify a string that is the full path and name for the file.

On opening a file for writing, the file length is truncated to zero and the position will be at the beginning of any existing data for the first operation. Any data that was previously written to the file will be lost and overwritten by any write operations.

### Append Mode

If you want to add to an existing text file rather than overwrite it, you can specify mode "a", the append mode of operation.

This positions the file at the end of any previously written data. If the file does not exist, a new file will be created.

```c
pFile = fopen("myfile.txt", "a"); // Open myfile. txt to add to it
```

Do not forget that you should test the return value for null each time.

When you open a file in append mode, all write operations will be at the end of the data in the file on each write operation. All write operations append data to the file and you cannot update the existing contents in this mode.

### Read Mode

If you want to read a file, open it with mode argument as "r". You can not write to this file.

```c
pFile = fopen("myfile.txt", "r"):
```

This positions the file to the beginning of the data

If you are going to read the file, it must already exist. If you try to open a file for reading that does not exist, fopen() will return a file pointer of NULL.

You always want to check the value returned from fopen.

### Renaming a file

Renaming a file is very easy. You just use the rename() function.

```c
int rename(const char *oldname, const char *newname);
```

The integer that is returned will be 0 if the name change was successful and nonzero otherwise. The file must not be open when you call rename(), otherwise the operation will fail.

```c
if(rename ( "C:\\temp\\myfile.txt", "C:\\temp\\myfile_copy.txt"))
	printf("Failed to rename file.");
else
	printf("File renamed successfully.");
```

This will change the name of myfile. txt in the temp directory on drive C to myfile copy.txt. If the file path is incorrect or the file does not exist, the renaming operation will fail.

### Closing a file

When you have finished with a file, you need to tell the operating system so that it can free up the file. You can do this by calling the fclose() function.

fclose() accepts a file pointer as an argument. It returns EOF (int) if an error occurs. EOF is a special character called the end-of-file character. It is defined in stdio.h as a negative integer that is usually equivalent to the value -1. It return 0 if it's successful.

```c
fclose(pfile);  // Close the file associated with pfile
pfile = NULL;
```

The result of calling close() is that the connection between the pointer, pfile, and the physical file is broken. pfile can no longer be used to access the file.

If the file was being written, the current contents of the output buffer are written to the file to ensure that data is not lost.

It is good programming practice to close a file as soon as you have finished with it, because it protects against output data loss. You must also close a file before attempting to rename it or remove it.

### Deleting a file

You can delete a file by invoking the remove() function. It is declared in stdio.h

```c
remove("myfile.txt");
```

This will delete the file that has the name myfile. txt from the current directory. The file cannot be open when you try to delete it.

You should always double check with operations that delete files. You could wreck your system if you do not.

## Reading from a file

### Reading characters from a text file

The fgetc() function reads a character from a text file that has been opened for reading.

The fgetc() function takes a file pointer as its only argument and returns the character read as type int.

```c
int mchar = fgetc(pfile);  // Reads a character into mchar with pfile a File pointer
```

The mchar is type int because EOF will be returned if the end of the file has been reached.

The function getc(), which is equivalent to fgetc(), is also available. It requires an argument of type FILE* and returns the character read as type int. It's virtually identical to fgetc(). The only difference between them is that getc() may be implemented as a macro, whereas fgetc() is a function.

You can read the contents of a file again when necessary. You can use the rewind() function, which positions the file that is specified by the file pointer argument at the beginning:

```c
rewind (pfile);
```

Example

```c
#include <stdio.h>
int main () {
	FILE *fp;
	int c;

	fp=fopen("file.txt","r");

	if(fp == NULL){
		perror("Error in opening file");
		return(-1);
		} // return from main

	// read a single char
	while((c = fgetc(fp)) != EOF)
		printf("%c", c);

	fclose(fp);
	fp = NULL;

	return(0);
```

### Reading a string from a text file

You can use the fgets() function to read from any file or stream.

```c
char *gets(char *str, int nchars, FILE *stream)
```

The function reads a string into the memory area pointed to by str, from the file specified by stream. Characters are read until either a '\n' is read or nchars-1 characters have been read from the stream, whichever occurs first.

If a newline character is read, it's retained in the string. A '\0' character will be appended to the end of the string. If there is no error, fgets() returns the pointer, str. If there is an error, NULL is returned. Reading EOF causes NULL to be returned.

```c
#include <stdio.h>

int main () {
	FILE *fp;
	char str[60];

	/* opening file for reading */
	fp = fopen("file.txt", "r");

	if(fp == NULL) {
		perror("Error opening file");
		return(-1);

	if(fgets (str, 60, fp)!=NULL){
		/* writing content to stdout*/
		printf("%s", str);
		}

	fclose(fp);
	fp = NULL:
	return(0);

	} // end main
```

### Reading formatted input from a file

You can get formatted input from a file by using the standard fscanf() function

```c
int fscanf(FILE *stream, const char *format, ...)
```

The first argument to this function is the pointer to a FILE object that identifies the stream.

The second argument to this function is the format. A C string that contains one or more of the following items:

* whitespace character
* non-whitespace character
* format specifiers
* usage is similar to scanf, but, from a file

```c
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

	printf("Read String1 |%s|\n", str1 );
	printf("Read String2 |%s|\n", str2 );
	printf("Read String3 |%s|\n", str3 );
	printf("Read Integer |%d|\n", year );

	fclose(fp);

	return(0);
	} // end of main
```

## Writing to a file

### Writing characters to a text file

The simplest write operation is provided by the function fputc(), which writes a single character to a text file.

```
int fputc(int ch, FILE *pfile);
```

The function writes the character specified by the first argument to the file identified by the second argument (file pointer). It returns the character that was written if successful and returns EOF if failure.

In practice, characters are not usually written to a physical file one by one. It is extremely inefficient.

The putc() function is equivalent to fputc(). It requires the same arguments and the return type is the same. Thedifference between them is that putc() may be implemented in the standard library as a macro, whereas fputc() is a function.

```c
#include <stdio.h>

int main () {
	FILE *fp;
	int ch;

	fp = fopen("file.txt", "w+");

	for( ch = 33; ch <= 100; ch++ ) {
		fputc(ch, fp);
	}

	fclose(fp);

	return(0);
}
```

### Writing a string to a text file

You can use the fputs() function to write to any file or stream.

```c
int fputs(const char * str, FILE * pfile);
```

The first argument is a pointer to the character string that is to be written to the file. The second argument is the file pointer.

This function will write characters from a string until it reaches a '\0' character. It does not write the null terminator character to the file. It can complicate reading back variable-length strings from a file that have been written by fputs(). It is expected to write a line of text that has a newline character at the end.

```c
#include <stdio.h>

int main 0) {
	FILE *filePointer;

	filePointer = fopen("file.txt", "w+");

	fputs("This is Jason Fedin Course.", filePointer);
	fputs("I am happy to be here", filePointer);

	fclose(filePointer);

	return(0);
}
```

### Writing formatted output to a file

The standard function for formatted output to a stream is fprintf().

```c
int fprintf(FILE *stream, const char *format, ...)
```

The first argument to this function is the pointer to a FILE object that identifies the stream. The second argument to this function is the format.

A C string that contains one or more of the following items:

* whitespace character
* non-whitespace character
* format specifiers
* usage is similar to printf, but, to a file

If successful, the total number of characters written is returned otherwise, a negative number is returned.

```c
#include <stdio.h>
#include <stdlib.h>

int main () {
	FILE * fp = NULL;

	fp = fopen ("file.txt", "w+");

	if(fp != NULL)
		fprintf(fp, "%s %s %s %s %d", "Hello", "my", "number", "is", 555);

	fclose(fp);

	return(0);
}
```

## File Positioning

For many applications, you need to be able to access data in a file other than sequential order. There are various functions that you can use to access data in random sequence.

There are two aspects to file positioning:

* finding out where you are in a file
* moving to a given point in a file

You can access a file at a random position regardless of whether you opened the file.

### Finding out where you are

You have two functions to tell you where you are in a file: ftell() or fgetpos()

#### ftell()

```c
long ftell(FILE *pfile);
```

This function accepts a file pointer as an argument and returns a long integer value that specifies the current position in the file.

```c
long fpos = ftell (pfile);
```

The fpos variable now holds the current position in the file and you can use this to return to this position at any subsequent time. Value is the offset in bytes from the beginning of the file.

```c
FILE *fp;
int len;

fp = fopen("file.txt", "r");
if( fp == NULL) {
	perror ("Error opening file");
	return(-1);
	}

fseek(fp, 0, SEEK_END);

len = ftell(fp);

fclose(fp);

printf("Total size of file.txt = %d bytes\n", len);
```

#### fgetpos()

The second function providing information on the current file position is a little more complicated.

```c
int fgetpos(FILE * pfile, fpos_t* position);
```

The first parameter is a file pointer. The second parameter is a pointer to a type that is defined in stdio.h. fpos_t is a type that is able to record every position within a file.

The fgetpos() function is designed to be used with the positioning function fsetpos().

The fgetpos() function stores the current position and file state information for the file in position and returns 0 if the operation is successful and returns a nonzero integer value for failure.

```c
fpos_t here;
fgetpos(pfile, &here);
```

The above records the current file position in the variable **here**. You must declare a variable of type fpos_t. You cannot declare a pointer of type fpos_t* because there will not be any memory allocated to store the position data.

```c
FILE *fp:
fpos_t position;

fp = fopen("file.txt" ."w+");
fgetpos(fp, &position);
fputs("Hello, World!", fp);

fclose(fp);
```

### Setting a position in a file

#### fseek()

As a complement to ftell(), you have the fseek() function.

```c
int fseek(FILE *pfile, long offset, int origin);
```

The first parameter is a pointer to the file you are repositioning. The second and third parameters define where you want to go in the file. The second parameter is an offset from a reference point specified by the third parameter. The reference point can be one of three values that are specified by the predefined names

* SEEK_SET - defines the beginning of the file
* SEEK_CUR - defines the current position in the file
* SEEK_END - defines the end of the file

For a text mode file, the second argument must be a value returned by ftell().

The third argument for text mode files must be SEEK_SET. For text files, all operations with fseek() are performed with reference to the beginning of the file. For binary files, the offset argument is simply a relative byte count. You can therefore supply positive or negative values for the offset when the reference point is specified as SEEK_CUR.

```c
#include <stdio.h>
int main () {
	FILE *fp;

	fp = fopen("file.txt"."w+");
	fputs ("This is Jason", fp);

	fseek( fp, 7, SEEK_SET );
	fputs(" Hello how are you", fp);
	fclose(fp);

	return(0);
}
```

#### fsetpos()

You have the fsetpos() function to go with fgetpos().

```c
int fsetpos(FILE *pfile, const fpos_t *position);
```

The first parameter is a pointer to the open file. The second is a pointer of the fpos_t type. The position that is stored at the address was obtained by calling fgetpos().

```c
fsetpos(pfile, &here);
```

The variable **here** was previously set by a call to fgetpos().

The fsetpos() returns a nonzero value on error or 0 when it succeeds.

This function is designed to work with a value that is returned by fgetpos(). You can only use it to get to a place in a file that you have been before. fseek() allows you to go to any position just by specifying the appropriate offset.

```c
#include <stdio.h>

int main () {
	FILE *fp;
	fpos_t position;

	fp = fopen("file.txt","w+");
	fgetpos(fp, &position);
	fputs("Hello, World!", fp);

	fsetpos(fp, &position);
	fputs("This is going to override previous content", fp);
	fclose(fp);

	return(0);
}
```
