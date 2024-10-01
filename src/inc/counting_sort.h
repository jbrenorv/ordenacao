#ifndef __COUNTING_SORT_H__
#define __COUNTING_SORT_H__

#include "utils.h"

void counting_sort(int n, int *array, algorithm_run_info *info);

void counting_sort_for_radix_sort(int n, int exp, int *array, algorithm_run_info *info);

#endif
