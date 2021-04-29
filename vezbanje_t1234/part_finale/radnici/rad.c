#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ms 20

typedef struct radnici_st{
	char ime[ms];
	char prezime[ms];
	int plata;
	char posao[ms];
}rad;

FILE *safeopen(char *name, char *mode){
	FILE *fp=fopen(name, mode);
	if(fp==NULL){
		printf("Datoteka %s nije otvorena.", name);
		exit(101);
	}
	return fp;
}
void unos(FILE *in, rad *niz, int *n){
	*n=0;
	while(fscanf(in, "%s %s %d %s", niz[*n].ime, niz[*n].prezime, &niz[*n].plata, niz[*n].posao)!=EOF){
		(*n)++;
	}
}
void ispis(FILE *out, rad *niz, int n, char *trazeno){
	int i;
	for(i=0;i<n;i++){
		if(strcmp(niz[i].posao,trazeno)==0){
			fprintf(out, "%s %s %d\n", niz[i].ime, niz[i].prezime, niz[i].plata);
		}
	}
}



int main(int brArg, char **args){
	if(brArg!=4){
		printf("Program nije dobro pozvan!");
		exit(21);
	}
	
	char *trazeno=args[1];
	char *ulazna=args[2];
	char *izlazna=args[3];
	
	FILE *in=safeopen(ulazna, "r");
	FILE *out=safeopen(izlazna, "w");
	
	int n;
	rad niz[ms];
	
	unos(in, niz, &n);
	ispis(out, niz, n, trazeno);
	
	fclose(in);
	fclose(out);
	
	
return 0;}
