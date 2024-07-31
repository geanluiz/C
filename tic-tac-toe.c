#include <stdio.h>
#include <stdlib.h>

void head();
void genMatrix();
void printMatrix();
int userPlay(char p);
void checkWin(int *p);
void checkEnd();
void incPlay(char p);

char matrix[3][3];

int intPlayer = 1;
int position;
int endGame = 0;
int turns = 1;

int main(void)
{
    char charPlayer = 'X';

    head();
    genMatrix();
    
    do
    {
        system("clear");
        head();

        printf("\nPlayer %i\n", intPlayer);
        printf("Type the number of the position you wanna play.\n");
        printMatrix();
        printf("\n%i\n", endGame);
        
        charPlayer = (intPlayer == 1) ? 'X': '0';
        
        userPlay(charPlayer);

        checkWin(&endGame);
        checkEnd();

        turns++;
        intPlayer = ((turns % 2) == 0) ? 1: 2;
    }while(endGame == 0);
}

void head()
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

int userPlay(char p)
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
                incPlay(p);
            }
            break;

        case 2:
            if (matrix[0][1] == '2')
            {  
                matrix[0][1] = p;
            }
            else
            {
                incPlay(p);
            }
            break;

        case 3:
            if (matrix[0][2] == '3')
            { 
                matrix[0][2] = p;
            }
            else
            {
                incPlay(p);
            }
            break;

        case 4:
            if (matrix[1][0] == '4')
            { 
                matrix[1][0] = p;
            }
            else
            {
                incPlay(p);
            }
            break;

        case 5:
            if (matrix[1][1] == '5')
            { 
                matrix[1][1] = p;
            }
            else
            {
                incPlay(p);
            }
            break;

        case 6:
            if (matrix[1][2] == '6')
            { 
                matrix[1][2] = p;
            }
            else
            {
                incPlay(p);
            }
            break;

        case 7:
            if (matrix[2][0] == '7')
            { 
                matrix[2][0] = p;
            }
            else
            {
                incPlay(p);
            }
            break;

        case 8:
            if (matrix[2][1] == '8')
            { 
                matrix[2][1] = p;
            }
            else
            {
                incPlay(p);
            }
            break;

        case 9:
            if (matrix[2][2] == '9')
            { 
                matrix[2][2] = p;
            }
            else
            {
                incPlay(p);
            }
            break;
    }
}

void incPlay(char p)
{
    system("clear");
    head();
    printf("\nPosition already in use, choose another!\n\n");
    printMatrix();
    userPlay(p);
}

void checkWin(int *p)
{
    if (turns < 5)
    {
        *p = 0;
    }
    if (turns > 8)
    {
        *p = 3;
    }
    /* else
    { */
        if ((matrix[0][0] == matrix[0][1]) && (matrix[0][1] == matrix[0][2])) // First row
        {
            *p = (matrix[0][0] == 'X')? 1 : 2;
        }
        if (matrix[1][0] == matrix[1][1] && matrix[1][1] == matrix[1][2])// Second row
        {
            *p = (matrix[1][0] == 'X')? 1 : 2;
        }
        if (matrix[2][0] == matrix[2][1] && matrix[2][1] == matrix[2][2])// Third row
        {
            *p = (matrix[2][0] == 'X')? 1 : 2;
        }
        if (matrix[0][0] == matrix[1][0] && matrix[1][0] == matrix[2][0]) // First column
        {
            *p = (matrix[0][0] == 'X')? 1 : 2;
        }
        if (matrix[0][1] == matrix[1][1] && matrix[1][1] == matrix[2][1]) // Second column
        {
            *p = (matrix[0][1] == 'X')? 1 : 2;
        }
        if (matrix[0][2] == matrix[1][2] && matrix[1][2] == matrix[2][2]) // Third column
        {
            *p = (matrix[0][2] == 'X')? 1 : 2;
        }
        if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2]) // Main diagonal
        {
            *p = (matrix[0][0] == 'X')? 1 : 2;
        }
        if (matrix[2][0] == matrix[1][1] && matrix[1][1] == matrix[0][2]) // Secondary diagonal
        {
            *p = (matrix[2][0] == 'X')? 1 : 2;
        }
    /* } */
}

void checkEnd()
{
    if (endGame == 3)
    {
        system("clear");
        head();
        printf("\nTIE!\n\n");
        printMatrix();
    }
    else if (endGame == 1 || endGame == 2)
    {
        system("clear");
        head();
        printf("\nPlayer %i wins!\n", endGame);
        printMatrix();
    }
    printf("\n%i\n", endGame);
}