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
void insertNode(List *list, int data);
void displayList(List *list);
void freeList(List *list);
void removeNode(List *list, int dataToRemove);

int main(void)
{
    List *list = createList();

    insertNode(list, 10);
    insertNode(list, 20);
    insertNode(list, 30);

    displayList(list);

    removeNode(list, 30);

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

void insertNode(List *list, int data)
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

void removeNode(List *list, int dataToRemove)
{
    // Check if the list is empty
    if (list->head == NULL)
    {
        printf("Empty list. No node to remove.\n");
        return;
    }

    // Check if the node to remove is the head of the list
    if (list->head->data == dataToRemove)
    {
        Node *temp = list->head; // Temporary node to free the memory after change the HEAD.
        list->head = list->head->next; // Changing the HEAD to the next node
        free(temp); // Desalocating memory of removed node
        printf("Node with value %d removed from the list.\n", dataToRemove);
        return;
    }

    // Search for the node to remove
    Node *prev = list->head; // points to the HEAD of the list
    Node *current = list->head->next; // points to the node next to the HEAD
    while (current != NULL) // if current != NULL, means that there are still nodes left in the list to check!
    {
        if (current->data == dataToRemove) // i start checking from second node to end of the list.
        {
            prev->next = current->next;    
                // if i'm removing the 3 element of the list, the second element the pointed to 3, must now point
                // to the 4, that's exactly what i'm doing here. The previous points now to current's next.
            free(current); // Free the memory of the removed node
            printf("Node with value %d removed from the list.\n", dataToRemove);
            return;
        }
        prev = current;
        current = current->next;
    }
    //If the node is not found
    printf("Node with value %d not found in the list.\n", dataToRemove);
}

void displayList(List *list)
{
    printf("Elementos da lista:\n");
    Node *current = list->head;
    while (current != NULL)
    {
        printf("Data: %d, Next: %p\n", current->data, (void *)current->next);
        current = current->next;
    }
}

void freeList(List *list)
{
    Node *current = list->head;
    while (current != NULL)
    {
        Node *temp = current;    // aponta para o mesmo nó que current
        current = current->next; // current agora é o próximo nó da lista
        free(temp);              // liberando o nó que current apontava antes de ser atualizado
    }
    free(list);
}