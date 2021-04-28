#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define mn 11
#define mz 9
#define mp 9

typedef struct igra_st{
	char naziv[mn];
	char zanr[mz];
	char platforma[mp];
	double cena;
	
	struct igra_st *sledeci;
}igra;

FILE *safeopen(char *naziv, char *mode, int err){
	FILE *fp=fopen(naziv, mode);
	if (fp==NULL){
		printf("Datoteka %s nije mogla da se otvori", naziv);
		exit(err);
	}
	return fp;
}
void inic(igra **glava){
	*glava=NULL;
}
igra *pravi_novi(char naziv[], char zanr[], char platforma[], double cena){
	igra *novi=(igra *)malloc(sizeof(igra));
	if (novi==NULL){
		printf("Nema dovoljno memorije!\n");
		exit(1312);
	}
	strcpy(novi->naziv, naziv);
	strcpy(novi->zanr, zanr);
	strcpy(novi->platforma,platforma);
	novi->cena=cena;
	
	novi->sledeci=NULL;
	
	return novi;
}
void dodaj_novi(igra **glava, igra *novi){
	if(*glava==NULL){		// * kod glave!!!
		*glava=novi;
		return;
	}
	
	igra *tek=*glava;		//zasto *glava
	igra *pret=*glava;
	while(tek!=NULL){
		pret=tek;
		tek=tek->sledeci;
	}
	pret->sledeci=novi;		//zamena tek tj NULL za novi
	return;
}
void ucitaj(FILE *in, igra **glava){
	char naziv[mn];
	char zanr[mz];
	char platforma[mp];
	double cena;
	
	while(fscanf(in, "%s %s %s %lf",naziv, zanr, platforma, &cena)!=EOF){
		igra *novi=pravi_novi(naziv, zanr, platforma, cena);
		dodaj_novi(glava, novi);
	}
}
void ispis(FILE *out, igra *glava){		// jedna * ovde
	while(glava!=NULL){		//ne moze tek i glava ovde, ne odradi zadnji element
		fprintf(out, "%-10s %-8s %-8s %5.2lf\n", glava->naziv,glava->zanr, glava->platforma, glava->cena);
		glava=glava->sledeci;
		}
}
void brisanje(igra **glava){
	igra *tek;
	while(*glava!=NULL){
		tek=*glava;
		*glava=(*glava)->sledeci;
		free(tek);
	}
}
igra *najpovoljnije(igra *glava, char *trazenaplatforma, char *trazenizanr){
	if(glava==NULL){
		return NULL;
	}
	
	igra *najpovoljnije=NULL;
	while(glava!=NULL){
		if(strcmp(trazenaplatforma,glava->platforma)==0 && strcmp(trazenizanr,glava->zanr)==0){
			if(najpovoljnije==NULL){
				najpovoljnije=glava;
			}
			else if((glava->cena) < (najpovoljnije->cena)){
				najpovoljnije=glava;
			}
		}
		glava=glava->sledeci;
	}
	return najpovoljnije;	//ako ti izbaci error da ne koristis pointer, u glavi izbaci jednu *
}





int main(int brArg, char **args){
	if(brArg!=5){
		printf("Nije dobro pozvan program.");
	}
	
	char *trazenaplatforma=args[1];
	char *trazenizanr=args[2];
	char *ulazna=args[3];
	char *izlazna=args[4];
	
	FILE *in=safeopen(ulazna, "r", 1);
	FILE *out=safeopen(izlazna, "w", 2);
	
	
	igra *glava;
	
	inic(&glava);
	ucitaj(in, &glava);
	ispis(out, glava);
	
	igra *najpovoljnija=najpovoljnije(glava, trazenaplatforma, trazenizanr);
	
	if(najpovoljnija==NULL){
		fprintf(out, "\nZa %s platformu ne postoje '%s' igre!", trazenaplatforma, trazenizanr);
	} else {
		fprintf(out, "\nNajpovoljnija '%s' igra za %s platformu je:\n", 
		trazenizanr, trazenaplatforma);
		fprintf(out, "%s %5.2lf", najpovoljnija->naziv, najpovoljnija->cena);
	}
	
	brisanje(&glava);
	
	fclose(in);
	fclose(out);
	
return 0;}
