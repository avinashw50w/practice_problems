/*
Once upon a day, Mary bought a one-way ticket from somewhere to somewhere with some flight transfers.

For example: SFO->DFW DFW->JFK JFK->MIA MIA->ORD.

Obviously, transfer flights at a city twice or more doesn't make any sense. So Mary will not do that.

Unfortunately, after she received the tickets, she messed up the tickets and she forgot the order of the ticket.

Help Mary rearrange the tickets to make the tickets in correct order.

Input

The first line contains the number of test cases T, after which T cases follow.
For each case, it starts with an integer N. There are N flight tickets follow.
Each of the next 2 lines contains the source and destination of a flight ticket.

Output

For each test case, output one line containing "Case #x: itinerary", where x is the test case number (starting from 1) and itinerary is sorted list of flight tickets which represents the actual itinerary. Each flight segment in the itinerary should be outputted as pair of source-destination airport codes.

Limits

1 = T = 100.
For each case, the input tickets are messed up from an entire itinerary bought by Mary. In other words, it's ensured can be recovered to a valid itinerary.

Small dataset

1 = N = 100.
Large dataset

1 = N = 104.
(The segment for second case in sample can be seen as below) MIA-ORD, DFW-JFK, SFO-DFW, JFK-MIA
Sample


Input 
 	
Output 
 
2
1
SFO
DFW
4
MIA
ORD
DFW
JFK
SFO
DFW
JFK
MIA

Case #1: SFO-DFW
Case #2: SFO-DFW DFW-JFK JFK-MIA MIA-ORD
*/
#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int d[1010][1010];
int dp[1010101];
int main(){
    CASET{
        map<string,string>H1;
        set<string>H2;
        DRI(n);
        REP(i,n){
            string str1,str2;
            cin>>str1>>str2;
            H1[str1]=str2;
            H2.insert(str2);
        }
        string st;
        for(map<string,string>::iterator it=H1.begin();it!=H1.end();it++){
            if(H2.count(it->F)==0){
                st=it->F;
                break;
            }
        }
        printf("Case #%d:",case_n++);
        while(H1.count(st)){
            printf(" %s-%s",st.c_str(),H1[st].c_str());
            st=H1[st];
        }
        puts("");
    }
    return 0;
}
