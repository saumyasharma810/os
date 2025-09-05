#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

int main() {
    // measuring the system call
    // I can call read operation 1000 times and check how much time it is taking
    struct timeval tv1, tv2;
    char buffer[1]; 
    int s = gettimeofday(&tv1, NULL);
    if (s==0) {
        for (int i = 0;i < 1000; i++){
            ssize_t bytes_read = read(0, buffer, 0);
        }
        s = gettimeofday(&tv2, NULL);
        if (s==0) {
            float second_diff = tv2.tv_sec - tv1.tv_sec;
            float ms_diff = tv2.tv_usec - tv1.tv_usec;
            printf("Time it took = %f",(second_diff*1000 + ms_diff)/1000);
        }
    }

    // measuring the context switch
    

    return 0;
}