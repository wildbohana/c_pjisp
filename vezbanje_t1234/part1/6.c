// razne binarne operacije

#include <stdio.h>

int main(){
	int a=5;
	int b=3;
	
	printf("Imamo dva broja, %d, %d: \n", a, b);
	printf("Zbir a+b: %d\n",a+b);
	printf("Razlika a-b: %d\n",a-b);
	printf("Proizvod a*b: %d\n",a*b);
	printf("Celobrojni količnik a/b: %d\n",a/b);
	// printf("Pogrešan pokušaj računjanja realnog količnika: %f\n",a/b); NEĆE DA KOMPAJLIRA
	printf("Realni količnik: %f\n",(float)a/(float)b);
	printf("Ostatak pri deljenju a/b: %d\n",a%b);
	
return 0;}
