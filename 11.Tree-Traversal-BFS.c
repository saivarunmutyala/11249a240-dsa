AIM:
To create a Binary Search Tree (BST) from user inputs and perform Level Order Traversal (Breadth-First Search - BFS) using a queue implemented with arrays.

ALGORITHM:
1. Algorithm for Node Creation
Allocate memory for a new node.
Assign the given value to data.
Set left and right children to NULL.
Return the newly created node.
2. Algorithm for BST Insertion
Input: root, value
Output: Updated root
Steps:
If root is NULL → create a new node and return it.
If value < root->data, recursively insert into the left subtree.
Otherwise, insert into the right subtree.
Return the updated root node.
3. Queue Algorithms for BFS
Enqueue
If queue is full (rear == MAX - 1), stop.
If queue is empty (front == -1), set front = 0.
Increment rear and insert the node at queue[rear].
Dequeue
If queue is empty (front == -1 or front > rear), return NULL.
Return queue[front] and increment front.
4. Level Order Traversal (BFS) Algorithm
Input: root
Output: Prints nodes in level‐orde
Steps:
If root is NULL, return.
Enqueue the root node.
While queue is not empty:
Dequeue a node and print its data.
If the node has a left child → enqueue it.
If the node has a right child → enqueue it.
PROGRAM:
#include <stdio.h>
#include <stdlib.h>
struct Node **queue;
int front = -1, rear = -1, MAX;
struct Node
{
    int data;
    struct Node *left, *right;
};
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node *insert(struct Node *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}
void enqueue(struct Node *temp)
{
    if (rear == MAX-1)
        return; 
    if (front == -1)
        front = 0;
    queue[++rear] = temp;
}
struct Node *dequeue()
{
    if (front == -1 || front > rear)
    return NULL;
    return queue[front++];
}
void levelOrder(struct Node *root)
{
    if (root == NULL)
    return;
    enqueue(root);
    while (front <= rear)
    {
        struct Node *current = dequeue();
        printf("%d ", current->data);
        if (current->left != NULL)
            enqueue(current->left);
        if (current->right != NULL)
            enqueue(current->right);
    }
}

int main()
{
    int value;
    struct Node *root = NULL;
    printf("Enter number of elements: ");
    scanf("%d", &MAX);
    queue = (struct Node **)malloc(MAX * sizeof(struct Node *));
    printf("Enter %d values:\n", MAX);
    for (int i = 0; i < MAX; i++)
    {
        scanf("%d", &value);
        root = insert(root, value); // Insert dynamically into BST
    }
    printf("\nLevel Order Traversal: ");
    levelOrder(root);
    return 0;
}
Tree-Traversal-BFS.c
Displaying Tree-Traversal-BFS.c.
  
OUTPUT:
Example Input:
Enter number of elements: 6
Enter 6 values:
50 30 70 20 40 60


The BST formed:

        50
       /  \
     30    70
    / \    /
  20  40  60


Program Output:

Level Order Traversal: 50 30 70 20 40 60

 RESULT:
The program successfully:
Accepts user input values.
Inserts them into a Binary Search Tree (BST).
Stores nodes in a queue for BFS.
Prints nodes level by level using Level Order Traversal.
For the sample input, the traversal order is:
50 30 70 20 40 60

This matches the expected BFS output.
