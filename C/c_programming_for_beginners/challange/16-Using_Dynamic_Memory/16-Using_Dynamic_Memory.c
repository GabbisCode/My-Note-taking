/**
 * @file 16-Using_Dynamic_Memory.c
 * @author gabbi (gabbi.huang@outlook.com)
 * @brief Write a program that allows a user to input a text string
 * @date 2022-09-03
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int byte = 0;
    char *text = NULL;

    printf("Please tell me the number of bytes you wanna use:");
    scanf("%d\n", &byte);     //备注见下！！！！重要！！！！！
    text = (char *)malloc(byte);

    printf("Please enter the text.\n");
    gets(text);
    printf("The text you have entered is: %s", text);

    free(text);
    text = NULL;

    return 0;
}

/******************************************************************
 * 1
 * scanf后必须附上\n，如果不这样的话，
 * 当输入int值回车，就会变成传入int值然后把回车，即\n传给下面的gets。
 * 或者这里要学Jason，在gets前加上一行scanf("");
 * 
 * 另：
 * scanf只能接收空格或\n以内的值，空格或\n之后结束。
 * gets可以接受text或\n内的值。
 * 
 * 2 ！！！！！
 * 需要用if(text != NULL) 或者 if(!text)，一定要确定text不能为NULL，不然很危险！
 * 
 * 3
 * 千万记得用完内存之后要free一下，Dynamic Memory是很珍贵的！
 ********************************************************************/