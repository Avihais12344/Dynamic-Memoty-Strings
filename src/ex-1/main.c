#include <stdlib.h>
#include <stdio.h>

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

int main(void)
{
    int* arr = create_index_arr(ARR_SIZE);
    for(size_t i = 0; i < ARR_SIZE; i++){
        printf("%d\n", arr[i]);
    }
    free(arr);
    return 0;
}