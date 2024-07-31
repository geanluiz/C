#include <stdio.h>
#include <stdlib.h>

void head();
void genMatrix();
void printMatrix();
void userPlay(char p, int pos);
int checkWin(char p);

char matrix[3][3];
char (*ptr)[3] = matrix;

int intPlayer = 1;
int position;
//char doContinue = 'S';
int endGame = 0;
int turns = 0;

int main(void)
{
    char charPlayer = 'X';

    head();
    genMatrix();
    
    do
    {
        head();

        printf("\nPlayer %i\n", intPlayer);
        printf("Type the number of the position you wanna play.\n");
        printMatrix();
        
        charPlayer = (intPlayer == 1) ? 'X': '0';

        scanf(" %i", &position);
        userPlay(charPlayer, position);
        turns++;
        checkWin(charPlayer);

        if (endGame == 3)
        {
            head();
            printf("\nTIE!\n\n");
            printMatrix();
        }

        //printf("Continuar?(S/N)\n");
        //scanf(" %c", &doContinue);

        intPlayer = (intPlayer == 1) ? 2: 1;
    }while (endGame == 0);
    head();
    printMatrix();
}

void head()
{
    system("clear");
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

void userPlay(char p, int pos)
{
    switch (pos)
    {
        case 1:
            matrix[0][0] = p;
            break;

        case 2:
            matrix[0][1] = p;
            break;

        case 3:
            matrix[0][2] = p;
            break;

        case 4:
            matrix[1][0] = p;
            break;

        case 5:
            matrix[1][1] = p;
            break;

        case 6:
            matrix[1][2] = p;
            break;

        case 7:
            matrix[2][0] = p;
            break;

        case 8:
            matrix[2][1] = p;
            break;

        case 9:
            matrix[2][2] = p;
            break;
    }
}

int checkWin(char p)
{
    if (turns < 5)
    {
        endGame = 0;
    }
    else if (turns > 8)
    {
        endGame = 3;
    }
    else if (turns % 2 != 0)
    {
        if (matrix[0][0] == matrix[0][1] && matrix[0][1] == matrix[0][2]) // ??
        {
            endGame = 1;
        }
    }

    return 1;
}












/* 

Create heading

declare matrix[][]

Create matrix function with numbers inside positions
    c = 0 
    for i 0 to 3
    for j 0 to 3
        matrix i j = c++

create userPlay
    switch case to change matrix content with cordinates 
    acording to option selected by user

Read input from user to start game

curr = X
loop do 
    print heading and matrix

    if curr = X
    Read input from player #1 as "X"
        call userPlay function with x and position as parameters
        call function to check if X won
        curr = O

    else
    Read input from player #2 as "O"
        call userPlay function with x and position as parameters
        call function to check if "O" won
        curr = X

while (not win or tie)
endLoop

print win or tie

ask if user wants to play again then
Call create matrix function if yes

*/