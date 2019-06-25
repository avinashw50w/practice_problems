#include <cstdio>
#include <cstring>
#include <algorithm>
#define dri(o) int o; scanf("%d",&(o))
#define drii(a,b) int a,b; scanf("%d%d",&(a),&(b))
#define driii(a,b,c) int a,b,c; scanf("%d%d%d",&(a),&(b),&(c))
typedef long long int ll;
using namespace std;

int main(){
	dri(t);
	ll n,m;
	while(t--){
		scanf("%lld%lld",&n,&m);
		if(n==1 or m==1) {
			if(n*m!=2)
				printf("No\n");
			else printf("Yes\n");
			continue;
		}
		if(n&1 and m&1){
			printf("No\n");
			continue;
		}
		else {
			printf("Yes\n");
			continue;
		}
	}
}
