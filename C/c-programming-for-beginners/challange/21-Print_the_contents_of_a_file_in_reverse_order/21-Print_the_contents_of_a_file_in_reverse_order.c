/**
 * @file 21-Print_the_contents_of_a_file_in_reverse_order.c
 * @author gabbi (gabbi.huang@outlook.com)
 * @brief to print the contents of a file in reverse order
 * @date 2022-09-09
 * 
 * 在afa的辅助下完成的，对fseek的概念理解的不太准确，需要加强！
 */

#include <stdio.h>
#include <stdlib.h>
#define FILENAME "file.txt"

int main()
{
    FILE *pfile = NULL;
    int len = 0;
    char mchar;

    //open the file
    pfile = fopen(FILENAME, "r");
    if (pfile == NULL)
    {
        printf("Error in openning file.");
        return (-1);
    }
    
    //access the data in the end
    fseek(pfile, 0, SEEK_END);

    //to know the position of the end
    len = ftell(pfile);


    //display the file in the reverse order
    for (int i = len; i > 0; i--)
    {
        fseek(pfile, i-1, SEEK_SET);
        mchar = fgetc(pfile);
        printf("%c", mchar);
    }
    
    // close the file
    fclose(pfile);

    return 0;    
}