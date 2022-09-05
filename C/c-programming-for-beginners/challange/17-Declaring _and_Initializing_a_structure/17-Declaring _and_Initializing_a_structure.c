/**
 * @file 17-Declaring _and_Initializing_a_structure.c
 * @author gabbi (gabbi.huang@outlook.com)
 * @brief to declare a structure and print out it's content
 * @date 2022-09-05
 */

#include <stdio.h>
#include <stdlib.h>

struct infoOfEmploy
{
   char name[20];
   int hireDate;
   float salary;
};

int main(void)
{
    struct infoOfEmploy employee1 = { .name = "Gabbi", .hireDate = 20220310, .salary = 6599.12 };
    struct infoOfEmploy employee2;
    
    //display the info of the 1st employee
    printf("The name of the employee is %s.\n", employee1.name);
    printf("The hire date of this employee is %d.\n", employee1.hireDate);
    printf("The salary of this employee is %.2f.\n", employee1.salary);
    
    //read the info of the 2nd employee
    printf("\nEnter the name of the employee: "); //冒号后面需要空格，不然就无法输入信息
    scanf("%s", employee2.name);
    // scanf(""); //如果printf最后没有空格，就需要补上这行代码
    printf("Enter the hire date: ");
    scanf("%d", &employee2.hireDate);
    // scanf("");
    printf("Enter the salary: ");
    scanf("%f", &employee2.salary);

    //display the info of the 2nd employee
    printf("The name of the employee is %s.\n", employee2.name);
    printf("The hire date of this employee is %d.\n", employee2.hireDate);
    printf("The salary of this employee is %.2f.\n", employee2.salary);

    return 0;
}

/*******************************************************************
 * 老是忘记scanf需要的是地址，不是变量。切记切记！！！
 * 只需要用一个structure就可以了，我可以重复使用enployee，就不需要12345……
 * 
 * 
 *******************************************************************/