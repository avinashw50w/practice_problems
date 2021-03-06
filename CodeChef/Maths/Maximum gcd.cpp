/* Chef has a set consisting of N integers. Chef calls a subset of this set to be good if the subset has two or more elements. He denotes all the good subsets as S1, S2, S3, ... , S2N-N-1. Now he represents the GCD of the elements of each good subset Si as Gi.
Chef wants to find the maximum Gi.

Input

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows."
The first line of each test case contains a single integer N denoting the number of elements in the set. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the set.

Output

For each test case, output the maximum Gi

Constraints

1 ≤ T ≤ 10
2 ≤ N ≤ 100000
1 ≤ Ai ≤ 500000

Example

Input:
2
5
1 2 3 4 5
6
2 9 99 12 36 48

Output:
2
12

Explanation

Example case 1.
Maximum gcd is 2 for the subset {2, 4}

Example case 2.
Maximum gcd is 12 for the subset {12, 36, 48} */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
vector<int> v(1000000),st(5000001);
int main()
{
    int i,t,n,maxi,c,res,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        maxi=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&(v[i]));
            maxi=max(maxi,v[i]);
        }
        for(i=0;i<=maxi;i++)
            st[i]=0;
        for(i=0;i<n;i++)
            st[v[i]]++;
            res=-1;
        for(i=maxi;i>0;i--)
        {
            c=0;
            for(j=i;j<=maxi;j=j+i)
            {
                c+=st[j];
            }
            if(c>1)
            {
                res=i;
                break;
            }
        }
        if(res!=-1)
            printf("%d\n",res);
        else
            printf("1\n");
    }
    return 0;
}