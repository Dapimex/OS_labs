#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MB 1024*1024
void main() {
int mem = 10*MB;
for (int i = 0; i < 10; i++) {
memset(malloc(mem), 0, mem);
sleep(1);}
return;}
