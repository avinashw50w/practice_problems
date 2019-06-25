#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int a_d,a_m,a_y,e_d,e_m,e_y,fine;
    scanf("%d%d%d",&a_d,&a_m,&a_y);
    scanf("%d%d%d",&e_d,&e_m,&e_y);
    if(a_m==e_m && a_y==e_y){
        if(a_d>e_d)
            fine=15*(a_d-e_d);
            else fine = 0;
    }
    else if(a_y==e_y && a_m>=e_m)
        fine=500*(a_m-e_m);
        else{ if(a_y>e_y)
            fine=10000;}
    printf("%d",fine);
        

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}

