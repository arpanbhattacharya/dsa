#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *createNode(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct node *insertNode(struct node *root, int value)
{
    if (root == NULL)
    {
        root = createNode(value);
    }
    else
    {
        int c;
        printf("pointer at %d", root->data);
        printf("\n1. Left\n2. Right");
        scanf("%d", &c);

        if (c == 1)
        {
            root->left = insertNode(root->left, value);
        }
        else
        {
            root->right = insertNode(root->right, value);
        }
    }
    return root;
}

void displayLevelOrder(struct node *root, int level)
{
    if (root == NULL)
    {
        printf("NULL ");
        return;
    }

    if (level == 1)
    {
        printf("%d ", root->data);
    }
    else if (level > 1)
    {
        displayLevelOrder(root->left, level - 1);
        displayLevelOrder(root->right, level - 1);
    }
}

int findHeight(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
}

void displayLevelWise(struct node *root)
{
    int height = findHeight(root);
    for (int i = 1; i <= height; i++)
    {
        displayLevelOrder(root, i);
        printf("\n");
    }
}

void order(struct node *root, int check)
{
    // if (root->left != NULL)
    // {
    //     if (root->right != NULL)
    //     {
    //         printf("The order is 2");
    //         return;
    //     }
    //     printf("The order is 1");
    //     return;
    // }
    // printf("The order is 0");
    // return;
    if(root->data == check){
        return;
    }
    root->left = order(root, check);
    root->right = order(root, check);
}

void main()
{
    struct node *root = NULL;
    int ch, val1, height, check;
    printf("\n1. Insert\n2. Display\n3. Height\n4. Order\n5. Exit");
    while (ch != 5)
    {
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the data to insert : ");
            scanf("%d", &val1);
            root = insertNode(root, val1);
            printf("\n%d inserted\n", val1);
            break;
        case 2:
            printf("\nThe tree structure : \n");
            displayLevelWise(root);
            break;
        case 3:
            height = findHeight(root);
            printf("\nHeight is %d\n", height);
            break;
        case 4:
            printf("\nEnter the node to check order : ");
            scanf("%d",&check);
            order(root);
            break;
        case 5:
            printf("Exiting");
            break;
        default:
            printf("Invalid choice");
            break;
        }
    }
}