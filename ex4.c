#include <stdio.h>

#include <string.h>


void swap(int *p1, int *p2) {
   
  int tmp = *p1;
   
  *p1 = *p2;
   
  *p2 = tmp;
   
  return;
}


int main(){
   
  printf("Enter two integers: ");
  
  int num1;
   
  printf("\n");
  
  scanf("%d", &num1);
   
  int num2;
  
  printf("\n");
  
  scanf("%d", &num2);
  
  swap(&num1, &num2);
  
  printf("Swapped combination: %d, %d", num1, num2);
   
  return 0;
}