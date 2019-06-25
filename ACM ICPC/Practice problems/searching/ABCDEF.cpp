/*
You are given a set S of integers between -30000 and 30000 (inclusive).

Find the total number of sextuples (a,b,c,d,e,f) a,b,c,d,f E S and d!=0 that satisfy:  (a*b+c)/d - e = f

*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	int A[n+1];
	for(int i=0;i<n;i++) cin>>A[i];
	vector<int> s1,s2;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++)
			s1.push_back(A[i]*A[j]+A[k]);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				if(A[k]==0) continue;
				s2.push_back((A[i]+A[j])*A[k]);
			}
		}
	}
	sort(s1.begin(),s1.end());
	sort(s2.begin(),s2.end());
	
	int l,h;
	long long int ans=0;
	for(int i=0;i<s1.size();i++){
		l = lower_bound(s2.begin(),s2.end(),s1[i])-s2.begin();
		h = upper_bound(s2.begin(),s2.end(),s1[i])-s2.begin();
		ans+=(h-l);
	}
	cout<<ans;
	return 0;
}
