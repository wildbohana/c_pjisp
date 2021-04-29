//liste

prvo glava dobija vrednost null(ne pokazuje ni na šta - inicijalizovana je lista)
glava=NULL;

onda stvaramo novi cvor
novi=(tip *)malloc(sizeof(tip));

ako je lista prazna tada se novi element ubacuje kao glava liste
if(glava==NULL)glava=novi;

ako lista već postoji, preskače se ovo i onda ide sledeći kod (uvezivanje)
tek=glava;
pret=glava;
while(tek!=NULL){
	pret=tek;
	tek=tek->sledeci;
	}
pret->sledeci=novi;		//ovim poslednji el liste ne pokazuje ni na šta

listanje liste
tek=glava;
while(tek!=NULL){
	printf(" %c",tek->znak);
	tek=tek->sledeci;
}

brisanje elementa se vrši tako što prvo tražimo taj element
tek=glava;
pret=glava;
while(tek!=NULL && (tek->znak!=c)){
	pret=tek;
	tek=tek->sledeci;
}

ako el koji brisemo nije prvi el liste
pret->sledeci=tek->sledeci;	//preskače se element između
tek->sledeci=NULL;		//briše se element između
free(tek);			// u suštini vraćaš ga u rikverc sa ovim prethodni->sledeci=tek->sledeci

ako je el prvi el liste
glava=tek->sledeci;		//glava pokazuje na drugi el niza
tek->sledeci=NULL;		//brišemo prvi el niza
free(tek);			// u suštini preveđeš glavu na drugi i oslobađaš prvi

brisanje cele liste
while(glava!=NULL){
	tek=glava;
	glava=tek->sledeci;
	free(tek);
}
