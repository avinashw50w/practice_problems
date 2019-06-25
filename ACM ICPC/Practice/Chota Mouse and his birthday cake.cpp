/*Today is Chota Mouse's birthday. He wants to celebrate it in a grand style. His brother Mota Chuha immediately contacted a nearby bakery for 
an online delivery of a cake. The cake is of rectangular shape with height H and width W. Chota Mouse has invited F of his friends to the party. 
So, he wants to make F vertical cuts at distinct positions on the cake, so that the cake will be divided into F + 1 non-zero area parts 
(F for his friends and one for himself).
Let us assume the cake is placed along the coordinate axis with its left end at x coordinate 0 and right end at W. 
Please see the image in the examples for details.
He will make cuts at positions Pi such that Pi is strictly greater than zero and strictly less than W.
Also note that, all the positions for cutting are distinct.
Chota Mouse is a nice guy. So, he will be keeping the piece with the least area for himself and leave the other pieces for his friends to enjoy.
Chota Mouse is weak in mathematics, so can you please help him figure out the area of the piece he is going to have?
Input
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
First line of each test case contains three space separated integers F, H, W.
Second line of each test case contains F space separated integers, i-th of them denotes Pi.
Output
For each test case, print a single integer corresponding to the answer of the problem.
Constraints
1 = T = 100
1 = F = 500
1 = H = 10000
F + 1 = W = 10000
1 = Pi = W - 1
Sample
Input

3
1 1 2
1
1 4 5
3
2 3 9
6 2
Output

1
8
6
Explanation

In the first example,
both the pieces have same area (i.e. = 1).   */
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int,int>
int main(){
	int t;cin>>t;
	while(t--){
		int f,h,w;
		cin>>f>>h>>w;
		int a[f+1];a[0]=0;
		for(int i=1;i<=f;i++) cin>>a[i];
		sort(a,a+f+1);
		int ans=(1<<30);
		int area=0;
		for(int i=1;i<=f;i++){
			area=(a[i]-a[i-1]);
			ans=min(ans,area);
		}
		ans=min(ans,w-a[f]);
		cout<<ans*h<<endl;
	}
}
