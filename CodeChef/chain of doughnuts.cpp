#include<bits/stdc++.h>
using namespace std;
#define getcx getchar
inline int input(){
	int n =0;
	char ch = getcx();
	while(ch<33)
	ch=getcx();
	while(ch>=33){
		n = (n<<3) + (n<<1) + (ch-'0');
		ch = getcx();
	}
	return n;
};

int main(){
	long long int n,count;
	int arr[20001];
	int m,t,i,j,gaps;
	scanf("%d",&t);
	while(t--){
		scanf("%lld %d",&n,&m);
		
		for(i=0;i<m;i++){
			arr[i]=input();
		}
		sort(arr,arr+m);
		count=0;
		gaps=m-1;
			if(gaps==(arr[0]+1)){
			printf("%d\n",arr[0]);
			continue;}
			if(gaps<=arr[0]){
			printf("%d\n",gaps);
			continue;
		}	
		for(i=0;i<m;i++)
		{
			count+= arr[i];
			
			if((gaps-i-1)<count){
				printf("%d\n",gaps-i);
				break;
			}
				else
				{
				if(count==(gaps-i-1)){
					printf("%lld\n",count);
					break;
				
				}
				}
		
			
		}
	}
	return 0;
}
