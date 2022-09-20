#include <stdio.h>
#define size 10

int hashmap[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

void insert(int element)
{
    int key = element % size;

    if(hashmap[key] == -1)
    {
        hashmap[key] = element;
    }
    else
    {
        printf("Collision, Cannot insert %d\n", element);
    }
}

void search(int element)
{
    int key = element % size;

    if(hashmap[key] == element)
    {
        printf("Element(%d) found\n", element);
    }
    else
    {
        printf("Element(%d) not present in the Map\n", element);
    }
}

void delete(int element)
{
    int key = element % size;

    if(hashmap[key] == element)
    {
        hashmap[key] = -1;
    }
    else
    {
        printf("Tried to delete %d, element not present in the Map", element);
    }
}

void display()
{
    for(int i = 0; i < size; i++)
    {
        if(hashmap[i] != -1)
            printf("Map[%d] = %d\n", i, hashmap[i]);
    }
}

int main(void)
{
    int input;
    while (1)
    {
        printf("---Menu---\n");
        printf("1. Insert Element\n");
        printf("2. Search Element\n");
        printf("3. Display Map\n");
        printf("4. Exit\n\n");

        scanf("%d", &input);

        switch (input)
        {
        case 1:
            int elementInsert;
            printf("\nEnter element to insert\n");
            scanf("%d", &elementInsert);
            insert(elementInsert);
            break;
        case 2:
            int element;
            printf("\nEnter element to search\n");
            scanf("%d", &element);
            search(element);
            break;
        case 3:
            printf("\n");
            display();
            break;
        case 4:
            return 0;
        default:
            printf("\nWrong Input, Try again\n");
            break;
        }
    }
    
}