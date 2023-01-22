#include "sort.h"

void counting_sort(int *array, size_t size)
{
    int i, c, j, u = 0, counter, uniq;
    int count[size];
    int uniq_items[size];

    /*Isolate unique items of the array*/
    for (i = 0; i < size; i++)
    {
        c = array[i];
        j = 0;
        uniq = 1;
        while (uniq_items[j])
        {
            if (c == uniq_items[j])
            {
                uniq = 0;
                break;
            }
            j++;
        }
        if (uniq)
        {
            uniq_items[u] = c;
            u++;
        }
    }
}
