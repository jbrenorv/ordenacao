/**
 * Selection sort
 * História:
 * Complexidade espacial:
 * Complexidade temporal:
 * Análise:
 */

#include "inc/selection_sort.h"

void selection_sort(int n, int *array, algorithm_run_info *info)
{
    // comparisons to find the index of de min element in each iteration of the main loop
    info->comparisons += ((long long)n * (n - 1)) / 2LL;

    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (array[j] < array[min_idx])
                min_idx = j;

        if (min_idx != i)
        {
            info->movements += 3;
            swap(&array[min_idx], &array[i]);
        }
    }
}
