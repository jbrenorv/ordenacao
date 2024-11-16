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
    int pivot = array[right];
    int i = left - 1;

    for (int j = left; j <= right - 1; j++) {
        if (array[j] < pivot) {
            i++;
            swap(&array[i], &array[j]);

            info->movements += 3;
        }

        info->comparisons += 1;
    }

    swap(&array[i + 1], &array[right]);  
    return i + 1;
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

    swap(&array[i], &array[right]);

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
    __quick_sort_probabilistic_impl(0, n - 1, array, info);
}
