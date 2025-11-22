//Programmer: Chau Nguyen

#include "constants.h"
#include <iostream>
#include <random>
#include <array>


const size_t NUMBER_OF_CYLINDERS = 5000;
const size_t NUMBER_OF_REQUESTS = 1000;

int main()
{
    //Create a pseudo random generator. 
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0, NUMBER_OF_CYLINDERS - 1);
    
    //An array to contain the cylinder request
    // int cylinderRequests[NUMBER_OF_REQUESTS]; <-- old style C

    std::array<int, NUMBER_OF_REQUESTS> cylinderRequests;

    //Generate a random series of 1,000 cylinder requests
    for (size_t i = 0; i < NUMBER_OF_REQUESTS; ++i)
    {
        cylinderRequests[i] = distribution(generator);
    } 
    
    //test
    std::cout << cylinderRequests[999] << " " << cylinderRequests[0] << std::endl;

    //Prompt user for the head location
    // int head = 0;
    // std::cout << "Which cylinder is the head currently at? " << std::endl;
    // std::cin >> head;

    //Calculate head movements ()
    return 0;

}