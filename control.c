/* *********************************************************************
* File:       control.c
* Author:     G.G.T.Shashen
* Created:    06/09/2021
* Modified:   14/10/2021
* Desc:       Player controlling implementation of the maze game
************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include "terminal.h"
#include "main.h"
#include "world.h"
#include "snake.h"
#include "linkedlist.h"

/* function to control the player inside the map */
void controlPlayer(char ** arr, int rows, int cols)
{
    int playerX;
    int playerY;
    int snakeX;
    int snakeY;
    int cont;
    char ch;
    char flag;
    /* creating a new linkedlist to store player movement */
    LinkedList * list = createLinkedList();
    system("clear");
    printMap(arr,rows,cols);
    playerX = getPlayerCurrentPosX(arr,rows,cols);
    playerY = getPlayerCurrentPosY(arr,rows,cols);
    cont = 1;
    flag = 'w';
    /* inserting initial positions of player and snake to the linked list */
    insertFirst(list,(void*)flag);
    insertFirst(list,(void*)getPlayerCurrentPosX(arr,rows,cols));
    insertFirst(list,(void*)getPlayerCurrentPosY(arr,rows,cols));
    insertFirst(list,(void*)getSnakeCurrentPosX(arr,rows,cols));
    insertFirst(list,(void*)getSnakeCurrentPosY(arr,rows,cols));
    /* do while loop to continue the player movement until the player wins or dies */
    do {
        /* taking input from the user */
        disableBuffer();
        scanf(" %c", &ch);
        enableBuffer();
        /* switch function to get the valid control input from the user */
        switch (ch)
        {
        case 'w':
            playerX = getPlayerCurrentPosX(arr,rows,cols);
            playerY = getPlayerCurrentPosY(arr,rows,cols);
            /* checking if the player is inside the border and on an empty path or if the player is on the goal position or the snake position */
            if ((playerX > 1) && (arr[playerX-1][playerY]==' ' || arr[playerX-1][playerY]=='x' || arr[playerX-1][playerY]=='~'))
            {
                system("clear");
                /*  checking to see if the next path contains the goal */
                if (arr[playerX-1][playerY]=='x')
                {
                    arr[playerX-1][playerY] = '^';
                    arr[playerX][playerY] = ' ';
                    playerWin(arr,rows,cols,list);
                }else if (arr[playerX-1][playerY]=='~')
                {
                /*  checking to see if the next path contains the snake */
                    arr[playerX-1][playerY] = ' ';
                    arr[playerX][playerY] = '~';
                    playerLoose(arr,rows,cols,list);
                }else {
                /* continuing the path if there are no obstructions or goal */
                    arr[playerX][playerY] = ' ';
                    arr[playerX-1][playerY] = '^';
                    flag = 'w';
                /* moving the snake accordingly as the player */
                    moveSnake(arr,rows,cols,list);
                /* inserting coordinate and position data into the linked list */
                    insertFirst(list,(void*)flag);
                    insertFirst(list,(void*)getPlayerCurrentPosX(arr,rows,cols));
                    insertFirst(list,(void*)getPlayerCurrentPosY(arr,rows,cols));
                    insertFirst(list,(void*)getSnakeCurrentPosX(arr,rows,cols));
                    insertFirst(list,(void*)getSnakeCurrentPosY(arr,rows,cols));
                    printMap(arr,rows,cols);
                }
                break;
            }else if (arr[playerX-1][playerY]=='o' || arr[playerX-1][playerY]=='-') {
                /* collision detection & print position when the player is near an obstruction */
                system("clear");
                playerX = getPlayerCurrentPosX(arr,rows,cols);
                playerY = getPlayerCurrentPosY(arr,rows,cols);
                arr[playerX][playerY] = '^';
                flag = 'w';
                /* moving the snake accordingly as the player */
                moveSnake(arr,rows,cols,list);
                /* inserting coordinate and position data into the linked list */
                insertFirst(list,(void*)flag);
                insertFirst(list,(void*)getPlayerCurrentPosX(arr,rows,cols));
                insertFirst(list,(void*)getPlayerCurrentPosY(arr,rows,cols));
                insertFirst(list,(void*)getSnakeCurrentPosX(arr,rows,cols));
                insertFirst(list,(void*)getSnakeCurrentPosY(arr,rows,cols));
                printMap(arr,rows,cols);
                break;
            }
        case 'a':
            playerX = getPlayerCurrentPosX(arr,rows,cols);
            playerY = getPlayerCurrentPosY(arr,rows,cols);
            /* checking if the player is inside the border and on an empty path or if the player is on the goal position or the snake position */
            if ((playerY > 1) && ((arr[playerX][playerY-1]==' ') || arr[playerX][playerY-1]=='x' || arr[playerX][playerY-1]=='~'))
            {
                system("clear");
                /*  checking to see if the next path contains the goal */
                if (arr[playerX][playerY-1]=='x')
                {
                    arr[playerX][playerY] = ' ';
                    arr[playerX][playerY-1] = '<';
                    playerWin(arr,rows,cols,list);
                }else if (arr[playerX][playerY-1]=='~')
                {
                /*  checking to see if the next path contains the snake */
                    arr[playerX][playerY-1] = ' ';
                    arr[playerX][playerY] = '~';
                    playerLoose(arr,rows,cols,list);
                }else {
                /* continuing the path if there are no obstructions or goal */
                    arr[playerX][playerY] = ' ';
                    arr[playerX][playerY-1] = '<';
                    flag = 'a';
                /* moving the snake accordingly as the player */
                    moveSnake(arr,rows,cols,list);
                /* inserting coordinate and position data into the linked list */
                    insertFirst(list,(void*)flag);
                    insertFirst(list,(void*)getPlayerCurrentPosX(arr,rows,cols));
                    insertFirst(list,(void*)getPlayerCurrentPosY(arr,rows,cols));
                    insertFirst(list,(void*)getSnakeCurrentPosX(arr,rows,cols));
                    insertFirst(list,(void*)getSnakeCurrentPosY(arr,rows,cols));
                    printMap(arr,rows,cols);
                }
                break;
            }else if (arr[playerX][playerY-1]=='o' || arr[playerX][playerY-1]=='|') {
                /* collision detection & print position when the player is near an obstruction */
                system("clear");
                playerX = getPlayerCurrentPosX(arr,rows,cols);
                playerY = getPlayerCurrentPosY(arr,rows,cols);
                arr[playerX][playerY] = '<';
                flag = 'a';
                /* moving the snake accordingly as the player */
                moveSnake(arr,rows,cols,list);
                /* inserting coordinate and position data into the linked list */
                insertFirst(list,(void*)flag);
                insertFirst(list,(void*)getPlayerCurrentPosX(arr,rows,cols));
                insertFirst(list,(void*)getPlayerCurrentPosY(arr,rows,cols));
                insertFirst(list,(void*)getSnakeCurrentPosX(arr,rows,cols));
                insertFirst(list,(void*)getSnakeCurrentPosY(arr,rows,cols));
                printMap(arr,rows,cols);
                break;
            }
            
        case 's':
            playerX = getPlayerCurrentPosX(arr,rows,cols);
            playerY = getPlayerCurrentPosY(arr,rows,cols);
            /* checking if the player is inside the border and on an empty path or if the player is on the goal position or the snake position */
            if ((playerX < rows-2) && ((arr[playerX+1][playerY]==' ') || arr[playerX+1][playerY]=='x'|| arr[playerX+1][playerY]=='~'))
            {
                system("clear");
                /*  checking to see if the next path contains the goal */
                if (arr[playerX+1][playerY]=='x')
                {
                    arr[playerX][playerY] = ' ';
                    arr[playerX+1][playerY] = 'v';
                    playerWin(arr,rows,cols,list);
                }else if (arr[playerX+1][playerY]=='~')
                {
                 /*  checking to see if the next path contains the snake */
                    arr[playerX+1][playerY] = ' ';
                    arr[playerX][playerY] = '~';
                    playerLoose(arr,rows,cols,list);
                }else {
                /* continuing the path if there are no obstructions or goal */
                    arr[playerX][playerY] = ' ';
                    arr[playerX+1][playerY] = 'v';
                    flag = 's';
                /* moving the snake accordingly as the player */
                    moveSnake(arr,rows,cols,list);
                /* inserting coordinate and position data into the linked list */
                    insertFirst(list,(void*)flag);
                    insertFirst(list,(void*)getPlayerCurrentPosX(arr,rows,cols));
                    insertFirst(list,(void*)getPlayerCurrentPosY(arr,rows,cols));
                    insertFirst(list,(void*)getSnakeCurrentPosX(arr,rows,cols));
                    insertFirst(list,(void*)getSnakeCurrentPosY(arr,rows,cols));
                    printMap(arr,rows,cols);
                }
                break;
            }else if (arr[playerX+1][playerY]=='o' || arr[playerX+1][playerY]=='-') {
                /* collision detection & print position when the player is near an obstruction */
                system("clear");
                playerX = getPlayerCurrentPosX(arr,rows,cols);
                playerY = getPlayerCurrentPosY(arr,rows,cols);
                arr[playerX][playerY] = 'v';
                flag = 's';
                /* moving the snake accordingly as the player */
                moveSnake(arr,rows,cols,list);
                insertFirst(list,(void*)flag);
                /* inserting coordinate and position data into the linked list */
                insertFirst(list,(void*)getPlayerCurrentPosX(arr,rows,cols));
                insertFirst(list,(void*)getPlayerCurrentPosY(arr,rows,cols));
                insertFirst(list,(void*)getSnakeCurrentPosX(arr,rows,cols));
                insertFirst(list,(void*)getSnakeCurrentPosY(arr,rows,cols));
                printMap(arr,rows,cols);
                break;
            }
            
        case 'd':
            playerX = getPlayerCurrentPosX(arr,rows,cols);
            playerY = getPlayerCurrentPosY(arr,rows,cols);
            /* checking if the player is inside the border and on an empty path or if the player is on the goal position or the snake position */
            if ((playerY < cols-2) && (arr[playerX][playerY+1]==' ' || arr[playerX][playerY+1]=='x'|| arr[playerX][playerY+1]=='~'))
            {
                system("clear");
                /*  checking to see if the next path contains the goal */
                if (arr[playerX][playerY+1]=='x')
                {
                    arr[playerX][playerY] = ' ';
                    arr[playerX][playerY+1] = '>';
                    playerWin(arr,rows,cols,list);
                }else if (arr[playerX][playerY+1]=='~')
                {
                /*  checking to see if the next path contains the snake */
                    arr[playerX][playerY+1] = ' ';
                    arr[playerX][playerY] = '~';
                    playerLoose(arr,rows,cols,list);
                }else {
                 /* continuing the path if there are no obstructions or goal */
                    arr[playerX][playerY] = ' ';
                    arr[playerX][playerY+1] = '>';
                    flag = 'd';
                /* moving the snake accordingly as the player */
                    moveSnake(arr,rows,cols,list);
                /* inserting coordinate and position data into the linked list */
                    insertFirst(list,(void*)flag);
                    insertFirst(list,(void*)getPlayerCurrentPosX(arr,rows,cols));
                    insertFirst(list,(void*)getPlayerCurrentPosY(arr,rows,cols));
                    insertFirst(list,(void*)getSnakeCurrentPosX(arr,rows,cols));
                    insertFirst(list,(void*)getSnakeCurrentPosY(arr,rows,cols));
                    printMap(arr,rows,cols);
                }
                break;
            } else if (arr[playerX][playerY+1]=='o' || arr[playerX][playerY+1]=='|') {
                /* collision detection & print position when the player is near an obstruction */
                system("clear");
                playerX = getPlayerCurrentPosX(arr,rows,cols);
                playerY = getPlayerCurrentPosY(arr,rows,cols);
                arr[playerX][playerY] = '>';
                flag = 'd';
                /* moving the snake accordingly as the player */
                moveSnake(arr,rows,cols,list);
                /* inserting coordinate and position data into the linked list */
                insertFirst(list,(void*)flag);
                insertFirst(list,(void*)getPlayerCurrentPosX(arr,rows,cols));
                insertFirst(list,(void*)getPlayerCurrentPosY(arr,rows,cols));
                insertFirst(list,(void*)getSnakeCurrentPosX(arr,rows,cols));
                insertFirst(list,(void*)getSnakeCurrentPosY(arr,rows,cols));
                printMap(arr,rows,cols);
                break;
            }
        case 'u': 
            system("clear");
            /* getting current player and snake positions */
            playerX = getPlayerCurrentPosX(arr,rows,cols);
            playerY = getPlayerCurrentPosY(arr,rows,cols);
            snakeX = getSnakeCurrentPosX(arr,rows,cols);
            snakeY = getSnakeCurrentPosY(arr,rows,cols);
            /* clearing current player and snake position according to the data */
            arr[playerX][playerY]=' ';
            arr[snakeX][snakeY]=' ';
            if (list->head != NULL)
            {
                /* removing the last entered player, snake coordinates and position */
                removeFirst(list);
                removeFirst(list);
                removeFirst(list);
                removeFirst(list);
                removeFirst(list);
                /* getting the current player, snake coordinates and position from the linked list */
                snakeY = (void*)list->head->data;
                snakeX = (void*)list->head->next->data;
                playerY = (void*)list->head->next->next->data;
                playerX = (void*)list->head->next->next->next->data;
                flag = (void*)list->head->next->next->next->next->data;
                /* checking appropriate position data and inserting new player and snake coordinates */
                if (flag == 'w')
                {
                    arr[playerX][playerY]='^';
                    arr[snakeX][snakeY]='~';
                }
                if (flag == 'a')
                {
                    arr[playerX][playerY]='<';
                    arr[snakeX][snakeY]='~';
                }
                if (flag == 's')
                {
                    arr[playerX][playerY]='v';
                    arr[snakeX][snakeY]='~';
                }
                if (flag == 'd')
                {
                    arr[playerX][playerY]='>';
                    arr[snakeX][snakeY]='~';
                }
                printMap(arr,rows,cols);
                
            }else if (list->head == NULL)
            {
                printMap(arr,rows,cols);
            }
            break;
        default:
            break;
        }
    } while(cont==1);
    /* freeing the linked list */
    freeLinkedList(list);
}