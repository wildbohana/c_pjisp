#include <stdio.h>
#include <string.h>
#define max 101

int main(){
	char str[max], str1[max], str2[max];
	int i, n, j=0;
	gets(str);
	n=strlen(str);
	for (i=0; i<n; i++){
		if (str[i]==' ' || '	'){
			i++;}
		else if (str[i]>64 || str[i]<90){
			str[i]-=32;
			str1[j]=str[i];
			j++;
			}
		else {
			str1[j]=str[i];
			}
		}
	for (i=0; i<n; i++){
		str2[i]=str1[n-i-1];
		}
	
	printf("%s\n",str2);
	
return 0;}
