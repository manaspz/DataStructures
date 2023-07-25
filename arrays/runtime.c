/**
 * Allocating memory during runtime
 * Malloc allocates memory blocks of fixed size
 **/

#include <stdio.h>
#include <stdlib.h>

void print_array(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void saveto_array(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
}

int main(void)
{
    int *arr;
    int size;

    printf("Insert the number of integers :");
    scanf("%d", &size);

    // Allocate the required size of block
    arr = malloc(size * sizeof(arr));

    // If in a case the program fails to allocate memory
    if (arr == NULL)
    {
        return 1;
    }

    // Alternatively can be done by int arr[size] but all compilers do not support
    // Variable type allocation with non initialized values

    printf("Input the integer numbers :");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    print_array(arr, size);

    // Free memory on exit
    free(arr);
    return 0;
}