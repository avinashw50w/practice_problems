#include<bits/stdc++.h>
using namespace std;
inline int min(int a, int b) {
   return a < b ? a : b;
}
int Minimum(int a, int b, int c)
{
    return min(min(a, b), c);
}
//int A,B,C;
int EditDistanceRecursion( char *X, char *Y, int m, int n ,int A,int B,int C)
{
	int W=(A+B>=C)?C:A+B;
    // Base cases
    if( m == 0 && n == 0 )
        return 0;
 
    if( m == 0 )
        return n*B;
 
    if( n == 0 )
        return m*A;
 
    // Recurse
    int left = EditDistanceRecursion(X, Y, m-1, n,A,B,C) + A;
    int right = EditDistanceRecursion(X, Y, m, n-1,A,B,C) + B;
    int corner = EditDistanceRecursion(X, Y, m-1, n-1,A,B,C) + (X[m-1] != Y[n-1])*C;
 
    return Minimum(left, right, corner);
}
 int main(){
	int t;
	cin>>t;
	while(t--){
		int A,B,C;
		char X[20004],U[20004];
		scanf("%s",X);
		scanf("%s",U);
		scanf("%d%d%d",&A,&B,&C);
		int cost = EditDistanceRecursion(X,U,strlen(X),strlen(U),A,B,C);
		printf("%d\n",cost);
	}
	return 0;
}
