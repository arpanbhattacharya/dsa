#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node *insertNode(struct Node *root, int value)
{
    if (root == NULL)
    {
        root = createNode(value);
    }
    else
    {
        printf("Where do you want to place %d?\n", value);
        printf("The pointer is at %d right now\n", root->data);
        printf("1. Left or 2. Right?\n");
        int n;
        scanf("%d", &n);
        if (n == 1)
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

struct Node *deleteNode(struct Node *root, int value)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->data == value)
    {
        struct Node *loop = root;
        while (loop->left != NULL)
        {
            loop = loop->left;
        }
        while (loop->right != NULL)
        {
            loop = loop->right;
        }
        root->data = loop->data;
        free(loop);
        return root;
    }
    else
    {
        struct Node *loop1 = deleteNode(root->left, value);
        struct Node *loop2 = deleteNode(root->right, value);
    }
    // printf("Value doesn't exist");
}

void displayLevelOrder(struct Node *root, int level)
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

int findHeight(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
}

void displayLevelWise(struct Node *root)
{
    int height = findHeight(root);
    for (int i = 1; i <= height; i++)
    {
        displayLevelOrder(root, i);
        printf("\n");
    }
}

void order(struct Node *root)
{
    if (root->left != NULL)
    {
        if (root->right != NULL)
        {
            printf("Order of the Tree is 2");
        }
        printf("Order of the Tree is 1");
    }
    printf("Order of the Tree is 0");
}

// void countLeafNodes(struct Node *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }
//     if (root->left != NULL)
//     {
//         struct Node *loop1 =
//     }
// }

int main()
{
    struct Node *root = NULL;

    while (1)
    {
        int ch, num, n;
        printf("1. Insert\n2. Delete");
        printf("3. Height\n4. Order\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter Data: ");
            scanf("%d", &n);
            root = insertNode(root, n);
            break;
        case 2:
            printf("Enter Data: ");
            scanf("%d", &n);
            root = deleteNode(root, n);
            break;
        case 3:
            printf("Height of the Binary Tree is: %d", findHeight(root));
            break;
        case 4:
            order(root);
            break;
        }
        displayLevelWise(root);
        int x;
        printf("\nDo you want to insert/delete more values?\n1. YES\n2. NO:\n");
        scanf("%d", &x);
        if (x == 2)
        {
            exit(0);
        }
    }

    return 0;
}
