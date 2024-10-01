/**
 * Insertion sort
 * História:
 * Complexidade espacial:
 * Complexidade temporal:
 * Análise:
 */

#include "inc/insertion_sort.h"

void insertion_sort(int n, int *array, algorithm_run_info *info)
{
    int key, j;

    // key movements
    info->movements += 2LL * n - 2;

    for (int i = 1; i < n; i++)
    {
        key = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            --j;

            info->comparisons++;
            info->movements++;
        }

        array[j + 1] = key;
    }
}
