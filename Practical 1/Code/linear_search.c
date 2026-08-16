#include <stdio.h>

int main()
{
    int n, num, i, found = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter number to search: ");
    scanf("%d", &num);

    for (i = 0; i < n; i++)
    {
        if (arr[i] == num)
        {
            printf("Element found at index %d\n", i);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Element not found\n");
    }

    return 0;
}
