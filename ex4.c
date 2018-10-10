#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>
#define MB 1024*1024
void main() {
int mem = 10*MB;
struct rusage usage;
for (int i = 0; i < 10; i++) {
memset(malloc(mem), 0, mem);
getrusage(RUSAGE_SELF, &usage);
printf("%d\n",usage.ru_maxrss);
sleep(1);}
return;}
