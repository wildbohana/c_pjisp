#include <stdio.h>
#include <math.h>
#define ms 20

int main(){
	int n,i,index;
	double niz[ms],prosek=0,najblizi,razlika;
	
	do{
		printf("Unesite broj clanova niza: ");
		scanf("%d", &n);
	}while(n<=0 || n>ms);
	
	for(i=0;i<n;i++){
		printf("Unesite %d. clan niza: ", i);
		scanf("%lf", &niz[i]);
		prosek+=niz[i];
		}
	prosek/=n;
	printf("Prosek ovog niza je %lf.\n", prosek);
	
	najblizi=niz[0];			//ovo ide van petlje da bi petlja imala
	index=0;				//sa čime da poredi kada krene da radi
	razlika=abs(niz[0]-prosek);
	
	for(i=0;i<n;i++){
		if (razlika>abs(niz[i]-prosek)){
			razlika=abs(niz[i]-prosek);
			najblizi=niz[i];
			index=i;
			}
		}
	
	printf("Najblizi clan je n[%d] a njegova vrednost je %lf \n", index, najblizi);
	
return 0;}
