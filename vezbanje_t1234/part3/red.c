#include <stdio.h>

int main(){
	int i,n,s=0,a[n],a2[n];
	
	do{
		printf("Koliko kupaca ceka red? ");
		scanf("%d", &n);
	}while(n<1);
	printf("\n");
	
	for(i=0;i<n;i++){
		printf("Koliko minuta traje usluzivanje %d. kupca? ", i+1);
		scanf("%d",&a[i]);
		s+=a[i];
		a2[i]=s;
		}
	printf("\n");
	for(i=0;i<n;i++)printf("%d. kupac ce cekati %d minuta.\n",i+1,a2[i]);
	
return 0;}
