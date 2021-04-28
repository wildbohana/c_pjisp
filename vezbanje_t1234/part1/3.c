// aritmetička, harmonijska, geometrijska i kvadratna sredina 3 broja

#include <stdio.h>
#include <math.h>
int main() {
	int a, b, c;
	
	printf("Unesite tri cela broja: ");
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	
	double x=a*1.0, y=b*1.0, z=c*1.0;
	double ar=(x+y+z)/3;
	double har=3/(1/x+1/y+1/z);
	double geo=sqrt(x*y*z);
	double kv=sqrt(pow(x,2)+pow(y,2)+pow(z,2));
	
	printf("Aritmerička: %.2lf, harmonijska: %.2lf, \ngeometrijska: %.2lf, kvadratna: %.2lf.\n", ar, har, geo, kv);
return 0; }
