/* *********************************************************************
* File:       linkedlist.c
* Author:     G.G.T.Shashen
* Created:    06/09/2021
* Modified:   18/10/2021
* Desc:       Linked list implementation of the maze game
************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

/* creating the linked list */
LinkedList * createLinkedList()
{
    LinkedList * ll = (LinkedList *) malloc(sizeof(LinkedList));
    ll->head = NULL;
    return ll;
}

/* function to insert data at the beginning of the linked list */
void insertFirst(LinkedList * list, void * pdata)
{
    struct LinkedListNode* newNode;
    int playerX;
    newNode = malloc(sizeof(struct LinkedListNode));
    newNode->data = pdata;
    newNode->next = list->head;
    list->head = newNode;
    playerX = list->head->data;
}

/* function to remove data at the beginning of the linked list */
void* removeFirst(LinkedList * list)
{
    struct LinkedListNode * temp;
    int playerX;
    void* empty;
    empty = NULL;
    if (list->head == NULL)
    {
        empty = NULL;
    }else {
        temp = list->head;
        list->head = temp->next;
        playerX = list->head->data;
        free(temp);
    }
    return empty;
}

void freeLinkedList(LinkedList * list)
{
    struct LinkedListNode * current, * nextNode;
    current = list->head;
    while (current != NULL)
    {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    free(list);
}

int isEmpty(LinkedList *list){
    int empty;
    if (list == NULL)
    {
        empty = TRUE;
    }else
    {
        empty = FALSE;
    }
    return empty;
}