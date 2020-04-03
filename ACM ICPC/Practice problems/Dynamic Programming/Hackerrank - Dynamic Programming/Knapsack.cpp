/* Given a list of n integers, A={a1,a2,…,an}, and another integer, k representing the expected sum. Select zero or more numbers from A such that the sum of these numbers is as near as possible, but not exceeding, to the expected sum (k).

Note

Each element of A can be selected multiple times.
If no element is selected then the sum is 0.
Input Format

The first line contains T the number of test cases. 
Each test case comprises of two lines. First line contains two integers, n k, representing the length of list A and expected sum, respectively. Second line consists of n space separated integers, a1,a2,…,an, representing the elements of list A.

Constraints 
1≤T≤10 
1≤n≤2000 
1≤k≤2000 
1≤ai≤2000,where i∈[1,n]
Output Format

Output T lines, the maximum sum for each test case which is as near as possible, but not exceeding, to the expected sum (k).

Sample Input

2
3 12
1 6 9
5 9
3 4 4 4 8
Sample Output

12
9         
*/
#include <bits/stdc++.h>
using namespace std;
void solve(int a[],int n,int k){
    int dp[k+1];
    memset(dp,0,sizeof dp);
    for(int i=1;i<=k;i++) {  // weight
        for(int j=0;j<n;j++){   //  numbers
             if(a[j]<=i) dp[i]=max(dp[i],max(dp[i-1],a[j]+dp[i-a[j]]));
        }
    }
    cout<<dp[k]<<endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        int a[n+2];
        for(int i=0;i<n;i++) cin>>a[i];
        solve(a,n,k);
    }
    return 0;
}
