#ifndef __BUCKET_SORT_H__
#define __BUCKET_SORT_H__

#include "utils.h"

#define NUM_BUCKETS 10

void bucket_sort(int n, int *array, algorithm_run_info *info);

void bucket_sort_for_radix_sort(int n, int exp, int *array, algorithm_run_info *info);

#endif
