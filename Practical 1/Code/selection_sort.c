#include <stdio.h>

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        // Assume the current position holds the minimum element
        int min_idx = i;

        // Find the minimum element in the unsorted portion
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }

        // Swap the minimum element with the current element
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n;

    // Take array size from user
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Take array elements from user
    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Print original array
    printf("Original array: ");
    printArray(arr, n);

    // Calling selection sort
    selectionSort(arr, n);

    // Print sorted array
    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
