// uneseš elemente u neki niz i broj n i brojiš koliko se broj n puta ponavlja u nizu

#include <stdio.h>
#define MAX 30

int main(){
	int a[MAX];
	int n, broj, m=0, i;
	printf("Unesite broj elemenata koje želite u nizu: \n");
	scanf("%d", &n);
	if (n>0 && n<=MAX){
		printf("Unesite ceo broj: \n");
		scanf("%d", &broj);
		for (i=0; i<n; i++){
			printf("a[%d]=", i);
			scanf("%d", &a[i]);
			}
		for (i=0; i<n; i++){
			if(a[i]==broj){
				m++;
				}}
		for (i=0; i<n; i++){
			printf("%d\t", a[i]);
			}
		printf("\nTraženi broj se ponavlja %d puta.\n", m);
		}
	else{
		printf("Uneli ste pogrešan broj.\n");
		}
return 0;}
