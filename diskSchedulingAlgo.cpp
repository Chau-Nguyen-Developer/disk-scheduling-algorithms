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
    
    //An array to contain the cylinder request
    // int cylinderRequests[NUMBER_OF_REQUESTS]; <-- old style C

    std::vector<int> cylinderRequests;

    //Generate a random series of 1,000 cylinder requests
    for (size_t i = 0; i < NUMBER_OF_REQUESTS; ++i)
    {
        cylinderRequests[i] = distribution(generator);
    } 
    
    //test
    //std::cout << cylinderRequests[999] << " " << cylinderRequests[0] << std::endl;

    //Prompt user for the head location
    int head = 0;
    std::cout << "Which cylinder is the head currently at? " << std::endl;
    std::cin >> head;

    //Calculate head movements ()

    //FCFS
    std::cout << "Running First-Come-First-Served Algorithm...\n" << "Head Movement: " << FCFS(head, cylinderRequests) << std::endl;

    return 0;

}