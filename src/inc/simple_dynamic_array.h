#ifndef __SIMPLE_DYNAMIC_ARRAY_H__
#define __SIMPLE_DYNAMIC_ARRAY_H__

struct __simple_dynamic_array
{
    // current size
    int size;

    // max size of the array
    int capacity;

    // pre allocated array
    int *array;
};

typedef struct __simple_dynamic_array simple_dynamic_array;

void create_sda(int capacity, simple_dynamic_array *array);

void push_back_sda(int value, simple_dynamic_array *array);

#endif
