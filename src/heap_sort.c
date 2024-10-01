/**
 * Heap sort
 * História:
 * Complexidade espacial:
 * Complexidade temporal:
 * Análise:
 */

#include "inc/heap_sort.h"

void __heapify(int n, int i, int *array, algorithm_run_info *info)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // one comparison for each next if
    info->comparisons += 2LL;

    if (left < n && array[left] > array[largest])
        largest = left;

    if (right < n && array[right] > array[largest])
        largest = right;

    if (largest == i) return;

    info->movements += 3LL;
    swap(&array[i], &array[largest]);

    __heapify(n, largest, array, info);
}

void heap_sort(int n, int *array, algorithm_run_info *info)
{
    // build heap
    for (int i = (n / 2 - 1); i >= 0; i--)
        __heapify(n, i, array, info);

    // 3 movements for each n next swaps
    info->movements += 3 * n;

    for (int i = n - 1; i > 0; i--)
    {
        swap(&array[0], &array[i]);

        __heapify(i, 0, array, info);
    }
}
