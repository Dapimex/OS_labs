#include <stdio.h> 
#include <stdlib.h> 
int main() {
    int pid = fork(), n = 15;
    if (pid > 0) {
        printf("Hello from parent [%d - %d]", pid, n);
}
    else if (pid == 0) { 
        printf("Hello from child [%d - %d]", pid, n);   }
return 0;}
