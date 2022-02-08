#ifndef LL
#define LL
#define FALSE 0
#define TRUE !FALSE

typedef struct LinkedListNode
{
    void * data;
    struct LinkedListNode * next;
}LLnode;

typedef struct
{
    LLnode * head;
}LinkedList;

typedef void (*FunPtr)(void * data);

LinkedList * createLinkedList();
void insertFirst(LinkedList * list, void * pdata);
void* removeFirst(LinkedList * list);
void freeLinkedList(LinkedList * list);
int isEmpty(LinkedList *list);
#endif