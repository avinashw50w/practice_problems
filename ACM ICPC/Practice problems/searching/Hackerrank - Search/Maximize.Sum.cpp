/* You are given an array of size N and another integer M. Your target is to find the maximum value of sum of subarray modulo M.

Subarray is a continuous subset of array elements.

Note that we need to find the maximum value of (Sum of Subarray)%M , where there are N×(N+1)/2N×(N+1)/2 possible subarrays.

For a given array A[]A[] of size NN, subarray is a contiguous segment from ii to jj where 0=i=j=N0=i=j=N

Input Format 
First line contains T , number of test cases to follow. Each test case consists of exactly 2 lines. First line of each test case contain 2 space separated integers NN and MM,
 size of the array and modulo value M. 
Second line contains N space separated integers representing the elements of the array.

Output Format 
For every test case output the maximum value asked above in a newline.

Constraints 
2=N=1052=N=105 
1=M=10141=M=1014 
1=elements of the array=10181=elements of the array=1018 
2=Sum of N over all test cases=5000002=Sum of N over all test cases=500000

Sample Input

1
5 7
3 3 9 9 5
Sample Output

6
Explanation

Possible subarrays are 
{3},{3},{9},{9},{5}{3},{3},{9},{9},{5} 
{3,3},{3,9},{9,9},{9,5}{3,3},{3,9},{9,9},{9,5} 
{3,3,9},{3,9,9},{9,9,5}{3,3,9},{3,9,9},{9,9,5} 
{3,3,9,9},{3,3,9,9,5},{3,9,9,5}{3,3,9,9},{3,3,9,9,5},{3,9,9,5} 
their sums modulo 77 are

3,3,2,2,5,6,5,4,0,1,0,2,3,1,53,3,2,2,5,6,5,4,0,1,0,2,3,1,5 respectively. 
Hence maximum possible sum taking Modulo 77 is 66 , and we can get 66 by adding first and second element of the array.  */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<set>
#define ll long long int
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t;cin>>t;
    while(t--){
        ll n,m;cin>>n>>m;
        ll pre_sum=0,maxx=0,a;
        set<ll> s;
        s.insert(0);
        for(int i=0;i<n;i++){
            cin>>a;
            pre_sum=(pre_sum+a)%m;
            maxx=max(maxx,pre_sum);   // if S[j]==0
            set<ll>::iterator it=s.lower_bound(pre_sum+1);
            if(it!=s.end()) maxx=max(maxx,m+pre_sum-(*it));
            s.insert(pre_sum);
        }
        cout<<maxx<<endl;
    }
    return 0;
}
