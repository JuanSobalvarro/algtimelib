#include "algtime.h"

/*
 * Calculate execution time of a function in ms
*/
double calculateExecutionTimeMili(void (*fun_ptr)())
{
    struct timespec start, end;

    // Get the start time
    clock_gettime(CLOCK_MONOTONIC, &start);

    // Execute the function
    fun_ptr();

    // Get the end time
    clock_gettime(CLOCK_MONOTONIC, &end);

    // Calculate the difference in seconds and convert to milliseconds
    double elapsed_time = (end.tv_sec - start.tv_sec) * 1000.0 + 
                          (end.tv_nsec - start.tv_nsec) / 1000000.0;

    return elapsed_time;
}

double calculateExecutionTimeMicro(void (*fun_ptr)())
{
    struct timespec start, end;

    clock_gettime(CLOCK_MONOTONIC, &start);
    fun_ptr();
    clock_gettime(CLOCK_MONOTONIC, &end);

    // Calculate the time difference in microseconds
    double elapsed_time = (end.tv_sec - start.tv_sec) * 1000000.0 + 
                          (end.tv_nsec - start.tv_nsec) / 1000.0;

    return elapsed_time;
}

double calculateExecutionTimeNano(void (*fun_ptr)())
{
    struct timespec start, end;

    clock_gettime(CLOCK_MONOTONIC, &start);
    fun_ptr();
    clock_gettime(CLOCK_MONOTONIC, &end);

    // Calculate the time difference in nanoseconds
    double elapsed_time = (end.tv_sec - start.tv_sec) * 1000000000.0 + 
                          (end.tv_nsec - start.tv_nsec);

    return elapsed_time;
}

void calculateMinMaxExecutionTime(void (*fun_ptr)(), int runs, double *min_time, double *max_time)
{
    *min_time = *max_time = calculateExecutionTimeMili(fun_ptr);

    for (int i = 1; i < runs; i++)
    {
        double time = calculateExecutionTimeMili(fun_ptr);
        if (time < *min_time)
            *min_time = time;
        if (time > *max_time)
            *max_time = time;
    }
}


bool hasTimedOut(void (*fun_ptr)(), double timeout_ms)
{
    double execution_time = calculateExecutionTimeMili(fun_ptr);
    return execution_time > timeout_ms;
}
