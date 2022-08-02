
#include<bits/stdc++.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
using namespace std;
struct cricketer_run
{
    double x;
};
int main()
{
    struct cricketer_run batsman1[5]={101,40,30,62,70};
    struct cricketer_run batsman2[5]={49,39,59,51,43};
    double total1 = (batsman1[0].x+batsman1[1].x+batsman1[2].x+batsman1[3].x+batsman1[4].x)/5;
    double total2 = (batsman2[0].x+batsman2[1].x+batsman2[2].x+batsman2[3].x+batsman2[4].x)/5;
    double n=0,x=0,sum1=0,sum2=0;
   for(int i=0;i<5;i++){
            n=batsman1[i].x - total1;
            x=n*n;
            sum1=sum1+x;

            n=batsman2[i].x - total2;
            x=n*n;
            sum2=sum2+x;
    }
    double better1 = sqrt( sum1/5 );
    double sample1 = sqrt( sum1/4 );
    double better2 = sqrt( sum2/5 );
    double sample2 = sqrt( sum2/4 );
    if(better1<better2){
        printf("Batsman 1 is better. Stanfard Deviation of his run  %lf",better1);
        printf("\nwhile the Stanfard Deviation of other player is %lf\n",better2);
    }
    else{
        printf("Batsman 2 is better. Stanfard Deviation of his run  %lf\n",better2);
        printf("\nwhile the Stanfard Deviation of other player is %lf\n",better1);
    }

}
