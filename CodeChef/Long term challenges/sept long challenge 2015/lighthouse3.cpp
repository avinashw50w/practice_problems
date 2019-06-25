#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef vector<pii> vii;
struct cord{
	int x,y;
};
/*#define gc getchar
inline int input(){
	int n =0;
	char ch = getcx();
	while(ch<'0' || ch>'9')
	ch=getcx();
	while(ch>='0' || ch<='9'){
		n = (n<<3) + (n<<1) + (ch-'0');
		ch = getcx();
	}
	return n;
}*/
int main(){
	int i,j,t,n,north1,north2,south1,south2;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		struct cord v[100001];
		for(i=0;i<n;i++){
			scanf("%d %d",&v[i].x,&v[i].y);
		}
		int maxx=-1000000001,maxy=-1000000001,maxi1=-1,maxi2=-1;
		for(i=0;i<n;i++){
			if(v[i].x>=maxx){
				if(v[i].x>maxx){
					maxx=v[i].x;
					maxy=v[i].y;
					maxi1=i;
				}
				else{
					if(v[i].y>maxy){
						maxy=v[i].y;
						maxi1=i;
					}
				}
			}
		}
		north1=0; north2=0; south1=0; south2=0;
		int ymax=v[maxi1].y;
		for(i=0;i<n;i++){
			if(v[i].y<=ymax)
			south1++;
			if(v[i].y>=ymax)
			north1++;
		}
		
		maxx=1000000001,maxy=-1000000001;
		for(i=0;i<n;i++){
			if(i==maxi1)
			continue;
			if(v[i].x<=maxx){
				if(v[i].x<maxx){
					maxx=v[i].x;
					maxy=v[i].y;
					maxi2=i;
				}
				else{
					if(v[i].y>maxy){
						maxy=v[i].y;
						maxi2=i;
					}
				}
			}
		}
		if(maxi2!=-1){
		ymax=v[maxi2].y;
		for(i=0;i<n;i++){
			if(v[i].y<=ymax)
			south2++;
			if(v[i].y>=ymax)
			north2++;
		}
	}
		if(north1==n){
			printf("1\n%d NW\n",maxi1+1);
			continue;
		}
		
		if(north2==n){
			printf("1\n%d NE\n",maxi2+1);
			continue;
		}
		
		if(south1==n){
			printf("1\n%d SW\n",maxi1+1);
			continue;
		}
		
		if(south2==n){
			printf("1\n%d SE\n",maxi2+1);
			continue;
		}
		
		if(south1>=south2){
			printf("2\n%d SW\n",maxi1+1);
			printf("%d NE\n",maxi2+1);
			continue;
		}
		if(south1<south2){
			printf("2\n%d SE\n",maxi2+1);
			printf("%d NW\n",maxi1+1);
			continue;
		}
	}
	return 0;
}
