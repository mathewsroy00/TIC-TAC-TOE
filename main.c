#include <stdio.h>
#include "header.h"

int main()
{
    char arr[SIZE][SIZE];
 
    enum menu opt;
    do
    {
        printf("\n1.Game rules\n");
        printf("2.Play the game\n");
        printf("3.Exit\n");
        printf("Choose the option : ");
        scanf("%d",(int*)&opt);

        switch(opt)
        {
            case RULES:
                    Display_rules();
                    break;
            case PLAY_GAME:
                    game(arr);
                    break;
            case EXIT:
                    return 0;
            default:
                    printf("Invalid option please enter valid option\n");
        }
    }
    while(opt != EXIT);
}