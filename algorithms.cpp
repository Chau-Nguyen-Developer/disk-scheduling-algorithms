//Programmer: Chau Nguyen

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "constants.h"


int FCFS(int head, const std::vector<int>& myVector)
{
    //If the segment faults happen before any of these lines, that tells us the vector reference itself is
    //invalid
    std::cout << "FCFS is being called. Head = " << head << 
    ", size = " << myVector.size() << "\n";

    int headMovement = 0;
    if (myVector.empty())
    {
        std::cout << "Vector is empty. Return 0\n";
        return 0;
    }

    headMovement = std::abs(myVector[0] - head);
    int len = myVector.size();

    for (size_t i = 1; i < len; ++i)
    {
        headMovement += std::abs(myVector[i] - myVector[i-1]); 
    }
   
    
    return headMovement;
}


// int SSTF(int head, std::vector<int> vector)
// {
//     int result = 0;
//     //Find the next location that is closet to head
//     size_t i = 0;

//     while(i < NUMBER_OF_REQUESTS)
//     {
//         int current = vector[0];
//         int oldMinDistance = std::abs(current - head);
//         int newMinDistance = 0;
//         size_t nextIndex = 0;
//         bool justDeleted = false;
//         for (size_t j = 0; j< NUMBER_OF_REQUESTS; ++j)
//         {
//             newMinDistance = std::min(oldMinDistance, std::abs(vector[j] - head));
//             if(newMinDistance != oldMinDistance)
//             {
//                 //Obtain the next location
//                 nextIndex = j;
//             }
//         }
//         result += newMinDistance;
//         //Obtain new head value
//         head = vector[nextIndex];
//         //Delete that entry, so that we don't duplicate calculating it. 
//         vector.erase(vector.begin() + nextIndex);

        
//         //Remove the element at that index

//         //may not increment i. may done = true when delete all elements in vector. 

//         ++i;
//     } 

//     return 0;
//}