#include <stdio.h>

#include <string.h>

int main(){
    
printf("Enter number: ");
    
int num;
    printf("\n");
    
scanf("%d", &num);
    
for (int i = 1; i <= num; i ++) {
    
    for (int j = 0; j < num - i; j++) {
     
       putchar(' ');
        }
    
    for (int k = 0; k < 2*i-1; k++) {
       
       putchar('*');
        }
    
    putchar('\n');
    }
    
return 0;

}
