int *pok;
pok=(int *)malloc(sizeof(int))	//malloc vraća void* pokazivač, pa ga treba kastovati
kod scanf ide ("%d",br)		//bez zvezde
kod printf ide ("%d",*br)		//sa zvezdom
free(br)				//obavezno oslobađanje memorije (dealociranje)

provera: if(pok==NULL){		//pok bez zvezde ovde
	printf(nema dovoljno memorije);
	return exit failure;}		//ako dinam.alok. vrati null, onda nema dovoljno memorije
