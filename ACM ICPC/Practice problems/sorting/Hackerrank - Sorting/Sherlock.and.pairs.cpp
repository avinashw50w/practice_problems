/* Sherlock is given an array of N integers (A0, A1 ... AN−1 by Watson. Now Watson asks Sherlock how many different pairs of indices i and j exist such that i is not equal to j but Ai is equal to Aj.

That is, Sherlock has to count the total number of pairs of indices (i,j) where Ai =Aj AND i≠j.

Input Format 
The first line contains T, the number of test cases. T test cases follow. 
Each test case consists of two lines; the first line contains an integer N, the size of array, while the next line contains N space separated integers.

Output Format 
For each test case, print the required answer on a different line.

Constraints 
1≤T≤10 
1≤N≤105 
1≤A[i]≤106

Sample input

2
3
1 2 3
3
1 1 2
Sample output

0
2
Explanation 
In the first test case, no two pair of indices exist which satisfy the given condition. 
In the second test case as A[0] = A[1] = 1, the pairs of indices (0,1) and (1,0) satisfy the given condition. */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
#define SIZE 1010101
using namespace std;
#define ll long long int
ll freq[SIZE];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        ll a[n+2];
        memset(freq,0,sizeof freq);
        ll ans=0;
        for(int i=0;i<n;i++) {cin>>a[i];freq[a[i]]++;}
        for(int i=0;i<SIZE;i++){
            if(freq[i])
                ans+=freq[i]*(freq[i]-1);
        }
        cout<<ans<<endl;
    }
    return 0;
}
