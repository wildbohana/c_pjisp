#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define mg 3
#define mt 11

typedef struct gorivo_st{
	char grad[mg];
	char tip[mt];
	double cena;
	
	struct gorivo_st *sledeci;
}gorivo;

FILE *safeopen(char *name, char *mode, int err){
	FILE *fp=fopen(name, mode);
	if(fp==NULL){
		printf("\nNije moguce otvoriti fajl %s.", name);
		exit(err);
	}
	return fp;
}
void inic(gorivo **glava){
	*glava=NULL;
}
gorivo *kreiraj_novi(char grad[], char tip[], double cena){
	gorivo *novi=(gorivo *)malloc(sizeof(gorivo));
	if (novi==NULL){
		printf("Nema dovoljno memorije!");
		exit(666);
	}
	
	strcpy(novi->grad, grad);
	strcpy(novi->tip, tip);
	novi->cena=cena;
	
	novi->sledeci=NULL;
	
	return novi;
}
void dodaj_novi(gorivo **glava, gorivo *novi){
	if(*glava==NULL){
		*glava=novi;
		return;
	}
	
	gorivo *pret=*glava;
	gorivo *tek=*glava;
	while(tek!=NULL){		//ne tek->sledeci!=NULL, samo tek!=NULL
		pret=tek;
		tek=tek->sledeci;
	}
	pret->sledeci=novi;
	return;
}
void ucitaj(FILE *in, gorivo **glava){
	char grad[mg];
	char tip[mt];
	double cena;
	
	while(fscanf(in, "%s %s %lf", grad, tip, &cena)!=EOF){
		gorivo *novi=kreiraj_novi(grad, tip, cena);
		dodaj_novi(glava, novi);
	}
}
void ispis(FILE *out, gorivo *glava){
	while (glava!=NULL){
		fprintf(out, "%6.2lf %s %s\n", glava->cena, glava->grad, glava->tip);
		glava=glava->sledeci;
	}
}
void brisanje(gorivo **glava){
	gorivo *tek;
	while(*glava!=NULL){
		tek=*glava;
		*glava=(*glava)->sledeci;
		free(tek);
	}
}
double prosek(gorivo *glava, char *trazeno){
	double suma=0;
	int i=0;
	
	while(glava!=NULL){
		if(strcmp(glava->tip,trazeno)==0){
			suma+=glava->cena;
			i++;
		}
		glava=glava->sledeci;
	}
	return (suma/i);
}




int main(int brArg, char **args){
	if(brArg!=4){
		printf("Program nije dobro pozvan!");
	}
	
	char *trazeno=args[1];
	char *ulazna=args[2];
	char *izlazna=args[3];
	
	FILE *in=safeopen(ulazna, "r", 1);
	FILE *out=safeopen(izlazna, "w", 2);
	
	gorivo *glava;
	
	inic(&glava);
	ucitaj(in, &glava);
	ispis(out, glava);
	
	fprintf(out, "\nAVG = %6.2lf", prosek(glava, trazeno));
	
	//brisanje(&glava);
	fclose(in);
	fclose(out);
	
return 0;}
