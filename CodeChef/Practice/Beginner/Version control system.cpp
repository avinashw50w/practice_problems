/*In this problem we'll consider a simplified model of a development project. Let's suppose, that there are N source files in the project. All the source files are 
distinct and numbered from 1 to N.

A VCS, that is used for maintaining the project, contains two sequences of source files. The first sequence contains the source files, that are ignored by the VCS. 
If a source file is not in the first sequence, then it's considered to be unignored. The second sequence contains the source files, that are tracked by the VCS. 
If a source file is not in the second sequence, then it's considered to be untracked. A source file can either be or not be in any of these two sequences.

Your task is to calculate two values: the number of source files of the project, that are both tracked and ignored, and the number of source files of the project, 
that are both untracked and unignored.

Input

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.

The first line of the test case description contains three integers N, M and K denoting the number of source files in the project, the number of ignored source files 
and the number of tracked source files.

The second line contains M distinct integers denoting the sequence A of ignored source files. The sequence is strictly increasing.

The third line contains K distinct integers denoting the sequence B of tracked source files. The sequence is strictly increasing.

Output

For each test case, output a single line containing two integers: the number of the source files, that are both tracked and ignored, and the number of the source files, 
that are both untracked and unignored.

Constraints

1 = T = 100
1 = M, K = N = 100
1 = A1 < A2 < ... < AM = N
1 = B1 < B2 < ... < BK = N */

#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;
int main(){
	int t;cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int freq[n+2] = {};
		for(int i=0;i<m;i++){
			int x;cin>>x;
			freq[x]++;
		}
		for(int i=0;i<k;i++){
			int x;cin>>x;
			freq[x]++;
		}
		int type1 = 0, type2 = 0;
		for(int i=1;i<=n;i++){
			if(freq[i]==2) type1++;
			else if(freq[i]==0) type2++;
		}
		cout<< type1 <<" "<<type2++ <<endl;
	}
}
