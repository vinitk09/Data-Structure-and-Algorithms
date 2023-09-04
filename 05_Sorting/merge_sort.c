#include <stdio.h>
void merge(int arr[], int left, int mid, int right)
{
    int n1[100], n2[100];
    for (int i = 0; i < right; i++)
    {
        n1[i] = arr[i];
    }
    for (int i = 0; i < right; i++)
    {
        n2[i] = arr[i];
    }
}
void mergesort(int arr[], int left, int right)
{
    int mid = (left + right) / 2;

    if (left <= right)
    {
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);
        merge(arr, left, mid, right);
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

    mergesort(arr, 0, size);
}