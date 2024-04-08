#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct node
{
    int key;
    int data;
    struct node *next;
} Node;

typedef struct list
{
    Node *nodeList[MAX_SIZE];
    int length;
} List;

List *createList();
void insertNode(List *list, int key, int data);
void displayList(List *list);
void freeList(List *list);

int main(void)
{
    List *list = createList();
    
    insertNode(list, 1, 10);
    insertNode(list, 2, 20);
    insertNode(list, 3, 30);

    displayList(list);

    freeList(list);

    return 0;
}

List *createList()
{
    List *list = (List *)malloc(sizeof(List));
    if (list)
    {
        list->length = 0;
        printf("List created sucessfuly!\n");
    }
    return list;
}

void insertNode(List *list, int key, int data)
{
    if (list->length == MAX_SIZE)
    {
        printf("The list is full!\n");
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Error on alocating memory!.\n");
        return;
    }
    newNode->key = key;
    newNode->data = data;
    newNode->next = NULL;

    if (list->length == 0)
    {
        list->nodeList[list->length++] = newNode;
    }
    else
    {
        list->nodeList[list->length] = newNode;
        list->nodeList[list->length - 1]->next = newNode;
        list->length++;
    }
}

void displayList(List *list)
{
    printf("Elementos da lista:\n");
    for (int i = 0; i < list->length; i++)
    {
        printf("Key: %d, Data: %d, Next: %p\n", list->nodeList[i]->key, list->nodeList[i]->data, list->nodeList[i]->next);
    }
}

void freeList(List *list)
{
    for (int i = 0; i < list->length; i++)
    {
        free(list->nodeList[i]);
    }
    free(list);
}