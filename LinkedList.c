#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int element;
    struct Node *next;
} Node;

Node *start = NULL; // Points to the first node
Node *List = NULL;  // Points to the last node

void createList(int theElement)
{
    if (start != NULL)
    {
        printf("List already created! Try again");
        return;
    }
    List = (Node *)malloc(1 * sizeof(Node));

    start = List;

    List->element = theElement;
    List->next = NULL;
}

void insert(int theElement)
{
    Node *Buffer = (Node *)malloc(1 * sizeof(Node));

    Buffer->element = theElement;
    Buffer->next = NULL;

    List->next = Buffer;
    List = Buffer;
}

void display()
{
    Node *LinkedList = start;
    while (LinkedList->next != NULL)
    {
        printf("%d ", LinkedList->element);
        LinkedList = (Node *)LinkedList->next;
    }
    printf("%d\n", LinkedList->element);
}

void displayUsingFor()
{
    for(Node *tmp = start; tmp != NULL; tmp = tmp->next)
    {
        printf("%d ", tmp->element);
    }
    printf("\n");
}

// Returns address of Node if element is found
// Else returns NULL
Node *find(int theElement)
{
    Node *LinkedList = start;
    while (LinkedList->next != NULL)
    {
        if (LinkedList->element == theElement)
        {
            return LinkedList;
        }
        LinkedList = (Node *)LinkedList->next;
    }
    if (LinkedList->element == theElement)
        return LinkedList;
    else
        return NULL;
}

// Deletes Nodei if element exists
void deleteFirst(int theElement)
{
    //Check for  first element
    if (start->element == theElement)
    {
        start = start->next;
    }
    else // Check for other elements
    {
        Node *LinkedList = start;
        Node *nodeToDelete = start->next;
        while (nodeToDelete != NULL)
        {
            if (nodeToDelete->element == theElement)
            {
                LinkedList->next = nodeToDelete->next;
                break;
            }
            nodeToDelete = (Node *)nodeToDelete->next;
            LinkedList = (Node *)LinkedList->next;
        }
    }
}

void deleteAll(int theElement)
{
    while(find(theElement))
        deleteFirst(theElement);
}

void clear()
{
    free(List);
    List = NULL;
    start = NULL;
}

int main(void)
{
    createList(5);
    insert(10);
    insert(20);
    insert(20);
    insert(30);
    display();

    deleteFirst(5);
    deleteAll(20);
    display();
    
    clear();
    
    createList(10);
    display();
    
    displayUsingFor();
}