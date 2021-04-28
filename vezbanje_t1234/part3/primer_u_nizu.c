// promenljive i pokazivači u nizu

#include <stdio.h>

int main(){
	int a[10]={1,2,3,4,5,6,7,8,9,0};
	int *pa;
	int i;
	pa=a;
	printf("%d\n\n",*pa);
	printf("%d\n\n",*(a+1));
	
	for (i=0; i<10; i+=2){
		pa=a+i;
		printf("%d\n",*pa);
		}
return 0;}
