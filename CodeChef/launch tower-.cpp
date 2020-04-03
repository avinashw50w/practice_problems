/*
The secret behind this successful launch was the launch pad that ISRO used. An important part of the launch pad is the launch tower. It is the long vertical structure which supports the rocket.
ISRO now wants to build a better launch pad for their next mission. For this, ISRO has acquired a long steel bar, and the launch tower can be made by cutting a segment from the bar. As part of saving the cost, the bar they have acquired is not homogeneous.
The bar is made up of several blocks, where the ith block has durability S[i], which is a number between 0 and 9. A segment is defined as any contiguous group of one or more blocks.
If they cut out a segment of the bar from ith block to jth block (i<=j), then the durability of the resultant segment is given by ( S[i]*10(j-i) + S[i+1]*10(j-i-1) + S[i+2]*10(j-i-2) + � + S[j] * 10(0) ) % M.
In other words, if W(i,j) is the base-10 number formed by concatenating the digits S[i], S[i+1], S[i+2], �, S[j], then the durability of the segment (i,j) is W(i,j) % M.
For technical reasons that ISRO will not disclose, the durability of the segment used for building the launch tower should be exactly L. Given S and M, find the number of ways ISRO can cut out a segment from the steel bar whose durability is L.
Input

The first line contains a string S. The ith character of this string represents the durability of ith segment.
The next line contains a single integer Q, denoting the number of queries.
Each of the next Q lines contain two space separated integers, denoting M and L.
Output

For each query, output the number of ways of cutting the bar on a separate line.
Constraints

1 = |S| = 2 * 10^4
Q = 5
0 < M < 500
0 = L < M
Example

Input:
23128765
3
7 2
9 3
15 5

Output:
9
4
5
Explanation

For M=9, L=3, the substrings whose remainder is 3 when divided by 9 are: 3, 31287, 12 and 876.
*/
#include<bits/stdc++.h>
using namespace std;
 
int T[100000][500];
 
void init(int s,int m){
	for(int i=0;i<s;i++){
		for(int j=0;j<m;j++)
			T[i][j]=0;
	}
}
 
int comp(string &s,int m,int l,int len){
	int i,j,count=0,dig,temp,temp2;
	dig=s[0]-'0';
	T[0][dig%m]=1;
	for(i=1;i<len;i++){
		dig=s[i]-'0';
		T[i][dig%m]=1;
		for(j=0;j<m;j++){
			if(T[i-1][j]){
		
			temp=(j*10+dig)%m;
			temp2=T[i-1][j]+T[i][temp];
			T[i][temp]=temp2;	
	
 
			}
		}
	}
	for(i=0;i<len;i++){
		if(T[i][l]) count+=T[i][l];
	}
 
 
	return count;
}
 
int main(){
	int len,Q,m,l,ans;
	string str="";
	cin>>str;
	cin>>Q;
	len=str.size();
	while(Q--){
		scanf("%d %d",&m,&l);
		ans=comp(str,m,l,len);
		cout<<ans<<endl;		
		init(len,m);
	}
	return 0;
}  
