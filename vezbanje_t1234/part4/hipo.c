#include <stdio.h>
#include <math.h>

float hipotenuza(float a, float b){
	return sqrt(a*a+b*b);}

int main(){
	float a, b, c;
	printf("Unesite dužine kateta: \n");
  	scanf("%f", &a);
    	scanf("%f", &b);
	c=hipotenuza(a,b);
	printf("Hipotenuza je %.2f.\n", c);
return 0;}
