#include <stdio.h>
#include <time.h>

int main()
{
    int n, key, i;
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

    printf("Enter element to search: ");
    scanf("%d", &key);

    start = clock();

    for (i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            found = 1;
            position = i;
            break;
        }
    }

    end = clock();
    executionTime = (double)(end - start) / CLOCKS_PER_SEC;

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
    printf("Average Case: O(n)\n");
    printf("Worst Case: O(n)\n");
    printf("Space Complexity: O(1)\n");

    return 0;
}
