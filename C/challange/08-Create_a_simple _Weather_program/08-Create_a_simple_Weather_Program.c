/**
 * @file 08-Create_a_simple_Weather_Program.c
 * @author Gabbi (gabbi.huang@outlook.com)
 * @date 2022-08-16
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // define variables and arrays
    int month;
    int year; // 可以同时定义year和month
    float totalRainfall[5] = {0}; //记得要赋值，不然后面忘记赋值结果会出错
    float avgOfYear = 0;
    float avgOfmonth[12] = {0};
    float rainfall[5][12] = //这里的constant5和12可以在preprocessor那里定义eg #define MONTHS 12，#define YEARS 5，和variable month，year不冲突
    {
        {4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
        {8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3},
        {9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4},
        {7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2},
        {7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2}
    };

    printf("YEAR\t\tRAINFALL (inches) \n");

    // caculate the total rainfall of each year
    for ( year = 0; year < 5; year++) //这里的5可以直接用constant YEAR替代，以后如果想更改年份就很方便！
    {
        for ( month = 0; month < 12; month++)
        {
            totalRainfall[year] += rainfall[year][month];
        }

        printf("%d\t\t%.1f\n", year+2010, totalRainfall[year]);

        //add the total rainfall of each year
        avgOfYear += totalRainfall[year];       
    }
    
    //calculate the average yearly rainfall 
    avgOfYear = avgOfYear / 5; //这里5也用YEAR代替！

    printf("\nThe average yearly rainfall is: %.1f inches.\n", avgOfYear); //把上面那行精简掉，放在这里直接除

    //caculate the average rainfall for each month
    printf("\nJan\t\tFeb\t\tMar\t\tApr\t\tMay\t\tJun\t\tJul\t\tAug\t\tSep\t\tOct\t\tNov\t\tDec\n");
    for (month = 0; month < 12; month++)
    {
        for (year = 0; year < 5; year++)
        {
            avgOfmonth[month] += rainfall[year][month];
        }

        avgOfmonth[month] = avgOfmonth[month] / 5;
        printf("%.1f\t\t", avgOfmonth[month]);    
    }
}

/********************************************************
 * 我觉得我取名不太好，Jason取名是total 和subtot。
 * 这样的话他就是直接算总数，后面在printf的时候直接是用total/constan YEAR。
 * 像他这么做便于后续修改和维护。
 ********************************************************/