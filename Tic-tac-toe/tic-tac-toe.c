/*  Cli Tic-Tac-Toe game created from scratch
     as a final project to the course on programing logic
     of the Youtube channel 'Curso em Vídeo" by Gustavo Guanabara */

#include <stdio.h>
#include <stdlib.h>

// Functions
void clearScr();
void header();
void genMatrix();
void printMatrix();
void userChoice(char p);
void choiceErr(char p);
void checkWin(int *p_endGame);
void checkEnd();

// Board 
char matrix[3][3];

// Variables
int playerNum = 1;
int position;
int endGame = 0;
int turns = 1;

int main(void)
{
    char charPlayer = 'X';

    header();
    genMatrix();
    
    do
    {
        clearScr();
        header();

        printf("\nPlayer %i\n", playerNum);
        printf("Type the number of the position you wanna play.\n");
        printMatrix();
        
        charPlayer = (playerNum == 1) ? 'X': '0';
        userChoice(charPlayer);

        checkWin(&endGame);
        checkEnd();

        turns++;
        playerNum = ((turns % 2) == 0) ? 2: 1;
    }while(endGame == 0);
}

void clearScr()
{
    #ifdef _WIN32
    system("cls");
    #endif

    #ifdef linux
    system("clear");
    #endif
}

void header()
{
    printf("--------------\n");
    printf(" TIC TAC TOE!\n");
    printf("--------------\n");
}

void genMatrix()
{
    int count = 49;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrix[i][j] = count;
            count++;
        }
    }
}

void printMatrix()
{
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j == 2)
            {
                printf("%c", matrix[i][j]);
            }
            else
            {
                printf("%c | ", matrix[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

void userChoice(char p)
{
    scanf(" %i", &position);
    switch (position)
    {
        case 1:
            if (matrix[0][0] == '1')
            {
                matrix[0][0] = p;
            }
            else
            {
                choiceErr(p);
            }
            break;

        case 2:
            if (matrix[0][1] == '2')
            {  
                matrix[0][1] = p;
            }
            else
            {
                choiceErr(p);
            }
            break;

        case 3:
            if (matrix[0][2] == '3')
            { 
                matrix[0][2] = p;
            }
            else
            {
                choiceErr(p);
            }
            break;

        case 4:
            if (matrix[1][0] == '4')
            { 
                matrix[1][0] = p;
            }
            else
            {
                choiceErr(p);
            }
            break;

        case 5:
            if (matrix[1][1] == '5')
            { 
                matrix[1][1] = p;
            }
            else
            {
                choiceErr(p);
            }
            break;

        case 6:
            if (matrix[1][2] == '6')
            { 
                matrix[1][2] = p;
            }
            else
            {
                choiceErr(p);
            }
            break;

        case 7:
            if (matrix[2][0] == '7')
            { 
                matrix[2][0] = p;
            }
            else
            {
                choiceErr(p);
            }
            break;

        case 8:
            if (matrix[2][1] == '8')
            { 
                matrix[2][1] = p;
            }
            else
            {
                choiceErr(p);
            }
            break;

        case 9:
            if (matrix[2][2] == '9')
            { 
                matrix[2][2] = p;
            }
            else
            {
                choiceErr(p);
            }
            break;
    }
}

void choiceErr(char p)
{
    clearScr();
    header();
    printf("\nPosition already in use, choose another!\n\n");
    printMatrix();
    userChoice(p);
}

void checkWin(int *p_endGame)
{
    if (turns < 5)
    {
        *p_endGame = 0;
    }
    if (turns > 8)
    {
        *p_endGame = 3;
    }

    if ((matrix[0][0] == matrix[0][1]) && (matrix[0][1] == matrix[0][2])) // First row
    {
        *p_endGame = (matrix[0][0] == 'X')? 1 : 2;
    }
    if (matrix[1][0] == matrix[1][1] && matrix[1][1] == matrix[1][2])// Second row
    {
        *p_endGame = (matrix[1][0] == 'X')? 1 : 2;
    }
    if (matrix[2][0] == matrix[2][1] && matrix[2][1] == matrix[2][2])// Third row
    {
        *p_endGame = (matrix[2][0] == 'X')? 1 : 2;
    }
    if (matrix[0][0] == matrix[1][0] && matrix[1][0] == matrix[2][0]) // First column
    {
        *p_endGame = (matrix[0][0] == 'X')? 1 : 2;
    }
    if (matrix[0][1] == matrix[1][1] && matrix[1][1] == matrix[2][1]) // Second column
    {
        *p_endGame = (matrix[0][1] == 'X')? 1 : 2;
    }
    if (matrix[0][2] == matrix[1][2] && matrix[1][2] == matrix[2][2]) // Third column
    {
        *p_endGame = (matrix[0][2] == 'X')? 1 : 2;
    }
    if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2]) // Main diagonal
    {
        *p_endGame = (matrix[0][0] == 'X')? 1 : 2;
    }
    if (matrix[2][0] == matrix[1][1] && matrix[1][1] == matrix[0][2]) // Secondary diagonal
    {
        *p_endGame = (matrix[2][0] == 'X')? 1 : 2;
    }
}

void checkEnd()
{
    if (endGame == 3)
    {
        clearScr();
        header();
        printf("\nTIE!\n\n");
        printMatrix();
    }
    else if (endGame == 1 || endGame == 2)
    {
        clearScr();        
        header();
        printf("\nPlayer %i wins!\n", endGame);
        printMatrix();
    }
    printf("\n%i\n", endGame);
}