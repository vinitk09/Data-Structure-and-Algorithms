// traversal --> it means to visit every element of the array
#include <stdio.h>
#include <stdlib.h>
void display(int arr[], int n)
{
    // traversal
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
    printf("\n");
}
int sortedinsertion(int arr[], int size, int ele, int capacity, int index)
{
    if (size >= capacity)
    {
        return -1;
    }
    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = ele;
    return 1;
}
int main()
{
    int arr[100] = {0, 1, 2, 3, 4, 5, 6};
    int size = 7;
    display(arr, size);
    int element = 45;
    int index = 3;
    sortedinsertion(arr, size, element, 100, index);
    size += 1;
    display(arr, size);
    return 0;
}