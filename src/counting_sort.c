/**
 * Counting sort
 * História:
 * Complexidade espacial:
 * Complexidade temporal:
 * Análise:
 */

#include "inc/counting_sort.h"

void counting_sort(int n, int *array, algorithm_run_info *info)
{
    int *count, *aux;

    // comparisons and movements to find max element of the array
    info->comparisons += n;
    info->movements += n;

    int M = 0;
    for (int i = 0; i < n; i++)
        M = max(M, array[i]);

    allocate_array_or_exit(M+1, true, &count); 
    allocate_array_or_exit(n, false, &aux); 

    for (int i = 0; i < n; i++)
        count[array[i]]++;

    for (int i = 1; i <= M; i++)
        count[i] += count[i - 1];

    // movements to move the elements to aux and then back to the array
    info->movements += 2LL * n;

    for (int i = n - 1; i >= 0; i--)
    {
        aux[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    for (int i = 0; i < n; i++)
        array[i] = aux[i];
}

void counting_sort_for_radix_sort(int n, int exp, int *array, algorithm_run_info *info)
{
    int *count, *aux;
    allocate_array_or_exit(10, true, &count); 
    allocate_array_or_exit(n, false, &aux); 

    for (int i = 0; i < n; i++)
        count[(array[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // movements to move the elements to aux and then back to the array
    info->movements += 2LL * n;

    for (int i = n - 1; i >= 0; i--)
    {
        aux[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        array[i] = aux[i];
}
