#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

long long divisibilty (long long a, long long c, long long b, long long n ) {
   // Write your code here
   ll res = 0;
 
   for (ll i = 1; i <= n; ++i)
   {
       if ((i % a) == 0 || (i % b) == 0 || (i % c) == 0) res++;
       
   }
   return res;

}

int main() {
    int T;
    scanf("%d", &T);
    for(int t_i=0; t_i<T; t_i++)
    {
        long long n;
        scanf("%lld", &n);
        long long a;
        scanf("%lld", &a);
        long long b;
        scanf("%lld", &b);
        long long c;
        scanf("%lld", &c);

        long long out_ = divisibilty(a, c, b, n);
        printf("%lld\n", out_);
    }
}