// scheduler.h
#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "process.h"

class Scheduler {
public:

    // // Run the scheduling algorithm on the given processes
    virtual void schedule() = 0;

    // Optional: calculate average waiting/turnaround time
    virtual double averageWaitingTime() = 0;
    virtual double averageTurnaroundTime() = 0;
    virtual double averageResponseTime() = 0;

    void printAverageWaitingTime(){
        std::cout << "Average Waiting Time is "<< averageWaitingTime() <<"\n";
    }

    void printAverageResponseTime(){
        std::cout << "Average Response Time is "<< averageResponseTime() <<"\n";
    }

    void printAverageTurnaroundTime(){
        std::cout << "Average Turnaround Time is "<< averageTurnaroundTime() <<"\n";
    }

};

#endif
