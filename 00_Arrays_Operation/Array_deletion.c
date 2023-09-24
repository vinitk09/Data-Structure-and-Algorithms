#include <stdio.h>
void delete(int arr[], int index, int size)
{
    for (int i = index; i < size; i++)
    {
        arr[i] = arr[i + 1];
    }
}
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = 5;
    printf("Array Before Deletion\n");
    display(arr, size);
    delete (arr, 2, size);
    size = size - 1;
    printf("\nArray After Deletion\n");
    display(arr, size);
    return 0;
}