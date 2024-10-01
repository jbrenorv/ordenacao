/**
 * Shell sort
 * História:
 * Complexidade espacial:
 * Complexidade temporal:
 * Análise:
 */

#include "inc/shell_sort.h"

void shell_sort(int n, int *array, algorithm_run_info *info)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; ++i)
        {
            // temp movements
            info->movements += 2LL;

            int temp = array[i];
            int j;

            for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
            {
                array[j] = array[j - gap];

                info->comparisons++;
                info->movements++;
            }

            array[j] = temp;
        }
    }
}
