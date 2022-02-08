/**********************************************************************
* File:       world.c
* Author:     G.G.T.Shashen
* Created:    06/09/2021
* Modified:   14/10/2021
* Desc:       Game world and objects implementation of the maze game
************************************************************************/
#include <stdio.h>
#include <stdlib.h>

/* function to allocate the map border */
void allocateMap(char ** arr, int rows, int cols)
{
    int r;
    int c;
    int i;
    int j;
    /* priting # for the corners */
    arr[0][0] = '#';
    arr[0][cols-1] = '#';
    arr[rows-1][0] = '#';
    arr[rows-1][cols-1] = '#';
    /* printing - for top and bottom border */
    for ( r = 0; r < rows; r++)
    {
        for ( c = 1; c < cols-1; c++)
        {
            arr[0][c] = '-';
            arr[rows-1][c] = '-';
        }
    }
    /* printing | for left and right border */
    for ( r = 1; r < rows-1; r++)
    {
        arr[r][0] = '|';
        arr[r][cols-1] = '|';
    }
    /* filling empty spaces  */
    for ( i = 1; i < rows-1; i++)
    {
        for ( j = 1; j < cols-1; j++)
        {
            arr[i][j] = ' ';
        }
    }
}

/* function to allocate objects in the map (player,snake,goal,walls) */
void allocateObjects(int ** tableData, char ** arr, int amount, int rows, int cols, int elements)
{
    int r;
    int i;
    int objectX;
    int objectY;
    int objectCode;
    /* printing the player, snake, goal, walls with appropriate coordinates from the argument file */
    for ( r = 0; r < amount; r++)
    {
        objectX = (int)tableData[r][0];
        objectY = (int)tableData[r][1];
        objectCode = (int)tableData[r][2];
        if (objectCode == 0)
        {
            arr[objectX][objectY] = '^';
        }else if (objectCode == 1)
        {
            arr[objectX][objectY] = '~';
        }else if (objectCode == 2)
        {
            arr[objectX][objectY] = 'x';
        }
        else if (objectCode == 3)
        {
            arr[objectX][objectY] = 'o';
        }else 
        {
            arr[objectX][objectY] = ' ';
        }
    }
    /* freeing malloc data */
    for ( i = 0; i < (elements); i++)
    {
        free(tableData[i]);
    }
    free(tableData);
}