//Programmer: Chau Nguyen

#include "constants.h"
#include "algorithms.cpp"
#include <iostream>
#include <random>
// #include <array>
#include <vector>
#include <algorithm>

int main()
{
    //Create a pseudo random generator. 
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0, NUMBER_OF_CYLINDERS - 1);
    
    std::vector<int> cylinderRequests(NUMBER_OF_REQUESTS);

    //Generate a random series of 1,000 cylinder requests
    for (size_t i = 0; i < NUMBER_OF_REQUESTS; ++i)
    {
        cylinderRequests[i] = distribution(generator);
    } 
    
    //test
    //std::cout << cylinderRequests[999] << " " << cylinderRequests[0] << std::endl;

    //Print out the content of the vector
    for(auto number: cylinderRequests)
    {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    //Prompt user for the head location
    int head = 0;
    std::cout << "Which cylinder is the head currently at? ";
    std::cin >> head;

    //Calculate head movements ()

    //FCFS - First Come First Served
    std::cout << "Running First-Come-First-Served Algorithm...\n" << FCFS(head, cylinderRequests) << std::endl;

    //SSTF - Shortest Seek Time First
    std::cout << "Running Shortest-Seek-Time-First Algorithm...\n" << SSTF(head, cylinderRequests) << std::endl;
    
    return 0;

}
