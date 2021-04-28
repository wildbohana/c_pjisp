#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ms 3
#define mi 21
#define mv 21

typedef struct element_st{
	char simbol[ms];
	char ime[mi];
	unsigned tezina;
	char vrsta[mv];
	
	struct element_st *sledeci;
}el;

FILE *safeopen(char *name, char *mode, int err){
	FILE *fp=fopen(name, mode);
	if (fp==NULL){
		printf("Nije moguce otvoriti datoteku %s.\n", name);
		exit(err);
	}
	return fp;
}
void inic(el **glava){
	*glava=NULL;
}
el *napravi_novi(char simbol[], char ime[], unsigned tezina, char vrsta[]){
	//ide zvezda kod f-je
	el *novi=(el *)malloc(sizeof(el));
	
	if (novi==NULL){
		printf("Nema dovoljno memorije!");
		exit(666);
	}
	
	strcpy(novi->simbol,simbol);
	strcpy(novi->ime,ime);
	novi->tezina=tezina;
	strcpy(novi->vrsta,vrsta);
	
	novi->sledeci=NULL;
	
	return novi;
}
void dodaj_novi(el **glava, el *novi){
	if(*glava==NULL){			//ne zaboravi * kod glave
		*glava=novi;
		return;
	}
	
	el *pret=*glava;
	el *tek=*glava;
	while(tek!=NULL){
		pret=tek;
		tek=tek->sledeci;
	}
	pret->sledeci=novi;
	return;
}
void ucitaj(FILE *in, el **glava){
	char simbol[ms];
	char ime[mi];
	unsigned tezina;
	char vrsta[mv];
	
	while(fscanf(in, "%s %s %u %s", simbol, ime, &tezina, vrsta)!=EOF){
		el *novi=napravi_novi(simbol, ime, tezina, vrsta);
		dodaj_novi(glava, novi);
	}
}
void ispis(FILE *out, el *glava){		//jedna * ovde, ako bude ** onda izađe neko ptr warrning
	while(glava!=NULL){
		fprintf(out, "%-2s %3u %s\n", glava->simbol, glava->tezina, glava->vrsta);
		glava=glava->sledeci;
	}
}
void brisanje(el **glava){
	el *tek;
	while(*glava!=NULL){
		tek=*glava;
		*glava=(*glava)->sledeci;
		free(tek);
	}
}



int main(int brArg, char **args){
	if(brArg!=4){
		printf("Nije dobro pozvan program!");
	}
	
	char *element=args[1];
	char *ulazna=args[2];
	char *izlazna=args[3];
	
	FILE *in=safeopen(ulazna, "r", 1);
	FILE *out=safeopen(izlazna, "w", 2);
	
	el *glava;
	inic(&glava);
	ucitaj(in,&glava);
	ispis(out,glava);
	
	brisanje(&glava);
	fclose(in);
	fclose(out);
	
return 0;}
