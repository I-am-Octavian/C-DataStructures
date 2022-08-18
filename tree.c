#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct treeNode
{
    struct treeNode *leftPtr;
    int data;
    struct treeNode *rightPtr;
};

typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;

void searchNode(TreeNodePtr *treePtr, int key);
void insertNode(TreeNodePtr *treePtr, int value);
void inOrder(TreeNodePtr treePtr);
void preOrder(TreeNodePtr treePtr);
void postOrder(TreeNodePtr treePtr);

int main(void)
{
    TreeNodePtr rootPtr = NULL;
    
    srand(time(NULL));
    puts("The numbers being placed in the tree are:");

    for(unsigned int i = 1; i <= 10; i++)
    {
        int item = rand() % 15;
        printf("%3d", item);
        insertNode(&rootPtr, item);
    }

    puts("\n\nThe preOrder traversal is:");
    preOrder(rootPtr);

    puts("\n\nThe inOrder traversal is:");
    inOrder(rootPtr);

    puts("\n\nThe postOrder traversal is:");
    postOrder(rootPtr);

    int elementToFind;
    printf("\n\nEnter element to search in the tree: ");
    scanf("%d", &elementToFind);
    searchParent(&rootPtr, elementToFind);
}

void searchParent(TreeNodePtr *treePtr, int key)
{
    TreeNodePtr parent = NULL;

    if (key == (*treePtr)->data)
    {
        parent = *treePtr; // Parent is root itself

        printf("Parent is root itself i.e. Parent = %d\n", parent->data);
        return;
    }
    else
    {
        // key is not the root element

        // Loop while current node is not a leaf
        while ((*treePtr)->leftPtr != NULL || (*treePtr)->rightPtr != NULL)
        {
            if (key < (*treePtr)->data && (*treePtr)->leftPtr != NULL)
            {
                // check left sub-tree
                parent = *treePtr;

                if ((parent->leftPtr)->data == key)
                {
                    printf("Left child of %d\n", parent->data);
                    return;
                }
                else
                    (*treePtr) = parent->leftPtr;

            }
            else if (key > (*treePtr)->data && (*treePtr)->rightPtr != NULL)
            {
                // check right sub-tree
                parent = *treePtr;

                if ((parent->rightPtr)->data == key)
                {
                    printf("Right child of %d\n", parent->data);
                    return;
                }
                else
                    (*treePtr) = parent->rightPtr;

            }
        }
    }

    printf("Element not found in the tree\n");
}

void insertNode(TreeNodePtr *treePtr, int value)
{
    if (*treePtr == NULL)
    {
        *treePtr = malloc(sizeof(TreeNode));

        if (*treePtr != NULL)
        {
            (*treePtr)->data = value;
            (*treePtr)->leftPtr = NULL;
            (*treePtr)->rightPtr = NULL;
        }
        else
        {
            printf("%d not inserted. No memory available.\n", value);
        }
    }
    else
    {
        if (value < (*treePtr)->data)
        {
            insertNode(&((*treePtr)->leftPtr), value);
        }
        else if (value > (*treePtr)->data)
        {
            insertNode(&((*treePtr)->rightPtr), value);
        }
        else
        {
            printf("%s", "dup");
        }
    }
}

void inOrder(TreeNodePtr treePtr)
{
    if (treePtr != NULL)
    {
        inOrder(treePtr->leftPtr);
        printf("%3d", treePtr->data);
        inOrder(treePtr->rightPtr);
    }
}

void preOrder(TreeNodePtr treePtr)
{
    if (treePtr != NULL)
    {
        printf("%3d", treePtr->data);
        preOrder(treePtr->leftPtr);
        preOrder(treePtr->rightPtr);
    }
}

void postOrder(TreeNodePtr treePtr)
{
    if (treePtr != NULL)
    {
        postOrder(treePtr->leftPtr);
        postOrder(treePtr->rightPtr);
        printf("%3d", treePtr->data);
    }
}
