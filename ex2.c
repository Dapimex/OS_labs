#include <stdio.h>
#include <string.h>
int main() {
char input[100];
printf("Enter string (up to 100 symbols) ");
scanf("%s", input);
int tmp = strlen(input);
for (int i = tmp; i >= 0; i--) {
putchar(input[i]);}
return 0;}
