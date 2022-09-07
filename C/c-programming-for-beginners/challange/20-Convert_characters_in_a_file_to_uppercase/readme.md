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

Codes by Jason

```c
#include <stdio.h>
#include <stdlib.h>

#define FILENAME "Test.txt"

int main()
{
    FILE *fp = NULL;
    FILE *fp1 = NULL;

    char ch = ' ';

    fp = fopen(FILENAME, "r");

    if (fp == NULL)
        return -1;

    // create a temp file
    fp1 = fopen("temp.txt", "w");

    if (fp1 == NULL)
        return -1;

    while ((ch = fgetc(fp)) != EOF)
    {
        if (islower(ch))
        {
            ch = ch-32;
        }

        fputc(ch, fp1);
    }

    fclose(fp);
    fclose(fp1);

    remove(FILENAME);

    // rename temp file to Test.txt file
    rename("temp.txt", FILENAME);

    // remove the temp file
    remove("temp.txt");

    fp = fopen(FILENAME, "r");

    if (fp == NULL)
        return -1;

    while ((ch =fgetc(fp)) != EOF)
        printf("%c", ch);


    fclose(fp);
    fp = NULL;
    fp1 = NULL;

    return 0;
}

```
