Operacije sa listom:
1) inicijalizacija liste,
2) unos novog elementa na pocetak liste,
3) listanje liste (prikaz svih elemenata iz liste),
4) brisanje elementa iz liste i
5) brisanje liste (oslobađanje memorije).

1)	glava=NULL;

2)	novi=(tip ?)malloc(sizeof(tip))
	popunjava se novi cvor (preko getc, preko fscanf i sa strcpy itd)
	if (glava==NULL){glava=novi} tj element je na početku liste
	ako lista več postoji onda se dodaje na sledeći način
		tek=glava;
		pret=glava;
		while(tek!=NULL)
		{
			pret=tek;
			tek=tek->sledeci;
		}
		pret->sledeci=novi;
	
3)	tek=glava;
	while(tek!=NULL)
	{
		printf("%c",tek->znak);	ili bilo koja druga f-ja za štampanje
		tek=tek->sledeci;		prelazi na sledeći element
	}

4)	traženje elementa (parametar je znak=c)
	tek=glava;
	pret=glava;
	while(tek!=NULL && (tek->znak != c))
	{
		pret=tek;
		tek=tek->sledeci;
	}
	nađemo član i imamo dva slučaja: da NIJE prvi element liste i da JESTE prvi element
	a)	pret->sledeci=tek->sledeci;
		tek->sledeci=NULL;
		free(tek);
	b)	glava=tek->sledeci;
		tek->sledeci=NULL;
		free(tek);

5)	while(glava!=NULL)
	{
	tek=glava;
	glava=tek->sledeci;
	free(tek);
	}
