#include<stdio.h>
#include<string.h>
 
#ifdef ONLINE_JUDGE
    #define gc getchar_unlocked
#else
    #define gc getchar
#endif
 
int read() {
    int num = 0;
    char c = gc();
    while( !(c>='0' && c<='9') ) c = gc();
    while(c>='0' && c<='9') {
        num = (num<<3)+(num<<1)+c-'0';
        c = gc();
    }
    return num;
}
 
 
int main() {
 
   int t, n, h, i, d, temp, sum[1000001];
   int long long ans, tSum;
   t = read();
 
   while( t-- ) {
 
        tSum = 0;
        n = read();
        h = read()-1;
 
        for(i=0; i<=n; i++)
            sum[i]=0;
 
        for(i=0; i<n; i++ ) {
            sum[read()]++;
            sum[read()+1]--;
        }
 
        for(i=1; i<n; i++)
            sum[i] += sum[i-1];
 
        for(i=0; i<=h; i++)
            tSum += sum[i];
        ans = tSum;
 
        for(i=1; i+h<n; i++) {
            tSum = tSum + sum[i+h] - sum[i-1];
            if( tSum > ans ) ans = tSum;
        }
        h++;
        printf("%lld\n",(long long int)h*n -  ans);
   }
 
   return 0 ;
}
