// unos stringa i njegov ispis obrnut

#include <stdio.h>
#include <string.h>

int main(){
	char str1[101];
	char str2[101];
	int i, n;
	gets(str1);
	n=strlen(str1);
	for (i=0; i<n; i++){
		str2[i]=str1[n-i-1];
		}
	puts(str2);
return 0;}

//ovo je sa strlen (koristi biblioteku string.h), ima način i bez toga
