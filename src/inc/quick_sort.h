#ifndef __QUICK_SORT_H__
#define __QUICK_SORT_H__

#include "utils.h"

int __partition(int left, int right, int pivot_index, int *array, algorithm_run_info *info);

void __quick_sort_deterministic_impl(int left, int right, int *array, algorithm_run_info *info);

void __quick_sort_probabilistic_impl(int left, int right, int *array, algorithm_run_info *info);

void quick_sort_deterministic(int n, int *array, algorithm_run_info *info);

void quick_sort_probabilistic(int n, int *array, algorithm_run_info *info);

#endif
