#include <stdio.h>

int ispis(int *niz, int duz){
	int i;
	printf("[");
	for(i=0; i<duz; i++){
		printf("%d", niz[i]);
		if(i!=(duz-1)) printf(", ");
		}
	printf("]\n");
	}

int main(){
	int niz[10], i;
	for(i=0; i<10; i++){
		niz[i]=i+1;
		}
	ispis(niz, 10);
	
return 0;}
