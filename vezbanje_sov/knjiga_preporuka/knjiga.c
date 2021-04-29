#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXS 9+1
#define MAXZ 15+1
#define MAXN 50+1
#define MAXA 30+1
#define MAXI 50+1
#define MAXG 4+1

typedef struct knjiga_st{
    char sifra_knjige[MAXS];
    char zanr_knjige[MAXZ];
    char naziv_knjige[MAXN];
    char ime_autora[MAXA];
    char izdavac[MAXI];
    double cena_bez_pdv;
    char godina_izdanja[MAXG];
    
    struct knjiga_st *sledeci;
}KNJIGA;

FILE *safe_open(char *name, char *mode){
    FILE *fp=fopen(name, mode);
    
    if(fp == NULL){
        printf("Doslo je do greske prilikom otvaranja datoteke %s\n", name);
        exit(EXIT_FAILURE);
    }
    return fp;
}
void inicijalizacija(KNJIGA **glava){
        *glava=NULL;
}
KNJIGA *kreiraj_novi(char sifra_knjige[], char zanr_knjige[], char naziv_knjige[], char ime_autora[], char izdavac[], double cena_bez_pdv, char godina_izdanja[]){
        
        KNJIGA *novi=(KNJIGA *)malloc(sizeof(KNJIGA));
        
        if(novi == NULL){
            printf("Nema dovoljno memorije!\n");
            exit(EXIT_FAILURE);
        }
        
        strcpy(novi->sifra_knjige, sifra_knjige);
        strcpy(novi->zanr_knjige, zanr_knjige);
        strcpy(novi->naziv_knjige, naziv_knjige);
        strcpy(novi->ime_autora, ime_autora);
        strcpy(novi->izdavac, izdavac);
        novi->cena_bez_pdv=cena_bez_pdv;
        strcpy(novi->godina_izdanja, godina_izdanja);
        
        novi->sledeci=NULL;
        
        return novi;
}
void dodaj_novi(KNJIGA **glava, KNJIGA *novi){
        
        if(*glava==NULL){
            *glava=novi;
            return;
        }
        
        KNJIGA *tek=*glava;
        KNJIGA *pret=*glava;
        
        while(tek != NULL){
            pret=tek;
            tek=tek->sledeci;
        }
        pret->sledeci=novi;
        
        return;
}
void ucitavanje(FILE *in, KNJIGA **glava){
    char sifra_knjige[MAXS];
    char zanr_knjige[MAXZ];
    char naziv_knjige[MAXN];
    char ime_autora[MAXA];
    char izdavac[MAXI];
    double cena_bez_pdv;
    char godina_izdanja[MAXG];

    while(fscanf(in, "%s %s %s %s %s %lf %s", sifra_knjige, zanr_knjige, naziv_knjige, ime_autora, izdavac, &cena_bez_pdv, godina_izdanja) != EOF){
        KNJIGA *novi=kreiraj_novi(sifra_knjige, zanr_knjige, naziv_knjige, ime_autora, izdavac, cena_bez_pdv, godina_izdanja);
        dodaj_novi(glava, novi);
    }
}
double cena_sa_pdv(KNJIGA *glava){
    double cena=(glava->cena_bez_pdv)/100*118;
    return cena;
}
void ispis(FILE *out, KNJIGA *glava, char zanr_knjige[], char maloprodajna[]){
    while(glava != NULL){
        if(strcmp(glava->zanr_knjige, zanr_knjige) == 0 && cena_sa_pdv(glava)<atof(maloprodajna)){
            fprintf(out, "%s %s %6.2f\n", glava->naziv_knjige, glava->ime_autora, cena_sa_pdv(glava));
        }
        glava=glava->sledeci;
    }
}
void brisanje_liste(KNJIGA **glava){
    KNJIGA *tek;
    while(*glava != NULL){
        tek=*glava;
        *glava=(*glava)->sledeci;
        free(tek);
    }

}
double prosek(KNJIGA *glava, char zanr_knjige[]){
        int brojac=0;
        double suma=0;
        
        while(glava != NULL){
            if(strcmp(glava->zanr_knjige, zanr_knjige) == 0){
                    brojac++;
                    suma += cena_sa_pdv(glava);
            }
            glava=glava->sledeci;
        }
        if(brojac==0){
            return 0;
        }
        return suma/brojac;
}

int main(int brArg, char *args[]){
        if(brArg != 4){
            printf("Nije dobro pozvan program.\n");
            exit(255);
        }
        
        char *zanr_knjige=args[2];
        char *maloprodajna=args[3];
        
        char preporuka[50];
        strcpy(preporuka, "preporuka_");
        strcat(preporuka, zanr_knjige);
        strcat(preporuka, ".txt");

        FILE *in=safe_open(args[1], "r");
        FILE *out=safe_open(preporuka, "w");
        
        KNJIGA *glava;
        
        inicijalizacija(&glava);
        
        ucitavanje(in, &glava);
        
        ispis(out, glava, zanr_knjige, maloprodajna);
        
        double avg=prosek(glava, zanr_knjige);
            if(avg==0){
                fprintf(out,"Nije pronadjeno\n");
            }else{
                fprintf(out, "\n Prosecna maloprodajna cena knjige %s zanra je: %6.2f\n", zanr_knjige, avg);
            }
            
            brisanje_liste(&glava);
            
            fclose(in);
            fclose(out);

    return 0;
}

