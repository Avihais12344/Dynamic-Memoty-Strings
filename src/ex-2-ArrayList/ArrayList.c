#include "ArrayList.h"
#include <stdlib.h>
#include <string.h>

#define CALCULATE_REALOCATION_JUMP_SIZE(capacity) capacity / 2 > 0 ? capacity / 2 : 1;

void ExpandArrayList(ArrayList* arrayList)
{
    arrayList->Capacity = arrayList->Capacity + arrayList->ReallocationJumpSize;
    arrayList->Items = realloc(arrayList->Items, sizeof(int) * arrayList->Capacity);
}

void ContractArrayList(ArrayList* arrayList)
{
    if(arrayList->Capacity <= arrayList->ReallocationJumpSize)
    {
        arrayList->Capacity = 0;
        free(arrayList->Items);
        arrayList->Items = NULL;
        return;
    }
    arrayList->Capacity = arrayList->Capacity - arrayList->ReallocationJumpSize;
    arrayList->Items = realloc(arrayList->Items, sizeof(int) * arrayList->Capacity);
}

void InitializeArrayList(ArrayList *arrayListToInitialize,
                         size_t capacityToInitialize)
{
    arrayListToInitialize->Capacity = capacityToInitialize;
    arrayListToInitialize->Size = 0;
    arrayListToInitialize->ReallocationJumpSize = CALCULATE_REALOCATION_JUMP_SIZE(capacityToInitialize);
    arrayListToInitialize->Items = malloc(capacityToInitialize * sizeof(int));
}

void DestructArrayList(ArrayList *arrayListToDestroy)
{
    if(arrayListToDestroy == NULL)
    {
        return;
    }
    arrayListToDestroy->Capacity = 0;
    arrayListToDestroy->Size = 0;
    arrayListToDestroy->ReallocationJumpSize = 0;
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

void AddItemToTheEndOfArrayList(ArrayList *arrayList, int itemToAdd)
{
    if(arrayList == NULL || arrayList->Items == NULL)
    {
        return;
    }
    else if(arrayList->Size + 1 > arrayList->Capacity)
    {
        ExpandArrayList(arrayList);
    }
    arrayList->Items[arrayList->Size++] = itemToAdd;
}

bool RemoveItemFromTheEndOfArrayList(ArrayList *arrayList)
{
    if(arrayList == NULL || arrayList->Items == NULL)
    {
        return false;
    }
    else if(arrayList - 1 == 0 || arrayList->Size - 1 <= (long int)arrayList->Capacity - arrayList->ReallocationJumpSize)
    {
        ContractArrayList(arrayList);
    }
    arrayList->Size--;
    return false;
}