/**
 * @file 12-Utilizing_common_string_functions.c
 * @author Gabbi (gabbi.huang@outlook.com)
 * @date 2022-08-26 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 1000
#define WORDS 4

int main(void)
{
    const char str[MAXLEN];
    int Length = strlen(str);
    char strs[WORDS][MAXLEN];
    char temp[MAXLEN];
    int count = WORDS;

    
    //to display a string in reverse order
    printf("Please enter a string less than %d characters:", MAXLEN);
    scanf("%s", str);
    printf("------------------------------------------------\n");

    if (Length < MAXLEN)
    {
        for (int i = Length; i >= 0; i--)
        {
            printf("%c", str[i]);
        }
    }
    else 
    printf("You've entered excess characters.");

    //to sort the strings of an array using a bubble sort
    printf("\nInput string %d:\n", WORDS);
    for (int i = 0; i < WORDS; i++)
    {
        scanf("%s", strs[i]);
    }

    for (int y = 0; y < WORDS - 1; y++)  //这里可以改成 y = 1，后面就不需要用WORD - 1 了。
    {
        count = count - 1;
        for (int x = 0; x < count; x++)  //to sort 2 character sequentially each time 
        {
            int result = strcmp(strs[x], strs[x + 1]);
            if (result > 0)
            {
                strcpy(temp, strs[x]);
                strcpy(strs[x], strs[x + 1]);
                strcpy(strs[x + 1], temp);
            }    
        }
    }
    
    printf("\nExpected Output:\n");
    for (int i = 0; i < WORDS; i++)
    {
        printf("%s\n", strs[i]);
    }

}
