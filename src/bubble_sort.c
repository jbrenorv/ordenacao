/**
 * Bubble sort
 * História:
 * Complexidade espacial:
 * Complexidade temporal:
 * Análise:
 */

#include "inc/bubble_sort.h"

void bubble_sort(int n, int *array, algorithm_run_info *info)
{
    bool swapped;
    for (int i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(&array[j], &array[j + 1]);
                swapped = true;

                // swap
                info->movements += 3;
            }

            // if
            info->comparisons++;
        }

        if (!swapped)
            break;
    }
}
