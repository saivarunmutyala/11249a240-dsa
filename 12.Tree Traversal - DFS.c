AIM:To implement and perform tree traversal operations (Preorder, Inorder, and Postorder) on a Binary Search Tree (BST).
Algorithm: 
1.Inserting a Node into the Binary Search Tree

Input: root (pointer to the root node of the BST), value (integer to insert)
Output: root (updated tree root after insertion)
ALGORITHM:
If root is NULL:

Create a new node with the given value.

Set the node's left and right pointers to NULL.

Return the newly created node.

If value is less than root->data:

Recursively insert the value into the left subtree (root->left).

If value is greater than or equal to root->data:

Recursively insert the value into the right subtree (root->right).

Return the updated root after the insertion.

2. Algorithm: Preorder Traversal (Root -> Left -> Right)

Input: root (pointer to the root node of the tree)
Output: Sequence of node values printed in preorder

Steps:

If root is NULL, return (base case).

Print root->data.

Recursively traverse the left subtree (root->left).

Recursively traverse the right subtree (root->right).

3. Algorithm: Inorder Traversal (Left -> Root -> Right)

Input: root (pointer to the root node of the tree)
Output: Sequence of node values printed in inorder

Steps:

If root is NULL, return (base case).

Recursively traverse the left subtree (root->left).

Print root->data.

Recursively traverse the right subtree (root->right).

4. Algorithm: Postorder Traversal (Left -> Right -> Root)

Input: root (pointer to the root node of the tree)
Output: Sequence of node values printed in postorder

Steps:

If root is NULL, return (base case).

Recursively traverse the left subtree (root->left).

Recursively traverse the right subtree (root->right).

Print root->data.

PROGRAM:
#include <stdio.h>
#include <stdlib.h>
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
void preorder(struct Node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void postorder(struct Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main()
{
    int n, value;
    struct Node *root = NULL;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = insert(root, value); 
    }
    printf("Preorder Traversal: ");
    preorder(root);
    printf("\nInorder Traversal: ");
    inorder(root);
    printf("\nPostorder Traversal: ");
    postorder(root);
    return 0;
}
Tree-Traversal-DFS.c
Displaying Tree-Traversal-DFS.c.

Result:
The program takes input from the user for the number of nodes (n) and then dynamically inserts the values into a Binary Search Tree (BST). The three tree traversal methods (Preorder, Inorder, Postorder) are applied to the BST, and the results are printed.

For the given example input:

The BST after inserting values 50 30 20 40 70 looks like:

        50
       /  \
     30    70
    /  \
  20   40
Preorder Traversal (Root -> Left -> Right):
Steps: Visit root node, then left subtree, then right subtree.
Output: 50 30 20 40 70
Inorder Traversal (Left -> Root -> Right):
Steps: Visit left subtree, then root node, then right subtree.
Output: 20 30 40 50 70
Postorder Traversal (Left -> Right -> Root):
Steps: Visit left subtree, then right subtree, then root node.
Output: 20 40 30 70 50
Output
Given the input values of 50 30 20 40 70 and following the tree traversal operations, the printed output will be:
Enter number of elements: Enter number of elements: 5
Enter 5 values:
50 30 20 40 70
Preorder Traversal: 50 30 20 40 70 
Inorder Traversal: 20 30 40 50 70 
Postorder Traversal: 20 40 30 70 50
This output represents the results of the Preorder, Inorder, and Postorder traversals printed in the order specified.
