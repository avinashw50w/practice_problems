/*Watson gives Sherlock an array A of length N. Then he asks him to determine if there exists an element in the array such that the sum of the elements on its left is equal to the sum of the elements on its right. If there are no elements to the left/right, then the sum is considered to be zero. 
Formally, find an i, such that, A1+A2...Ai-1 =Ai+1+Ai+2...AN.

Input Format 
The first line contains T, the number of test cases. For each test case, the first line contains N, the number of elements in the array A. The second line for each test case contains N space-separated integers, denoting the array A.

Output Format 
For each test case print YES if there exists an element in the array, such that the sum of the elements on its left is equal to the sum of the elements on its right; otherwise print NO.

Constraints 
1≤T≤10 
1≤N≤105 
1≤Ai ≤2×104 
1≤i≤N
Sample Input

2
3
1 2 3
4
1 2 3 3
Sample Output

NO
YES
Explanation 
For the first test case, no such index exists. 
For the second test case, A[1]+A[2]=A[4], therefore index 3 satisfies the given conditions.  */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long int
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        ll a[n+5];
        ll prefix=0,suffix=0;
        for(int i=0;i<n;i++) {cin>>a[i]; suffix+=a[i];}
        int f=0;
        for(int i=0;i<n;i++){
            suffix-=a[i];
            if(i>0)
                prefix+=a[i-1];
            if(suffix==prefix){f=1;break;}
        }
        if(f==1) cout<<"YES\n";
        else cout<<"NO\n";
    }
    
    return 0;
}
