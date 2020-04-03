/*You have a string of N decimal digits,  denoted by numbers A1, A2,  ...,  AN.

Now you are given M queries,  each of whom is of following two types.


Type 1: 1 X Y: Replace AX by Y.
Type 2: 2 C D: Print the number of sub-strings divisible by 3 of the string denoted by AC, AC+1 ...
AD.


Formally,  you have to print the number of pairs (i,j) such that the string Ai,Ai+1...Aj,
(C ≤ i ≤ j ≤ D), when considered as a decimal number, is divisible by 3. 
Input
There is only one test case.
First line of input contains two space separated integers N, M.
Next line contains a string of N digits, denoting string A.
For next M lines, each line contains a query.
Each query is given by three space separated integers.
The first integer denotes type of the query. For each query of type 1, next two integers denote Xi, Yi.
For each query of type 2, next two integers denote Ci, Di.
Output
For each query of type 2, print the required answer in a single line.

Constraints
0 ≤ Ai ≤ 9
1 ≤ Xi ≤ N
0 ≤ Yi ≤ 9
1 ≤ Ci ≤ Di ≤ N
Subtasks
Subtask #1 (10 points): 1 ≤ N, M ≤ 103 and only type 2 queries.
Subtask #2 (15 points): 1 ≤ N, M ≤ 103
Subtask #3 (20 points): 1 ≤ N, M ≤ 105 and only type 2 queries
Subtask #4 (55 points): 1 ≤ N, M ≤ 105
Example
Input:
5 3
01245
2 1 3
1 4 5
2 3 5

Output:
3
1*/

#include<bits/stdc++.h>
using namespace std;
#define assn(n,a,b) assert(n<=b and n>=a)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sd(n) scanf("%d",&n)
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
#define MAXN 100000
#define MAXM 100000

struct segtree
{
    int left[3];
    int right[3];
    LL cnt;
    int total;
    segtree(){
        memset(left,0,sizeof(left));
        memset(right,0,sizeof(right));
        cnt=0;
    }
};

segtree tree[6*MAXN];
string arr;

segtree merge(segtree a, segtree b){
    segtree ret;
    ret.cnt=a.cnt+b.cnt;
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            if((i+j)%3==0)ret.cnt+=(LL)a.right[i]*(LL)b.left[j];
    for(int i=0; i<3; i++){
        ret.left[i]=a.left[i]+b.left[(i-a.total + 6)%3];
        ret.right[i]=b.right[i]+a.right[(i-b.total + 6)%3];
    }
    ret.total=(a.total+b.total)%3;
    return ret;
}

void assign(int node, int p){
    tree[node]=segtree();
    tree[node].left[p]=1;
    tree[node].right[p]=1;
    tree[node].total=p;
    if(p==0)tree[node].cnt=1;
}

void build_tree(int node, int a, int b)
{
    if(a > b) return;
    if(a == b){
        assign(node,(arr[a]-'0')%3);
        return;
    }
    int mid=(a+b)/2;
    build_tree(node*2, a, mid);
    build_tree(node*2+1, 1+mid, b);
    tree[node] = merge(tree[node*2],tree[node*2+1]);
}

segtree query_tree(int node, int a, int b, int i, int j){
    if(a > b || a > j || b < i){
        segtree ret;
        return ret;
    }
    if(a >= i && b <= j)
        return tree[node];
    segtree q1 = query_tree(node*2, a, mid, i, j);
    segtree q2 = query_tree(1+node*2, 1+mid, b, i, j);
    return merge(q1,q2);
}

void update_tree(int node, int a, int b, int i, int value){
    if(a > b || a > i || b < i)
        return;
    if(a == b){
        assign(node,value%3);
        return;
    }
    update_tree(node*2, a, (a+b)/2, i,  value);
    update_tree(1+node*2, 1+(a+b)/2, b, i, value);
    tree[node] = merge(tree[node*2], tree[node*2+1]);
}
 
int main()
{
    int m,n;
    sd(n),sd(m);
    cin >> arr;

    build_tree(1,0,n-1);

    while(m--){
        int fl,l,r;
        sd(fl),sd(l),sd(r);

        if(fl==2)
            printf("%lld\n",query_tree(1,0,n-1,l-1,r-1).cnt);
        else 
            update_tree(1,0,n-1,l-1,r);
    }
    return 0;
}
 
 /////////////////////////////////////////////////////////

/*ALTERNATIVE SOLUTION:
Suppose we keep in segment tree for each node, how many prefix sums in this interval are divisible by 0,1,2. 
For a query [L,R], we just have to count number of prefix sums in interval [L,R] divisible by 0,1,2(let's call them s1,s2,s3). 
Our answer will be choose(s1,2)+choose(s2,2)+choose(s3,2). Why? Because, suppose prefix_sum[i] % 3 = prefix_sum[j] % 3, 
then sum of substring [i+1, j] is divisible by 3.

For update query(mark A[x] = y), since we are keeping prefix sum modulo 3, for range [x, N], 
we increase/decrease each prefix sum by k(k<3). We can do this using lazy propagation.*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[100001];
struct node
{
    int sum, mod[3];
};
struct node tree[262144];

void init_node(struct node &x)
{
    x.sum=0;
    x.mod[0]=x.mod[1]=x.mod[2]=0;
}

void func(struct node &res, struct node &left, struct node &right)
{   
	init_node(res);
    res.sum=(left.sum+right.sum)%3;
    for(int i=0;i<3;i++)
    {
        res.mod[i]+=left.mod[i];
        res.mod[(i+left.sum)%3]+=right.mod[i];
    }
}

void build(int v, int l, int r)
{
    if(l==r)
    {   init_node(tree[v]);
        tree[v].sum=(s[l]-'0')%3;
        tree[v].mod[tree[v].sum]=1;
    }
    else
    {
        int m=(l+r)>>1;
        build(v<<1, l, m);
        build((v<<1)+1, m+1, r);
        func(tree[v], tree[v<<1], tree[(v<<1)+1]);//result, left, right
    }
}

void update(int v, int l, int r, int pos, int new_val)//pos, new val
{
    if(l == r)
    {   init_node(tree[v]);
        tree[v].sum = (new_val) % 3;
        tree[v].mod[tree[v].sum] = 1;
    }
    else
    {
        int m = (l+r)>>1;
        if(pos <= m)
            update(v<<1, l, m, pos, new_val);
        else
            update((v<<1)+1, m+1, r, pos, new_val);
        func(tree[v], tree[v<<1], tree[(v<<1)+1]);
    }
}
struct node query(int v, int tl, int tr, int l, int r)
{   struct node res={0, {0, 0, 0}};
    if(l>r)
        return res;
    if(l==tl && r==tr)
        return tree[v];
    int tm=(tl+tr)>>1;
    struct node left=query(v<<1, tl, tm, l, std::min(r, tm));
    struct node right=query((v<<1)+1, tm+1, tr, std::max(tm+1, l), r);
    func(res, left, right);
    return res;
}
int main()
{   int n, m, i, j, k, type;
    scanf("%d%d", &n, &m);
    scanf("%s", s);
    build(1, 0, n-1);
    while(m--)
    {
        scanf("%d%d%d", &type, &j, &k);
        if(type==1)
        {
            update(1, 0, n-1, j-1, k);
        }
        else
        {   struct node res=query(1, 0, n-1, j-1, k-1);
            ll ans=0;
            ++res.mod[0];
            //cout<<res.mod[0]<<" "<<res.mod[1]<<" "<<res.mod[2]<<endl;
            for(i=0;i<3;++i)
                ans+=(res.mod[i]*1LL*(res.mod[i]-1))>>1;
            printf("%lld\n", ans);
        }
    }
    return 0;
}