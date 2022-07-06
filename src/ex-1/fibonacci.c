#include "fibonacci.h"

uint64_t fibonacci(uint64_t index)
{
    if (index == 0) {
        return 0;
    }
    else if (index == 1) {
        return 1;
    }
    uint64_t currentNumber = 1;
    uint64_t prevNumber = 0;
    for (uint64_t i = 2; i <= index; i++) {
        uint64_t tempHolder = currentNumber;
        currentNumber += prevNumber;
        prevNumber = tempHolder;
    }
    return currentNumber;
}

int get_fib_index(int n) {
    if (n < 0)
    {
        return -1;
    }
    else if (n == 0) {
        return 0;
    }
    uint64_t index = 1;
    uint64_t currentNumber = 0;
    while (currentNumber < n)
    {
        currentNumber = fibonacci(index);
        if (currentNumber == n)
        {
            return index;
        }
        index++;
    }
    return index - 1;
}
