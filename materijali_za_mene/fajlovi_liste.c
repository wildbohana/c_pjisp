
//za fajlove:

na kraju obavezno uradi fclose(in) i fclose(out)
koristiš fprintf i fscanf iz ulazne


FILE *safe_open(char *name, char *mode){
    FILE *fp=fopen(name, mode);
    
    if(fp == NULL){
        printf("Doslo je do greske prilikom otvaranja datoteke %s\n", name);
        exit(EXIT_FAILURE);	//ili neki broj ili bilo šta što želiš
    }
    return fp;
}

// u mainu za fajlove:
 FILE *in=safe_open(args[1], "r");
 FILE *out=safe_open(proizvoljno ime(sa .txt na kraju), "w");

void ucitavanje(FILE *in, KNJIGA **glava){	//znači (FILE *in, tip podatka **glava (pokaz na pokaz)
    char sifra_knjige[MAXS];			//sva polja iz strukture zajedno sa ograničenjima
    char zanr_knjige[MAXZ];
    char naziv_knjige[MAXN];
    char ime_autora[MAXA];
    char izdavac[MAXI];			//onda praviš dokle učitava (do EOF)
    double cena_bez_pdv;			//u fscanf idu tipovi podataka logično
    char godina_izdanja[MAXG];		//i nigde gde je string ne ide &, on ide samo kod broja

    while(fscanf(in, "%s %s %s %s %s %lf %s", sifra_knjige, zanr_knjige, naziv_knjige, ime_autora, izdavac, &cena_bez_pdv, godina_izdanja) != EOF){
    KNJIGA *novi=kreiraj_novi(sifra_knjige, zanr_knjige, naziv_knjige, ime_autora, izdavac, cena_bez_pdv, godina_izdanja);
        dodaj_novi(glava, novi);		//ujedno praviš sledeći pokazvač

    }
}						//u main pozivaš sa ucitavanje(in, &glava)


void ispis(FILE *out, KNJIGA *glava, char zanr_knjige[], char maloprodajna[]){
    while(glava != NULL){			//null je na kraju liste
        if(strcmp(glava->zanr_knjige, zanr_knjige) == 0 && cena_sa_pdv(glava)<atof(maloprodajna)){
            fprintf(out, "%s %s %6.2f\n", glava->naziv_knjige, glava->ime_autora, cena_sa_pdv(glava));
        }
        glava=glava->sledeci;			//šalta na sledeći pok(ako ga ima)
    }
}




/////////////////////////////////////////////////////////////////////////////////////////////////////

//za liste:

u typedef za strukturu na kraj staviš
	struct knjiga_st *sledeci;

void inicijalizacija(KNJIGA **glava){
        *glava=NULL;
}						//glava na nulu logično


KNJIGA *kreiraj_novi(char sifra_knjige[], char zanr_knjige[], char naziv_knjige[], char ime_autora[], char izdavac[], double cena_bez_pdv, char godina_izdanja[]){
        					//za novi čvor(poziv su svi podaci iz strukture
        KNJIGA *novi=(KNJIGA *)malloc(sizeof(KNJIGA));
        					//dinamička alokacija memorije
        if(novi == NULL){			//provera da li uopšte ima dovoljo memorije
            printf("Nema dovoljno memorije!\n");
            exit(EXIT_FAILURE);		//opet opciono
        }
        
        strcpy(novi->sifra_knjige, sifra_knjige);
        strcpy(novi->zanr_knjige, zanr_knjige);
        strcpy(novi->naziv_knjige, naziv_knjige);
        strcpy(novi->ime_autora, ime_autora);
        strcpy(novi->izdavac, izdavac);
        novi->cena_bez_pdv=cena_bez_pdv;
        strcpy(novi->godina_izdanja, godina_izdanja);
        					//kopiraš podatke u novi koji ti dođe kao privremena
        novi->sledeci=NULL;			//staviš da ne pokazuje na sledeći
        					//ne treba ti, menjaš ovo po potrebi
        return novi;
}


void dodaj_novi(KNJIGA **glava, KNJIGA *novi){
        
        if(*glava==NULL){			//ako je lista prazna onda je glava novi
            *glava=novi;			//ako nije ideš na ovo ispod
            return;
        }
        
        KNJIGA *tek=*glava;			//knjiga je tip podatka ovde, praviš tek i pret pokaz
        KNJIGA *pret=*glava;			//oba su glava i dalje nz zašto
        					AUUU JEBOTE KREĆE JEBAČINA
        while(tek != NULL){			//ako postoji glava (realtivno logično)
            pret=tek;				//prethodni je tekuči?
            tek=tek->sledeci;			//tekući pokazuje na sledeći iz strukture tek
        }					//znači tekući je sledeći?
        pret->sledeci=novi;			//prethodni pokazuje na sledeći koji je novi
        
        return;
}


void brisanje_liste(KNJIGA **glava){
    KNJIGA *tek;				//inic tek koji ti je pomoćna promenljiva
    while(*glava != NULL){
        tek=*glava;				//krećeš od glave
        *glava=(*glava)->sledeci;		//glavu premestiš na sledeći
        free(tek);				//oslobodiš memoriju sa tek (tj sa pomoćnog)
    }
}

