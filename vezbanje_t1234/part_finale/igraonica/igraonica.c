#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ms 30

typedef struct igraci{
	char ime[ms];
	char prezime[ms];
	unsigned s1;
	unsigned m1;
	unsigned s2;
	unsigned m2;
}igr;

FILE *safeopen(char *name, char *mode){
	FILE *fp=fopen(name, mode);
	if(fp==NULL){
		printf("Datoteka %s nije mogla da se otvori.", name);
		exit(EXIT_FAILURE);
	}
	return fp;
}
void ucitaj(igr *niz, int *n){
	int i;
	do{
		printf("Koliko igraca je bilo u igraonici? ");
		scanf("%d", n);
	}while(*n<0 || *n>ms);
	
	for(i=0;i<*n;i++){		//uslovi su svi tu ali za ofo je bolje scanf
					//gets je više za druge stvari
		printf("Unesite ime igraca: ");
		__fpurge(stdin);
		gets(niz[*n].ime);
		printf("Unesite prezime igraca: ");
		__fpurge(stdin);
		gets(niz[*n].prezime);
		
		do{
			printf("U koliko sati je krenuo da igra? ");
			scanf("%d", &niz[*n].s1);
		}while(niz[*n].s1<10 || niz[*n].s1>22);
		do{
			printf("U koliko minuta je krenuo da igra? ");
			scanf("%u", &niz[*n].m1);
		}while(niz[*n].m1<0 || niz[*n].m1>59);
		
		
		do{
			printf("U koliko sati je zavrsio sa igrom? ");
			scanf("%d", &niz[*n].s2);
		}while((niz[*n].s2<10 || niz[*n].s2>22) && niz[*n].s1>niz[*n].s2);
		do{
			printf("U koliko minuta je zavrsio sa igrom? ");
			scanf("%u", &niz[*n].m2);
		}while(niz[*n].m2<0 || niz[*n].m2>59);
			
	}
}
unsigned sati(unsigned s1, unsigned m1, unsigned s2, unsigned m2){
	unsigned mu1=s1*60+m1;
	unsigned mu2=s2*60+m2;
	unsigned razlika=(mu2-mu1)/60+1;
return razlika;	
}
void ispis(FILE *out, igr *niz, int n){
	int i;
	unsigned hr;
	for(i=0;i<n;i++){
		hr=sati(niz[i].s1, niz[i].m1, niz[i].s2, niz[i].m2);
		fprintf(out, "%s %u\n", niz[i].ime, hr);
	}
}



int main(int brArg, char **args){
	if(brArg!=2){
		printf("Program nije dobro pozvan!");
		exit(EXIT_FAILURE);
	}
	
	char *izlazna=args[1];
	FILE *out=safeopen(izlazna, "w");
	igr niz[ms];
	int n;
	
	ucitaj(niz,&n);
	ispis(out, niz, n);
	
	fclose(out);
return 0;}
