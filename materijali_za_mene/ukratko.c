više izvornih datoteka: #include (konstante, deklaracije f-ja, globalne promenljive itd
prvi znak identifikatora ne sme biti cifra (standard max broja cifara u id je 31)
__func__ (func je proizvoljno ime f-je) služi za pristupanje stringu koji sadrži ime f-je
za vrednosti tačno netačno se uvodi poseban logički tip (_Bool)
float - realni brojevi (deljenje u tipu double daje realan broj)
kastovanje (cast) - konverzija tipova
char - pojedinačni znak // string - niz znakova
operandi različitog tipa -> konverzija užeg u širi tip
unarni operatori>binarni operatori
operatori: aritmetički>relacioni>logički>dodele
side effect=pojava da se menja vrednost promenljive u nekom računanju
inkrementacija ++, dekrementacija --  (++n != n++)
niz pokazivača ima default vrednost NULL (a ne 0 kao brojevi)
operatorom = ne možemo preneti vrednost jednog niza u drugi niz (samo kroz ciklus, elem po elem)
sizeof() - pokazuje koliko memorije zauzima niz (u bajtovima)
//// nizovi /////
pokazivači pokazuju adresu (i tip) promenljive
char 1 byte, short int 2 byte, long int i float 4 byte, double 8 byte, pokazivači ugl 4 byte
& daje adresu promenljive, %p konverzija pokazivača za štampanje
sa * možemo da pristupimo nekoj vrednosti koja se nalazi na određenoj adresi
pokazivač void ne pokazuje na vodi tip podatka (koji ne postoji), pokazuje adresu bilo kog tipa
vodi pokazivač se kastuje da bi mogli nešto više da uradimo sa njim
operatori: - > < na pokazivače istog tipa koji pokazuju na elemente istog niza (a da nije void*)
relacijski op: == i != na pokazivače istog tipa (i void*)
svi pokazivači mogu da se porede sa NULL (da vidimo da li uopšte pokazuju na nešto)
niz je kao pokazivač, p pokazuje na prvi el niza (identifikator niza) / a[i]=*(a+i) / %a[i]=a+i
restrict - ograničenje (pokazivač)
u toku unosa mogu da stavim kod printf(" %s", string), ili da uradim __fpurge(stdin) posle toga
scanf kupi sve do prvog belog karaktera (loše za stringove
gets() funkcija scanf za stringove (ne stavljam format specifikator)
puts() funkcija printf za stringove 
gets () uzima bele karaktere, ide do \0 a ne do prvog razmaka
zanemari warning za __fpurge i za gets, samo kucaj ./a.out
poslednji element u nizu stringa je \0 (znači za 6 slova ide 7 lokacija (6 slova i \0))
f-ja po referenci: u f-ji staviš *i, u main ide f(&i)
za strukture pišeš struct imestr_st{tip imeprom; tip imeprom;...;}
kada dodaješ vrednost nekom članu u strukturi ide imestr.imeprom=vrednost
struktura može biti poziv funkcije
pristup članu: str.ime; (*p).m; p->m (bez i 2x sa pokazivačem)
FILE *fopen( argumenti ) (ugl tri: ime ul dat, ime izl dat, režim) (svodi size datoteke na 0)
fclose obavezan za zatvaranje datoteke
čitanje: getc (ide do EOF); pisanje: putc / fprintf, fscanf


prez t6 ovo kod main (int br arg,...) - kako komp zna koliki je brarg? on sam izbroji ili??
ATOI I ATOF (int su prirodni brojevi, float su realni, double su sa zarezima)
atoi atof i exit failure su u <stdlib.h>, fopen fscanf fprintf fclose i eof su u <stdio.h>
bubble sort
*kad ideš do tj od kraja niza, poslednji element ti je n-1, jer je n element /0 koji ti ne treba
pokazivači:	deklaracija int *p;	dodela vrednosti: p=&a;	pristup lokaciji: c=*p; *p=6;
konverzije za štampu: %d, %f, %c, %s, %p za p*,
u deklaraciji funkcije samo pišeš tipove	int funkc(int *, int *) npr
u definiciji već idu promenjive i operacije i return		u pozivu samo funkc(a, b);
char možeš štampati kao char sa %c a možeš i kao broj sa %d
__fpurge(stdin); posle scanf i fscanf
ima kul fora za p* na niz i ispis: while (*p){printf("%c ", *p++};
