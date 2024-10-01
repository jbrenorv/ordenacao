/**
 * Quick sort
 * História:
 * Complexidade espacial:
 * Complexidade temporal:
 * Análise:
 */

#include <stdio.h>
#include <stdlib.h>
#include "inc/quick_sort.h"

int __partition(int left, int right, int pivot_index, int *array, algorithm_run_info *info)
{
    int pivot = array[pivot_index];
    int i = left;
    int j = right;

    // move array[pivot_index] to pivot, comparisons and swaps
    info->comparisons += (j - i) + 2;
    info->movements += 3LL * (j - i) + 4;

    while (i < j)
    {
        while (i < j && array[i] <= pivot) ++i;
        while (i < j && array[j] >= pivot) --j;
        
        swap(&array[i], &array[j]);
    }

    if (array[i] > pivot && pivot_index < i) --i;
    if (array[i] < pivot && pivot_index > i) ++i;

    swap(&array[i], &array[pivot_index]);
    
    return i;
}

void __quick_sort_deterministic_impl(int left, int right, int *array, algorithm_run_info *info)
{
    if (left >= right) return;

    int j = __partition(left, right, left, array, info);

    __quick_sort_probabilistic_impl(left, j - 1, array, info);
    __quick_sort_probabilistic_impl(j + 1, right, array, info);
}

void __quick_sort_probabilistic_impl(int left, int right, int *array, algorithm_run_info *info)
{
    if (left >= right) return;

    int i = generate_number_randomly(left, right);
    int j = __partition(left, right, i, array, info);

    __quick_sort_probabilistic_impl(left, j - 1, array, info);
    __quick_sort_probabilistic_impl(j + 1, right, array, info);
}

void quick_sort_deterministic(int n, int *array, algorithm_run_info *info)
{
    __quick_sort_deterministic_impl(0, n - 1, array, info);
}

void quick_sort_probabilistic(int n, int *array, algorithm_run_info *info)
{
    __quick_sort_deterministic_impl(0, n - 1, array, info);
}
