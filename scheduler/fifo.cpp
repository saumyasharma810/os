#ifndef FIFO_CPP
#define FIFO_CPP

#include "process.h"
#include "scheduler.h"
#include <algorithm>

class FIFO: public Scheduler {

    private:

        std::vector<Process> processes;
        double avgWaitTime = 0;
        double avgTurnTime = 0;
        double avgRespTime = 0;


        static bool cmp(Process &p1, Process &p2) {
            if (p1.arrival_time == p2.arrival_time){
                return p1.priority > p2.priority;
            }
            return p1.arrival_time < p2.arrival_time;
        }

        void findAverages(){
            int n = processes.size();
            if (n==0) return;
            for (auto &p : processes){
                avgRespTime += p.response_time;
                avgTurnTime += p.turnaround_time;
                avgWaitTime += p.waiting_time;
            }
            avgRespTime /= double(n);
            avgTurnTime /= double(n);
            avgWaitTime /= double(n);
        }



    public:

        FIFO(std::vector<Process>& processes){
            this->processes = processes;
        }

        void schedule(){
            sort(this->processes.begin(), this->processes.end(), cmp);
            int time = 0;
            for (auto &p : processes) {
                time = std::max(time,p.arrival_time);
                p.start_time = std::max(p.arrival_time,time);
                p.completion_time = time + p.burst_time;
                p.response_time = std::max(0,(time-p.arrival_time));
                p.waiting_time = p.response_time;
                p.turnaround_time = p.completion_time - p.arrival_time;
                time = p.completion_time;
            }
            findAverages();
            return;
        }

        void print_processes_schedule(){
            std::cout << "Printing processes based on fifo scheduler\n";
            std::cout << "PID\tArrival\tBurst\tPriority\n";
            for (const auto& p : processes) {
                std::cout << p.pid << "\t"
                        << p.arrival_time << "\t"
                        << p.burst_time << "\t"
                        << p.priority << "\n";
            }
        }

        void print(){
            std::cout << "Printing processes based on fifo scheduler\n";
            std::cout << "PID\tArrival\tBurst\tPriority\tStart\tCompletion\tWaiting\tResponse\tTurnAround\n";
            for (const auto& p : processes) {
                std::cout << p.pid << "\t"
                        << p.arrival_time << "\t"
                        << p.burst_time << "\t"
                        << p.priority << "\t\t"
                        << p.start_time <<"\t"
                        <<p.completion_time <<"\t\t"
                        <<p.waiting_time <<"\t"
                        <<p.response_time <<"\t\t"
                        <<p.turnaround_time<<"\n";
            }
        }

        double averageWaitingTime(){
            return avgWaitTime;
        }

        double averageTurnaroundTime(){
            return avgTurnTime;
        }

        double averageResponseTime(){
            return avgRespTime;
        }
};

#endif