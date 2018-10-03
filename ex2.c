#include <stdio.h>
#include <malloc.h>

int main() {
    char input[3];
    fgets(input, 4, stdin);
    int n = atoi(input);
    int* arr = (int*) malloc(n*sizeof(int));

    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}