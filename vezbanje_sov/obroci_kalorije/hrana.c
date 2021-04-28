#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define mn 21
#define mv 21

//naziv gramaza kalorije
//najmanja kal vrednost
//prosledjues vrstu
//poziv ./a.out dezert obroci.txt
//ispis standardan, cela lista plus najjeftiniji

//dodaj nešto da računaš kalorije=kalorije*gramaza/100

typedef struct obrok_st{
	char naziv[mn];
	char vrsta [mv];
	unsigned gramaza;
	unsigned kalorije;
	
	struct obrok_st *sledeci;
}obrok;

FILE *safeopen(char *name, char *mode, int err){
	FILE *fp=fopen(name, mode);
	if (fp==NULL){
		printf("\nDatoteka %s nije uspesno otvorena!\n", name);
		exit(err);
	}
	return fp;
}
void inic(obrok **glava){
	*glava=NULL;
}
obrok *kreiraj_novi(char naziv[], char vrsta[], unsigned gramaza, unsigned kalorije){
	obrok *novi=(obrok *)malloc(sizeof(obrok));
	if (novi==NULL){
		printf("\nNema odvoljno memorije!\n");
		exit(666);
	}
	strcpy(novi->naziv, naziv);
	strcpy(novi->vrsta, vrsta);
	novi->gramaza=gramaza;
	novi->kalorije=kalorije;
	
	novi->sledeci=NULL;
	
	return novi;
}
void dodaj_novi(obrok **glava, obrok *novi){
	if(*glava==NULL){
		*glava=novi;
		return;
	}
	
	obrok *pret=*glava;
	obrok *tek=*glava;
	while(tek!=NULL){
		pret=tek;
		tek=tek->sledeci;
	}
	pret->sledeci=novi;
	return;
}
void ucitaj(FILE *in, obrok **glava){
	char naziv[mn];
	char vrsta [mv];
	unsigned gramaza;
	unsigned kalorije;
	
	while(fscanf(in, "%s %s %u %u", naziv, vrsta, &gramaza, &kalorije)!=EOF){
		obrok *novi=kreiraj_novi(naziv, vrsta, gramaza, kalorije);
		dodaj_novi(glava, novi);
	}
}
void ispis(obrok *glava){
	while(glava!=NULL){
		printf("%s %u %u\n", glava->naziv, glava->gramaza, glava->kalorije);
		glava=glava->sledeci;
	}
}
void brisanje(obrok **glava){
	obrok *tek;
	while(*glava!=NULL){
		tek=*glava;
		*glava=(*glava)->sledeci;
		free(tek);
	}
}
obrok *djeta(obrok *glava, char *trazeno){
	if(glava==NULL){
		return NULL;
	}
	obrok *pravi=NULL;
	while(glava!=NULL){
		if(strcmp(glava->vrsta, trazeno)==0){
			if(pravi==NULL){
				pravi=glava;
			}
			else if(glava->kalorije<pravi->kalorije){
				pravi=glava;
			}
		}
		glava=glava->sledeci;
	}
	return pravi;
}


int main(int brArg, char **args){
	if (brArg!=3){
		printf("\nNije dobro pozvan program!\n");
		exit(EXIT_FAILURE);
	}
	
	char *trazeno=args[1];
	char *ulazna=args[2];
	
	FILE *in=safeopen(ulazna, "r", 1);
	
	obrok *glava;
	inic(&glava);
	
	ucitaj(in, &glava);
	ispis(glava);
	
	obrok *a=djeta(glava, trazeno);
	if(a==NULL){
		printf("\nNije pronađena ova vrsta obroka\n");
	}
	else{
		printf("\nNajmanje kaloricno %s je %s sa %u kalorija.\n", a->vrsta, a->naziv, a->kalorije);
	}
	
	brisanje(&glava);
	fclose(in);
	
return 0;}
