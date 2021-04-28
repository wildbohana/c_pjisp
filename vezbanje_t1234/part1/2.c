// površina trougla

#include <stdio.h>
#include <math.h>

int main() {
	double a, b, c, s, p1, p2;
	
	printf("Unesi tri broja: ");
	scanf("%lf", &a);
	scanf("%lf", &b);
	scanf("%lf", &c);
	
	s=a/2+b/2+c/2;
	p1=s*(s-a)*(s-b)*(s-c);
	p2=sqrt(p1);
	
	printf("Porvršina trougla je %.2lf cm.\n", p2);
return 0; } 
