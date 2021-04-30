#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct pizza_st{
    int cena;
    char drzava[4];
    char grad[3];
    char naziv[21];
    
    struct pizza_st *sledeci;
}PIZZA;

FILE *safe_open(char *filename, char *mode, int error_code){
        FILE *fp=fopen(filename, mode);
        if(fp==NULL){
            printf("Ne mozemo otvoriti fajl");
            exit(error_code);
        }
        return fp;
}
void inicijalizacija(PIZZA **glava){
        *glava=NULL;
}
PIZZA *kreiraj_novi(int cena, char drzava[], char grad[], char naziv[]){
        PIZZA *novi= (PIZZA *)malloc(sizeof(PIZZA));
        if(novi==NULL){
            printf("Nema dovoljno memorije");
            exit(21);
        }
        
        novi->cena=cena;
        strcpy(novi->drzava, drzava);
        strcpy(novi->grad, grad);
        strcpy(novi->naziv, naziv);
        
        novi->sledeci = NULL;
        
        return novi; 
}
void dodaj_cvor(PIZZA **glava, PIZZA *novi){
        if(*glava == NULL){
            *glava=novi;
        }else{
            PIZZA *tekuci = *glava;
            
            while(tekuci->sledeci != NULL){
                tekuci=tekuci->sledeci;
            }
            tekuci->sledeci=novi;
        }
}
void ucitaj(FILE *in, PIZZA **glava){
    int cena;
    char drzava[4];
    char grad[3];
    char naziv[21];
    
    while(fscanf(in, "%d %s %s %s", &cena, drzava, grad, naziv) != EOF){
           PIZZA *novi=kreiraj_novi(cena, drzava, grad, naziv);
           dodaj_cvor(glava, novi);
    }
}
void ispis(PIZZA *glava){
       PIZZA *tekuci=glava;
        
        while(tekuci != NULL){
            printf("%4d %s %s %s\n", tekuci->cena, tekuci->drzava, tekuci->grad, tekuci->naziv);
            tekuci = tekuci->sledeci;
        }
}
void brisanje_liste(PIZZA **glava){
    PIZZA *tekuci;
    
    while(*glava != NULL){
        tekuci=*glava;
        *glava = (*glava)->sledeci;
        tekuci->sledeci = NULL;
        free(tekuci);
    }
}

double prosek(char drzava[], char naziv[], PIZZA **glava){
	PIZZA *tekuci=*glava;
	double suma=0;
	int i=0;
	while (tekuci!=NULL){
		//strcmp trazi da ga izjednacis sa necim (ovde je to null ili 0 izgleda)
		if (strcmp(tekuci->drzava,drzava)==0 && strcmp(tekuci->naziv,naziv)==0){
			suma+=tekuci->cena;
			i++;
			}
		tekuci=tekuci->sledeci;
		}
	return (suma/i);
}

int main(int brArg, char *args[]){
        if(brArg != 4){
           printf("Nije dobro pozvan program");
           exit(255);
        }
        char *drzava = args[1];
        char *naziv=args[2];
        char *in_filename = args[3];
        
        FILE *in = safe_open(in_filename, "r", 1);
        
        PIZZA *glava;
        inicijalizacija(&glava);
        
        ucitaj(in, &glava);
        ispis(glava);
        
        printf("\nProsecna cena pizze %s u %s je: %.2lf\n",naziv,drzava,prosek(drzava,naziv,&glava));
        
        brisanje_liste(&glava);
        
        fclose(in);
         
    return 0;

}
