/*Chefland has a very famous university. The university offers N courses. Each course runs for some consecutive range of days. You are given 
starting and ending days of the ith course by starti and endi, respectively.
Our Chef wanted to enroll himself in the university. But he is not sure about the exact time period for which he wants to study. Though he has 
Q such tentative plans in his mind. Each plan consists of a start date plan_startj and an end date plan_endj.
Chef wants your help in finding out the maximum number of courses he can complete during each of his plans. Note that at a time, Chef can not 
handle multiple courses, i.e. he can attend at most one course during a day. Also, a course will be considered completed only if Chef attends 
all the classes of the course.
Input

There is a single test case.
The first line of the input contains two space separated integers N and Q denoting the number of courses university offers and the number of 
plans Chef has in mind, respectively.
The ith of the next N lines contains two space separated integers starti and endi denoting the starting and the ending day of the ith course.
The jth of the next Q lines contains two space separated integers plan_startj and plan_endj, denoting the start and the end day of Chef's plan.
Output
Output Q lines - each containing an integer corresponding to the maximum number of the courses Chef can complete in the corresponding planned 
visit.
Constraints
1 ≤ N, Q ≤ 105
1 ≤ starti ≤ endi ≤ 106
1 ≤ plan_startj ≤ plan_endj ≤ 106
Example

Input:
3 3
1 3
5 6
2 4
1 6
1 3
2 3

Output:
2
1
0
Explanation

Plan #1. Chef stays on the campus from the first day till the sixth day. During this time, he can complete maximum two courses. He can 
complete either the 1st and the 2nd or the 2nd and the 3rd courses..
Plan #2. Chef can complete no more than one course and this course can be only the first one.
Plan #3. Chef stays for quite a small duration in this plan. He can't complete any course during this visit.*/
 
#define TRACE(x)
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto c=a; c!=b;) cout << *(c++) << " "; cout << endl)
#define WATCHC(V) TRACE(cout << #V" = "; WATCHR(V.begin(), V.end()))
 
typedef long long ll;
 
const int MAXN = 1e6 + 100;
const int MAXL = 20;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);
 
    int N, Q;
    cin >> N >> Q;
 
    vector<int> start(N + 1), finish(N + 1);
    vector<vector<int>> starting(MAXN), ending(MAXN);
    vector<vector<int>> succ(MAXL, vector<int>(N + 1, 0));
 
    start[0] = 0, finish[0] = MAXN;
    for (int i = 1; i <= N; i++) {
        cin >> start[i] >> finish[i];
 
        starting[start[i]].push_back(i);
        ending[finish[i]].push_back(i);
    }
 
    vector<int> fend(MAXN);
 
    int best = 0;
    for (int inx = MAXN - 1; inx > 0; inx--) {
        for (int i : ending[inx]) {
            succ[0][i] = best;
        }
 
        for (int i : starting[inx]) {
            if (finish[i] < finish[best])
                best = i;
        }
 
        fend[inx] = best;
    }
 
    WATCHC(succ[0]);
 
    for (int l = 1; l < MAXL; l++) {
        for (int i = 1; i <= N; i++)
            succ[l][i] = succ[l-1][succ[l-1][i]];
    }
 
    for (int q = 0; q < Q; q++) {
        int qs, qe;
        cin >> qs >> qe;
 
        int f = fend[qs];
        if (finish[f] > qe) {
            cout << 0 << "\n";
            continue;
        }
 
        int use = 1;
 
        for (int l = MAXL - 1; l >= 0; l--) {
            int w = succ[l][f];
            if (finish[w] <= qe) {
                use += 1 << l;
                f = w;
            }
        }
 
        cout << use << "\n";
    }
 
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
#define maxv 1000010
#define gc getchar_unlocked
int st[4*maxv+10], lz[4*maxv+10];
 
int jump[maxv][21];
int two[21];
void init(){
    for (int i=0; i<21; i++) two[i]= (1<<i);
}
 
void relax (int N, int L, int R){
    if (lz[N]!=0){
        st[N]= max(st[N], lz[N]);
        if (L!=R){
            lz[2*N+1]= max(lz[2*N+1], lz[N]);
            lz[2*N+2]= max(lz[2*N+2], lz[N]);
        }
        lz[N]= 0;
    }
}
 
inline int ri()
{
    char c = gc();
    while((c<'0' || c>'9') && c!='-')
        c = gc();
    int ret = 0, neg = 1;
    if(c == '-')
    {
        neg = -1;
        c = gc();
    }
    while(c>='0' && c<='9')
    {
        ret = 10 * ret + c - 48;
        c = gc();
    }
    return ret * neg;
}
 
void upd (int N, int L, int R, int S, int E, int v){
    if (L>R or L>E or S>R) return;
    relax(N, L, R);
    if (L>=S and R<=E){
        st[N]= max(st[N], v);
        if (L!=R){
            lz[2*N+1]= max(lz[2*N+1], v);
            lz[2*N+2]= max(lz[2*N+2], v); 
        }
        return;
    }
    int mid= (L+R)>>1;
    upd (2*N+1, L, mid, S, E, v);
    upd (2*N+2, mid+1, R, S, E, v);
    st[N]= max(st[2*N+1], st[2*N+2]);  
}
 
int query (int N, int L, int R, int S, int E){
    if (L>R or L>E or S>R) return 0;
    relax(N, L, R);
    if (L>=S and R<=E) return st[N];
    int mid= (L+R)>>1;
    return max(query(2*N+1, L, mid, S, E), query(2*N+2, mid+1,R, S, E));
}
 
int main() {
    // your code goes here
    init();
    int n, q, l, r;
    n= ri();
    q= ri();
    for (int i=1; i<=n; i++){
        l= ri();
        r= ri();
        upd (0, 1, maxv, 1, l, maxv+1-(r+1));
    }
    for (int i=1; i<=maxv; i++) jump[i][0]= maxv+1-query(0, 1, maxv, i, i);
    for (int j=1; j<=20; j++){
        for (int i=1; i<=maxv; i++){
            if (jump[i][j-1]==maxv+1) jump[i][j]= maxv+1;
            else jump[i][j]= jump[jump[i][j-1]][j-1];
        }
    }
    while (q--) {
        l= ri();
        r= ri();
        int ans= 0;
        for (int i=20; i>=0; i--){
            if (jump[l][i]<=r+1){
                ans+=two[i];
                l= jump[l][i];
            }
        }
        printf("%d \n", ans);
    }
    return 0;
} 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef long long int uli;
struct iv{
   int l,r;
   bool operator <(iv x)const{
      if(r!=x.r)return r<x.r;
      return l<x.l;
   }
};
const int mx=1e5+10;
const int mxl=20;
iv d[mx];
tuple<int,int,int>lri[mx];
int f[mxl][mx];
int ans[mx];
int main(){
   int n,q,l,r;
   scanf("%d %d",&n,&q);
   for(int i=0;i<n;i++)
      scanf("%d %d",&d[i].l,&d[i].r);
   for(int i=0;i<q;i++){
      scanf("%d %d",&l,&r);
      lri[i]=make_tuple(l,r,i);
   }
   sort(lri,lri+q);
   sort(d,d+n);
   d[n].l=d[n].r=2e6;
   r=0;
   for(l=0;l<n;l++){
      r=max(r,l);
      while(r<n && d[r].l<=d[l].r)r++;      
      f[0][l]=r;
   }
   f[0][n]=n;
   for(l=1;l<mxl;l++)
      for(int i=0;i<=n;i++)
         f[l][i]=f[l-1][f[l-1][i]];         
   int idx=0;
   for(int i=0;i<q;i++){
      int from,to,qi;
      tie(from,to,qi)=lri[i];
      while(idx<n && d[idx].l<from)idx++;
      if(idx==n || d[idx].r>to){
         ans[qi]=0;
         continue;
      }
      int ansi=1;
      int u=idx;
      for(int l=mxl-1;l>=0;l--){
         if(d[f[l][u]].r<=to){
            ansi+=(1<<l);
            u=f[l][u];
         }
      }
      ans[qi]=ansi;      
   }
   for(int i=0;i<q;i++)printf("%d\n",ans[i]);
   return 0;
}
 

/*There are NN courses in a university. The iith course starts on day SiSi and ends on day EiEi.

Chef plans to enroll, but he isn't sure about the exact time yet. Instead, he has QQ plans, where the iith plan starts on day PSiPSi and ends on day ESiESi.

For each plan, what is the maximum number of courses Chef can attend? Chef cannot attend more than one course at the same time.

QUICK EXPLANATION:
A single query is an instance of the famous activity selection problem, where the answer can be obtained by a famous greedy algorithm.

Now, first sort the courses by increasing EiEi, and then break ties by sorting by decreasing SiSi. After this, EiEi becomes increasing.

Then, remove courses which contain other courses. This can be done in O(N)O(N) by simply removing the iith course if Si−1≥SiSi−1≥Si. After this, SiSi and EiEi become increasing.

For each course, compute its parent course, which we define as the first course whose start time is greater than the end time of the course. If no such course exists, we set its parent to a sentinel course with start time ∞∞. The parent of the sentinel course is itself. This forms a rooted tree.

Jump pointers: For each course, compute its 2i2ith ancestor for every 2i≤N2i≤N.

Finally, to answer a query (PSi,ESi)(PSi,ESi):

Compute the first course with start time ≥PSi≥PSi using binary search (because SiSi is increasing).
Use the jump pointers to compute the lowest ancestor of the first course whose end time is ≤ESi≤ESi.
The answer is the distance of this ancestor from the first course.
EXPLANATION:
A single query is an instance of the famous activity selection problem, where the answer can be obtained by the following famous greedy algorithm:

Sort the courses by end time.
For each course in that order, take that course if it doesn't conflict with the previous course.
An explanation of why this works can be found here.

The problem is an extension of that, where we answer multiple queries. Each query only considers activities in a particular interval [PSi,ESi][PSi,ESi].

Based on the greedy algorithm, a good preprocessing step would be to sort the courses by end time beforehand. For now, we break ties arbitrarily.

Unfortunately, even after sorting, we can't simply run the greedy algorithm for every query as is, because it's too slow! Specifically, there are two parts of it that make it slow:

Finding the first activity whose start time is ≥PSi≥PSi.
Finding all activities after that, greedily, but only including activities with end time ≤ESi≤ESi.
We can probably simplify the problem by removing some unneeded courses. Consider for example courses whose start and end times are [6,22][6,22], and another one with [11,16][11,16]. These two courses overlap, so we can't take both of them. But looking closer, actually the first one completely contains the second, which means if we were to pick one of these courses, it's better to pick the second! If you pick the first one, you can always replace it with the second and end up with more free time.

This suggests removing courses which completely contain other courses. To do this efficiently, we first modify the tie-breaking method of our initial sort. If the end times are the same, we break ties by sorting them in decreasing order of start time. This way, if we have a series of consecutive courses with the same end time, the first one is always the shortest, so the others can be removed! The whole procedure can be done in O(N)O(N) time (after sorting) in a single pass, as illustrated by the following pseudocode:

sort the courses by increasing E_i, then by decreasing S_i

rel_courses = [] // relevant courses

add the first course (s,e) to rel_courses

for each subsequent course (s,e):
    let (S,E) be the last course in rel_courses
    if S < s and E < e: // (s,e) doesn't contain (S,E)
        add (s,e) to rel_courses
After this, we can now ignore the original list of courses and work only on rel_courses! And this pseudocode reveals another property of the remaining courses: Their SiSis are also increasing! This means that, for a given query, the first part (computing the first activity whose start time is ≥PSi≥PSi) can be done with a simple binary search!

Now all that remains is to actually compute the answer. Even having computed the first activity, doing the greedy algorithm above is still slow: it runs in O(N)O(N) in the worst case.

We can somewhat improve this by introducing the concept of a successor course. For each course, define its successor course to be the first course whose start time is greater than the end time of the course. To ensure such a course exists, we can add a dummy course whose start time is really large, say ∞∞.

The idea of successor courses is useful because the greedy algorithm is basically equivalent to selecting successor courses! The following pseudocode illustrates this:

def answer_query(PS,PE):
    find the index i of the first course with S_i >= PS, with binary search

    ans = 0
    while E_i <= PE:
        ans++
        i = successor[i]

    return ans
This is basically the same as the greedy algorithm, but potentially faster because we're possibly skipping lots of activities that won't be selected. Unfortunately, the worst case running time is still O(N)O(N) because there can still be up to O(N)O(N) nonoverlapping courses.

But looking closer, we can actually see that the idea of successor courses actually organizes our courses into a tree! If you consider the successor of a course as its "parent", then the courses are in fact organized as a tree that is rooted in our dummy course.

With this interpretation, a query actually reduces to finding the lowest ancestor of a node satisfying a certain condition: Ei≤PEEi≤PE. But since EiEi is increasing, this can also be done in O(logN)O(log⁡N) using a form of binary search which uses jump pointers!

In more detail, let's define jump(i,j)jump⁡(i,j) as the 2j2jth ancestor of node ii. These jump pointers can be computed recursively using the recurrence
jump(i,j)=jump(jump(i,j−1),j−1)
jump⁡(i,j)=jump⁡(jump⁡(i,j−1),j−1)
For the base case, we set jump(i,0)jump⁡(i,0) to be the parent of node ii. We also define the parent of the root as the root itself. We compute jump pointers for every jj such that 2j≤N2j≤N, so the size of the jumpjump table is Θ(NlogN)Θ(Nlog⁡N).

Now, with jump pointers, we can now answer a query more quickly by skipping lots of nodes at a time. See the following pseudocode:

def answer_query(PS,PE):
    find the index i of the first course with S_i >= PS, with binary search

    if E_i > PE: return 0 // skip this case

    ans = 1
    for j = floor[log_2 N]..0 by -1:
        if E_(jump[i][j]) <= PE:
            ans += 1<<j // "2 raised to j"
            i = jump[i][j]
    return ans
This works because the height of the tree is at most NN, and every such height's binary representation has at most log2N+1log2⁡N+1 bits. This clearly runs in O(logN)O(log⁡N) time!*/