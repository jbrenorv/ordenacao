/**
 * Merge sort
 * História:
 * Complexidade espacial:
 * Complexidade temporal:
 * Análise:
 */

#include <stdlib.h>

#include "inc/merge_sort.h"
#include "inc/utils.h"

void __merge(int left, int mid, int right, int *array_aux, int *array, algorithm_run_info *info)
{
    // copy elements to auxiliary array and then back to the array
    info->movements += 2LL * (right - left + 1);

    copy_array((right - left + 1), left, left, array, array_aux);

    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid || j <= right)
    {
        if (j > right || (i <= mid && array_aux[i] <= array_aux[j])) {
            array[k] = array_aux[i];
            i++;
        }
        else {
            array[k] = array_aux[j];
            j++;
        }

        k++;

        info->comparisons += 1;
    }
}

void __merge_sort_impl(int left, int right, int *array_aux, int *array, algorithm_run_info *info)
{
    if (left >= right) return;

    int mid = left + (right - left) / 2;

    __merge_sort_impl(left, mid, array_aux, array, info);
    __merge_sort_impl(mid + 1, right, array_aux, array, info);
    
    __merge(left, mid, right, array_aux, array, info);
}

void merge_sort(int n, int *array, algorithm_run_info *info)
{
    int *array_aux;
    allocate_array_or_exit(n, false, &array_aux);

    __merge_sort_impl(0, n-1, array_aux, array, info);

    free(array_aux);
}
