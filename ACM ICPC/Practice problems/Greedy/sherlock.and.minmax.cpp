/*Watson gives Sherlock an array A1,A2...AN. 
He asks him to find an integer M between P and Q(both inclusive), such that, min {|Ai-M|, 1 ≤ i ≤ N} is maximised. If there are multiple 
solutions, print the smallest one.

Input Format 
The first line contains N. The next line contains space separated N integers, and denote the array A. The third line contains two space 
separated integers denoting P and Q.

Output Format 
In one line, print the required answer.

Constraints 
1 ≤ N ≤ 102 
1 ≤ Ai ≤ 109 
1 ≤ P ≤ Q ≤ 109

Sample Input

3
5 8 14
4 9
Sample Output

4
Explanation 
For M = 4,6,7, or 9, the result is 1. Since we have to output the smallest of the multiple solutions, we print 4.  */

#include <cmath>
#include <vector>
#include <iostream>
#include <climits>
using namespace std;
#define ll long long int
vector<int> a(101);
int n,p,q,ans;
ll check(int x){
    int r=INT_MAX;
    for(int i=0;i<n;i++){
        r=min(r,abs(a[i]-x));
    }
    return r;
}
void valid(int x){
    if(x<p || x>q) return;
    if(check(x)>check(ans))
        ans=x;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    n; cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    
    cin>>p>>q;
    ans=p;
    valid(p);
    valid(q);
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++){
        valid((a[i]+a[j])>>1);
    }
    cout<<ans;
    return 0;
}
