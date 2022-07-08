#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__ 1
#include <stdbool.h>
#include <stddef.h>

typedef struct ArrayList {
  int *Items;
  size_t Size;
  size_t Capacity;
  size_t ReallocationJumpSize;
} ArrayList;

void InitializeArrayList(ArrayList *arrayListToInitialize,
                         size_t capacityToInitialize);

void DestructArrayList(ArrayList *arrayListToInitialize);

bool TryGetItemAtIndexFromArrayList(ArrayList *arrayList,
                                    size_t index,
                                    int *itemContainer);

void CloneArrayList(ArrayList *src, ArrayList *dest);

void AddItemToTheEndOfArrayList(ArrayList *arrayList, int itemToAdd);

bool RemoveItemFromTheEndOfArrayList(ArrayList *arrayList);

#endif // __ARRAY_LIST_H__