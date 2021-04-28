// promenljive i pokazivači

#include <stdio.h>

int main(){
	int i, *pi;
	i=7;
	pi=&i;
	printf("Promenljiva	- adresa:\t %p, vrednost: \t %d\n\n", &i, i);
	printf("Pokazivač	- adresa:\t %p, vrednost: \t %p\n\n", &pi, pi);
	printf("Pokazivač	- vrednost:\t %p, sadržaj:\t %d\n\n", pi, *pi);
	i=10;
	printf("Pokazivač	- vrednost:\t %p, sadržaj:\t %d\n\n", pi, *pi);
	(*pi)++;
	printf("Promenljiva	- adresa:\t %p, vrednost:\t %d\n\n", &i, i);
return 0;}
