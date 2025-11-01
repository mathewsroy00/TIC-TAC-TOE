# Tic-Tac-Toe (C Project)

A simple console based Tic-Tac-Toe game written in C.  
This project supports 2 players, input validation, winner checking and replay option.  
Board is 3x3.

## Features
- Player 1 uses **X**, Player 2 uses **O**
- Validates row & column input (0 – 2 only)
- Detects if position is already taken
- Detects winner (row / column / diagonal)
- Detects tie (no winner in 9 moves)
- Coloured output for better user experience
- Option to play again after finishing a match
- Clean modular code (multiple .c and .h files)

## How to Compile and Run
gcc main.c game.c board.c -o tictactoe
./tictactoe
