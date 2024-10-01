#ifndef __MERGE_SORT_H__
#define __MERGE_SORT_H__

#include "utils.h"

void __merge(int left, int mid, int right, int *array_aux, int *array, algorithm_run_info *info);

void __merge_sort_impl(int left, int right, int *array_aux, int *array, algorithm_run_info *info);

void merge_sort(int n, int *array, algorithm_run_info *info);

#endif
