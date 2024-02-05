#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to calculate the parent index
int getParentIndex(int index)
{
    return (index - 1) / 2;
}

// Function to calculate the left child index
int getLeftChildIndex(int index)
{
    return 2 * index;
}

// Function to calculate the right child index
int getRightChildIndex(int index)
{
    return 2 * index + 1;
}

// Function to display the binary tree level-wise
void displayTreeLevelWise(int tree[], int size)
{
    if (size == 0)
    {
        printf("Tree is empty!\n");
        return;
    }

    int level = 1, i = 0;
    while (i < size)
    {
        printf("Level %d: ", level++);
        int levelNodes = 1 << (level - 1);
        for (int j = 0; j < levelNodes && i < size; ++j, ++i)
        {
            printf("%d ", tree[i]);
        }
        printf("\n");
    }
}

// Function to insert a node in the tree
void insertNode(int tree[], int *size, int value)
{
    if (*size == MAX_SIZE)
    {
        printf("Tree is full! Cannot insert more nodes.\n");
        return;
    }

    // Insert the new value at the next available position
    int index = *size;
    tree[index] = value;

    // Adjust the position by moving up the tree
    while (index > 0)
    {
        int parentIndex = getParentIndex(index);
        if (tree[index] > tree[parentIndex])
        {
            // Swap values if the new value is greater than the parent
            int temp = tree[index];
            tree[index] = tree[parentIndex];
            tree[parentIndex] = temp;
            index = parentIndex;
        }
        else
        {
            // Break if the new value is not greater than the parent
            break;
        }
    }

    // Increase the size of the tree
    (*size)++;
    printf("Node %d inserted!\n", value);
}

int main()
{
    int tree[MAX_SIZE];
    int size = 0; // Current size of the tree array
    int choice, value;

    do
    {
        printf("\nMenu:\n");
        printf("1. Insert Node\n");
        printf("2. Display Tree Level-wise\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value for the new node: ");
            scanf("%d", &value);
            insertNode(tree, &size, value);
            break;

        case 2:
            printf("Tree elements (level-wise):\n");
            displayTreeLevelWise(tree, size);
            break;

        case 3:
            printf("Exiting the program. Goodbye!\n");
            break;

        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }

    } while (choice != 3);

    return 0;
}
