#include <stdio.h>
#include <stdlib.h>

int main(){
    int sek, min, sat, n;
    printf("\nUnesi n: ");
    scanf("%d", &n);
    for(sat=0;sat<24;sat++)
        for(min=0;min<60;min++)
            for(sek=0;sek<60;sek++)
                if(sek+min+sat==n)
                    printf("\n %d sat %d min %d sek", sat, min, sek);
return 0;}
