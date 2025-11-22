//Programmer: Chau Nguyen

#include <iostream>
#include <array>
#include <cmath>
#include <algorithm>
#include "constants.h"


int FCFS(int head, const std::vector<int>& vector)
{
    int headMovement = std::abs(vector[0] - head);

    for (size_t i = 1; i < NUMBER_OF_REQUESTS; ++i)
    {
        headMovement += std::abs(vector[i] - vector[i-1]); 
    }

    return headMovement;
} 

int SSTF(int head, std::vector<int> vector)
{
    int result = 0;
    //Find the next location that is closet to head
    size_t i = 0;

    while(i < NUMBER_OF_REQUESTS)
    {
        int current = vector[0];
        int oldMinDistance = std::abs(current - head);
        int newMinDistance = 0;
        size_t nextIndex = 0;
        bool justDeleted = false;
        for (size_t j = 0; j< NUMBER_OF_REQUESTS; ++j)
        {
            newMinDistance = std::min(oldMinDistance, std::abs(vector[j] - head));
            if(newMinDistance != oldMinDistance)
            {
                //Obtain the next location
                nextIndex = j;
            }
        }
        result += newMinDistance;
        //Obtain new head value
        head = vector[nextIndex];
        //Delete that entry, so that we don't duplicate calculating it. 
        vector.erase(vector.begin() + nextIndex);

        
        //Remove the element at that index

        //may not increment i. may done = true when delete all elements in vector. 

        ++i;
    } 

    return 0;
}