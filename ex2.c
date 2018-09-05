#include <stdio.h>  

void bubble_sort(int* arr, int len) {
    for (int k = 0; k < len - 1; k++) {
        for (int g = 0; g < len - k - 1; g++) {
            if (*(arr+g) > *(arr+1+g)) {
                int tmp = *(arr+g);
                *(arr+g) = *(arr + g + 1);
                *(arr + 1 + g) = tmp;
            }
        }
    }
}

int main(){   
    printf("Enter number of integers: ");
    int i;
    scanf("%d", &i);
    printf("Enter integers: ");
    int* sort = (int *)malloc(i * sizeof(int));
    for (int j = 0; j < i; j++) {
        scanf("%d", (sort+j));
    }
    bubble_sort(sort, i);
    for (int j = 0; j < i; j++) {
        printf("%d ", *(sort + j));
    }
    return 0;
}

 