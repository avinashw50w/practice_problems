#include <cstdio>
#include <cstring>
#include <algorithm>
#define dri(o) int o; scanf("%d",&(o))
#define drii(a,b) int a,b; scanf("%d%d",&(a),&(b))
#define driii(a,b,c) int a,b,c; scanf("%d%d%d",&(a),&(b),&(c))
typedef long long int ll;
using namespace std;

int main() {
	dri(t);
	while(t--){
		ll color[3];
		for(int i=0;i<3;++i) scanf("%lld",&color[i]);
		sort(color,color+3);
		ll k; scanf("%lld",&k);
		k--;
		ll ans = 0;
		if(k<=color[0]){
			ans = k*3;
		}
		else if(k>color[0] and k<=color[1]){
			int diff = k-color[0];
			ans = color[0]*3;
			ans += diff*2;
		}
		else{
			if(k>color[1])
			ans = color[0]*3 + (color[1]-color[0])*2 + (k-color[1]);
		}
		printf("%lld\n",ans+1);
	}
	return 0;
}
