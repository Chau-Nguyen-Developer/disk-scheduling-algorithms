# Hard Disk Scheduling Algorithms

Report the total amount of head movement and the total number of change of direction based on different disk-scheduling algorithms

This program currently implements two following hard-disk-scheduling algorithms: first come first serve (FCFS) and shortest seek time first (SSTF)

## First Come First Serve (FCFS)
Hard disk requests are serviced and processed in the order that they arrive. No starvation happen. 

## Shortest Seek Time First (SSTF)
The hard-disk request with the shortest distance from the current head position (i.e., the head reaches that cylinder the fastest) is serviced first.     

For my current implementation, the disk controller performs a scan of all the requests each time in the vector to find the one that yields the minimum seek time from the head current position. Currently used vector to store data. Will look into different data structures in the future to mitigate the overhead in finding the closest request (maybe binary tree).  

Please stay tuned.    

## What The Program Does
This program will service a disk with 5,000 cylinders (numbered from 0 to 4,999). As a user, you will input in the initial position of the disk head, and this program will report for you `the total amount of head movements` and `the total number of changes of direction` required by each algorithm under each of the following cases:  

1. A random series of 1,000 cylinder requests will be generated automatically, and this program will service them according to the two algorithms listed above.  

2. You will feed in an `input.txt` file where you can control what the order of cylinder requests looks like. The program will service them according to the two algorithms listed above. 

## Current Work  
Able to return the number of head movements for both algorithms correctly. Will work on the number of changes in direction in the future.  

## Reference  
Good post talking about different hard-disk algorithms: https://pieces.app/blog/intro-to-disk-scheduling-algorithms  



