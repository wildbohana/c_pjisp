// unos elemenata i njihov ispis

#include <stdio.h>
#define MAX_SIZE 30

int main(){
	int a[MAX_SIZE];
	int i, n;
	printf("Unesite broj elemenata niza: \n");
	scanf("%d", &n);
	if(n>0 && n<=MAX_SIZE){
		for (i=0; i<n; i++){
			a[i]=0;
			}
		for (i=0; i<n; i++){
			printf("a[%d]=", i);
			scanf("%d", &a[i]);
			}
		printf("Elementi po učitanom redosledu: \n");
		for (i=0; i<n; i++){
			printf("a[%d]=%d \t", i, a[i]);
			}
		printf("\n");
		printf("Elementi po obrnutom redosledu: \n");
		for (i=n-1; i>=0; i--){
			printf("a[%d]=%d \t", i, a[i]);
			}
		printf("\n");
		}
	else{
		printf("Niste uneli dobar broj n.\n");
	}
return 0;}
