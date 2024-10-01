#ifndef __RADIX_SORT_H__
#define __RADIX_SORT_H__

#include "utils.h"

void radix_sort_with_bucket_sort(int n, int *array, algorithm_run_info *info);

void radix_sort_with_counting_sort(int n, int *array, algorithm_run_info *info);

#endif
