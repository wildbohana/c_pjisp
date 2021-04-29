#include <stdio.h>

void god(int *, int *);
int prest(int);
void ispis(int, int);

void god(int *a, int *b){
	do{
		printf("Unesite početnu godinu: ");
		scanf("%d", a);
		printf("Unesite krajnju godinu: ");
		scanf("%d", b);
	}while (*a>*b|| *a < 0);
}

int prest(int x){
	return (x%4==0) && (x%100!=0 || x%400==0);
}

void ispis(int a, int b){
	int i;
	for(i=a; i<=b; i++){
		if(prest(i)){
			printf("%d\n",i);
		}
	}
}

int main(){
	int a, b;
	god(&a,&b);
	printf("Prestupne godine su:\n");
	ispis(a,b);
	
return 0;}
