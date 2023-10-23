#include <stdio.h>
#include <stdlib.h>

#define N 1000
#define T 100
#define T0 573
#define TN 300
#define ALPHA 1.979e-6
#define REM 100
#define DELT 1
#define DELX 0.005

//高温測定数値計算用　10月4日
/*There will be so vast amount of data that excel or other tools cannot deal with.
Some of them have to be ignored.
In this program unit is conform to SI system. */

double proceed(double *p,double delta){
    int i = N;
    double newtemp[N-1];
    // delta is dt*a/dx^2

    for(i=0 ; i<N ; i++){
        if(i == 0){
            newtemp[i] = T0;
            *p++;
            continue;
        };

        if(i == N-1){
            newtemp[i] = TN;
            *p++;
            continue;
        };

        if(i == N){
            newtemp[i] = TN;
            break;
        }

        //according to the boundary condition

        newtemp[i] = delta*T*(*(p+1) + *(p-1)) + (1-2*delta)*(*p); // Using a finite difference equation to calculate next step.
        *p++ ;
    };

    for(i=N ; i>-1 ; i--){
        *p = newtemp[i] ;
        *p-- ;
    };// Assign new data to the temp in main function.
}


double sphproc(double *p, double){
    
}








int main(void){
    double temp[N-1];
    FILE *fp;
    double a = ALPHA * DELT /(DELX * DELX);

    if((fp = fopen("result.txt","w")) == NULL){
        fprintf(stderr,"File is not opened.");
        return 0;
    }

    temp[0] = T0;
    for(int i = 1; i< N ; i++){
        temp[i] = TN;
    }; //According to the boundary condition.

    for(int j=0 ; j<T ; j++){
         if(j%REM == 0){
            printf("%4d  %6.2lf \n",j, temp[10]);
            fprintf(fp,"%4d  %6.2lf \n",j, temp[10]);
        }
        
        proceed(&temp[0] , a);
    }       

    fclose(fp);
    return 0;
}