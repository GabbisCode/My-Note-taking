/**
 * @file 10-Create_a_Tic_Tac_Toe_Game.c
 * @author gabbi (gabbi.huang@outlook.com)
 * @date 2022-08-22
 * 
 * afa帮助我一块debug。
 * 我犯了好几个常见的错误
 * 首先是判断是否相等，我总是写成=，而不是==。
 * 其次scanf()中，数字变量前面需要加&符号
 * 
 * afa帮我改动比较大的地方就是我的drawBoard()。
 * 他表示只需要刷新展现就可以。而我莫名其妙地在函数里判断i是否可以添加进去，导致需要用到全局函数。
 * 加油。下次继续努力！
 */

#include <stdio.h>
#include <stdlib.h>

char board[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int markBoard(int x);
void drawBoard(void);
int checkForWin(void);

int main(void)
{
    int player = 1;     // x = player 1 or player 2;
    int win = 0;        // 1 = somebody wins the game, 0 = nobody wins
    int changesucc = 0; // 1 = change the value of the array successfully, 0 = not successful

    for (int count = 0; count < 9;)
    {
        drawBoard(); // show the drawBoard
        changesucc = markBoard(player);
        if (changesucc != 0) // change the value of the array successfully
        {
            win = checkForWin();
            if (win == 1)
            {
                printf("==> Player %d wins", player);
                break;
            }
            else
            {
                player = (player == 1) ? 2 : 1;
            }
            count++; // move to the next Cyc
        }
        else // change the value of the array unsuccessfully
        {
            printf("Invalid move\n");
        }
    }

    return 0;
}

/**
 * @brief To set the char array with a selection and check for an invalid selection
 * 
 * @param x which player, player 1 or player 2
 * @return int if the change value is invalid reurn 0, else return the value of index
 */
int markBoard(int x) 
{
    int i;

    printf("Player %d, enter a number:", x);
    scanf("%d", &i);

    if (i == 0 || i > 9 )
    {
        return 0;
    }
    else if (board[i] == 'O' || board[i] == 'X')
    {
        return 0;
    }


    if (x == 1)
    {
        board[i] = 'X';
    }
    else if (x == 2)
    {
        board[i] = 'O';
    }

    return i;
}

/**
 * @brief show the drawboard
 */
void drawBoard(void) // x = player 1 or player 2; i = index
{
    printf("\nTic Tac Toe\n");
    printf("Player 1 (X) - Player 2 (O)\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", board[1], board[2], board[3]);
    printf("___|___|___\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", board[4], board[5], board[6]);
    printf("___|___|___\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", board[7], board[8], board[9]);
    printf("   |   |   \n");
}

/**
 * @brief To check to see if a player has won or the game is a draw
 * 
 * @return int return =1 somebody wins; return = 0 nobody wins
 */
int checkForWin(void) 
{
    if (board[1] == board[2] && board[2] == board[3])
    return 1;
    if (board[4] == board[5] && board[5] == board[6])
    return 1;
    if (board[7] == board[8] && board[8] == board[9])
    return 1;
    if (board[1] == board[4] && board[4] == board[7])
    return 1;
    if (board[2] == board[5] && board[5] == board[8])
    return 1;
    if (board[3] == board[6] && board[6] == board[9])
    return 1;
    if (board[1] == board[5] && board[5] == board[9])
    return 1;
    if (board[3] == board[5] && board[5] == board[7])
    return 1;

    return 0;  
}

/******************************************************************
 * checkForwin()
 * Jason的代码有三种情况（return），1=游戏结束有赢家，0=游戏结束无赢家，-1=游戏进行中
 * 
 * drawBoard()
 * 
 * 
 ******************************************************************/