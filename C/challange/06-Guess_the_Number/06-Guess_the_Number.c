/**
 * @file 06-Guess_the_Number.c
 * @author Gabbi (gabbi.huang@outlook.com)
 * @date 2022-08-13 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t t;
    int usersNumber;
    int randomNumber;

    srand((unsigned)time(&t));
    randomNumber = rand() % 21;

    printf("This is a guessing game.\n");
    printf("I have chosen a number between 0 and 20 which you must guess.\n");

    for (int count = 5; count >= 1; --count)
    {
        printf("You have %d tries left.\n", count); //这里有误，见下注释
        printf("Enter a guess:");
        scanf("%d", &usersNumber);

        if (usersNumber > randomNumber)
        {
            printf("Sorry, %d is wrong. My number is more than that.", usersNumber); //改成greater
        }
        else if (usersNumber < randomNumber)
        {
            printf("Sorry, %d is wrong. My number is less than that.", usersNumber);
        }
        else
        {
            printf("Congratulations. You guessed it!");
            break;
        }
    }

    return 0;
}

/**********************************************************************************
 * 
 * 我忘记考虑英语的写法和中文的不同了，当只有一次的时候英语是try，当两次以及两次以上时候是tries
 * 所以正确的代码应该是printf("\nYou have %d tr%s left.", count, count == 1 ? "y" : "ies");
 * 变量有趣的点在于变！这里先是赋值成int，后面又变成了char，然后又变回int！！！
 * 
 * 当有很多种可能性的时候，我可以使用nested if else statementent。
 * 
 * 在我的考虑里我还漏掉了其他的可能性，比如说我漏掉了用户可能会输入0-20以外的数，所以需要增加以下代码
 * else if(usersNumber < 0 || usersNumber > 20)  // checking for an invalid guess
 *  printf("I said the number is between 0 and 20.\n");
 * 
 * 如果五次还没猜中的话，就告诉用户他五次都用完了，没猜中，并告知答案。
 * printf("\nYou have had five tries and failed. The number was %d\n",randomNumber);
 * 
 * 更详细代码，看readme.md对比
 * 
 **********************************************************************************/