#include <stdio.h>
#include <limits.h>
#include <float.h>
int main(){
int a = INT_MAX;
float b = FLT_MAX;
double c = DBL_MAX;
printf("Int size: %d; Float size: %d;  Double size: %d", sizeof(a), sizeof(b), sizeof(c) );
printf("Int value: %d, Float value: %lf, Double value: %lf", a, b, c );
return 0;}
