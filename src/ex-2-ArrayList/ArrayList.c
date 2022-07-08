#include "ArrayList.h"
#include <stdlib.h>

#define CALCULATE_REALOCATION_JUMP_SIZE(capacity) capacity / 2;

void InitializeArrayList(ArrayList *arrayListToInitialize,
                         size_t capacityToInitialize)
{
    arrayListToInitialize->Capacity = capacityToInitialize;
    arrayListToInitialize->Size = NULL;
    arrayListToInitialize->ReallocationJumpSize = CALCULATE_REALOCATION_JUMP_SIZE(capacityToInitialize);
    arrayListToInitialize->Items = malloc(capacityToInitialize * sizeof(int));
}

void DestructArrayList(ArrayList *arrayListToInitialize)
{
    arrayListToInitialize->Capacity = NULL;
    arrayListToInitialize->Size = NULL;
    arrayListToInitialize->ReallocationJumpSize = NULL;
    free(arrayListToInitialize->Items);
    arrayListToInitialize->Items = NULL;
}

bool TryGetItemAtIndexFromArrayList(ArrayList *arrayList,
                                    size_t index,
                                    int *itemContainer)
{
    if(arrayList == NULL ||
    itemContainer == NULL ||
    arrayList->Items == NULL ||
    index >= arrayList->Size)
    {
        return false;
    }
    *itemContainer = arrayList->Items[index];
    return true;
}