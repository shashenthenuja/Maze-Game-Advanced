/**********************************************************************
* Title:      Assignment 2
* Author:     G.G.T.Shashen
* Created:    06/09/2021
* Modified:   18/10/2021
* Requisites: terminal.h, world.h, control.h, fileIO.h, linkedlist.h
* Desc:       Maze Game
***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "terminal.h"
#include "world.h"
#include "control.h"
#include "fileIO.h"
#include "snake.h"
#include "linkedlist.h"

int main(int argc, char * argv[]) 
{   
    int rows;
    int cols;
    int amount;
    int i;
    int **dataTable;
    char **mapLayout;
    /* checking arguments */
    if (argc < 2)
    {
        printf("Too Few Arguments!\n");
        printf("Usage : ./maze <map.txt>\n");
        return 0;
    }else if (argc > 2)
    {
        printf("Too Many Arguments!\n");
        printf("Usage : ./maze <map.txt>\n");
        return 0;
    }
    /* getting the meta data from the fileIO.c and storing in appropriate variables */
    fileRead(argv[1],&dataTable,&amount,&rows,&cols);
    /* making the map layout from the map.c data */
    mapLayout = (char **) malloc(sizeof(int *) * (rows));
    for ( i = 0; i < (rows); i++)
    {
        mapLayout[i] = NULL;
        mapLayout[i] = (char *) malloc(sizeof(int *) * (cols));
    }
    /* calling allocateMap function to allocate map data */
    allocateMap(mapLayout,rows,cols);
    /* calling allocateObjects function to allocate map object */
    allocateObjects(dataTable,mapLayout,amount,rows,cols,amount);
    /* calling controlPlayer function to control the player in the map */
    controlPlayer(mapLayout,rows,cols);
    /* freeing malloc data */
    for ( i = 0; i < (rows); i++)
    {
        free(mapLayout[i]);
        mapLayout[i] = NULL;
    }
    free(mapLayout);
    mapLayout = NULL;
    for ( i = 0; i < (rows); i++)
    {
        free(dataTable[i]);
    }
    free(dataTable);
    dataTable = NULL;
    return 0;
}

/* function to print the map to the screen */
void printMap(char ** arr, int rows, int cols)
{
    int r;
    int c;
    r=0;
    c=0;
    /* printing the whole map */
    for ( r = 0; r < rows; r++)
    {
        for ( c = 0; c < cols; c++)
        {
            printf("%c", arr[r][c]);
        }
        printf("\n");
    }
}

/* function to return the current player position in the map (row coordinate) */
int getPlayerCurrentPosX(char ** arr, int rows, int cols)
{
    int i;
    int j;
    int playerX;
    /* searching for the current row coordinate of the player position on the map */
    for ( i = 0; i < rows; i++)
    {
        for ( j = 0; j < cols; j++)
        {
            if ((arr[i][j] == '^') || (arr[i][j] == 'v') || (arr[i][j] == '<') || (arr[i][j] == '>') )
            {
                playerX = i;
            }
            
        }
        
    }
    return playerX;
}

/* function to return the current player position in the map (column coordinate) */
int getPlayerCurrentPosY(char ** arr, int rows, int cols)
{
    int i;
    int j;
    int playerY;
    /* searching for the current column coordinate of the player position on the map */
    for ( i = 0; i < rows; i++)
    {
        for ( j = 0; j < cols; j++)
        {
            if ((arr[i][j] == '^') || (arr[i][j] == 'v') || (arr[i][j] == '<') || (arr[i][j] == '>') )
            {
                playerY = j;
            }
            
        }
        
    }
    return playerY;
}

/* function to display the player winning message */
void playerWin(char ** arr, int rows, int cols, LinkedList * pList)
{
    int i;
    /* calling printMap function to print the map to the screen */
    printMap(arr,rows,cols);
    printf("\n");
    printf("You Win!\n");
    printf("\n");
    /* freeing malloc data */
    for ( i = 0; i < (rows); i++)
    {
        free(arr[i]);
    }
    free(arr);
    /* freeing the linked list */
    freeLinkedList(pList);
    exit(0);
}

/* function to display the player loosing message */
void playerLoose(char ** arr, int rows, int cols, LinkedList * pList)
{
    int i;
    /* calling printMap function to print the map to the screen */
    printMap(arr,rows,cols);
    printf("\n");
    printf("You Lose! try again.\n");
    printf("\n");
    /* freeing malloc data */
    for ( i = 0; i < (rows); i++)
    {
        free(arr[i]);
    }
    free(arr);
    /* freeing the linked list */
    freeLinkedList(pList);
    exit(0);
}