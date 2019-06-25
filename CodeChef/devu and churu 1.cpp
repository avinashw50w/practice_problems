/*Devu and Churu love to play games a lot. Today, they have an array A consisting of N positive integers. First they listed all N × (N+1) / 2 non-empty 
continuous subarrays of the array A on a piece of paper and then replaced all the subarrays on the paper with the maximum element present in the respective
 subarray.
Devu and Churu decided to play a game with numbers on the paper. They both have decided to make moves turn by turn. In one turn, the player picks some number
 from the list and discards that number. The one who is not able to make a valid move will be the loser. To make the game more interesting, they decided 
 to put some constraints on their moves.
A constraint on a game can be any of following three types :
> K : They are allowed to choose numbers having values strictly greater than K only.
< K : They are allowed to choose numbers having values strictly less than K only.
= K : They are allowed to choose numbers having values equal to K only.
Given M constraints and who goes first, you have to tell the outcome of each game. Print 'D' if Devu wins otherwise print 'C' without quotes.
Note that M games are independent, that is, they'll rewrite numbers by using array A after each game. (This is the task for the loser of the previous game!)
Input
First line of input contains two space separated integers N and M denoting the size of array A and number of game played by them. Next line of input 
contains N space-separated integers denoting elements of array A. Each of the next M lines of input contains three space-separated parameters describing a game.
 First two parameter are a character C ? {<, >, =} and an integer K denoting the constraint for that game. The last parameter is a character X ? {D, C} denoting 
 the player who will start the game.

Output
Output consists of a single line containing a string of length M made up from characters D and C only, where ith character in the string denotes the outcome 
of the ith game.
*/
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define N 2200000
inline char scanc(){
	char c = getchar_unlocked();
	while(c < '<' || c > 'D'){
		c = getchar_unlocked();
	}
	return c;
}
inline int scan(){
	int x = 0;
	char c = getchar_unlocked();
	while(c < '0' || c > '9'){
		c = getchar_unlocked();
	}
	while(c >= '0' && c <= '9'){
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar_unlocked();
	}
	return x;
}
int fw[N], bk[N];
int a[N];
int n,q;
vector<pair<pair<char,int>,char> > v;
vector<pair<int,pair<int,int> > >lol;
stack<pair<int,int> > st;
void comp();
void fwd();
void bkwd();
int temp[N];
int cnt[N];
int main(){
//	scanf("%d %d",&n,&q);
    n=scan(); q=scan();
    comp();
	fwd();
    bkwd();
    int val=0;
    for(int i=1; i<=n; i++){
        int ff=fw[i];
        int bb=bk[i];
        val=(bb-i+1)*(i-ff+1);
        cnt[a[i]]+=val;        
    }
    //for(int i=1; i<=n; i++) cout<<cnt[a[i]]<<" ";
    for(int i=1; i<N; i++) cnt[i]+=cnt[i-1];
    int sz=v.size(), cc=0,x;
    for(int i=0; i<sz; i++){
        x=v[i].first.second;
        char y=v[i].second;
        if(v[i].first.first=='>'){
            cc=cnt[N-1]-cnt[x];
        }
        else if(v[i].first.first=='<'){
            cc=cnt[x-1];
        }
        else cc=cnt[x]-cnt[x-1];
       // cout<<cc<<endl;
        
        if(cc%2){
            printf("%c",y);
        }
        else{
            if(y=='C') printf("D");
            else printf("C");
        }
        //cout<<y; */
    }
}
void fwd(){
    while(!st.empty()) st.pop();
    for(int i=1; i<=n; i++){
        while(!st.empty()){
            if(st.top().first<=a[i]){
                st.pop();    
            }     
            else break;
        }
        if(!st.empty()) fw[i]=st.top().second+1;
        else fw[i]=1; 
        st.push(mp(a[i],i)); 
        
    } 
}
void bkwd(){
    while(!st.empty()) st.pop();
    for(int i=n; i>0; i--){
        while(!st.empty()){
            if(st.top().first<a[i]) st.pop();  
            else break;
        }
        if(!st.empty()) bk[i]=st.top().second-1;
        else bk[i]=n; 
        st.push(mp(a[i],i)); 
        
    } 
    
}
void comp(){
    for(int i=1; i<=n; i++){
		a[i]=scan();
        lol.push_back(mp(a[i],mp(0,i)));	
	} 
	for(int i=0; i<q; i++){
		char x=scanc();
        int z;
        z=scan();
        char y=scanc();
		v.push_back(mp(mp(x,z),y));
		lol.push_back(mp(z,mp(1,i)));
	}
	sort(lol.begin(),lol.end());
	int f=1;
	int sz=lol.size();
	for(int i=0; i<sz; i++){
        if(lol[i].second.first==0){
            if(i==0) a[lol[i].second.second]=f;
            else if(lol[i].first!=lol[i-1].first) a[lol[i].second.second]=++f;
            else a[lol[i].second.second]=f;
        }
        else{
            if(i==0) v[lol[i].second.second].first.second=f;
            else if(lol[i].first!=lol[i-1].first) v[lol[i].second.second].first.second=++f;
            else v[lol[i].second.second].first.second=f;
        }
    }
   // for(int i=0; i<q; i++) cout<<v[i].first.second<<" ";
   // cout<<endl<<endl;
}
