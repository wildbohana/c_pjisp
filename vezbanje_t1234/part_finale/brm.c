#include <stdio.h>
#define ms 30
#define mm 20

typedef struct automobil_st{
	char marka[mm];
	unsigned kub;
	unsigned god;
}brm;

void unos(brm *niz, int *pn){
	do{
		printf("Koliko ćete automobila uneti: ");
		scanf("%d", pn);
	}while (*pn<0 || *pn>ms);
	
	int i;
	for(i=0;i<*pn;i++){
		printf("\nUnesite marku automobila: ");
		__fpurge(stdin);
		gets(niz[i].marka);
		printf("Unesite kubikažu automobila: ");
		scanf("%u", &niz[i].kub);
		printf("Unesite godište automobila: ");
		scanf("%u", &niz[i].god);
		}
}

void ispis(brm a){
	printf("Marka: %s\n", a.marka);
	printf("Kubikaža: %d\n", a.kub);
	printf("Godište: %u\n", a.god);
}

void kubi(brm *niz, int n){
	unsigned kub;
	printf("\nUnesite traženu kubikažu: ");
	scanf("%u", &kub);
	int i, j=0, ng=0;
	for(i=0;i<n;i++){
		if(niz[i].kub<kub){
			if(niz[i].god>ng){
				j=i;
				}
			}
		}
	ispis(niz[j]);
	
}

int main(){
	brm niz[ms];
	int n;
	unos(niz,&n);
	kubi(niz,n);
return 0;}

//standardni ispis
/*
void ispis(str *niz, int n){
	int i;
	for(i=0;i<n;i++){
		printf("\nPrva osobina: %s", niz[i].1osobina);
		printf("\nDruga osobina: %d", niz[i].2osobina);
		printf("\n");
	}	
}
*/
