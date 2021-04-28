// faktorijel za broj n
// zaštita unosa gratis

#include <stdio.h>

int main(){
	int n, m=1, fakt=1;
	printf("Unesite broj n: \n");
	scanf("%d", &n);
	if (n>0){
		while (m<=n){
			fakt=fakt*m;
			m++;
			}
		printf("Faktorijal je: %d\n", fakt);
		}
	else	{
		printf("Niste uneli ispravan broj.\n");
		}
return 0;}

