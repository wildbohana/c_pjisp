#include <stdio.h> 
#include <stdlib.h> 
  
struct cvor_st { 
    int znak; 
    struct cvor_st* next; 
}; 
  
//Program za stvaranje jednostavnog povezanog
// lista sa 3 čvora
int main() 
{ 
    struct cvor_st* glava = NULL; 
    struct cvor_st* drugi = NULL; 
    struct cvor_st* treci = NULL; 
  
    // alociranje memorije za tri cvora
    glava = (struct cvor_st*)malloc(sizeof(struct cvor_st)); 
    drugi = (struct cvor_st*)malloc(sizeof(struct cvor_st)); 
    treci = (struct cvor_st*)malloc(sizeof(struct cvor_st)); 
  
    /*Tri bloka su dodeljena dinamički.
     Imamo pokazivače na ova tri bloka kao glavu,
     drugi i treći     
       glava           drugi           treci 
        |                |               | 
        |                |               | 
    +---+-----+     +----+----+     +----+----+ 
    | #  | #  |     | #  | #  |     |  # |  # | 
    +---+-----+     +----+----+     +----+----+ 
     
   # predstavlja bilo koju slučajnu vrednost.
   Podaci su slučajni jer im nismo dodelili
   nista još */
  
    glava->znak = 1; // dodeliti podatke prvom čvoru
    glava->next = drugi; // Poveži prvi čvor sa
    // drugim čvorom
  
    /* podaci su dodeljeni delu podataka prvog
     blok (blok uperen na glavu). I sledeći
     pokazivač prvog bloka pokazuje na drugi.
     Dakle, oba su povezana.
  
       glava          drugi         treci 
        |              |              | 
        |              |              | 
    +---+---+     +----+----+     +-----+----+ 
    | 1  | o----->| #  | #  |     |  #  | #  | 
    +---+---+     +----+----+     +-----+----+     
  */
  
    // dodeliti podatke drugom čvoru
    drugi->znak = 2; 
  
    // Povežite drugi čvor sa trećim čvorom
    drugi->next = treci; 
  
    /* podaci su dodeljeni delu podataka drugog
     blok (blok uperen na drugi). I sledeći
     pokazivač drugog bloka pokazuje na treći
     blok. Dakle, sva tri bloka su povezana.
    
       glava         drugi         treci 
        |             |             | 
        |             |             | 
    +---+---+     +---+---+     +----+----+ 
    | 1  | o----->| 2 | o-----> |  # |  # | 
    +---+---+     +---+---+     +----+----+      */
  
    treci->znak = 3; // dodeliti podatke trećem čvoru
    treci->next = NULL; 
  
    /* podaci su dodeljeni delu podataka trećeg
    blok (blok uperen na treći). I sledeći pokazivač
    trećeg bloka je NULL da bi označio
    da je ovde lista završena. 
  
     Spremili smo povezanu listu.  
  
           glava     
             | 
             |  
        +---+---+     +---+---+       +----+------+ 
        | 1  | o----->|  2  | o-----> |  3 | NULL | 
        +---+---+     +---+---+       +----+------+        
     
      
    Imajte na umu da je za predstavljanje dovoljna samo glava
    čitave liste. Možemo preći kompletnu
    listu prateći next pokazivac.   */
  
    return 0; 
} 
