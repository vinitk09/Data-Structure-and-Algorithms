// Counting sort in C programming
#include <stdio.h>
void countsort(int arr[], int size)
{
    // Find the largest element of the array
    int max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    // The size of count must be at least (max+1) but
    // we cannot declare it as int count(max+1) in C as
    // it does not support dynamic memory allocation.
    // So, its size is provided statically.
    int count[10];

    // Initialize count array with all zeros.
    for (int i = 0; i <= max; ++i)
    {
        count[i] = 0;
    }

    // Store the count of each element
    for (int i = 0; i < size; i++)
    {
        ++count[arr[i]];
    }

    // Store the cummulative count of each array
    for (int i = 1; i <= max; i++)
    {
        count[i] = count[i] + count[i - 1];
    }
    int b[10];

    // Find the index of each element of the original array in count array, and
    // place the elements in output array
    for (int i = size - 1; i >= 0; i--)
    {
        b[--count[arr[i]]] = arr[i];
    }

    // Copy the sorted elements into original array
    for (int i = 0; i < size; i++)
    {
        arr[i] = b[i];
    }
}

// To print the array contents.
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
}
int main()
{
    int size;
    printf("Enter the size\n");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the array\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    countsort(arr, size);
    display(arr, size);
}
