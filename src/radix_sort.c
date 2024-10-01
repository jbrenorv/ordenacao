/**
 * Radix sort
 * História:
 * Complexidade espacial:
 * Complexidade temporal:
 * Análise:
 */

#include "inc/radix_sort.h"
#include "inc/bucket_sort.h"
#include "inc/counting_sort.h"

void radix_sort_with_bucket_sort(int n, int *array, algorithm_run_info *info)
{
    // movements and comparisons to find max element
    info->comparisons += n - 1;
    info->movements += n;

    int mx = array[0];
    for (int i = 1; i < n; i++)
        mx = max(mx, array[i]);

    for (int exp = 1; mx / exp > 0; exp *= 10)
        bucket_sort_for_radix_sort(n, exp, array, info);
}

void radix_sort_with_counting_sort(int n, int *array, algorithm_run_info *info)
{
    // movements and comparisons to find max element
    info->comparisons += n - 1;
    info->movements += n;

    int mx = array[0];
    for (int i = 1; i < n; i++)
        mx = max(mx, array[i]);

    for (int exp = 1; mx / exp > 0; exp *= 10)
        counting_sort_for_radix_sort(n, exp, array, info);
}
