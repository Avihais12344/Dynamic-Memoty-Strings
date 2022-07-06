#ifndef __FIBONACCI_H__
#define __FIBONACCI_H__

#include <stdint.h>

uint64_t fibonacci(uint64_t index);

/*
* @brief This function return the closest fibonacci index of an item to a given item (if the item is a natual number).
*/
int get_fib_index(int n);

#endif // __FIBONACCI_H__