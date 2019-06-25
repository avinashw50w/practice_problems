/*Chef has a sequence of N numbers. He like a sequence better if the sequence contains his favorite sequence as a substring.
Given the sequence and his favorite sequence(F) check whether the favorite sequence is contained in the sequence
Input

The first line will contain the number of test cases and are followed by the cases. 
Each test case consists of four lines: The length of the sequence, the sequence N,the length of F and the sequence F
Output

Print "Yes" if the sequence contains the favourite sequence int it otherwise print "No"  

Constraints

1<=T<=10 
1 1
Input:
2
6
1 2 3 4 5 6
3
2 3 4
6
22 5 6 33 1 4
2
4 15


Output:
Yes
No */

#include <iostream>
#include <algorithm>
#define ll long long int
#define gc getchar
inline ll input(){
	int n = 0;
	register int ch = gc();
	while(ch==' '||ch=='\n') ch = gc();
	while(ch>='0'&&ch<='9'){
		n = (n<<3)+(n<<1)+ch-48;
		ch = gc();
	}
	return n;
}

using namespace std; 
int main(){
	int t,i,j,b;cin>>t;
	while(t--){
		int n; cin>>n;
		int a[n+2];
		for(i=0;i<n;++i) a[i]=input();
		int m = input();
		for(i=j=0;i<m;++i){
			b = input();
			while(j<n && a[j]!=b) j++;
			
			if(j>=n) {
				for(i++;i<m;i++)
				b = input();
				break;
			}
		}
		fputs(j<n ? "Yes\n" : "No\n",stdout);
	}
	return 0;
}
