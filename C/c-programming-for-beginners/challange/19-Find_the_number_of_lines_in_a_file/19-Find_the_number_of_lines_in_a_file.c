/**
 * @file 19-Find_the_number_of_lines_in_a_file.c
 * @author gabbi (gabbi.huang@outlook.com)
 * @brief to find the total number of lines in a text file
 * @date 2022-09-07
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp = NULL;
    int c = 0;
    int line = 1;

    fp = fopen("test.txt", "r");

    if (fp == NULL)
    {
        perror("Error in opening file");
        return (-1);
    }

    while ((c = fgetc(fp)) != EOF)
    {
        if (c == '\n')
        {
            ++line;
        }
        
    }
    
    printf("The number of line in this file is %d.\n", line);

    return 0;
}

/****************************************
 * 开了的file记得要关闭，不要忘记fclose(),
 * 以及把pointer fp设置成NULL！！！ 
 *****************************************/