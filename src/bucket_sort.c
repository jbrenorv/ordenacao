/**
 * Bucket sort
 * História:
 * Complexidade espacial:
 * Complexidade temporal:
 * Análise:
 */

#include <math.h>
#include "inc/bucket_sort.h"
#include "inc/simple_dynamic_array.h"
#include "inc/insertion_sort.h"

void bucket_sort(int n, int *array, algorithm_run_info *info)
{
    simple_dynamic_array buckets[NUM_BUCKETS];
    for (int i = 0; i < NUM_BUCKETS; i++)
        create_sda(n, &buckets[i]);

    // in the next for loop, the min and max functions each require one comparison
    info->comparisons += 2LL * n - 2;

    // up to 2n movements to find min and max elements
    info->movements += 2LL * n;

    int min_element = array[0];
    int max_element = array[0];
    for (int i = 1; i < n; i++)
    {
        min_element = min(min_element, array[i]);
        max_element = max(max_element, array[i]);
    }

    int bucket_range_length = (int) ceil((max_element - min_element + 1.0) / NUM_BUCKETS);

    // insertion of all n elements into buckets
    info->movements += n;

    for (int i = 0; i < n; i++)
    {
        int index = (array[i] - min_element) / bucket_range_length;
        push_back_sda(array[i], &buckets[index]);
    }

    for (int i = 0; i < NUM_BUCKETS; i++)
        insertion_sort(buckets[i].size, buckets[i].array, info);
    
    // insertion of all n elements into array again
    info->movements += n;

    int index = 0;
    for (int i = 0; i < NUM_BUCKETS; i++)
        for (int j = 0; j < buckets[i].size; j++)
            array[index++] = buckets[i].array[j];
}

void bucket_sort_for_radix_sort(int n, int exp, int *array, algorithm_run_info *info)
{
    simple_dynamic_array buckets[NUM_BUCKETS];
    for (int i = 0; i < NUM_BUCKETS; i++)
        create_sda(n, &buckets[i]);

    // insertion of all n elements into buckets
    info->movements += n;

    for (int i = 0; i < n; i++)
    {
        int index = (array[i] / exp) % 10;
        push_back_sda(array[i], &buckets[index]);
    }

    for (int i = 0; i < NUM_BUCKETS; i++)
        insertion_sort(buckets[i].size, buckets[i].array, info);
    
    // insertion of all n elements into array again
    info->movements += n;

    int index = 0;
    for (int i = 0; i < NUM_BUCKETS; i++)
        for (int j = 0; j < buckets[i].size; j++)
            array[index++] = buckets[i].array[j];
}
