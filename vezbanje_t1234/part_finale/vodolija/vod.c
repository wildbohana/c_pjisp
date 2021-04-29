#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ms 30

typedef struct licnost_st{
	char ime[ms];
	char adresa[ms];
	unsigned dan;
	unsigned mesec;
	unsigned godina;
}lic;

FILE *safeopen(char *name, char *mode){
	FILE *fp=fopen(name, mode);
	if(fp==NULL){
		printf("Datoteka %s se nije uspesno otvorila.\n", name);
		exit(EXIT_FAILURE);
	}
	return fp;
}
void ucitaj(FILE *in, lic *niz, int *n){
	*n=0;
	while(fscanf(in, "%s %s %u %u %u", niz[*n].ime, niz[*n].adresa, &niz[*n].dan, &niz[*n].mesec, &niz[*n].godina)!=EOF){
	(*n)++;			// a ne (*n++) !!!
	}
}
// 	&& logičko i 	|| logičko ili
void vodolija(FILE *out, lic *niz, int n){
	int i;
	for(i=0;i<n;i++){
		if((niz[i].mesec==1 && (niz[i].dan>=21 && niz[i].dan<=31)) || (niz[i].mesec==2 && (niz[i].dan>=1 && niz[i].dan<=19))){
			fprintf(out, "%s %u %u %u\n", niz[i].ime, niz[i].dan, niz[i].mesec, niz[i].godina);
		}
	}
}



int main(int brArg, char **args){
	if(brArg!=3){
		printf("Program nije dobro pozvan!");
		exit(EXIT_FAILURE);
	}
	
	char *ulazna=args[1];
	char *izlazna=args[2];
	
	FILE *in=safeopen(ulazna, "r");
	FILE *out=safeopen(izlazna, "w");
	
	lic niz[ms];
	int n;
	
	ucitaj(in, niz, &n);
	vodolija(out, niz, n);
	
	fclose(in);
	fclose(out);
	
return 0;}



//genericki ispis u fajl
/*void ispis(FILE *out, lic *niz, int n){
	int i;
	for(i=0;i<n;i++){
		fprintf(out, "%s %s %u %u %u\n", niz[i].ime, niz[i].adresa, niz[i].dan, niz[i].mesec, niz[i].godina);
	}
}*/
