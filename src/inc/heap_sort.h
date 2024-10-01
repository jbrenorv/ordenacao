#ifndef __HEAP_SORT_H__
#define __HEAP_SORT_H__

#include "utils.h"

void __heapify(int n, int i, int *array, algorithm_run_info *info);

void heap_sort(int n, int *array, algorithm_run_info *info);

#endif
