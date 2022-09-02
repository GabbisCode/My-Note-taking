/**
 * @file 14-Counting_characters_in_a _String.c
 * @author Gabbi (gabbi.huang@outlook.com)
 * @date 2022-09-02
 */

#include <stdio.h>
#include <stdlib.h>

int LengthOfStr(const char *ptr);

int main(void)
{
    char string[] = "I am Happy.";

    int Length = LengthOfStr(string);
    printf("The length of the string is %d.", Length);

    return 0;
}

/**
 * @brief to calculate the length of a string
 * 
 * @param ptr the string to be caculated
 * @return int the length of the string
 */
int LengthOfStr(const char *ptr)
{
    char *pBegin = (void*)ptr;
    char *pEnd;
    int Length;

    while (*ptr)
    {
        ++ptr;
    }
        
    pEnd = (void*)ptr;
    Length = pEnd - pBegin + 1;

    return Length;
}

/**********************************************************************
 * Jason的代码比较好，因为他没有就只整了一个变量。
 * 而我整多了两。
 * 
 **********************************************************************/