Aim:
To write a C program to implement basic stack operations such as Push, Pop, and Display using a linked list, where insertion and deletion are performed at the top of the list.

Algorithm:
1. Start the program
2. Define a structure NODE
Contains data
Contains pointer next
3. Initialize
top = NULL
PUSH (Insert at top)
Read the value
Create a new node
Set newNode->data = value
Set newNode->next = top
Update top = newNode
POP (Delete from top)
If top == NULL
→ Print “Stack Underflow”
Else:
Store top in temp
Update top = top->next
Free temp
DISPLAY
If stack is empty → print message
Else traverse from top to NULL
Print each node's data
4.Repeat using switch case until user chooses EXIT
5.Stop the program

Program:
#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;             
    struct Node *next;      
};
struct Node *top = NULL;    
void push() 
{
    int value;
    printf("Enter value to push: ");
    scanf("%d", &value);
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("Element pushed.\n");
}
void pop() 
{
    if (top == NULL) 
    {          
        printf("Stack Underflow.\n");
        return;
    }

    struct Node *temp = top;    
    top = top->next;         
    free(temp);   
    printf("Element popped.\n");
}
void display() 
{
    if (top == NULL) 
    {
        printf("Stack is empty.\n");
        return;
    }
    struct Node *temp = top;
    printf("Stack elements (top to bottom): ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);  
        temp = temp->next;            
    }

    printf("NULL\n");
}
int main() 
{
    int choice;
    while (1) 
    {
        printf("\n--- STACK USING LINKED LIST ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1: 
              push(); break;
            case 2: 
              pop(); break;
            case 3: 
              display(); break;
            case 4: 
              return 0;   
            default: printf("Invalid choice!\n");
        }
    }
}
Output:
--- STACK USING LINKED LIST ---
1. Push
2. Pop
3. Display
4. Exit
Enter choice: 1
Enter value to push: 15
Element pushed.

Enter choice: 1
Enter value to push: 25
Element pushed.

Enter choice: 3
Stack elements (top to bottom): 25 -> 15 -> NULL

Enter choice: 2
Element popped.

Enter choice: 3
Stack elements (top to bottom): 15 -> NULL

Enter choice: 4

Result:
The program successfully demonstrates stack operations using a linked list. It performs push, pop, and display efficiently by inserting and deleting elements at the top of the linked list.
