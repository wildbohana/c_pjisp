#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define mg 3
#define mn 21

typedef struct meso_st{
	char grad[mg];
	char naziv[mn];
	double cenakg;
	
	struct meso_st *sledeci;
}meso;

FILE *safeopen(char *name, char *mode, int exitbroj){
	FILE *fp=fopen(name, mode);
	if (fp==NULL){
		printf("\nDatoteka %s nije uspesno otvorena.\n", name);
		exit(exitbroj);
	}
	return fp;
}
void inicijalizacija(meso **glava){
	*glava=NULL;
}
meso *kreiraj_novi(char grad[], char naziv[], double cenakg){
	meso *novi=(meso *)malloc(sizeof(meso));
	
	if(novi==NULL){
		printf("Nema dovoljno memorije.");
		exit(843);
	}
	
	strcpy(novi->grad,grad);
	strcpy(novi->naziv,naziv);
	novi->cenakg=cenakg;
	
	novi->sledeci=NULL;
	
	return novi;
}
void dodaj_novi(meso *novi, meso **glava){
	
	if(*glava==NULL){
		*glava=novi;
		return;
	}
	meso *pret=*glava;
	meso *tek=*glava;
	
	while(tek!=NULL){
		pret=tek;
		tek=tek->sledeci;
	}
	pret->sledeci=novi;
	return;
}
void ucitavanje(FILE *in, meso **glava){
	char grad[mg];
	char naziv[mn];
	double cenakg;
	
	while(fscanf(in, "%s %s %lf", grad, naziv, &cenakg)!=EOF){
		meso *novi=kreiraj_novi(grad, naziv, cenakg);
		dodaj_novi(novi, glava);
	}
}
void ispis(FILE *out, meso *glava){
	while(glava!=NULL){
		fprintf(out, "%6.2lf %s %s\n", glava->cenakg, glava->grad, glava->naziv);
		glava=glava->sledeci;
	}
}
void brisanje(meso **glava){
	meso *tek;
	while(*glava!=NULL){
		tek=*glava;
		*glava=(*glava)->sledeci;
		free(tek);
	}
}
meso *najpovoljnije(char *trazeno, meso *glava){
	if(glava==NULL){
		return NULL;
	}
	
	meso *best=NULL;
	while(glava!=NULL){
		if(strcmp(glava->naziv,trazeno)==0){
			if (best==NULL){
				best=glava;
			}
			else if (glava->cenakg < best->cenakg){
				best=glava;
			}
		}
		glava=glava->sledeci;
	}
	return best;
}


int main(int brArg, char **args){
	
	if(brArg!=4){
		printf("Niste dobro pozvali program.");
		exit(101);
	}
	
	meso *glava;
	
	char *trazeno=args[1];
	char *indat=args[2];
	char *outdat=args[3];
	
	FILE *in=safeopen(indat, "r", 1);
	FILE *out=safeopen(outdat, "w", 2);
	
	inicijalizacija(&glava);
	ucitavanje(in, &glava);
	ispis(out, glava);
	brisanje(&glava);
	
	fprintf(out, "\n\nNajpovoljnija %s je:\n",trazeno);
	meso *najjef=najpovoljnije(trazeno, glava);
	if(najjef==NULL){
		fprintf(out, "\nNigde nema %s!\n", trazeno);
	} else{
		fprintf(out, "\nNajpovoljnija %s je:\n", trazeno);
		fprintf(out, "%6.2lf %s %s\n", najjef->cenakg, najjef->grad, najjef->naziv);
	}
	//ne vraca mi nista na junetinu u ispisu
	
	fclose(in);
	fclose(out);
	
return 0;}
