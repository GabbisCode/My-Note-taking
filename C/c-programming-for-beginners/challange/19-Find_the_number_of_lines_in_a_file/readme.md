## Requirements

•write a program to find the total number of lines in a text file

•create a file that contains some lines of text

•open your test file

•use the fetc function to parse characters in a file until you get to the EOF

•If EOF increment counter

•display as output the total number of lines in the file

## Codes by Jason

```c
#include <stdio.h>
#include <stdlib.h>

#define FILENAME "Test.txt"

int main()
{
    FILE *fp = NULL;
    char ch;
    int linesCount = 0;

    fp = fopen(FILENAME, "r");

    if(fp == NULL)
    {
        printf("File does not exist\n");
        return -1;
    }

    while((ch=fgetc(fp))!= EOF)
    {
        if(ch=='\n')
            linesCount++;
    }

    fclose(fp);
    fp = NULL;

    printf("Total number of lines are: %d\n", ++linesCount);

    return 0;
}
```
