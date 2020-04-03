#include <cstdio>
#include <cstring>
#include <algorithm>
#define dri(o) int o; scanf("%d",&(o))

using namespace std;
int main(){
    dri(T);
    while(T--){
        dri(N);
        char str[100000+5];
        scanf("%s",str);
        int R,G,B;
        R=G=B=0;
        for(int i=0;str[i];++i){
            if(str[i]=='R') R++;
            else if(str[i]=='G') G++;
            else B++;
        }
        int maxx = max(max(R,G),B);
        printf("%d\n",N-maxx);
    }
    return 0;
}
