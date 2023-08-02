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
        printf("%d\n ", arr[i]);
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = 5;
    delete (arr, 2, size);
    size = size - 1;
    display(arr, size);
    return 0;
}