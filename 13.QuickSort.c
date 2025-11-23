AIM:
To implement Quick Sort, a divide-and-conquer sorting algorithm that uses partitioning to recursively sort elements in an array.
ALGORITHM:
1. Swap Algorithm
Purpose: Swap values of two variables using call-by-reference.
Steps:
Store *a in temporary variable temp.
Assign *b to *a.
Assign temp to *b.
2. Partition Algorithm
Input: list[], low, high
Purpose: Position the pivot such that:
All elements smaller than pivot go to the left.
All elements greater go to the right.
Steps:
Choose pivot as list[high].
Initialize index i = low - 1.
Loop j from low to high - 1:
If list[j] < pivot:
Increase i.
Swap list[i] with list[j].
After loop ends, swap list[i+1] with pivot (list[high]).
Return pivot index i + 1.
3. Quick Sort Algorithm
Input: list[], low, high
Steps:
If low < high:
Partition the array → store pivot index pi.
Recursively apply Quick Sort to:
Left subarray → quickSort(list, low, pi - 1)
Right subarray → quickSort(list, pi + 1, high)
4. Main Function Algorithm
Read number of elements n.
Read n elements into array list[].
Call quickSort(list, 0, n - 1).
Print the sorted array.

PROGRAM:
#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int list[], int low, int high)
{
    int pivot = list[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (list[j] < pivot)
        {
            i++;
            swap(&list[i], &list[j]);
        }
    }
    swap(&list[i + 1], &list[high]);
    return i + 1;
}
void quickSort(int list[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(list, low, high);
        quickSort(list, low, pi - 1);
        quickSort(list, pi + 1, high);
    }
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int list[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &list[i]);

    quickSort(list, 0, n - 1);

    printf("Sorted array (Quick Sort): ");
    for (int i = 0; i < n; i++)
        printf("%d ", list[i]);

    return 0;
}
QuickSort.c
Displaying QuickSort.c.

OUTPUT:
Input:
Enter number of elements: 7
Enter 7 elements:
10 7 8 9 1 5 3

Program Output:
Sorted array (Quick Sort): 1 3 5 7 8 9 10

 RESULT:
The Quick Sort program successfully:
Takes user input elements.
Uses partitioning and recursion to sort the array.
Produces the final sorted list in ascending order.
For the sample input, the resulting sorted array is:
1 3 5 7 8 9 10
