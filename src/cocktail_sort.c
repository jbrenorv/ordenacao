/**
 * Cocktail sort
 * História:
 * Complexidade espacial:
 * Complexidade temporal:
 * Análise:
 */

#include "inc/cocktail_sort.h"

void cocktail_sort(int n, int *array, algorithm_run_info *info)
{
    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while (swapped)
    {
        swapped = false;

        for (int i = start; i < end; ++i)
        {
            if (array[i] > array[i + 1])
            {
                swap(&array[i], &array[i + 1]);
                swapped = true;

                // swap
                info->movements += 3LL;
            }

            // if
            info->comparisons += 1LL;
        }

        if (!swapped)
            break;

        swapped = false;
        --end;

        for (int i = end - 1; i >= start; --i)
        {
            if (array[i] > array[i + 1])
            {
                swap(&array[i], &array[i + 1]);
                swapped = true;
                
                // swap
                info->movements += 3LL;
            }
            
            // if
            info->comparisons += 1LL;
        }

        ++start;
    }
}
