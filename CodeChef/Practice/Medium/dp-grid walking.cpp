/* Enter your code here. Read input from STDIN. Print output to STDOUT */
#include <iostream>
#include <memory.h>

const int maxn = 10;
const int maxm = 10000;
const long long modulo = 1000000007;

int D[maxn];
int X[maxn];

int n,m;
int solve(){
	std::cin>>n>>m;
	for (int i=0; i<n; i++)
		std::cin>>X[i];
	for (int i=0; i<n; i++)
		std::cin>>D[i];

	long long totalway[n][m+1];
	for (int i=0; i<n; i++){		
		long long total[D[i]];
		memset(total, 0, sizeof(total));
		total[X[i]-1] = 1;
		long long ans;
		totalway[i][0] = 1;
		for (int step=1; step<=m; step++){
			long long tmp[D[i]];
			for (int j=0; j<D[i]; j++){
				tmp[j] = 0;
				if (j>0) tmp[j] += total[j-1];
				if (j<D[i]-1) tmp[j] += total[j+1];
				tmp[j] %= modulo;
			}
			totalway[i][step] = 0;
			for (int j=0; j<D[i]; j++){
				total[j] = tmp[j];
				totalway[i][step] += total[j];
				totalway[i][step] %= modulo;
			}
        }		
  	}	
	
	long long C[m+1][m+1];
	for (int i=0; i<=m; i++){
		C[i][0] = 1;
		for (int j=1; j<=i; j++)
			C[i][j] = (C[i-1][j]+C[i-1][j-1])%modulo;
		for (int j=i+1; j<=m; j++)
			C[i][j] = 0;
	}
		
	long long result[n][m+1];	
	for (int i=0; i<n; i++)
		for (int step=0; step<=m; step++){
			if (i==0){
				result[i][step] = totalway[i][step];
				continue;
			}
			result[i][step] = 0;
			for (int k=0; k<=step; k++){
				long long tmp = (result[i-1][k]*totalway[i][step-k])%modulo;
				tmp = tmp*C[step][step-k]%modulo;
				result[i][step] += tmp;
				result[i][step] %= modulo;
			}
			
		}
	std::cout<<result[n-1][m]<<std::endl;

}
int main(){
	int T;
	std::cin>>T;
	while (T>0){
		solve();
		T--;
	}
	return 0;
}

