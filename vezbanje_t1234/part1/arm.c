#include <stdio.h>
#include <math.h>

int main(){
	int i=100, a, b, c;
	for (i; i<1000; i++){
		a=pow(i/100,3);
		b=pow(i%100/10,3);
		c=pow(i%10,3);
		if (i==(a+b+c)){
			printf("Broj %d je armstrongov.\n", i);}
		}
return 0;}
