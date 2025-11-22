//Programmer: Chau Nguyen

#include <iostream>
#include <array>
#include <cmath>
#include "constants.h"


int FCFS(int head, const std::array<int, NUMBER_OF_REQUESTS>& array)
{
    int headMovement = std::abs(array[0] - head);
    for (size_t i = 1; i < NUMBER_OF_REQUESTS; ++i)
    {
        headMovement += std::abs(array[i] - array[i-1]); 
    }

    return headMovement;

} 