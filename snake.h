#ifndef SNAKE_H
#define SNAKE_H

int getSnakeCurrentPosX(char ** arr, int rows, int cols);
int getSnakeCurrentPosY(char ** arr, int rows, int cols);
int getDiffX(char ** arr, int rows, int cols);
int getDiffY(char ** arr, int rows, int cols);
void moveSnake(char ** arr,  int rows, int cols, LinkedList * pList);
void moveUp(char ** arr, int rows, int cols, LinkedList * pList);
void moveDown(char ** arr, int rows, int cols, LinkedList * pList);
void moveLeft(char ** arr, int rows, int cols, LinkedList * pList);
void moveRight(char ** arr, int rows, int cols, LinkedList * pList);


#endif