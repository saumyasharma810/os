#include <iostream>
#include <vector>
#include "process.h"
#include "scheduler.h"

int main() {
    // Step 1: Create some sample processes
    std::vector<Process> processes = {
        {1, 0, 4, 0},   // pid=1, arrival=0, burst=4
        {2, 1, 5, 0},   // pid=2, arrival=1, burst=5
        {3, 2, 2, 0}    // pid=3, arrival=2, burst=2
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

    std::cout << "\n[Scheduler not yet implemented]\n";

    return 0;
}
