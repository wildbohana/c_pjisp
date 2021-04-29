#include <stdio.h>
#define ms 30

int main(){
	int i,n,j;
	float x[ms], t;
	printf("Unesite broj elemenata za sortiranje:\n");
	scanf("%d", &n);
	printf("Unesite clanove niza: \n");
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			if(x[i]>x[j]){
				t=x[i];
				x[i]=x[j];
				x[j]=t;	
				}
	printf("Sortirani niz je:\n");
	for(i=0;i<n;i++)printf("x[%d]=%.2f\n"),i,x[i]);
return 0;}
