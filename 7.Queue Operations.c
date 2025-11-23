Aim:
To write a C program to implement queue operations using array, including Enqueue, Dequeue, and Display, along with proper handling of overflow and underflow conditions.

Algorithm:
1. Start the program
2. Initialize
front = -1
rear = -1
Read MAX (size of the queue)
Create array queue[MAX]
3. Enqueue Operation
Check if rear == MAX - 1
→ If true, display Queue Overflow
Else:
Read the element item
If queue is empty (front == -1 and rear == -1):
→ set front = rear = 0
Else:
→ rear = rear + 1
Insert item into queue[rear]
4. Dequeue Operation
Check if queue is empty (front == -1 or front > rear)
→ Display Queue Underflow
Else:
Remove element from queue[front]
Increment front = front + 1
If front > rear after deletion:
→ Reset queue → front = rear = -1
5. Display Operation
If queue is empty: print Queue is Empty
Else:
Print all elements from queue[front] to queue[rear]
6. Repeat operations until user chooses Exit
7. Stop the program

Program:
#include<stdio.h>
int front = -1, rear = -1, MAX;   
void enqueue(int queue[])
{
    int item;
    if(rear == MAX - 1)
    {
        printf("Queue is Overflow\n");
    }
    else
    {
        printf("Enter element to enqueue : ");
        scanf("%d", &item);
        if(front == -1 && rear == -1)
        {
            front = rear = 0;
        }
        else
        {
            rear = rear + 1;
        }

        queue[rear] = item;  
    }
}
void dequeue(int queue[])
{
    if(front == -1 || front > rear)
    {
        printf("Queue is Underflow\n");
    }
    else
    {
        int item = queue[front];  
        front = front + 1;       
        if(front > rear)
        {
            front = rear = -1;
        }
    }
}
void display(int queue[])
{
    if(front == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Current Queue elements: ");
        for(int i = front; i <= rear; i++)
        {
            printf(" %d ", queue[i]);  
        }
        printf(" <-rear\n");  
    }
}

int main()
{
    int choice;
    printf("Enter the size of queue: ");
    scanf("%d", &MAX);

    int queue[MAX];   
    while(1)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Choose queue operation: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                enqueue(queue);
                break;

            case 2:
                dequeue(queue);  
                break;

            case 3:
                display(queue);   
                break;

            case 4:
                return 0;        

            default:
                printf("Invalid choice\n");
        }
    }
}

Output:
Enter the size of queue: 5

1. Enqueue
2. Dequeue
3. Display
4. Exit
Choose queue operation: 1
Enter element to enqueue : 10

1. Enqueue
2. Dequeue
3. Display
4. Exit
Choose queue operation: 1
Enter element to enqueue : 20

Choose queue operation: 3
Current Queue elements: 10 20 <-rear

Choose queue operation: 2
(10 is deleted)

Choose queue operation: 3
Current Queue elements: 20 <-rear

Choose queue operation: 4

Result:
The program successfully implements queue operations using an array.
It performs enqueue, dequeue, and display operations correctly and handles overflow and underflow conditions properly.
