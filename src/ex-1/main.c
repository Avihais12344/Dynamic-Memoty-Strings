#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fibonacci.h"

#define ARR_SIZE 5

/**
 * @brief Create a new array with every cell has the index it's in (for example, the first index would have the value 0).
 * @warning This function allocates the array with malloc and it must be freed with the `free` function.
 */
int* create_index_arr(int n)
{
    if(n < 1)
    {
        return NULL;
    }
    int* arr = malloc(n * sizeof(int));
    
    for(size_t i = 0; i < n; i++){
        arr[i] = i;    
    }
    return arr;
}

/**
 * @warning This function allocates the array with malloc and it must be freed with the `free` function.
 * numbers may be dynamic array, it can also be a static array, it doesn't matter because we get it's size.
 */
int* duplicate_numbers(const int* numbers, int length)
{
    if(length < 1 || numbers == NULL)
    {
        return NULL;
    }
    int* numbersCopy = malloc(sizeof(int) * length);
    memcpy(numbersCopy, numbers, length * sizeof(int));
    return numbersCopy;

}


/*
 * @warning This function allocates the array with malloc and it must be freed with the `free` function.
*/
int* fib(int max_num)
{
    const int arrayLength = get_fib_index(max_num) + 1;
    if (arrayLength == -1)
    {
        return NULL;
    }
    int* numbers = malloc(sizeof(int) * arrayLength);
    for (int i = 0; i < arrayLength; i++)
    {
        numbers[i] = fibonacci(i);
    }
    return numbers;
}

int main(void)
{
    int* arr = create_index_arr(ARR_SIZE);
    for(size_t i = 0; i < ARR_SIZE; i++){
        printf("%d\n", arr[i]);
    }
    putchar('\n');
    int* secondArr = duplicate_numbers(arr, ARR_SIZE);
    for(size_t i = 0; i < ARR_SIZE; i++){
        printf("%d\n", arr[i]);
    }
    int* fibNums = fib(8);
    free(arr);
    free(secondArr);
    free(fibNums);
    return 0;
}