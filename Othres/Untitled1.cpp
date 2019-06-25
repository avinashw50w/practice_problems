#include<bits/stdc++.h>
using namespace std;
int A,B,C;
int min(int a,int b) {
   return ((a < b) ? a : b);
}

/* convert str1 to str2 with minimum edits(insert,delete,replace)
   suppose length(str1) = m and length(str2) = n
   cost(i,j) -> cost of converting str1[0...i-1] to str2[0...j-1]
   cost(m,n) -> cost of converting str1 to str2 
   Standard recursive formula for computing cost(m,n) :-
   cost(i,j) = min[cost(i-1,j)+D, cost(i,j-1)+I, cost(i-1,j-1)+R]
   D -> delete cost, I -> insert cost, R -> replace cost  */

int EditDistanceDP(char str1[],char str2[],int size1,int size2) {
   // cost matrix
   // row -> str1 & col -> str2
   int cost[size1][size2];
   int i,j;
   // initialize the cost matrix
   for (i=0;i<size1;i++) {
      for(j=0;j<size2;j++) {
         if (i == 0) {
            // source string is NULL
            // so we need 'j' insert operations
            cost[i][j] = j*B;
         } else if (j == 0) {
            // target string is NULL
            // so we need 'i' delete operations
            cost[i][j] = i*A;
         } else {
            cost[i][j] = -1;
         }
      }
   } //initialization done

   //compute cost(i,j) and eventually return cost(m,n)
   for(i=1;i<size1;i++) {
      for(j=1;j<size2;j++) {
         int x = cost[i-1][j] + A;
         int y = cost[i][j-1] + B;
         // if str1(i-1) != str2(j-1), add the replace cost
         // we are comparing str1[i-1] and str2[j-1] since
         // the array index starts from 0
         int z = cost[i-1][j-1] + (str1[i-1] != str2[j-1])*C;
         // as per our recursive formula
         cost[i][j] = min(x, min(y,z));
      }
   }

   // last cell of the matrix holds the answer
   return cost[size1-1][size2-1];
}
int main(){
	int t;
	cin>>t;
	while(t--){
		//int A,B,C;
		char X[20004],U[20004];
		scanf("%s",X);
		scanf("%s",U);
		scanf("%d%d%d",&A,&B,&C);
		int cost = EditDistanceDP(X,U,strlen(X)+1,strlen(U)+1);
		printf("%d\n",cost);
	}
	return 0;
}
