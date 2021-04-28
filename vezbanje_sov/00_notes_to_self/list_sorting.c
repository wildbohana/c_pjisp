tip - typedef struct pa ime posle toga


-na pocetak:
//vec imas novi element napravljen
void na_pocetak(tip **glava, tip *novi){
	novi->sledeci=*glava;
	*glava=novi;
}



-bubble sort
void bubbleSort(tip *glava){
	int swapped, i;
	tip *tek;
	tip *pret=NULL;
	
	if(glava==NULL){
		return;
	}
	do{
		swapped=0;
		tek=glava;
		
		while (tek->next!=pret){
			if (tek->data > tek->sledeci->data){
				swap(tek, tek->sledeci);
				swapped=1;
			}
			tek=tek->sledeci;
		}
		pret=tek;
	}while(swapped);
}

void swap(tip *a, tip *b){
	int temp=a->data;
	a->data=b->data;
	b->data=temp;
}
