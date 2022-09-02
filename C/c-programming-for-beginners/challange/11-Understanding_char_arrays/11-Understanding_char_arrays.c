/**
 * @file 11-Understanding_char_arrays.c
 * @author Gabbi (gabbi.huang@outlook.com)
 * @date 2022-08-25
 * 今天的练习很简单，是我独立完成的！开心！
 * afa说我的比对string的function写的不错，是个苗子~被夸了好开心呀~
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int lengthOfString (const char str[]);
void concatString (char result[], const char str1[], const char str2[]);
bool compareString(const char str1[], const char str2[]);

int main(void)  //codes for test of the function
{
    char Happy[] = "Today ";
    int result = lengthOfString(Happy);
    printf("The length of the string is: %d.\n", result);
    return 0;

    // char result[1000];
    // const char str1[] = "Do you happy?\n";
    // const char str2[] = "Yes, I am.";
    // concatString (result, str1, str2);
    // printf("The concatenated string is: \n%s", result);
    // return 0;

    // char str1[] = "Happy";
    // char str2[] = "Happy";
    // int result = compareString(str1, str2);
    // printf("The result is: %d.\n", result);
    // return 0;
}

/**
 * @brief to count the number of characters in a string (length)
 * 
 * @param str a character array
 * @return int the length of a string
 */
int lengthOfString (const char str[])
{
    int length = 0;

    for (int i = 0; str[i] != '\0'; ++i)
    {
        length = i;
    }
    
    return length + 1;    
}

/**
 * @brief to concatenate two character strings
 * 
 * @param result the string that has been concatenated
 * @param str1 
 * @param str2 
 */
void concatString(char result[], const char str1[], const char str2[])
{
    int x, y;
    for (x = 0; str1[x] != '\0'; x++)
    {
        result[x] = str1[x];
    }
    
    for (y = 0; str2[y] != '\0'; y++)
    {
        result[x + y] = str2[y];
    }
    result[x + y] = str2[y];
}

/**
 * @brief to determine if two strings are equal
 * 
 * @param str1 
 * @param str2 
 * @return int 0 = not equal, 1 = equal
 */
bool compareString(const char str1[], const char str2[])
{
    for (int i = 0; str1[i] == str2[i]; i++)
    {
        if (str1[i] == '\0' && str2[i] == '\0')
            return 1;   
    }        
    return 0;
}

/*****************************************************************
 * lengthOfString()如果向Jason那样子做的话可以省略一个variabl，以及省一行加法。
 *****************************************************************/