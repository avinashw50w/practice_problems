#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <string.h>
#include <cstdlib>
#define ll long long int
#define gc getchar()
using namespace std;
template <typename T>
string numtostr( T Number )
{
	stringstream ss;
	ss << Number;
	return ss.str();
}
inline ll input(){
	int n = 0;
	register int c=gc;
	while(c==' '||c=='\n') c=gc;
	while(c>='0'&&c<='9'){
		n=(n<<3)+(n<<1)+c-48;
		c=gc;
	}
	return n;
}
#define sz 10000000
int p[sz+1];
void seive(){
	memset(p,1,sz+1);
	for(ll i=2;i*i<=sz;++i){
		if(p[i]){
			for(ll j=i*i;j<=sz;j+=i)
			p[j] = 0;
		}
	}
}
void generate(){
	for(int i=2;i<=sz;i++){
		if(p[i]){
			string s = to_string(i);
			int n = s.size(), f=0;
			for(int k=0;k<n/2;k++){
				if(s[k]!=s[n-k-1]){
					f=1; break;
				}
			}
			if(f==1) p[i]=0;
		}
	}
}

int main(){
	int n=input();
	seive();
	generate();
	for(int i=2;i<sz;i++){
		if(p[i] && i>=n){
			cout<< i;
			break;
		}
	}
	return 0;
}
