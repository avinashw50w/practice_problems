//Coder: Balajiganapathi
#ifndef ONLINE_JUDGE
#   define DEBUG
//#   define TRACE
#else
//#   define NDEBUG
#endif

#include <algorithm>
#include <bitset>
#include <deque>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<string> vs;
typedef vector<pi> vpi;

// Basic macros
#define fi          first
#define se          second
#define all(x)      (x).begin(), (x).end()
#define ini(a, v)   memset(a, v, sizeof(a))
#define re(i,s,n)  	for(int i=s;i<(n);++i)
#define rep(i,s,n)  for(int i=s;i<=(n);++i)
#define fo(i,n)     re(i,0,n)
#define rev(i,n,s)  for(int i=(n)-1;i>=s;--i)
#define repv(i,n,s) for(int i=(n);i>=s;--i)
#define fov(i,n)    rev(i,n,0)
#define pu          push_back
#define mp          make_pair
#define si(x)       (int)(x.size())

#ifdef TRACE
    #define trace(x)            cerr<<x<<endl;
    #define trace1(x)           cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<endl;
    #define trace2(x,y)         cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<endl;
    #define trace3(x,y,z)       cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<" | "#z" = "<<z<<endl;
    #define trace4(a,b,c,d)     cerr<<__FUNCTION__<<":"<<__LINE__<<": "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<endl;
    #define trace5(a,b,c,d,e)   cerr<<__FUNCTION__<<":"<<__LINE__<<": "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<" | "#e" = "<<e<<endl;
    #define trace6(a,b,c,d,e,f) cerr<<__FUNCTION__<<":"<<__LINE__<<": "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<" | "#e" = "<<e<<" | "#f" = "<<f<<endl;
#else
    #define trace(x)
    #define trace1(x)
    #define trace2(x,y)
    #define trace3(x,y,z)
    #define trace4(a,b,c,d)
    #define trace5(a,b,c,d,e)
    #define trace6(a,b,c,d,e,f)
#endif

const int oo = 1000000009;
const double eps = 1e-6;

const int mod = 1000000007;
const int mx = 12;

int cnt;
char b[mx][mx];

int di[] = {0, 0, 1, -1, -1, 1, -1, 1};
int dj[] = {1, -1, 0, 0, 1, -1, -1, 1};

bool check(int i, int j) {
    if(i >= 0 && i < 8 && j >= 0 && j < 8 && b[i][j] != '.') {
        ++cnt;
        return true;
    }

    return false;
}

void doking(int i, int j) {
    fo(d, 8) check(i + di[d], j + dj[d]);
}

void dopawn(int i, int j) {
    check(i - 1, j - 1);
    check(i + 1, j - 1);
}

void doknight(int i, int j) {
    static int di[] = {2, -2, 2, -2, 1, -1, 1, -1};
    static int dj[] = {1, -1, -1, 1, 2, -2, -2, 2};
    fo(d, 8) check(i + di[d], j + dj[d]);
}

void dorook(int i, int j) {
    fo(d, 4) {
        rep(k, 1, 8) if(check(i + di[d] * k, j + dj[d] * k)) break;
    }
}

void dobishop(int i, int j) {
    re(d, 4, 8) {
        rep(k, 1, 8) if(check(i + di[d] * k, j + dj[d] * k)) break;
    }
}

int main() {
    int kases;
    cin >> kases;
    rep(kase, 1, kases) {
        printf("Case #%d: ", kase);
        fo(i, 8) fo(j, 8) b[i][j] = '.';
        int n;
        string s;
        cin >> n;
        while(n--) {
            cin >> s;
            int i = 7 - (s[1] - '1'), j = 7 - (s[0] - 'A');
            b[i][j] = s[si(s) - 1];
        }

        cnt = 0;
        fo(i, 8) fo(j, 8) if(b[i][j] != '.') {
            trace4(i, j, b[i][j], cnt);
            switch(b[i][j]) {
                case 'K':
                    doking(i, j);
                    break;
                case 'P':
                    dopawn(i, j);
                    break;
                case 'N':
                    doknight(i, j);
                    break;
                case 'Q':
                    dorook(i, j);
                    dobishop(i, j);
                    break;
                case 'B':
                    dobishop(i, j);
                    break;
                case 'R':
                    dorook(i, j);
                    break;
                default:
                    assert(0);
            }
            trace4(i, j, b[i][j], cnt);
        }

        printf("%d\n", cnt);
    }
    
	return 0;
}
