// poređenje dve unete vrednosti, ternarni operator

#include <stdio.h>

int main() {
	int a, b, v;
	scanf("%d",&a);
	scanf("%d",&b);
	v = (a>b) ? a : b ;
	printf("Veći je %d.\n", v);
return 0;}
