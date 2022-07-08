#include "ArrayList.h"
#include <stdlib.h>
#include <string.h>

#define CALCULATE_REALOCATION_JUMP_SIZE(capacity) capacity / 2;

void InitializeArrayList(ArrayList *arrayListToInitialize,
                         size_t capacityToInitialize)
{
    arrayListToInitialize->Capacity = capacityToInitialize;
    arrayListToInitialize->Size = NULL;
    arrayListToInitialize->ReallocationJumpSize = CALCULATE_REALOCATION_JUMP_SIZE(capacityToInitialize);
    arrayListToInitialize->Items = malloc(capacityToInitialize * sizeof(int));
}

void DestructArrayList(ArrayList *arrayListToDestroy)
{
    if(arrayListToDestroy == NULL)
    {
        return;
    }
    arrayListToDestroy->Capacity = NULL;
    arrayListToDestroy->Size = NULL;
    arrayListToDestroy->ReallocationJumpSize = NULL;
    free(arrayListToDestroy->Items);
    arrayListToDestroy->Items = NULL;
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

void CloneArrayList(ArrayList *src, ArrayList *dest)
{
    // First, destroy the destination array list.
    DestructArrayList(dest);
    // If we can't copy the source, leave it be.
    if(src == NULL) 
    {
        return;
    }
    // Copy the basic items.
    dest->Capacity = src->Capacity;
    dest->Size = src->Size;
    dest->ReallocationJumpSize = src->ReallocationJumpSize;
    // Initialize and copy the array.
    dest->Items = malloc(src->Capacity);
    memcpy(dest->Items, src->Items, src->Size);
}