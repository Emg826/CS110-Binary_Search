#include <stdio.h>
#include <stdlib.h>
#include "binary_search.h"

int main(int argc, char** argv) {

    if(argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    size_t size;
    int* array = load_array(argv[1], &size);

    if(array == NULL) {
        printf("Error loading array from %s.\n", argv[1]);
        return 2;
    }

    if(is_sorted(array, size) == 0) {
        printf("Error: the array is not in ascending order.\n");
        return 3;
    }

    printf("Enter integers to search for. Enter ""quit"" when done.\n");

    int choice;
    while(scanf("%i", &choice) == 1) {

        int result = binary_search(choice, array, 0, size-1);
        if(result == 1)
            printf("Yes\n");
        if(result == 0)
            printf("No\n");
    }

    free(array);
}
