/*
 * Author      : Mathews Roy
 * Date        : 31-10-2025
 * Description : A 3 x 3 Tic Tac Toe gameplay which validates input and decides winner 
 */


#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void game(char (*arr)[SIZE])
{
    int opt, flag;
    char player1[15];
    char player2[15];

    // Player names
    printf("Enter the name of player1: ");
    scanf(" %[^\n]",player1);
    printf("Enter the name of player2: ");
    scanf(" %[^\n]", player2);
    system("clear");

    do                        // Loop for playing again
    {
        flag = 0;             // For finding if game is tied or not
        board_initialis(arr); // For initialising board with spaces
        print_board(arr);     // Displaying empty board

        for(int i = 0; i < 9; i++) // maximum 9 turns
        {
            if((i & 1) == 0) // if it is even player 1 turn
            {
                int r, c, valid = 0;
                do
                {
                    printf("\n%s turn ("RED"X"RESET")\n",player1);
                    printf("Enter your move (row col): ");
                    scanf("%d %d", &r, &c);
                    
                    // Input validation
                    if((r >= 0 && r <= 2) && (c >= 0 && c <= 2))
                    { 
                        if(arr[r][c] == ' ' )
                        {
                            arr[r][c] = 'X';
                            valid = 0;
                        }
                        else
                        {
                            printf(RED"\n⚠️ Already taken\n"RESET);
                            valid = 1;
                        }
                    }
                    else
                    {
                        printf(RED"\n⚠️ Row and column should be within the range(0-2)\n"RESET);
                        valid = 1;
                    }
                }
                while(valid);

                system("clear");
                print_board(arr); // Printing updated board
            // For checking winner 
            int res =  winner_check(arr, 'X', player1, player2);
            if(res == 1)
                {
                    flag = 1;
                    printf(YELLOW"\n🎉Game completed🎉\n"RESET);
                    break;
                }
            }
            else if((i & 1) == 1)  // Player 2 turn
            {
                int r, c, valid = 0;
                do
                {
                    printf("\n%s turn ("CYAN"O"RESET")\n",player2);
                    printf("Enter your move (row col): ");
                    scanf("%d %d", &r, &c);
                
                    if((r >= 0 && r <= 2) && (c >= 0 && c <= 2))
                    {
                        if(arr[r][c] == ' ' )
                        {
                            arr[r][c] = 'O';
                            valid = 0;
                        }
                        else
                        {
                            printf(RED"\n⚠️ Already taken\n"RESET);
                            valid = 1;
                        }
                    }
                    else
                    {
                        printf(RED"\n⚠️ Row and column should be within the range(0-2)\n"RESET);
                        valid = 1;
                    }
                }
                while(valid);
                system("clear");
                print_board(arr);
                int res = winner_check(arr, 'O', player1, player2);
                if(res == 1)
                {
                    flag = 1;
                    printf(YELLOW"\n🎉Game completed🎉\n"RESET);
                    break;
                }
            }
        }
       if(flag == 0)
             printf(CYAN"Game tied🫂\n"RESET);

        printf("------------------------------------------------------\n");

        printf("\nDo you want to play the game once more: (1-Yes / 0-No): ");
        scanf("%d", &opt);
        system("clear");


    }while(opt != 0);
}


int winner_check(char(*arr)[SIZE], char var, char* player1, char* player2)
{
    // Row check
    int row_count;
    for(int i = 0; i < SIZE; i++)
    {
        row_count = 0;
        for(int j = 0; j < SIZE; j++)
        {
            if(arr[i][j] == var)
            {
                row_count++;
            }
        }
        if(row_count == SIZE)
        {
            if(var == 'X')
            {
                printf(GREEN"Congratulations %s wins✅ " RESET "Better luck next time %s📍\n", player1, player2);
                return 1;
            }
            else
            {
                printf(GREEN"Congratulations %s wins✅ " RESET"Better luck next time %s📍\n", player2, player1);
                return 1;
            }
        }
    }

    // Column check
    int col_count;
    for(int i = 0; i < SIZE; i++)
    {
        col_count = 0;
        for(int j = 0; j < SIZE; j++)
        {
            if(arr[j][i] == var)
            {
                col_count++;
            }
        }
        if(col_count == SIZE)
        {
           if(var == 'X')
            {
                printf(GREEN"Congratulations %s wins✅ " RESET "Better luck next time %s📍\n", player1, player2);
                return 1;
            }
            else
            {
                printf(GREEN"Congratulations %s wins✅ " RESET"Better luck next time %s📍\n", player2, player1);
                return 1;
            }
        }

    }
    // Diagonal check
    if((arr[0][0] == var && arr[1][1] == var && arr[2][2] == var) || (arr[0][2] == var && arr[1][1] == var && arr[2][0] == var))
    {
         if(var == 'X')
            {
                printf(GREEN"Congratulations %s wins✅ " RESET "Better luck next time %s📍\n", player1, player2);
                return 1;
            }
            else
            {
                printf(GREEN"Congratulations %s wins✅ " RESET"Better luck next time %s📍\n", player2, player1);
                return 1;
            }
    }
    return 0;
}  