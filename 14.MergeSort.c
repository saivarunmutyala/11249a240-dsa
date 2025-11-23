AIM:

To implement the Merge Sort algorithm using the Divide and Conquer technique, which recursively divides the array into two halves, sorts them, and merges them back into a sorted array.

  ALGORITHM:
1. Merge Function Algorithm
Purpose: Merge two sorted subarrays into one sorted array.
Input:
arr[] → main array
left → starting index
mid → middle index
right → ending index
Steps:

Initialize:
i = left (pointer for left subarray)
j = mid + 1 (pointer for right subarray)
k = 0 (pointer for temp array)
Create a temporary array temp[] of size right - left + 1.
Compare arr[i] and arr[j]:
If smaller, store in temp[k] and move pointer.
Copy any remaining elements from left subarray.
Copy any remaining elements from right subarray.
Copy all elements from temp[] back into original arr[].

2. Merge Sort Algorithm
Input: Array arr[], starting index left, ending index right.
Steps:
If left < right:
Find the middle index: mid = (left + right) / 2.
Recursively sort left half: mergeSort(arr, left, mid).
Recursively sort right half: mergeSort(arr, mid + 1, right).
Merge the two sorted halves using merge().

3. Main Function Algorithm
Ask user for number of elements n.
Read n elements into array arr[].
Call mergeSort(arr, 0, n - 1).
Print the sorted array.

PROGRAM:
#include <stdio.h>
void merge(int arr[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = 0;
    int temp[right - left + 1];
    while (i <= mid && j <= right)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];
    for (i = left, k = 0; i <= right; i++, k++)
        arr[i] = temp[k];
}
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);     
        mergeSort(arr, mid + 1, right); 
        merge(arr, left, mid, right);   
    }
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    scanf("%d", &arr[i]);
    mergeSort(arr, 0, n - 1);
    printf("Sorted array (Merge Sort): ");
    for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
    return 0;
}
MergeSort.c
Displaying MergeSort.c.

OUTPUT:
Input:
Enter number of elements: 6
Enter 6 elements:
8 3 1 7 0 10

Program Output:
Sorted array (Merge Sort): 0 1 3 7 8 10

RESULT:
The Merge Sort program successfully:
Reads input elements from the user.
Divides the array into smaller subarrays.
Sorts them recursively.
Merges them back into a fully sorted array.
For the sample input, the final sorted array is:
0 1 3 7 8 10
