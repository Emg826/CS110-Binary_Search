#include <stdio.h>
#include <stdlib.h>
#include "binary_search.h"

int* load_array(const char* filename, size_t* size) {
    int value = 0;
    int index_count = 0;
    int new_size = sizeof(int);

    int* array = malloc(new_size);
    FILE* fp = fopen(filename, "r");

    // Returns NULL if there is an error reading from the given file
    if(fp == NULL)
        return NULL;

    // Scans through file pointed to by fp until the end of the file
    while(fscanf(fp, "%i", &value) != -1) {
        // Doubles the size of the array if already at maximum number of
        // elements in array
        if(index_count * sizeof(int) == new_size) {
            new_size = 2 * new_size;
            array = realloc(array, new_size);
        }

        array[index_count] = value;
        index_count++;
    }

    array = realloc(array, index_count * sizeof(int));
    *size = index_count;
    fclose(fp);

    return array;
}



int is_sorted(int* array, size_t size) {
    for(int i = 1; i < size; i++) {
        // If the current element is smaller than the previous
        // the array is not in ascending order
        if(array[i] < array[i-1])
            return 0;
    }

    return 1;
}



int binary_search(int target, int* array, int start, int end) {
    if(end < start)
        return 0;

    int range = end - start;
    int middle = (range / 2) + start;

    if(array[middle] == target) {
        return 1;
    }

    if(array[middle] > target) {
        return binary_search(target, array, start, middle - 1);
    }

    if(array[middle] < target) {
        return binary_search(target, array, middle + 1, end);
    }
}
