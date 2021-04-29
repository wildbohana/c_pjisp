#include <stdio.h>
#define MAX 30


int min(int *a, int n){
	int min, i;
	min=a[0];
	for(i=1; i<n; i++){
		if(a[i]<min){
			min=a[i];
			}
		}
return min;
}

int max(int *a, int n){
	int max, i;
	max=a[0];
	for(i=1; i<n; i++){
		if(a[i]>max){
			max=a[i];
			}
		}
return max;
}

void unosN(int *n){
	int i;
	do{
		printf("Unesite koliko el. ima niz: ");
		scanf("%d", n);
	}while(n<0);
}

void unosA(int *a, int n){
	int i;
	for(i=0; i<n; i++){
		a[i]=0;
		}
	for(i=0; i<n; i++){
		printf("Unesite %d element niza: ", i+1);
		scanf("%d", &a[i]);
		}	
}

int suma(int *a, int n){
	int i, s=0;
	for(i=0; i<n; i++){
		s+=a[i];}
return s;
}

float srvr(int *a, int n){
	float x;
	x=(double)suma(a,n)/n;
return x;
}

void ispisA(int *a, int n){
	int i;
	printf("[");
	for(i=0; i<n; i++){
		printf("%d", a[i]);
		if(i!=(n-1)) printf(", ");
		}
	printf("]\n");
}

//////////////////////////////////////////////////////////////////////////////

int main(){
	int a[MAX], n, m, izbor;
	do{	printf("\n1. Unos niza.");
		printf("\n2. Suma niza.");
		printf("\n3. Srednja vrednost niza.");
		printf("\n4. Najmanji element niza.");
		printf("\n5. Najveći element niza.");
		printf("\n6. Ispis niza.");
		printf("\n7. Izlaz iz programa.");
		
		printf("\n\nIzaberi jednu od opcija: ");
		scanf("%d", &izbor);
		printf("\n");
		
		switch(izbor){
		case 1: unosN(&n); unosA(a,n); break;
		case 2: printf("Suma svih elemenata niza je: %d\n", suma(a,n)); break;
		case 3: printf("Srednja vrednost ovog niza je: %.2f\n", srvr(a,n)); break;
		case 4: printf("Najmanji element niza je: %d\n", min(a,n)); break;
		case 5: printf("Najveći element niza je: %d\n", max(a,n)); break;
		case 6: ispisA(a,n); break;
		}
	
	}while(izbor!=7);	
	
return 0;}
