using namespace std;
 
namespace SUBBXOR {
struct Node {
  Node* ch[2];
  int cnt;
 
};
 
typedef long long ll;
typedef Node* pNode;
pNode root;
int a[111000];
 
pNode alloc() {
  pNode p = new Node();
  p->ch[0] = p->ch[1] = NULL;
  p->cnt = 0;
  return p;
}
 
void add(const int x) {
  pNode at = root;
  for (int b = 19; b >= 0; b--) {
    const int nx = (x >> b & 1);
    if (!at->ch[nx])
      at->ch[nx] = alloc();
    at->cnt++;
    at = at->ch[nx];
  }
  at->cnt++;
}
 
int go(const int x, const int k) {
  pNode at = root;
  int res = 0;
  for (int b = 19; b >= 0 && at; b--) {
    if (k >> b & 1) {
      const int need = x >> b & 1;
      res += (at->ch[need] ? at->ch[need]->cnt : 0);
    }
    at = at->ch[(k >> b & 1) ^ (x >> b & 1)];
  }
  return res;
}
 
void solve(int test_num) {
  int N, K;
  cin >> N >> K;
  for (int i = 1; i <= N; i++)
    cin >> a[i];
  root = alloc();
  add(0);
  int xsum = 0;
  ll res = 0;
  for (int i = 1; i <= N; i++) {
    xsum ^= a[i];
    res += go(xsum, K);
    //pln(i, res);
    //dbgln(xsum);
    add(xsum);
  }
  cout << res << endl;
}
 
void solve() {
#ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
#endif
  ios::sync_with_stdio(false);
  int tests;
  cin >> tests;
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}
 
int main() {
  SUBBXOR::solve();
  return 0;
}
