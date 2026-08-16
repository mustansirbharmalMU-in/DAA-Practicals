#include <stdio.h>
#include <time.h>

void bubbleSort(int arr[], int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n, key, i;
    int low, high, mid;
    int found = 0;
    int position = -1;
    clock_t start, end;
    double executionTime;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    /* Sort the array (same as arr.sort() in Python) */
    bubbleSort(arr, n);

    printf("Enter element to search: ");
    scanf("%d", &key);

    start = clock();

    low = 0;
    high = n - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] == key)
        {
            found = 1;
            position = mid;
            break;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    end = clock();
    executionTime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    if (found)
    {
        printf("Element found at index %d\n", position);
    }
    else
    {
        printf("Element not found\n");
    }

    printf("Execution Time: %.8f seconds\n", executionTime);
    printf("Time Complexity:\n");
    printf("Best Case: O(1)\n");
    printf("Average Case: O(log n)\n");
    printf("Worst Case: O(log n)\n");
    printf("Space Complexity: O(1)\n");

    return 0;
}
