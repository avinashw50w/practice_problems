/* The chef has just finished baking several pies, and it's time to place them on cooling racks. The chef has exactly as many cooling racks as pies. 
Each cooling rack can only hold one pie, and each pie may only be held by one cooling rack, but the chef isn't confident that the cooling racks can support 
the weight of the pies. The chef knows the weight of each pie, and has assigned each cooling rack a maximum weight limit. What is the maximum number of pies the 
chef can cool on the racks?
Input:

Input begins with an integer T=30, the number of test cases. Each test case consists of 3 lines. The first line of each test case contains a positive integer N=30, 
the number of pies (and also the number of racks). The second and third lines each contain exactly positive N integers not exceeding 100. The integers on the 
second line are the weights of the pies, and the integers on the third line are the weight limits of the cooling racks.
Output:

For each test case, output on a line the maximum number of pies the chef can place on the racks.*/

#include <iostream>
#include <algorithm>
#define ll long long int
#define gc getchar_unlocked()
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;
inline ll input(){
	int n = 0;
	register int c = gc;
	while(c==' '||c=='\n') c=gc;
	while(c>='0' && c<='9') {
		n = (n<<3)+(n<<1)+c-48;
		c=gc;
	}
	return n;
}

int main()
{
	
	int t,n;
	t = input();
	while(t--){
		n=input();
		int pie[101]={},rack[101]={},done[101]={};
		REP(i,n) pie[i]=input();
		REP(i,n) rack[i]=input();
		sort(pie,pie+n);
		sort(rack,rack+n);
		int count =0;
		REP(i,n)
		REP(j,n)
		{
			if(!done[j])
			if(rack[j]>=pie[i])
			{
				done[j]=1;
				count++;
				break;
			}
		}
		cout<<count<<"\n";
	}
	return 0;
} 
