#include <stdio.h>

int main(void){
    long a = 1 ;
    int i ;
    for(i=1;i<11;i++){
        a = a*i;
        printf("%d!=%ld \n",i,a);
    }
    return 0;
}