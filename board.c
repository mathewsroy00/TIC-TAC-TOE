#include <stdio.h>
#include "header.h"

void print_board(char (*arr)[SIZE])
{
    printf(CYAN"\n    ==== TIC TAC TOE ====\n\n"RESET);
    printf(YELLOW"       0       1       2\n"RESET);
    printf("   +-------+-------+-------+\n");

    for (int i = 0; i < SIZE; i++)
    {
        printf(YELLOW" %d "RESET, i);
        for (int j = 0; j < SIZE; j++)
        {
            if(arr[i][j] == 'X')
                printf("|   "RED"X"RESET"   ");
            else if(arr[i][j] == 'O')
                printf("|   "CYAN"O"RESET"   ");
            else
                printf("|   %c   ", arr[i][j]);
        }
        printf("|\n");
        printf("   +-------+-------+-------+\n");
    }

    printf("\n");
}
void board_initialis(char (*arr)[SIZE])
{
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            arr[i][j] = ' ';
        }
    }
}

void Display_rules()
{
    printf("\t\t\t::: GAME RULES :::\n\n");
    printf("\t1.Should enter valid number of coloumn and row that is (0-2)\n");
    printf("\t2.The first player to get three of their marks in a row vertically,horizontally and diagonaly wins\n");
    printf("\t3.If all nine squares are filled and neither of the player won then the game is tied\n");
    printf("\n\t----------------------------------------------------------------------------------------------------\n");

}




