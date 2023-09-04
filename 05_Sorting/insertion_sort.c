#include <stdio.h>
void insertion_sort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
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
void display(int arr[], int size)
{
    printf("After sorting the array\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
}
int main()
{
    int size;
    printf("Enter the size of the array\n");
    scanf("%d", &size);
    printf("Enter the array\n");
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    insertion_sort(arr, size);
    display(arr, size);
}