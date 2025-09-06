// process.h
#ifndef PROCESS_H
#define PROCESS_H

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int priority;

    // Metrics (to be filled during scheduling)
    int start_time = -1;
    int completion_time = -1;
    int waiting_time = -1;
    int turnaround_time = -1;
    int response_time = -1;
};

#endif
