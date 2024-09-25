# algtimelib
The `algtime` library is designed to measure the execution time of functions in C with precision. This library allows developers to profile functions by tracking how long they take to execute, providing insights into performance. It can measure time in milliseconds, microseconds, and nanoseconds, and also offers additional functionality like calculating the minimum and maximum execution times over multiple runs and detecting if a function has exceeded a timeout threshold.

> The library is especially useful for performance-critical applications where execution time must be measured with precision, such as in real-time systems, algorithm optimization, or benchmarking.

## Features
- **Measure Execution Time in Milliseconds:** Track how long a function takes to execute with millisecond precision.
- **Measure Execution Time in Microseconds:** Provides higher precision for performance measurements with microseconds.
- **Measure Execution Time in Nanoseconds:** Offers nanosecond-level precision for highly accurate measurements.
- **Min/Max Execution Time:** Run a function multiple times and find the minimum and maximum execution times over the specified runs.
- **Timeout Detection:** Check whether a function’s execution time exceeds a predefined threshold.

## Installation
 Download the algtime.h and algtime.c files.

Include algtime.h in your C project:

```c
#include "algtime.h"
```

Compile your C code along with algtime.c:

```bash
gcc -o my_program my_program.c algtime.c -lrt
```
> The -lrt flag is required to link the real-time library for clock_gettime().

## Usage
Here’s an example of how to use the algtime library:

```c
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
```

### License
This library is distributed under the MIT License. Feel free to use, modify, and distribute as needed.

### Contributing
If you'd like to contribute to the development of this library, please feel free to open an issue or submit a pull request on the repository.