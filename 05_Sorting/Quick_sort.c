#include <stdio.h>
int split(int arr[], int lower, int upper);
void quick_sort(int arr[], int lower, int upper)
{
    int i;
    if (upper > lower)
    {
        i = split(arr, lower, upper);
        quick_sort(arr, lower, i - 1);
        quick_sort(arr, i + 1, upper);
    }
}
int split(int arr[], int lower, int upper)
{
    int pivotless = lower + 1;
    int pivotgreater = upper;
    int num = arr[lower];
    while (pivotgreater >= pivotless)
    {
        while (arr[pivotless] < num)
        {
            pivotless++;
        }
        while (arr[pivotgreater] > num)
        {
            pivotgreater--;
        }
        if (pivotgreater > pivotless)
        {
            int temp = arr[pivotless];
            arr[pivotless] = arr[pivotgreater];
            arr[pivotgreater] = temp;
        }
    }
    int temp = arr[lower];
    arr[lower] = arr[pivotgreater];
    arr[pivotgreater] = temp;
    return pivotgreater;
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

    printf("Enter the size of the array\n");
    int size;
    scanf("%d", &size);
    printf("Enter the array\n");
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    quick_sort(arr, 0, size);
    display(arr, size);
}