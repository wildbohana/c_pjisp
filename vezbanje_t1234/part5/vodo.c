#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define mime 21
#define madr 50
#define mdat 12
#define ms 30

typedef struct licnost_st{
	char ime[mime];
	char adresa[madr];
	unsigned dan;
	unsigned mesec;
	unsigned godina;
}lic;

void unos(lic *niz, int *pn){
	do{
		printf("Unesite broj osoba: ");
		scanf("%d", pn);
	}while(*pn<=0 || *pn>ms);
	
	int i;
	char datum[mdat];
	for (i=0;i<*pn;i++){
		printf("Unesite ime %d osobe: ",i+1);
		__fpurge(stdin);
		gets(niz[i].ime);
		printf("Unesite adresu %d osobe: ",i+1);
		__fpurge(stdin);
		gets(niz[i].adresa);
		printf("Unesite datum rođenja %d osobe (dd.mm.gggg.): ",i+1);
		scanf("%u.%u.%u.", &niz[i].dan, &niz[i].mesec, &niz[i].godina);
		}
}

void ispis(lic l){
	printf("Ime: %s\n",l.ime);
	printf("Adresa: %s\n",l.adresa);
	printf("Datum rođenja: %u.%u.%u.\n",l.dan,l.mesec,l.godina);
}

void vodolija(lic *niz, int n){
	int i;
	for (i=0;i<n;i++){
		if((niz[i].mesec==1 && (niz[i].dan>21 && niz[i].dan<=31)) || (niz[i].mesec==2 && (niz[i].dan>=1 && niz[i].dan<=19)))ispis(niz[i]);
		}
	
}

int main(){
	lic niz[ms];
	int n;
	unos(niz,&n);
	vodolija(niz,n);
return 0;}
