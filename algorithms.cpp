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

//SSTF: Shortest Seek Time First
// int SSTF(int head, std::vector<int>& myVector)
// {
//     if (myVector.empty())
//     {
//         std::cout << "Vector is empty." << std::endl;
//         return 0;
//     }
//     std::cout << "Head is " << head << std::endl;

//     int headMovement = 0;
//     int min;
//     int indexNextMove = 0;
//     int len = myVector.size(); //this value will change according to time
//     int temp;

//     for(size_t i = 0; i < NUMBER_OF_REQUESTS; ++i)
//     {
//          min = std::abs(head - myVector[0]);

//         //Identify where the head will move next to
//         for(size_t i = 1; i < len; ++i)
//         {
//             temp = std::abs(head - myVector[i]);
//             if(temp < min)
//             {
//                 min = temp;
//                 indexNextMove = i;
//             }
//         }
//         std::cout << "Current head: " << head << std::endl;
//         std::cout << "Next position: " << myVector[indexNextMove] << std::endl;
        
//         //Calculation head movement 
//         headMovement += min;

//         //Reset head
//         head = myVector[indexNextMove];

//         //remove the element
//         std::swap(myVector[indexNextMove], myVector.back());
//         myVector.pop_back();
//     }

//     return headMovement;

// }
int SSTF(int head, std::vector<int>& myVector)
{
    int result = 0;
    //Take head and subtract head to every element to identify which element yields the minimum distance
    int min = std::abs(head - myVector[0]);
    int nextIndex = 0;
    int temp;
   

    //This is the for loop to indentify which element yields the minimum distance from current head
    for(size_t i = 1; i < myVector.size(); ++i)
    {
        temp = std::abs(myVector[i] - head);
        if(temp < min)
        {
            min = temp;
            nextIndex = i;
        }
    }

    //Now, we got the element and the index that yiels the minimum distance with head
    result += min;
    head = myVector[nextIndex];

    //After asigning the value at "nextIndex" to head, delete that element so we don't recalculate it. 
    std::swap(myVector[nextIndex], myVector.back());
    myVector.pop_back();

    //Now, do the for loop again


    for(size_t i = 1; i < myVector.size(); ++i)
    {
        if(myVector.empty())
        {
            break;
        }

        //Take head and subtract head to every element to identify which element yields the minimum distance
       
        temp = std::abs(head - myVector[i]);
        if(temp < min)
        {
            min = temp;
            nextIndex = i;
        }

        result += min;
        //Update head

        //Remove that element

        min = std::abs(head - myVector[0]);
    }
}
