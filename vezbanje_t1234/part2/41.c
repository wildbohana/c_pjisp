// unos elemenata niza i ispis u obrnutom redosledu

#include <stdio.h>
#define MAX 30

int main(){
	int a[MAX];
	int n, i, pom, *pa;
	pa=a;
	do {
		printf("Unesite broj elemenata niza: ");
		scanf("%d", &n);
	}while (n<0 || n>MAX);
	printf("Unesite elemente niza: \n");
	for(i=0; i<n; i++){
		printf("a[%d]= ", i);
		scanf("%d", pa+i);
		}
	for(i=0; i<n/2; i++){
		pom=*(pa+i);
		*(pa+i)=*(pa+n-1-i);
		*(pa+n-1-i)=pom;
		}
	printf("\nIspis elemenata niza: \n");
	for (i=0; i<n; i++){
		printf("a[%d]=%d \n", i, *(pa+i));
		}
return 0;}
