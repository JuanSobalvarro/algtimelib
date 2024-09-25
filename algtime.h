#ifndef ALGTIME_H
#define ALGTIME_H

#include <time.h>
#include <stdbool.h>
#include <stdlib.h>

double calculateExecutionTimeMili(void (*fun_ptr)());
double calculateExecutionTimeMicro(void (*fun_ptr)());
double calculateExecutionTimeNano(void (*fun_ptr)());

void calculateMinMaxExecutionTime(void (*fun_ptr)(), int runs, double *min_time, double *max_time);

bool hasTimedOut(void (*fun_ptr)(), double timeout_ms);

#endif // ALGTIME_H