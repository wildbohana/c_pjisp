// ispis vrednosti iz fahr u celz (fahr 0->300 sa korakom 20)

#include <stdio.h>

int main(){
	float lower, upper, step, fahr, celsius;
	lower=0;
	upper=300;
	step=20;
	fahr=lower;
	while (fahr<=upper){
		celsius=(5.0/9.0)*(fahr-32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr+=step;}
return 0;}
