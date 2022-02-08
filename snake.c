/**********************************************************************
* File:       snake.c
* Author:     G.G.T.Shashen
* Created:    06/09/2021
* Modified:   14/10/2021
* Desc:       Snake AI implementation of the maze game
************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "snake.h"
#include "linkedlist.h"

void moveSnake(char ** arr,  int rows, int cols, LinkedList * pList)
{
    int diffX;
    int diffY;
    /* getting the coordinate difference between player and snake */
    diffX = getDiffX(arr,rows,cols);
    diffY = getDiffY(arr,rows,cols);

    /* checking the difference and moving the snake accordingly */
    if (diffX > 0 && diffY > 0)
    {
        moveDown(arr,rows,cols,pList);
    }
    if (diffX > 0 && diffY == 0)
    {
        moveDown(arr,rows,cols,pList);
    }
    if (diffX < 0 && diffY < 0)
    {
        moveUp(arr,rows,cols,pList);
    }
    if (diffX < 0 && diffY == 0)
    {
        moveUp(arr,rows,cols,pList);
    }
    if (diffX == 0 && diffY > 0)
    {
        moveRight(arr,rows,cols,pList);
    }
    if (diffX < 0 && diffY > 0)
    {
        moveRight(arr,rows,cols,pList);
    }
    if (diffX == 0 && diffY < 0)
    {
        moveLeft(arr,rows,cols,pList);
    }
    if (diffX > 0 && diffY < 0)
    {
        moveLeft(arr,rows,cols,pList);
    }
    
}

/* move up function to move the up snake in the map */
void moveUp(char ** arr, int rows, int cols, LinkedList * pList)
{
    int snakeX;
    int snakeY;
    snakeX = getSnakeCurrentPosX(arr,rows,cols);
    snakeY = getSnakeCurrentPosY(arr,rows,cols);
    /* checking collisions */
    if (arr[snakeX-1][snakeY]== 'o' || arr[snakeX-1][snakeY]== 'x')
    {
        arr[snakeX][snakeY] = '~';
    }else if (arr[snakeX-1][snakeY]== '^' || arr[snakeX-1][snakeY]== 'v' || arr[snakeX-1][snakeY]== '>' || arr[snakeX-1][snakeY]== '<')
    {
    /* checking if the player is nearby according to the current coordinates and eliminating the player */
        arr[snakeX][snakeY] = ' ';
        arr[snakeX-1][snakeY] = '~';
        playerLoose(arr,rows,cols,pList);
    }else 
    {
    /* moving the snake if the player is not nearby */
        arr[snakeX][snakeY] = ' ';
        arr[snakeX-1][snakeY] = '~';
    }
}

/* move down function to move the snake down in the map */
void moveDown(char ** arr, int rows, int cols, LinkedList * pList)
{
    int snakeX;
    int snakeY;
    snakeX = getSnakeCurrentPosX(arr,rows,cols);
    snakeY = getSnakeCurrentPosY(arr,rows,cols);
    /* checking collisions */
    if (arr[snakeX+1][snakeY]== 'o' || arr[snakeX+1][snakeY]== 'x')
    {
        arr[snakeX][snakeY] = '~';
    }else if (arr[snakeX+1][snakeY]== 'v' || arr[snakeX+1][snakeY]== '^' || arr[snakeX+1][snakeY]== '<' || arr[snakeX+1][snakeY]== '>')
    {
    /* checking if the player is nearby according to the current coordinates and eliminating the player */
        arr[snakeX][snakeY] = ' ';
        arr[snakeX+1][snakeY] = '~';
        playerLoose(arr,rows,cols,pList);
    }else
    {
    /* moving the snake if the player is not nearby */
        arr[snakeX][snakeY] = ' ';
        arr[snakeX+1][snakeY] = '~';
    }
    
}

/* move left function to move the snake left in the map */
void moveLeft(char ** arr, int rows, int cols, LinkedList * pList)
{
    int snakeX;
    int snakeY;
    snakeX = getSnakeCurrentPosX(arr,rows,cols);
    snakeY = getSnakeCurrentPosY(arr,rows,cols);
    /* checking collisions */
    if (arr[snakeX][snakeY-1]== 'o' || arr[snakeX][snakeY-1]== 'x')
    {
        arr[snakeX][snakeY] = '~';
    }else if (arr[snakeX][snakeY-1]== '<' || arr[snakeX][snakeY-1]== '>' || arr[snakeX][snakeY-1]== 'v' || arr[snakeX][snakeY-1]== '^')
    {
    /* checking if the player is nearby according to the current coordinates and eliminating the player */
        arr[snakeX][snakeY] = ' ';
        arr[snakeX][snakeY-1] = '~';
        playerLoose(arr,rows,cols,pList);
    }else
    {
    /* moving the snake if the player is not nearby */
        arr[snakeX][snakeY] = ' ';
        arr[snakeX][snakeY-1] = '~';
    }
    
}

/* move right function to move the snake right in the map */
void moveRight(char ** arr, int rows, int cols, LinkedList * pList)
{
    int snakeX;
    int snakeY;
    snakeX = getSnakeCurrentPosX(arr,rows,cols);
    snakeY = getSnakeCurrentPosY(arr,rows,cols);
    /* checking collisions */
    if (arr[snakeX][snakeY+1]== 'o' || arr[snakeX][snakeY+1]== 'x')
    {
        arr[snakeX][snakeY] = '~';
    }else if (arr[snakeX][snakeY+1]== '>' || arr[snakeX][snakeY+1]== '^' || arr[snakeX][snakeY+1]== 'v' || arr[snakeX][snakeY+1]== '<' )
    {
    /* checking if the player is nearby according to the current coordinates and eliminating the player */
        arr[snakeX][snakeY] = ' ';
        arr[snakeX][snakeY+1] = '~';
        playerLoose(arr,rows,cols,pList);
    }else
    {
    /* moving the snake if the player is not nearby */
        arr[snakeX][snakeY] = ' ';
        arr[snakeX][snakeY+1] = '~';
    }
    
}

/* function to ge the difference of playerX coordinate and snakeX coordinate */
int getDiffX(char ** arr, int rows, int cols)
{
    int diffX;
    int snakeX;
    int playerX;
    playerX = getPlayerCurrentPosX(arr,rows,cols);
    snakeX = getSnakeCurrentPosX(arr,rows,cols);
    diffX = playerX - snakeX;
    return diffX;
}

/* function to ge the difference of playerY coordinate and snakeY coordinate */
int getDiffY(char ** arr, int rows, int cols)
{
    int diffY;
    int snakeY;
    int playerY;
    playerY = getPlayerCurrentPosY(arr,rows,cols);
    snakeY = getSnakeCurrentPosY(arr,rows,cols);
    diffY = playerY - snakeY;
    return diffY;
}

/* function to return the current snake position in the map (row coordinate) */
int getSnakeCurrentPosX(char ** arr, int rows, int cols)
{
    int i;
    int j;
    int snakeX;
    /* searching for the current row coordinate of the snake position on the map */
    for ( i = 0; i < rows; i++)
    {
        for ( j = 0; j < cols; j++)
        {
            if ((arr[i][j] == '~'))
            {
                snakeX = i;
            }
            
        }
        
    }
    return snakeX;
}

/* function to return the current snake position in the map (column coordinate) */
int getSnakeCurrentPosY(char ** arr, int rows, int cols)
{
    int i;
    int j;
    int snakeY;
    /* searching for the current column coordinate of the snake position on the map */
    for ( i = 0; i < rows; i++)
    {
        for ( j = 0; j < cols; j++)
        {
            if ((arr[i][j] == '~'))
            {
                snakeY = j;
            }
            
        }
        
    }
    return snakeY;
}