#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
int lonelyinteger(int n, int* a) {
    int i,j,c,d;
    for(i=0;i<n;i++){
        if(a[i]==-1)
            continue;
        else{
        d=a[i];
        for(j=i+1;j<n;j++){
            if(a[j]==-1)
                continue;
           else if(d==a[j])
                a[j]=a[i]=-1;
                else continue;
                 
                
        }
        }
         }
    for(i=0;i<n;i++){
            if(a[i]==-1)
                continue;
            else 
                c=a[i];
        
    }
return c;

}
int main() {
    int res;
    
    int _a_size, _a_i;
    scanf("%d", &_a_size);
    int _a[_a_size];
    for(_a_i = 0; _a_i < _a_size; _a_i++) { 
        int _a_item;
        scanf("%d", &_a_item);
        
        _a[_a_i] = _a_item;
    }
    
    res = lonelyinteger(_a_size, _a);
    printf("%d", res);
    
    return 0;
}
