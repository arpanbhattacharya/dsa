#include <stdio.h>
#include <stdlib.h>

// Node structure for the binary tree
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary tree
struct Node *insertNode(struct Node *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }

    if (value < root->data)
    {
        root->left = insertNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insertNode(root->right, value);
    }

    return root;
}

// Function to find the height of the binary tree
int findHeight(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

// Function to print nodes at a specific level
void printLevel(struct Node *root, int level)
{
    if (root == NULL)
    {
        return;
    }

    if (level == 1)
    {
        printf("%d ", root->data);
    }
    else if (level > 1)
    {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

// Function to display the binary tree level-wise
void displayLevelOrder(struct Node *root)
{
    int height = findHeight(root);
    for (int i = 1; i <= height; i++)
    {
        printf("Level %d: ", i);
        printLevel(root, i);
        printf("\n");
    }
}

int main()
{
    struct Node *root = NULL;

    // Insert nodes into the binary tree
    // root = insertNode(root, 50);
    // insertNode(root, 30);
    // insertNode(root, 20);
    // insertNode(root, 40);
    // insertNode(root, 70);
    // insertNode(root, 60);
    // insertNode(root, 80);

    // // Display the binary tree level-wise
    // printf("Binary Tree Level-wise:\n");
    // displayLevelOrder(root);

    int ch, val, ht;
    printf("\n1. Insert\n2. Display\n3. Height\n5. Exit\n");
    while (ch != 5)
    {
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the value to insert : ");
            scanf("%d", &val);
            root = insertNode(root, val);
            printf("\n%d inserted\n", val);
            break;
        case 2:
            printf("Binary Tree Level-wise:\n");
            displayLevelOrder(root);
            break;
        case 3:
            ht = findHeight(root);
            printf("\nThe height of the tree is %d\n", ht);
            break;

        case 5:
            printf("Exiting");
            break;
        default:
            printf("Invalid input");
        }
    }

    return 0;
}
