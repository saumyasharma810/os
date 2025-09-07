#include <iostream>
#include <vector>
#include "process.h"
#include "scheduler.h"
#include "fifo.cpp"

int main() {
    // Step 1: Create some sample processes
    std::vector<Process> processes = {
    {1, 12, 5, 2},   // PID=1, Arrival=12, Burst=5
    {2, 0, 4, 1},    // PID=2, Arrival=0, Burst=4  
    {3, 20, 3, 3},   // PID=3, Arrival=20, Burst=3  
    {4, 6, 2, 2},    // PID=4, Arrival=6, Burst=2  
    {5, 8, 6, 1},    // PID=5, Arrival=8, Burst=6  
    {6, 3, 4, 2},    // PID=6, Arrival=3, Burst=4  
    {7, 100, 5, 3},   // PID=7, Arrival=14, Burst=5  
    {8, 1, 2, 1},    // PID=8, Arrival=1, Burst=2  
    {9, 18, 4, 2},   // PID=9, Arrival=18, Burst=4  
    {10, 5, 3, 1}    // PID=10, Arrival=5, Burst=3  
    };



    // Step 2: Print the initial process list
    std::cout << "Initial Processes:\n";
    std::cout << "PID\tArrival\tBurst\tPriority\n";
    for (const auto& p : processes) {
        std::cout << p.pid << "\t"
                  << p.arrival_time << "\t"
                  << p.burst_time << "\t"
                  << p.priority << "\n";
    }


    // Step 3: Initialize schedulers
    FIFO fifo_scheduler(processes); 
    fifo_scheduler.schedule();
    fifo_scheduler.print();
    fifo_scheduler.printAverageResponseTime();
    fifo_scheduler.printAverageTurnaroundTime();
    fifo_scheduler.printAverageWaitingTime();

    


    return 0;
}
