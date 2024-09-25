#include <stdio.h>
#include "algtime.h"

// A test function for timing, we'll make it sleep for some time
void testFunction()
{
    // we put volatile so the compiler does not optimize this loop
    for (volatile int i = 0; i < 1000000; i++);  // Busy-wait loop to simulate work
}

int main()
{
    // Test calculateExecutionTimeMili
    double time_in_mili = calculateExecutionTimeMili(testFunction);
    printf("Function executed in %.6lf ms\n", time_in_mili);

    // Test calculateExecutionTimeMicro
    double time_in_micro = calculateExecutionTimeMicro(testFunction);
    printf("Function executed in %.6lf us\n", time_in_micro);

    // Test calculateExecutionTimeNano
    double time_in_nano = calculateExecutionTimeNano(testFunction);
    printf("Function executed in %.6lf ns\n", time_in_nano);

    // Test calculateMinMaxExecutionTime
    double min_time, max_time;
    calculateMinMaxExecutionTime(testFunction, 5, &min_time, &max_time);
    printf("Min execution time: %.6lf ms, Max execution time: %.6lf ms (over 5 runs)\n", min_time, max_time);

    // Test hasTimedOut
    double timeout_threshold = 0.01;  // 10 ms threshold
    bool timed_out = hasTimedOut(testFunction, timeout_threshold);
    if (timed_out)
    {
        printf("Function exceeded the timeout of %.6lf ms\n", timeout_threshold);
    }
    else
    {
        printf("Function did not exceed the timeout of %.6lf ms\n", timeout_threshold);
    }

    return 0;
}
