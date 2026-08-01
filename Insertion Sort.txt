#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main()
{
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Please enter a valid number of elements.\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the elements:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    /* Measure execution time */
    clock_t startTime = clock();

    insertionSort(arr, n);

    clock_t endTime = clock();

    double executionTime =
        (double)(endTime - startTime) / CLOCKS_PER_SEC;

    printf("\nSorted Array: ");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n\nExecution Time: %.8f seconds\n", executionTime);

    printf("\nTime Complexity:\n");
    printf("Best Case   : O(n)\n");
    printf("Average Case: O(n^2)\n");
    printf("Worst Case  : O(n^2)\n");

    printf("\nSpace Complexity: O(1)\n");

    free(arr);

    return 0;
}
