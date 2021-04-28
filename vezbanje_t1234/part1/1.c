// konverzija iz celzijusa u kelvine

#include <stdio.h>

int main(){
	double cel, kel;
	
	printf("Unesite temperaturu u Celzijusima: ");
	scanf("%lf",&cel);
	
	kel=cel+273.15;
	
	printf("%2lf stepeni Celzijusa je %2lf stepeni Kelvina\n", cel, kel);
return 0;}
