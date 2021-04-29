#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define mc 21

typedef struct pacijent_st{
	char ime[mc];
	char prezime[mc];
	float holesterol;
	int pritisak;
	float secer;
}pac;

FILE *safeopen(char *name, char *mode){
	FILE *fp=fopen(name, mode);
	if(fp==NULL){
		printf("Datoteka %s nije mogla da se otvori.", name);
		exit(31);
	}
	return fp;
}
void unos(FILE *in, pac *niz, int *n){
	*n=0;
	while(fscanf(in, "%s %s %f %d %f",niz[*n].ime, niz[*n].prezime, &niz[*n].holesterol, &niz[*n].pritisak, &niz[*n].secer)!=EOF){
		(*n)++;
	}
}
void ispis(FILE *out, pac *niz, float zadato, int n){
	int i;
	for(i=0;i<n;i++){
		if(zadato<niz[i].pritisak){
			fprintf(out, "%s %s %d\n", niz[i].ime, niz[i].prezime, niz[i].pritisak);
		}
	}
}



int main(int brArg, char **args){
	if(brArg!=4){
		printf("Nije dobro pozvan program!");
		exit(1);
	}
	
	float zadato=atof(args[1]);
	char *ulazna=args[2];
	char *izlazna=args[3];
	
	FILE *in=safeopen(ulazna, "r");
	FILE *out=safeopen(izlazna, "w");
	
	int n;
	pac niz[10];	//ne ide zvezda ovde majmune
	
	unos(in, niz, &n);
	ispis(out, niz, zadato, n);
	
	
	fclose(in);
	fclose(out);
	
return 0;}
