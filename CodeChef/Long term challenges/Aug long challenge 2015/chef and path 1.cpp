#include <bits/stdc++.h>
#define md 1000000007
#define ll long long
#define gc getchar_unlocked
using namespace std;
inline int inp(){
	 int n=0,sign=1;
	char c;
	c=gc();
	while(c<'0' || c>'9'){
		if(c=='-')	sign=-sign;
		c=gc();
	}
	while(c>='0' && c<='9'){
		n=(n<<3)+(n<<1)+c-'0';
		c=gc();
	}
	n=n*sign;
	return n;
}
struct node{
	int a[51][51];
};
int mn[100];
vector < pair<int,int> > gr[100001];
node *ar[100001];
int temp[60],temp2[60];
int r;
inline int dfs(int idx,int pr){
	int mx=0;
	
	for(int i=0;i<gr[idx].size();i++){
		if(gr[idx][i].first!=pr){
			int tot=dfs(gr[idx][i].first,idx);
			int t=gr[idx][i].second;
			int id=gr[idx][i].first;
			for(int j=0;j<gr[id].size();j++)
				if(gr[id][j].first!=idx)
				free(ar[gr[id][j].first]);
			for(int j=1;j<=min(r,mx);j++){
				
				for(int k=1;k<=j;k++)
				{	temp[k]=ar[idx]->a[j][k];}
			
				
				for(int k=0;k<tot;k++){
					if(j+1+k<=r){
						for(int l=1;l<=k;l++)
						{	temp[j+l]=ar[id]->a[k][l];}
						temp[j+k+1]=t;
						for(int l=1;l<=j+k+1;l++)
							temp2[l]=temp[l];
						
						sort(temp2+1,temp2+j+k+2);
						mn[j+k+1]=min(mn[j+k+1],temp2[(j+k+2)/2+!((j+k+1)%2)]);
					}
				}
				
			}
			mx=max(mx,tot);
			
			ar[idx]->a[1][1]=min(ar[idx]->a[1][1],gr[idx][i].second);
			
			mn[1]=min(mn[1],ar[idx]->a[1][1]);
			
			for(int i=1;i<min(r,tot);i++){
				
				int idx2=1;
				bool f=false;
				for(int j=1;j<=i+1;j++)
					temp[j]=md;
				for(int j=1;j<=i;j++){
					if(t<=ar[id]->a[i][j] && !f)
					{	temp[idx2++]=t;f=true;}
					temp[idx2++]=ar[id]->a[i][j];
					
				}
				if(!f)
					temp[idx2++]=t;
				
				for(int j=1;j<=i+1;j++)
				{	temp[j]=min(temp[j],ar[idx]->a[i+1][j]);}
			
			for(int j=1;j<=i+1;j++)
				ar[idx]->a[i+1][j]=temp[j];
				
				
				mn[i+1]=min(mn[i+1],temp[(i+2)/2+(i%2)]);
			}
			
				
			
			
		}
	}
	
	return mx+1;
}
int main (){
	#ifndef ONLINE_JUDGE
			freopen("input.txt","r",stdin);	
	#endif
	int test;
	test=inp();
	while(test--){
		int n,l;
		n=inp();
		l=inp();
		r=inp();
		for(int i=1;i<=n+1;i++)
		{	gr[i].clear();
			ar[i]=(node *)malloc(sizeof(node));
			
		}
		for(int i=1;i<n;i++){
			int x,y,d;
			x=inp();
			y=inp();
			d=inp();
			gr[x].push_back(make_pair(y,d));
			gr[y].push_back(make_pair(x,d));
		}
		int mini=md;
		
			for(int ii=0;ii<=60;ii++)
			mn[ii]=md;
				for(int lll=1;lll<=n;lll++)
				for(int j=0;j<51;j++)
				for(int k=0;k<51;k++)
				ar[lll]->a[j][k]=md;
			
				dfs(1,1);
				
		
		for(int ii=l;ii<=r;ii++)
			mini=min(mini,mn[ii]);
				
			
		if(mini==md)
			printf("-1\n");
		else
		printf("%d\n",mini);
	}
	
	
    return 0;
}
