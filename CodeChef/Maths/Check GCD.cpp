/* Devu is a student of Mathematics. He has just gotten to know about GCD.

Now, he has a set S having N elements. He wants to check if there is any subset of S whose gcd is K. As the number of subsets can be very large, he wants your help checking it.

Input Format

The first line will contain a number T, the number of test cases.

The first line of each test case will contain two integers, N and K. The second line of each test case will contain N integers, S1…SN.

Constraints:

1≤T≤10 
1≤N≤105 
1≤K≤109 
1≤Si≤109

Output Format

A line containing YES or NO for each test case.

Sample Input

4
3 1
2 4 6
3 2
2 4 6
3 2
4 8 12
1 3
3
Sample Output

NO
YES
NO
YES
Explanation

For the first sample case, GCD of all the subsets can be enumerated as given below:

gcd(2)=2
gcd(4)=4
gcd(6)=6
gcd(2,4)=2
gcd(2,6)=2
gcd(4,6)=2
gcd(2,4,6)=2


For the second case {2,4} is such a subset, having GCD 2. 

SOlution:

Let `L` be the list of all numbers from `S` which are divisible by `K`. 

Let us consider that there is a subset `S′` of `S` whose GCD is `K`. By the property of the GCD, we can claim that each number will be divisible by `K`. This says that all members of `S′` must be members of `L`. 

Now, we can see that any subset of the list `L` will have GCD either `K` or a multiple of `K`. Now calculate the GCD of all numbers of `L`, and call it `g`. There are two cases: 

Case 1:
`g=K`. Then the list `L` is our subset and answer will be YES. 

Case 2:
`g=mK` where `m>1`. Now any subset of list `L` will have GCD either `mK` or a multiple of `mK`. So no subset of given set will have GCD `K`. hence, answer will be NO.
 Set by amititkgp

Problem Setter's code :   */
#include<bits/stdc++.h>

using namespace std;

#define ll  long long int 
#define MOD 1000000007
#define MOD9 1000000009

#define pb push_back
#define mp make_pair

#define as(x,a,b) assert(a <=x  && x<= b);
#define MM(a,x) memset(a, x, sizeof(a))
#define P(x) cout<<#x<<" = "<<x<<endl;
#define P2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl;
#define PV(a,n) for(int i=0;i<n;i++) cout<<#a<<"[" << i <<"] = "<<a[i]<<endl;
#define TM(a,b) cout<<#a<<"->"<<#b<<": "<<1.*(b-a)/CLOCKS_PER_SEC<<"s\n";

#define all(X) (X).begin(), (X).end ()
#define for_each(it, X) for (__typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)


int main()
{
    int t;
    cin>>t;
    as(t,1,10);
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        as(n,1,100000);
        as(k,1,MOD-7);
        ll a[n];
        for(int i=0 ; i< n ; i++)
        {
            cin>>a[i];
            as(a[i],1,MOD-7);
        }
        vector<ll> v;
        for(int i =0 ; i< n ; i++)
        {
            if( (a[i]%k) == 0 )
                v.pb(a[i]);
        }
        if(v.size() == 0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        if(v.size() == 1)
        {
            if(v[0] == k)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
            continue;
        }
        ll gc = __gcd(v[0], v[1]);
        for(int i = 2 ; i< v.size() ; i++)
        {
            gc = __gcd(gc,v[i]);
        }
        if(gc == k)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }   
    return 0;
}