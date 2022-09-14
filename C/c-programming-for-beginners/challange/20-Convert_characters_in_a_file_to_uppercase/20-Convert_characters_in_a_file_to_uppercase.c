/**
 * @file 20-Convert_characters_in_a_file_to_uppercase.c
 * @author gabbi (gabbi.huang@outlook.com)
 * @brief to convert all characters of a file to uppercase and write the results out to a temporary file
 * @date 2022-09-09
 * 
 * 独立完成，独立debug！真开心！
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main (void)
{
    FILE *pfile = NULL;
    FILE *ptemFile = NULL;
    int mchar = 0;

    //open the file
    pfile = fopen("file.txt", "r");
    ptemFile = fopen("temFile.txt", "w");
    if (pfile == NULL || ptemFile == NULL)
    {
        printf("Error in opening file.");
        return (-1);
    }

    //uppercase all the characters
    while ((mchar = fgetc(pfile)) != EOF)
    {
        if (islower(mchar))
        {
            fputc(mchar - 32, ptemFile);
        }
        
        else
        {
            fputc(mchar, ptemFile);
        }
    }
    
    //rename the temFile to file
    if (rename("temFile.txt", "file.txt"))
    {
        printf("Failed to rename file.");
    }

    //close all the file
    fclose(pfile);
    pfile = NULL;
    fclose(ptemFile);
    ptemFile = NULL;

    //display the result
    pfile = fopen("file.txt", "r");
    while ((mchar = fgetc(pfile)) != EOF)
    {
        printf("%c", mchar);
    }

    //close thr file
    fclose(pfile);
    pfile = NULL;   

    return 0;

}