#include <iostream>
#include <algorithm>

using namespace std;

struct job{
	int idx;
	int dead;
	int treq;
};
vector<job> v;

bool comp(const job& a,const job& b){ return a.treq < b.treq; }
int main(){
	int t; cin>>t;
	int n = t;
	int d,m,i;
	while(t--){
		cin>>d>>m;
		v.push_back(job(i++,d,m));

		sort(v.begin(),v.end(),comp);
		int res[n];
		bool slot[n] = {0};

		for(int i=0;i<n;++i){
			for(int j=min(n,v[i].dead)-1;j>=0;--j){
				if(slot[j]==false){
					res[j] = i;
					slot[j] = false;
				}
			}
		}
	}
}