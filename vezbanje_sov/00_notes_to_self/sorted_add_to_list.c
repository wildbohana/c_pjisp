// nije exec fajl nego čiso radi formatiranja .c

void dodaj_cvor(PIZZA **glava, PIZZA *novi){
        int nakraj=1;
        if(*glava == NULL){				//prvi slučaj prazne liste
            *glava=novi;				//novi je prvi element
        }else{
            PIZZA *tekuci = *glava;
            PIZZA *prethodni = *glava;
           						//standardno dovde
            if(novi->cena > tekuci->cena){		//drugi slučaj - lista nije prazna, pporedis ovde
                novi->sledeci=*glava;			//stavljaš element na početak
                *glava=novi;
                return;
            }
            while(tekuci != NULL){			//treću slučaj - element je u sredini negde
                if(novi->cena > tekuci->cena){	
                    nakraj=0;				//nađeš mu mesto i izađeš iz petlje
                    break;
                }
                prethodni=tekuci;			//šaltaš dalje
                tekuci = tekuci->sledeci;
            }
            if(nakraj == 1){				//četrvrti slučaj
            						//prošao je celu listu i nigde nije našao mesto
                prethodni->sledeci = novi;		//staviš ga na kraj
            }else{					
                novi->sledeci = prethodni->sledeci;	//ako nije na kraju onda ga staviš na mesto
                prethodni->sledeci = novi;		//a.k.a. slučaj tri
            }
        }
}

//dodaj na kraj
