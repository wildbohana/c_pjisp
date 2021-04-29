#include <stdio.h>

int main( int brArg, char *arg[ ]) {
int i;
printf("Broj argumenata je: %d\n\n", brArg);
for(i=0; i<brArg; i++) {
	puts(arg[i]);
}
return 0;}



/*
(Kompajliramo naš program sa gcc –o zad zadatak1.c)
Ako bi smo prilikom poziva programa prosledili ./zad

konverzija atoi i atof idu u main
npr float a=atof(args[i]);

za tekst dat u kojoj u pozivu imas ul i izl dat ide ovo:
char *in_filename = args[i];
char *out_filename = args[j];
*/
