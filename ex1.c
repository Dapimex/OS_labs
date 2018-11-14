#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <windef.h>

#define PROC_NUMBER 5
#define RES_NUMBER 3

int main() {

    FILE * fptr;
    char * input_filename = "input.txt";
    char * output_filename = "output.txt";

    int e_resources[RES_NUMBER];
    int a_resources[RES_NUMBER];
    int c_matrix[PROC_NUMBER][RES_NUMBER];
    int r_matrix[PROC_NUMBER][RES_NUMBER];

    //Reading input and filling structures
    char str[63];
    int current_value, size = 0;
    fptr = fopen(input_filename, "r");

    int counter=0, i=0, j=0;
    while(fscanf(fptr, "%s", str) != EOF){
        current_value = atoi(str);
        if(counter < RES_NUMBER){
            e_resources[counter] = current_value;
        } else if(counter < 2*RES_NUMBER){
            a_resources[counter - RES_NUMBER] = current_value;
        }  else if(counter < 2*RES_NUMBER + PROC_NUMBER*RES_NUMBER){
            size = counter - 2*RES_NUMBER;
            j = size % RES_NUMBER;
            i = size / RES_NUMBER;
            c_matrix[i][j] = current_value;
        } else {
            size = counter - 2*RES_NUMBER - PROC_NUMBER*RES_NUMBER;
            j = size % RES_NUMBER;
            i = size / RES_NUMBER;
            r_matrix[i][j] = current_value;
        }
        counter += 1;
    }
    fclose(fptr);

    int dead_processes = PROC_NUMBER;
    bool dead = FALSE;

    while ((dead_processes > 0) && (!dead)) {
        bool proc_found = FALSE;
        int init_proc = 0;
        while ((init_proc < PROC_NUMBER) && (!proc_found)) {
            bool avail_res = TRUE;
            int res = 0;
            while ((res < RES_NUMBER) && (avail_res)) {
                if (a_resources[res] < r_matrix[init_proc][res]) avail_res = FALSE;
                res++;
            }
            if (avail_res) {
                proc_found = TRUE;
                for (int res = 0; res < RES_NUMBER; res++) {
                    a_resources[res] = a_resources[res] + c_matrix[init_proc][res];
                    r_matrix[init_proc][res] = e_resources[res] + 1; //just to disable process to be found again
                }

                for (int i = 0; i < RES_NUMBER; i++) {
                    printf("%d ", a_resources[i]);
                }
                printf("\n");

            }
            init_proc++;
        }
        if (!proc_found) {
            dead = TRUE;
        }
        dead_processes--;
    }
    if (dead) dead_processes++;

    if (dead_processes == 0) {
        fptr = fopen(output_filename, "w");
        fprintf(fptr, "There are no deadlocks in system");
        fclose(fptr);
    }
    else {
        fptr = fopen(output_filename, "w");
        fprintf(fptr, "There are %d processes in deadlock", dead_processes);
        fclose(fptr);
    }
    return 0;
}