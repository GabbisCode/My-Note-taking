/**
 * @file 07-Generate_Prime_Numbers.c
 * @author Gabbi (gabbi.huang@outlook.com)
 * @date 2022-08-15
 **/

#include <stdio.h>

int main()
{
    int number;
    int primes[50] = {[0] = 2, [1] = 3};
    int i ;

    for (number = 4; number < 100; number++)
    { //从4开始累加

        for (i = 0; i < 50; i++)
        { //开始验证当前number是否是质数
             if (primes[i] == 0)
            {
                primes[i] = number;
                printf("%d\n", number);
                break;
            }
            else if (number % primes[i] == 0)
            {
                break;
            }
        }
    }
}

/***********************************************************
 * 这是个笨方法，效率很低。
 * 可以参考readme.md里Jason的代码。
 * 或者是去学习one two three …… infinitity中的筛法（计划中）。
 * 一开始写了两三个小时不断地排查总是出现问题，后面情绪状态都很不好。
 * 晚上在afa的帮助下，脑袋昏昏沉沉的情况下，完成了这些代码。
 * 好多年没接触过数学了。差点都忘了质数是啥。希望勤能补拙吧！
 * 会越来越好的，加油加油！
************************************************************/