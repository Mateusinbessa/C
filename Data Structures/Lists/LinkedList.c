#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

typedef struct list
{
    Node *head;
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
    if (!list)
    {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    list->head = NULL;
    printf("List created!\n");
    return list;
}

void insertNode(List *list, int key, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Error on alocating memory!.\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL)
    {
        list->head = newNode;
    }
    else
    {
        Node *current = list->head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

void displayList(List *list)
{
    printf("Elementos da lista:\n");
    Node *current = list->head;
    while (current != NULL)
    {
        printf("Data: %d, Next: %p\n",current->data, (void *)current->next);
        current = current->next;
    }
}

void freeList(List *list)
{
    Node *current = list->head;
    while (current != NULL)
    {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}