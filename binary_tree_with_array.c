#include <stdio.h>
#define max 100

void buildTree(int arr[], int index, int item)
{
    int ch, val;

    arr[index] = item;
    printf("\nDo you want left child of %d ? (1. yes 2. no) ", arr[index]);
    scanf("%d", &ch);
    if (ch == 1)
    {
        printf("\nEnter left child of %d : ", arr[index]);
        scanf("%d", &val);
        buildTree(arr, 2 * index, val);
    }

    printf("\nDo you want right child of %d ? (1. yes 2. no) ", arr[index]);
    scanf("%d", &ch);
    if (ch == 1)
    {
        printf("\nEnter right child of %d : ", arr[index]);
        scanf("%d", &val);
        buildTree(arr, 2 * index + 1, val);
    }
}

void main()
{
    int tree[max], item;
    for (int i = 0; i < max; i++)
        tree[i] = -1;

    printf("\nEnter the value of root node : ");
    scanf("%d", &item);

    buildTree(tree, 1, item);

    printf("\nTree Structure : \n");
    for (int i = 1; i <= max; i++)
    {
        if (tree[i] == -1)
        {
            printf("- ");
        }
        else
        {
            printf("%d ", tree[i]);
        }
    }
}