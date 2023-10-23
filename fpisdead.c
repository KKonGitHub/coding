#include <stdio.h>

int main(void){
    FILE *fp; 

    if((fp = fopen("fpisalive.txt","w")) == NULL){
        fprintf(stderr,"fp is dead.");
    };

    fprintf(fp,"fp is still alive");
    return 0;
}