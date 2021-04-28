// suma do n-tog broja

#include <stdio.h>

int main(){
	int n, suma=0, i;
	printf("Unesite broj n: \n");
	scanf("%d", &n);
	for (i=1; i<=n; i++){
		suma+=i;
		}
	printf("Suma iznosi %d.\n", suma);
return 0;}
