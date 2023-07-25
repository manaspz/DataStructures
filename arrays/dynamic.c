/**
 * Allocating memory during runtime
 * Allocate a fixed block of space initially
 * If the required space exceeds the initial space
 * Double the memory and copy over all the elements, freeing the previous block
 * If the initial block turns out to be larger free the remaining space
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Initial capacity is 10 elements
*/ 
#define INITIAL_CAPACITY 10
#define GROWTH_FACTOR 2

/**
 * But the range of elements is 1-20
 */
#define SIZE 20

/**
 * Struct contains an : array pointer
 * size_t type size and capacity unsigned 16bit
 * defines upper max limit on the memory block
 **/
typedef struct
{
    int *array;
    size_t size;
    size_t capacity;
} DynamicArray;

DynamicArray *createDynamicArray()
{
    DynamicArray *dynamicArray = (DynamicArray *)malloc(sizeof(DynamicArray));
    if (dynamicArray == NULL)
    {
        printf("Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }

    dynamicArray->array = (int *)malloc(INITIAL_CAPACITY * sizeof(int));
    if (dynamicArray->array == NULL)
    {
        printf("Memory allocation error.\n");
        free(dynamicArray);
        exit(EXIT_FAILURE);
    }

    dynamicArray->size = 0;
    dynamicArray->capacity = INITIAL_CAPACITY;

    return dynamicArray;
}

void push(DynamicArray *dynamicArray, int value)
{
    if (dynamicArray->size == dynamicArray->capacity)
    {
        // Amortization
        size_t newCapacity = dynamicArray->capacity * GROWTH_FACTOR;
        int *newArray = (int *)realloc(dynamicArray->array, newCapacity * sizeof(int));

        if (newArray == NULL)
        {
            printf("Memory allocation error.\n");
            exit(EXIT_FAILURE);
        }

        dynamicArray->array = newArray;
        dynamicArray->capacity = newCapacity;
    }

    dynamicArray->array[dynamicArray->size] = value;
    dynamicArray->size++;
}

void printArray(DynamicArray *dynamicArray, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", dynamicArray->array[i]);
    }
    printf("\n");
}

void freeDynamicArray(DynamicArray *dynamicArray)
{
    free(dynamicArray->array);
    free(dynamicArray);
}

int main(void)
{
    DynamicArray *dynamicArray = createDynamicArray();

    // Template insertion of integer elements
    for (int i = 1; i <= SIZE; i++)
    {
        push(dynamicArray, i);
    }

    printArray(dynamicArray, SIZE);
    freeDynamicArray(dynamicArray);
    return 0;
}
