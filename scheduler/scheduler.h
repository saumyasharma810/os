// scheduler.h
#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>
#include "process.h"

class Scheduler {
public:

    // Run the scheduling algorithm on the given processes
    virtual void schedule(std::vector<Process>& processes) = 0;

    // Optional: calculate average waiting/turnaround time
    virtual double averageWaitingTime(const std::vector<Process>& processes);
    virtual double averageTurnaroundTime(const std::vector<Process>& processes);
};

#endif
