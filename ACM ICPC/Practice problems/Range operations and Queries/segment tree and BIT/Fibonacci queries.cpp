/*Chef's love for Fibonacci numbers helps him to design following interesting problem.

He defines a function F for an array S as follows:

F = (summation of(fibonacci(Si)) ) % 1000000007

where

Si denotes a non-empty subset of multiset S.
sum(Si) denotes the sum of all element of multiset Si.
Fibonacci(x) denotes the xth Fibonacci number.
Given an array A consisting of N elements. Chef asked you to process following two types of queries on this array accurately and efficiently.

C X Y: Change the value of Xth element of array to Y i.e AX = Y.
Q L R: Compute function F over the subarray defined by the elements of array A in the range L to R, both inclusive.
Please see the Note section if you need details regarding Fibonacci function.

Input

First line of input contains 2 space separated integer N and M denoting the size of array A and the number of queries to be performed. Next line of input contains N space separated integers denoting the elements of array A. Each of next M lines of input contains a query having one of the mentioned two types.

Output

For each query of type Q, output the value of function F for the given range of array A.

Constraints

1 ≤ N, M ≤ 105
1 ≤ Ai, Y ≤ 109
1 ≤ L, R, X ≤ N
type = {'C', 'Q'}

Alternate approach :
Build a segment tree where we store a 2x2 transition matrix in each node . ( Transition matrix is [1,1],[1,0] and fib(n) = T^n ) . 
Let matrix for parent and its two child nodes be X,A,B respectively . We can easily see that X = A+B+A*B . 
To get the final answer just multiply the matrix by the base case matrix ([0,1]) .*/
 
bool check(int v) {
    if (v < 2) return false;
    for (int i = 2; i * i <= v; ++i) {
        if (v % i == 0) {
            return false;
        }
    }
    return true;
}
 
long long pw(long long a, long long n, long long m) {
    ll res = 1;
    while (n) {
        if (n & 1ll) {
            res = res * a % m;
        }
        a = a * a % m;
        n >>= 1;
    }
    return res;
}
 
long long inv(long long a, long long p) {
    long long res = 1;
    while (a > 1) {
        res = res * (p - p / a) % p;
        a = p % a;
    }
    return res;
}
 
long long mod = 1000000007;
 
struct Matrix {
    Matrix() { a = b = 0; }
    Matrix(ll a, ll b) : a(a % mod), b(b % mod) {}
    long long a;
    long long b;
 
    Matrix operator+(const Matrix &r) const {
        return Matrix(a + r.a, b + r.b);
    }
 
    Matrix operator*(const Matrix &r) const {
        return Matrix(a * r.a + b * r.b, a * r.b + b * r.a + b * r.b);
    }
};
 
Matrix E, X;
 
Matrix powers[32];
 
Matrix fib(int n) {
    Matrix res = E;
    for (int i = 0; i < 30; ++i) {
        if (n & (1 << i)) {
            res = res * powers[i];
        }
    }
    return res + E;
}
 
void solve(int test) {
    int n = nxt();
    int q = nxt();
    Matrix st[n + n];
 
    for (int i = 0; i < n; ++i) {
        st[i + n] = fib(nxt());
    }
 
    for (int i = n - 1; i > 0; --i) {
        st[i] = st[i + i] * st[i + i + 1];
    }
 
    while (q--) {
        char c = getchar();
        if (c == 'C') {
            int id = nxt() - 1;
            int value = nxt();
 
            id += n;
 
            st[id] = fib(value);
 
            for (id >>= 1; id; id >>= 1) {
                st[id] = st[id + id] * st[id + id + 1];
            }
        } else {
            int l = nxt() - 1;
            int r = nxt() - 1;
 
            Matrix res = E;
 
            for (l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
                if (l & 1) {
                    res = res * st[l];
                }
                if (!(r & 1)) {
                    res = res * st[r];
                }
            }
 
            cout << res.b << "\n";
        }
    }
}
 
void pre() {
    E = Matrix(1, 0);
    X = Matrix(0, 1);
    powers[0] = X;
    for (int i = 1; i < 32; ++i) {
        powers[i] = powers[i - 1] * powers[i - 1];
    }
}
 
int main(int argc, char ** argv) {
 
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    #define fname "sequence"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif
    pre();
    int t = 1;
 
#ifdef LOCAL
#else
#endif
    int c = 0;
    while (t--) {
        solve(++c);
    }
 
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
} 

////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100005;
const int Q = 1e9 + 7;
 
pair<int , int> operator + (const pair<int , int> &A , const pair<int , int> &B) {
    int a = (LL)(A.first + A.second) * (B.first + B.second) % Q;
    int b = (LL)A.first * B.first % Q;
    int c = (LL)A.second * B.second % Q;
    return make_pair((b + c) % Q , (a + Q - b) % Q);
}
pair<int , int> operator * (const pair<int , int> &A , const pair<int , int> &B) {
    pair<int , int> C;
    C.first = ((LL)A.first * B.second + (LL)(A.second + Q - A.first) * B.first) % Q;
    C.second = ((LL)A.second * B.second + (LL)A.first * B.first) % Q;
    return C;
}
pair<int , int> t[N << 1];
inline int id(int l , int r) {
    return l + r | l != r;
}
#define MID int mid = l + r >> 1
#define Left l , mid
#define Right mid + 1 , r
 
void update(int l , int r , int x , pair<int , int> w) {
    if (l == r) {
        t[id(l , r)] = w;
    } else {
        MID;
        if (x <= mid)
            update(Left , x , w);
        else
            update(Right , x , w);
        t[id(l , r)] = t[id(Left)] * t[id(Right)];
    }
}
pair<int , int> get(int l , int r , int top, int bot) {
    if (top <= l && r <= bot) {
        return t[id(l , r)];
    } else {
        MID;
        if (bot <= mid)
            return get(Left , top , bot);
        else if (top > mid)
            return get(Right , top , bot);
        else {
            return get(Left , top , bot) * get(Right , top , bot);
        }
    }
}
pair<int , int> pw[30];
int n , m , a[N];
 
int main() {
 
    pw[0] = make_pair(0 , 1);
    for (int i = 1 ; i < 30 ; ++ i) {
        pw[i] = pw[i - 1] + pw[i - 1];
    }
    scanf("%d%d" , &n , &m);
    for (int i = 1 ; i <= n ; ++ i) {
        int x;
        scanf("%d" , &x);
        ++ x; pair<int , int> w(1 , 0);
        for (int j = 29 ; j >= 0 ; -- j) {
            if (x >> j & 1)
                w = w + pw[j];
        } ++ w.second;
        update(1 , n , i , w);
    }
    char str[10];
    for (int i = 1 ; i <= m ; ++ i) {
        int l , r;
        scanf("%s%d%d" , str , &l , &r);
        if (*str == 'Q') {
            printf("%d\n" , get(1 , n , l , r).first);
        } else {
            ++ r; pair<int , int> w(1 , 0);
            for (int j = 29 ; j >= 0 ; -- j) {
                if (r >> j & 1)
                    w = w + pw[j];
            } ++ w.second;
            update(1 , n , l , w);
        }
    }
    return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////

// solution using golden ratio and matrix exponentiation //
/*
Saurabh Joshi
PDPM IIITDM Jabalpur
*/
/*
To solve this i need to exponentiate the (root(5)+1)^n and (1-root(5))^n
The answer to each exponentiation is of form a + b*root(5)
This code is basically the worst imple
*/
#include <bits/stdc++.h>
using namespace std;

#define M 1000000007
#define LL long long int
#define inv 500000004

struct irrational
    {
        LL a;//rational part
        LL b;//irrational part
    } s,t,term1[100001],term2[100001],tree1[400001],one,x,y;

//multiply two irrational numbers eg. (1+sqrt(2)).(2+sqrt(3))
irrational multiply(irrational a,irrational b)
    { 
        irrational c;
        LL x1 = (a.a * b.a) % M;
        LL y1 = (a.b * b.b) % M;
       
        c.a = x1 + (5*y1);
        if(c.a>=M)
            c.a%=M;
        if(c.a<0)
            c.a = c.a+M;
        x1 = (a.a * b.b) % M;
        y1 = (a.b * b.a) % M;
        if(x1>=M)
            x1%=M;
        if(y1>=M)
            y1%=M;
        
        c.b = x1 + y1;
        if(c.b>=M)
            c.b%=M;
        if(c.b<0)
            c.b = c.b+M;
        return c;
    }
 //raise a long long integer a to power b modulo m
 LL pow(LL a, LL b,LL m) {
     LL x = 1
    while(b > 0){
        if(b&1)
            x=(x*a)%m;
        
        x = (x*x)%m;
        b >>= 1;
    }
    return x%m;
}
    
 
 irrational power(irrational a,LL b)//raise an irrational number to power b with mod
    {
        irrational x,y;
        x.a = 1;
        x.b = 0;
        y.a = x.a;
        y.b = x.b;
        while(b > 0) {
            if(b%2 == 1)
                x=multiply(x,y);
            
            y = multiply(y,y);
            b /= 2;
        }
        return x;
    }
    
LL a[100001];
/*Segment tree part begins from here for point update and range query*/ 
 
void build(LL node,LL i,LL j)
    {
        if(i>j)
            return;
        if(i==j)
            {
                tree1[node] = term1[i];
                return;
            }
        LL mid = (i+j)/2;
        build(2*node,i,mid);
        build(2*node+1,mid+1,j);
        tree1[node] = multiply(tree1[2*node],tree1[2*node+1]);
    }
    
irrational query(LL node,LL a,LL b,LL i,LL j,int id)
    {
        if(a>b||b<i||a>j)
            return one;
        if(a>=i&&b<=j)
            {
                    return tree1[node];
            }
        int mid = (a+b)/2;
        irrational x = query(2*node,a,mid,i,j,id);
        irrational y = query(2*node+1,mid+1,b,i,j,id);
        return multiply(x,y); 
    }
 
void update(LL node,LL a,LL b,LL i,LL val)
    {
        if(a>i||b<i||a>b)
            return;
        if(a==b)
            {
                tree1[node] = power(x,val);
                LL extra = pow(inv,val,M);
                tree1[node].a = 1 + tree1[node].a*extra;
                tree1[node].b = tree1[node].b*extra;
                if(tree1[node].a>=M)
                    tree1[node].a%=M;
                if(tree1[node].b>=M)
                    tree1[node].b%=M;
                return;
            }
        int mid = (a+b)/2;
        update(2*node,a,mid,i,val);
        update(2*node+1,mid+1,b,i,val);
        tree1[node] = multiply(tree1[2*node],tree1[2*node+1]);
    }
    
int main()
    {
        //ios_base::sync_with_stdio(0);
        LL ans,extra;
        one.a = 1;
        one.b = 0;
        //power_of_two[0] = 1;
        irrational ans1,ans2,term;
        x.a = 1;
        x.b = 1;
        y.a = 1;
        y.b = M-1;
        LL i,n,m,l,r,id;
        char type;
        scanf("%lld%lld",&n,&m);
        for(i=1;i<=n;++i)
            {
                scanf("%lld",&a[i]);
                term1[i] = power(x,a[i]);
                extra = pow(inv,a[i],M);
                term1[i].a = (1 + term1[i].a*extra)%M;
                term1[i].b = (term1[i].b*extra)%M;
            }
        build(1,1,n);
        s.a = 1;
        s.b = 0;
        t.a = 1;
        t.b = 0;
        while(m--)
            {
                //id = 1 for tree1 and 2 for tree2
                //8fflush(stdin);
                cin>>type;
                scanf("%lld%lld",&l,&r);
                //printf("%c %d %d",type,l,r);
                
                if(type=='Q')
                    {
                        ans1 = query(1,1,n,l,r,1);
                        //cout<<endl<<ans1.b<<endl;
                        ans = (2*ans1.b)%M;
                        
                        printf("%lld\n",ans);
                    }
                else
                    {
                        update(1,1,n,l,r);
                    }
            }
            
    } 

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <map>
 
using namespace::std;
 
uint64_t mod = 1000000007;
 
struct info
{
    info()
    {
        mat[0][0] = mat[1][1] = 1;
        mat[0][1] = mat[1][0] = 0;
    }
 
    uint64_t mat[2][2]; 
};
 
void mat_mult(info &a, info &b, info &c)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            c.mat[i][j] = 0;
            for (int k = 0; k < 2; k++)
                c.mat[i][j] += a.mat[i][k] * b.mat[k][j];
 
            c.mat[i][j] %= mod;
        }
    }
}
 
void power(int n, info &a)
{
    if (n == 0)
    {
        a.mat[0][0] = a.mat[1][1] = 1;
        a.mat[0][1] = a.mat[1][0] = 0;
        return;
    }
 
    info t;
    power(n/2, t);
 
    mat_mult(t, t, a);
    if (n & 1)
    {
        info tmp;
        tmp.mat[0][0] = tmp.mat[0][1] = tmp.mat[1][0] = 1;
        tmp.mat[1][1] = 0;
 
        info b;
        mat_mult(a, tmp, b);
 
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                a.mat[i][j] = b.mat[i][j];
    }
}
 
void get(int n, info &a)
{
    power(n, a);
 
    a.mat[0][0]++;
    if (a.mat[0][0] >= mod)
        a.mat[0][0] -= mod;
 
    a.mat[1][1]++;
    if (a.mat[1][1] >= mod)
        a.mat[1][1] -= mod;
}
 
class SegT
{
public:
    int up(int n)
    {
        int m = 1;
        n--;
 
        while (n)
        {
            n >>= 1;
            m <<= 1;
        }
 
        return m;
    }
 
    SegT(vector<int> &v)
    {
        // get the size of the segment tree which is about 2^(no of elements in the array)
        sz = up(v.size()); 
        
        P = new info[2 * sz];
        for (int i = 0; i < sz; i++)
            if (i < v.size())       
                get(v[i], P[sz + i]);               
 
        for (int i = sz - 1; i > 0; i--)
            mat_mult(P[2 * i], P[2 * i + 1], P[i]);
    }
 
    void update(int idx, int val)
    {
        idx += sz;
        get(val, P[idx]);
 
        idx >>= 1;
        while (idx)
        {
            mat_mult(P[2 * idx], P[2 * idx + 1], P[idx]);
            idx >>= 1;
        }
    }
 
    void range_val(int idx, int beg, int end, int s, int e, info &res)
    {
        if (s > end || e < beg)
            return;
 
        if (beg >= s && end <= e)
        {
            info tmp;
            mat_mult(res, P[idx], tmp);
 
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 2; j++)
                    res.mat[i][j] = tmp.mat[i][j];
 
            return;
        }
 
        int mid = (beg + end)/2;
        range_val(2 * idx, beg, mid, s, e, res);
        range_val(2 * idx + 1, mid + 1, end, s, e, res);
    }
 
    uint64_t range_val(int s, int e)
    {
        info res;
        range_val(1, 0, sz - 1, s, e, res);
        return res.mat[0][1];
    }
 
private:
    info ID;
    
    int sz;
    info *P;
};
 
int main()
{
    int N, M;
    scanf("%d", &N);
    scanf("%d", &M);
 
    vector<int> v(N, 0);
    for (int i = 0; i < N; i++)
    {
        int x;
        scanf("%d", &x);
 
        v[i] = x;
    }
 
    SegT segT(v);
 
    for (int i = 0; i < M; i++)
    {
        char ch;
        while (true)
        {
            scanf("%c", &ch);
            if (ch == 'C' || ch == 'Q')
                break;
        }
 
        if (ch == 'C')
        {
            int x, y;
            scanf("%d", &x);
            scanf("%d", &y);
 
            segT.update(x - 1, y);
        }
        else
        {
            int L, R;
            scanf("%d", &L);
            scanf("%d", &R);
 
            printf("%d\n", (int) segT.range_val(L - 1, R - 1));
        }
    }
 
    return 0;
}