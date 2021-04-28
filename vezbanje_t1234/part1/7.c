// računanje jednačine sa dva elementa

#include <stdio.h>

int main(){
	double a, b, x;
	
	printf("Unesite dva broja za koje želite da se reši jednačina:\n");
	scanf("%lf",&a);
	scanf("%lf",&b);
	
	if (b==0) {printf("x=0");}
	else if (a==0) {printf("x je nedefinisano");}
	else {printf("x=%.2lf", (-b)/a);}
	
return 0;}
