//Programmer: Chau Nguyen

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "constants.h"

void printVector(const std::vector<int>& myVector)
{
    for(size_t element: myVector)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

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
    int min;
    int nextIndex = 0;
    int temp;

    int count = 0; 
    while(count < NUMBER_OF_REQUESTS)
    {
        std::cout <<"\nCount: " << count << std::endl;
        std::cout << "Current head: " << head << std::endl;

        //Temporarily calculate "min". Will replace min with real minimum later after comparing "temporary" value to current min.
        min = std::abs(head - myVector[0]);
        //nextIndex = 0;
        std::cout << "myVector[0]: " << myVector[0] <<std::endl;
        std::cout << "Temporary min: "<< min << std::endl;
        std::cout <<"Head: " << head << ". At index " << 0 << ". Temp value " << head << " - " << myVector[0] << ": " << min <<std::endl;

        //This is the for loop to indentify which element yields the minimum distance from current head
        for(size_t i = 1; i < myVector.size(); ++i)
        {
            temp = std::abs(head - myVector[i]);
            std::cout <<"Head: " << head << ". At index " << i << ". Temp value " << head << " - " << myVector[i] << ": " << temp <<std::endl;

            if(temp < min)
            {
                min = temp;
                nextIndex = i;
            }
        }

        //Now, we got the element and the index that yiels the minimum distance with head
        std::cout << "Next request: " << myVector[nextIndex] << ". With distance: " << min << std::endl;
        result += min;
        std::cout << "Total head movements so far: " << result << std::endl;
        //Update head
        head = myVector[nextIndex];
        std::cout << "Head moves to this new position: " << head << std::endl;

        //After asigning the value at "nextIndex" to head, delete that element so we don't recalculate it. 
        std::swap(myVector[nextIndex], myVector.back());
        myVector.pop_back();
        printVector(myVector);

        //Now, do the for loop again
        ++count;
    }

    return result;
}

