#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define mi 31
//ime bodovi golrazlika
typedef struct ekipa_st{
	char ime[mi];
	double bodovi;
	double golr;
	
	struct ekipa_st *sledeci;
}ek;

FILE *safeopen(char *name, char *mode, int err){
	FILE *fp=fopen(name, mode);
	if (fp==NULL){
		printf("\nDatoteka %s nije uspesno otvorena.\n", name);
		exit(err);
	}
	return fp;
}
void inic(ek **glava){
	*glava=NULL;
}
ek *kreiraj_novi(char ime[], double bodovi, double golr){
	ek *novi=(ek *)malloc(sizeof(ek));
	if (novi==NULL){
		printf("\nNema dovoljno memorije!\n");
		exit(666);
	}
	
	strcpy(novi->ime,ime);
	novi->bodovi=bodovi;
	novi->golr=golr;
	
	novi->sledeci=NULL;
	
	return novi;
}
void dodaj_novi(ek **glava, ek *novi){
	int kraj=1;
	if(*glava==NULL){
		*glava=novi;
	}
	else{
		ek *pret=*glava;
		ek *tek=*glava;
		if(novi->bodovi > tek->bodovi){
			novi->sledeci=*glava;
			*glava=novi;
			return;
		}
		while (tek!=NULL){
			if(novi->bodovi > tek->bodovi){
				kraj=0;
				break;
			}
			pret=tek;
			tek=tek->sledeci;
		}
		if (kraj==1){
			pret->sledeci=novi;
		}
		else{
			novi->sledeci=pret->sledeci;
			pret->sledeci=novi;
		}
	}
	
}
void ucitaj(FILE *in, ek **glava){
	char ime[mi];
	double bodovi;
	double golr;
	
	while(fscanf(in, "%s %lf %lf", ime, &bodovi, &golr)!=EOF){
		ek *novi=kreiraj_novi(ime, bodovi, golr);
		dodaj_novi(glava, novi);
	}
}
void ispis(FILE *out, ek *glava){
	while(glava!=NULL){
		fprintf(out, "%s \t%3.0lf \t%3.0lf\n", glava->ime, glava->bodovi, glava->golr);
		glava=glava->sledeci;
	}
}
void brisanje(ek **glava){
	ek *tek;
	while(*glava!=NULL){
		tek=(*glava);
		*glava=(*glava)->sledeci;
		free(tek);
	}
}



int main(int brArg, char **args){
	if (brArg!=3){
		printf("\nNiste dobro pozvali program!\n");
		exit(EXIT_FAILURE);
	}
	
	char *ulazna=args[1];
	char *izlazna=args[2];
	
	FILE *in=safeopen(ulazna, "r", 1);
	FILE *out=safeopen(izlazna, "w", 2);
	
	ek *glava;
	inic(&glava);
	
	ucitaj(in, &glava);
	ispis(out, glava);
	
	brisanje(&glava);
	fclose(in);
	fclose(out);
	
return 0;}
