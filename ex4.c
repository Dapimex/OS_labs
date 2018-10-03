#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>

void* my_realloc(void* point, size_t new_size);

size_t minFunction(size_t int1, size_t int2) {
    if (int1 >= int2) return int2;
    else return int1;
}

int main(){
    int* arr = malloc(5* sizeof(int));
    for (int i = 0; i < 5; i++) {
        arr[i] = 8;
    }
    printf("%d\n", arr[4]); //before resizing
    arr = (int*) my_realloc(arr, 3* sizeof(int));
    printf("%d", arr[4]); //after resizing
    return 0;
}

void* my_realloc(void* point, size_t new_size) {
    if (point == NULL) {
        if (new_size == 0) return NULL;
        else {
            return malloc(new_size);
        }
    }
    else {
        if (new_size == 0) {
            free(point);
            return point;
        }
        else {
            void* new_point = malloc(new_size);
            size_t old_size = _msize(point); //using C11 it is same as malloc_usable_size in C99
            size_t min = minFunction(old_size, new_size);
            memcpy(point, new_point, min);
            return new_point;
        }
    }
}
