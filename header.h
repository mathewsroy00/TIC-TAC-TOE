#ifndef HEADER_H
#define HEADER_H

// Color codes
#define YELLOW "\033[1;33m"
#define RED "\033[1;91m"
#define CYAN "\033[1;96m"
#define GREEN "\033[1;92m"
#define RESET "\033[0m"

#define SIZE 3

enum menu
{
    RULES = 1,
    PLAY_GAME,
    EXIT
};

void Display_rules();
void game(char (*arr)[SIZE]);
void print_board(char (*arr)[SIZE]);
void board_initialis(char (*arr) [SIZE]);
int winner_check(char(*arr)[SIZE], char var, char* player1, char* player2);

#endif
