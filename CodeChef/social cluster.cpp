/*
This problem deals with the effective formation of a cluster among K individuals living in a society. A society can be represented as a N × N grid. 
Individuals are located at certain points on the grid. Each individual's social interaction is measured by a positive integer, called interaction power 
denoted by Ii. The dissimilarity between two individuals is defined as the absolute difference between their interaction powers. Less the absolute difference 
between interaction powers of two individuals, more the probability that they will interact with each other.
Now your task is to form a single cluster of individuals by displacing some individuals from their original positions. Formally, a cluster means a connected 
component. An individual at point (xi, yi) is said to be adjacent to another individual at point (xj, yj) if and only if |xi - xj| = 1 and |yi - yj| = 1.
What needs to be optimized ?
The cost of clustering is defined as Score = 1000×A + 10×B , where A and B are two variables. The task is to minimize this cost.
We define A first. Suppose P be the set of individuals on the grid and |P| = K. In order to create the cluster, we may need to displace some individuals from 
their original positions on the grid. Let the individual pi be displaced by a Manhattan distance di in order to become a part of the cluster.
Now di = |xi(final) - xi(initial)| + |yi(final) - yi(initial)|.
Here (xi(initial), yi(initial)) is the initial position of individual pi and (xi(final), yi(final)) is the position of the same individual after becoming a part 
of the cluster.
Now A = S (di / Ii) where i = 1 to K.
Here Ii = Interaction power of individual pi.
The variable B is defined after the cluster is formed.
B = S ( si / ni ) , where i = 1 to K.
si = S (|Ij - Ii| ), where { pj ? P | pj is adjacent to pi }.
ni = Number of individuals adjacent to pi.
Input

The first line of input contains an integer T, denoting the number of test cases. Then T test cases follow.
The first line of each test case contains two space separated integers N and K, denoting the grid size and the number of individuals, respectively. 
Then N lines follow. The ith of these lines contains N space separated integers, denoting the information regarding the ith row. The jth value of ith row 
contains the index value of an individual at (i, j) cell. The index value, of course, ranges from 1 to K. Empty cells have zero value.
Then K lines follow. The ith of these lines contains the value of Ii
, the interaction power of ith individual.
Output

For each test case, print N lines, each line containing N space separated integers. It represents the N × N grid containing the cluster.
Constraints

1 = T = 60
2 = N = 60
2 = K = 2000
1 = Ii = 25
Example

Input:
1
5 5
0 0 0 1 0
0 0 0 0 0
2 0 5 0 4
0 0 0 0 0
0 3 0 0 0
2
3
2
3
3

Output:
0 0 0 0 0
0 0 1 0 0
0 2 5 4 0
0 0 3 0 0
0 0 0 0 0
Explanation

Calculation of value A :
d1 = 2        I1 = 2
d2 = 1        I2 = 3
d3 = 2        I3 = 2
d4 = 1        I4 = 3
d5 = 0        I5 = 3
A  =   d1/ I1 + d2/I2 + d3/I3 + d4/I4 + d5/I5
    = 1 + 0.333... + 1 + 0.333... + 0
    = 2.666... 
   
Calculation of value B :
(Number of individuals adjacent to 1) = n1 = 3  ( 2 , 5 , 4 )
s1 = |I1 - I2| + |I1 - I5| + |I1 - I4|
    = 1 + 1 + 1
    = 3
(Number of individuals adjacent to 2) = n2 = 3  ( 1 , 5 , 3 )
s2 = |I2 - I1| + |I2 - I5| + |I2 - I3|
    = 1 + 0 + 1
    = 2
In a similar fashion ,
n3 = 3, n4 = 3, n5 = 4,
s3 = 3, s4 = 2, s5 = 2,
B  =   s1/n1 + s2/n2 + s3/n3 + s4/n4 + s5/n5
     =  1 + 0.666... + 1 + 0.666... + 0.5
     =  3.833...

Now Cost = 1000×A + 10×B
                 = 2666.66... + 38.33...
                 = 2705
								
A different configuration of the cluster may result in a different cost. The task is to minimize this clustering cost  
*/

#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }
 
//#undef MY_LOCAL_RUN
 
#ifdef assert
#undef assert
#ifdef MY_LOCAL_RUN
#include "C:\Dropbox\backup\implements\Util\MyAssert.hpp"
#define assert my_assert
#else
#define assert(e)
#endif
#endif
 
struct Xor128 {
	unsigned x, y, z, w;
	Xor128(): x(123456789), y(362436069), z(521288629), w(88675123) { }
 
	//[0, 2^32)
	unsigned operator()() {
		unsigned t = x ^ (x << 11);
		x = y; y = z; z = w;
		return w = w ^ (w >> 19) ^ (t ^ (t >> 8));
	}
	//[0, 2^64)
	unsigned long long nextLL() {
		unsigned x = (*this)();
		unsigned y = (*this)();
		return (unsigned long long)x << 32 | y;
	}
	//[0, n)
	unsigned operator()(unsigned n) {
		unsigned mask = calculateMask(n - 1), x;
		do {
			x = (*this)() & mask;
		}while(x >= n);
		return x;
	}
	//[0, n)
	signed int operator()(signed int n) { return (*this)((unsigned int)n); }
	//[L, U]
	signed int operator()(signed int L, signed int U) {
		return L + (*this)(U - L + 1);
	}
	//[0, n)
	unsigned long long operator()(unsigned long long n) {
		unsigned long long mask = calculateMask(n - 1), x;
		do {
			x = (*this).nextLL() & mask;
		}while(x >= n);
		return x;
	}
	//[0, n)
	signed long long operator()(signed long long n) { return (*this)((unsigned long long)n); }
	//[L, U]
	signed long long operator()(signed long long L, signed long long U) {
		return L + (*this)(U - L + 1);
	}
private:
 
	static unsigned calculateMask(unsigned v) {
		v |= v >> 1; v |= v >> 2; v |= v >> 4; v |= v >> 8; v |= v >> 16;
		return v;
	}
	static unsigned long long calculateMask(unsigned long long v) {
		v |= v >> 1; v |= v >> 2; v |= v >> 4; v |= v >> 8; v |= v >> 16;
		v |= v >> 32;
		return v;
	}
} genxor128, miscxor128;
 
struct UnionFind {
	vector<int> data;
	void init(int n) { data.assign(n, -1); }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if(x != y) {
			if(data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool findSet(int x, int y) { return root(x) == root(y); }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
};
 
struct LCNode {
	typedef int Weight;
private:
	LCNode *parent, *left, *right;
	Weight weight;
	LCNode *maxNode;
	bool rev;
 
public:
	//é??ã?¿ã??0ã?§ã??å¿?ã??constructã??ã??å¾?ã?«setWeightã??å?¼ã?°ã?ªã??ã?¨ã??ã??ã?ªã??
	LCNode(): parent(NULL), left(NULL), right(NULL),
		weight(0), maxNode(NULL), rev(false) { }
 
private:
	bool is_root() const {
		return !parent || (parent->left != this && parent->right != this);
	}
    void update() {
		maxNode = this;
		if(left && left->maxNode->weight > maxNode->weight)
			maxNode = left->maxNode;
		if(right && right->maxNode->weight > maxNode->weight)
			maxNode = right->maxNode;
    }
    void propagate() {
        if(rev) {
            if(left) left->rev = !left->rev;
            if(right) right->rev = !right->rev;
            swap(left, right);
            rev = false;
        }
    }
 
 
private:
	void rotateR() {
		LCNode *q = parent, *r = q->parent;
		if(q->left = right) right->parent = q;
		right = q; q->parent = this;
		if(parent = r) {
			if(r->left == q) r->left = this;
			else if(r->right == q) r->right = this;
		}
	}
	void rotateL() {
		LCNode *q = parent, *r = q->parent;
		if(q->right = left) left->parent = q;
		left = q; q->parent = this;
		if(parent = r) {
			if(r->left == q) r->left = this;
			else if(r->right == q) r->right = this;
		}
	}
 
	static void global_topdown(LCNode *a) {
		LCNode *r = a, *q = a->parent;
		while(q != NULL) {
			LCNode *p = q;
			q = p->parent;
			p->parent = r;
			r = p;
		}
		while(r != a) {
			LCNode *c = r->parent;
			r->parent = q;
			q = r;
			r->propagate();
			r = c;
		}
		a->propagate();
	}
 
	static void splay(LCNode *a, bool nolastupdate = false) {
		if(a->is_root()) return;
		while(1) {
			LCNode *p = a->parent;
			bool plr = p->right == a;
			if(p->is_root()) {
				if(!plr) a->rotateR(), a->right->update();
				else a->rotateL(), a->left->update();
				break;
			}else {
				LCNode *g = p->parent;
				bool glr = g->right == p;
				bool groot = g->is_root();
				if(plr == glr) {
					if(!plr) p->rotateR(), a->rotateR(), p->right->update();
					else p->rotateL(), a->rotateL(), p->left->update();
					p->update();
				}else {
					if(!plr) a->rotateR(), a->rotateL();
					else a->rotateL(), a->rotateR();
					a->left->update();
					a->right->update();
				}
				if(groot) break;
			}
		}
		if(!nolastupdate) a->update();
	}
 
public:
	bool isExposed() const {
		return parent == NULL;
	}
 
	void setWeight(Weight w) {
		assert(is_root());
		weight = w;
		update();
	}
	Weight getWeight() const {
		return weight;
	}
 
private:
	static void splitPath(LCNode *a) {
		LCNode *r = a->right;
		if(r != NULL) {
			a->right = NULL;
			a->update();
		}
	}
 
public:
	static void expose(LCNode *a) {
		global_topdown(a);
		LCNode *rp = NULL;
		for(LCNode *p = a; p != NULL; p = p->parent) {
			splay(p, true);
			p->right = rp;
			p->update();
			rp = p;
		}
		splay(a);
	}
 
	static void evert(LCNode *x) {
		expose(x);
		splitPath(x);
		x->rev = true;
	}
	static void connect(LCNode *x, LCNode *y) {
		evert(x);
		x->parent = y;
	}
 
	static void cut(LCNode *x) {
		expose(x);
		LCNode *l = x->left;
		assert(l != NULL);
		x->left = NULL;
		l->parent = NULL;
		x->update();
	}
 
	static LCNode *findMaxNode(LCNode *x) {
		if(!x) return NULL;
		expose(x);
		if(x->left != NULL && x->left->maxNode->weight > x->weight)
			return x->left->maxNode;
		else
			return x;
	}
 
	bool debugCheckUpdated() const {
		LCNode tmp = *this;
		tmp.update();
		if(tmp.maxNode == &tmp) tmp.maxNode = const_cast<LCNode*>(this);
		return memcmp(this, &tmp, sizeof(LCNode)) == 0;
	}
};
 
class DynamicPlaneMST {
public:
	typedef LCNode Node;
	typedef Node::Weight Weight;
private:
	//primal: ei * 2 + 0, dual: ei * 2 + 1
	vector<pair<int,int> > edges;
	vector<bool> inMST;
	vector<Node> vertexNodes, edgeNodes;
	int numV, numF;
 
public:
	DynamicPlaneMST(): numV(1), numF(1) { }
 
	static Weight InfWeight() { return numeric_limits<Weight>::max(); }
	static Weight MinusInfWeight() { return -InfWeight(); }
	int numVertices() const { return numV; }
	int numFaces() const { return numF; }
	int numEdges() const { return numV + numF - 2; }
 
	//primal vertex: [0, V), dual vertex (face): [V, V + F)
	void init(int V, int F, const vector<pair<int,int> > &primalEdges, const vector<pair<int,int> > &dualEdges, const vector<Weight> &initWeights) {
		int E = (int)primalEdges.size();
		assert(primalEdges.size() == dualEdges.size());
		assert(E + 2 == V + F);
		assert(initWeights.size() == E);
		numV = V, numF = F;
 
		edges.resize(E * 2);
		for(int i = 0; i < E; ++ i) {
			assert(0 <= primalEdges[i].first && primalEdges[i].first < V);
			assert(0 <= primalEdges[i].second && primalEdges[i].second < V);
			assert(V <= dualEdges[i].first && dualEdges[i].first < V + F);
			assert(V <= dualEdges[i].second && dualEdges[i].second < V + F);
 
			edges[i * 2 + 0] = primalEdges[i];
			edges[i * 2 + 1] = dualEdges[i];
		}
		setInitWeights(initWeights);
	}
 
	//æ??å°?å?¨å??æ?¨ã?®ã?³ã?¹ã??ã?®å·®å??ã??è¿?ã??
	Weight changeWeight(int ei, Weight newWeight) {
		assert(0 <= ei && ei < numEdges());
 
		Weight prevWeight = edgeNodes[ei * 2 + 0].getWeight();
 
		Node::expose(&edgeNodes[ei * 2 + (inMST[ei] ? 0 : 1)]);
		edgeNodes[ei * 2 + 0].setWeight(+newWeight);
		edgeNodes[ei * 2 + 1].setWeight(-newWeight);
 
		int k;
		if(newWeight < prevWeight && !inMST[ei])
			k = 0;
		else if(prevWeight < newWeight && inMST[ei])
			k = 1;
		else
			return inMST[ei] ? newWeight - prevWeight : 0;
		
		Node *removeEdgeNode = findMaxEdgeNode(edges[ei * 2 + k].first, edges[ei * 2 + k].second);
		if(removeEdgeNode == NULL || removeEdgeNode->getWeight() <= edgeNodes[ei * 2 + k].getWeight())
			return inMST[ei] ? newWeight - prevWeight : 0;
 
		int fi = (removeEdgeNode - &edgeNodes[0]) / 2;
		assert(0 <= fi && fi < numEdges());
 
		inMST[fi] = k != 0;
		inMST[ei] = k == 0;
		removeEdge(fi, k);
		insertEdge(ei, k);
		removeEdge(ei, k ^ 1);
		insertEdge(fi, k ^ 1);
		return k == 0 ?
			newWeight - removeEdgeNode->getWeight() :
			-removeEdgeNode->getWeight() - prevWeight;
	}
 
	Weight findMaxWeightTreeEdgeBetweenVertices(int u, int v) {
		assert(0 <= u && u < numVertices());
		assert(0 <= v && v < numVertices());
		Node *node = findMaxEdgeNode(u, v);
		return !node || node->getWeight() == InfWeight() ? MinusInfWeight() : node->getWeight();
	}
 
	Weight findMinWeightNontreeEdgeBetweenFaces(int u, int v) {
		assert(numVertices() <= u && u < numVertices() + numFaces());
		assert(numVertices() <= v && v < numVertices() + numFaces());
		Node *node = findMaxEdgeNode(u, v);
		return !node || node->getWeight() == InfWeight() ? InfWeight() : -node->getWeight();
	}
 
private:
	Node *findMaxEdgeNode(int u, int v) {
		Node::expose(&vertexNodes[v]);
		Node::evert(&vertexNodes[u]);
		if(vertexNodes[v].isExposed())
			return NULL;
		return Node::findMaxNode(&vertexNodes[v]);
	}
 
	void removeEdge(int ei, int k) {
		Node *edgeNode = &edgeNodes[ei * 2 + k];
		Node::evert(&vertexNodes[edges[ei * 2 + k].first]);
		Node::cut(edgeNode);
		Node::evert(&vertexNodes[edges[ei * 2 + k].second]);
		Node::cut(edgeNode);
	}
 
	void insertEdge(int ei, int k) {
		Node *edgeNode = &edgeNodes[ei * 2 + k];
		Node::connect(&vertexNodes[edges[ei * 2 + k].first], edgeNode);
		Node::connect(&vertexNodes[edges[ei * 2 + k].second], edgeNode);
	}
 
	void setInitWeights(const vector<Weight> &initWeights) {
		int V = numVertices(), F = numFaces(), E = numEdges();
		vertexNodes.assign(V + F, Node());
		for(int i = 0; i < V + F; ++ i)
			vertexNodes[i].setWeight(MinusInfWeight());
 
		edgeNodes.assign(E * 2, Node());
		for(int i = 0; i < E; ++ i) {
			edgeNodes[i * 2 + 0].setWeight(+initWeights[i]);
			edgeNodes[i * 2 + 1].setWeight(-initWeights[i]);
		}
		vector<pair<Weight,int> > v(E);
		for(int i = 0; i < E; ++ i)
			v[i] = make_pair(edgeNodes[i * 2 + 0].getWeight(), i);
		sort(v.begin(), v.end());
		UnionFind uf; uf.init(numVertices());
		inMST.assign(E, false);
		for(int i = 0; i < E; ++ i) {
			int ei = v[i].second;
			inMST[ei] = uf.unionSet(edges[ei * 2 + 0].first, edges[ei * 2 + 0].second);
			insertEdge(ei, inMST[ei] ? 0 : 1);
		}
	}
};
 
struct Grid {
	int N;
	vector<short> grid;
	Grid(): N(0) { }
	Grid(int N_): N(N_), grid(N * N, -1) { }
	int getN() const { return N; }
	short &operator()(int i, int j) {
		return grid[i * N + j];
	}
	short &operator()(pair<int,int> p) { return operator()(p.first, p.second); }
	short operator()(int i, int j) const {
		return (*const_cast<Grid*>(this))(i, j);
	}
	short &operator[](int i) { return grid[i]; }
	short operator[](int i) const { return grid[i]; }
};
 
//global
int N, K;
vector<pii> initpos;
vector<int> powers;
vector<double> invpowers;
inline double NumComponentsPenalty(int c) {
	return 1e7 * (c-1);
};
 
inline double EmptyAverage() {
	return 12.5;
}
 
double calculateScore(const Grid &moved, bool checkConnected = false) {
	vector<bool> vis(K, false);
	UnionFind uf; uf.init(N * N);
	int edges = 0;
	double A = 0, B = 0;
	rep(i, N) rep(j, N) {
		int a = moved(i, j);
		if(a == -1) continue;
		assert(!vis[a]);
 
		int d = abs(i - initpos[a].first) + abs(j - initpos[a].second);
		int l = powers[a];
 
		int s = 0, n = 0;
		rer(dy, -1, 1) rer(dx, -1, 1) if(dy || dx) {
			int yy = i + dy, xx = j + dx;
			if(yy < 0 || yy >= N || xx < 0 || xx >= N) continue;
			int b = moved(yy, xx);
			if(b == -1) continue;
			s += abs(l - powers[b]);
			++ n;
			edges += uf.unionSet(i * N + j, yy * N + xx);
		}
		A += d * 1. / l;
		if(n == 0)
			B += EmptyAverage();
		else
			B += s * 1. / n;
 
		vis[a] = true;
	}
 
	assert(count(all(vis), true) == K);
//	assert(edges == K - 1);
	int C = K - edges;
	if(checkConnected && C != 1) {
		cerr << "not connected" << endl;
		abort();
	}
 
//	cerr << "N = " << N << ", K = " << K << ", A * 1000 = " << A * 1000 << ", B * 10 = " << B * 10 << ", " << (A * 1000) / (A * 1000 + B * 10) << endl;
	return 1000 * A + 10 * B + NumComponentsPenalty(C);
}
 
double calculateLocalScore(const Grid &grid, int a, int y, int x) {
	int s = 0, n = 0;
	rer(dy, -1, 1) rer(dx, -1, 1) if(dy || dx) {
		int yy = y + dy, xx = x + dx;
		if(yy < 0 || yy >= N || xx < 0 || xx >= N) continue;
		int b = grid(yy, xx);
		if(b == -1) continue;
		s += abs(powers[a] - powers[b]);
		++ n;
	}
	double A = (abs(initpos[a].first - y) + abs(initpos[a].second - x)) * invpowers[a];
	double B = n == 0 ? EmptyAverage() : s * 1. / n;
	return 1000 * A + 10 * B;
}
 
#ifdef WIN32
extern "C" unsigned __stdcall GetTickCount(void);
double getTime() { return GetTickCount() / 1e3; }
#else
#include <sys/time.h>
double getTime() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec + tv.tv_usec / 1e6;
}
#endif
 
inline void greedySetPos(Grid &grid, int a, int i, int j, set<int> &oklist) {
	assert(grid(i, j) == -1);
	grid(i, j) = a;
	oklist.erase(i * N + j);
	rer(dy, -1, 1) rer(dx, -1, 1) if(dy || dx) {
		int yy = i + dy, xx = j + dx;
		if(yy < 0 || yy >= N || xx < 0 || xx >= N) continue;
		if(grid(yy, xx) != -1) continue;
		int t = yy * N + xx;
		oklist.insert(t);
	}
}
 
Grid solveGreedy() {
	vpii ord(K);
	rep(a, K) {
		int inity = initpos[a].first, initx = initpos[a].second;
		ord[a] = mp((inity < 2 ? 0 : inity) * N + initx, a);
	}
	sort(all(ord));
 
	Grid grid(N);
	set<int> okset;
	{	int a = ord[0].second;
		int inity = initpos[a].first, initx = initpos[a].second;
		greedySetPos(grid, a, inity, initx, okset);
	}
	reu(ix, 1, K) {
		int a = ord[ix].second;
		int inity = initpos[a].first, initx = initpos[a].second;
		pair<double,pii> minpos(1e99, mp(-1, -1));
		each(i, okset) {
			int y = *i / N, x = *i % N;
//			double t = abs(y - inity) + abs(x - initx);
			double t = calculateLocalScore(grid, a, y, x);
			amin(minpos, mp(t, mp(y, x)));
		}
		int y = minpos.second.first, x = minpos.second.second;
		greedySetPos(grid, a, y, x, okset);
	}
	return grid;
}
 
void createDiagontalGridGraph(int H, int W, vector<pair<int,int> > &primalEdges, vector<pair<int,int> > &dualEdges, int &resV, int &resF) {
	/*
		ï¼¼ã??ï¼?ï¼¼ã??ï¼?ï¼¼ã??ï¼?
		ã??><ã??ã??><ã??ã??><ã??
		ï¼?ã??ï¼¼ï¼?ã??ï¼¼ï¼?ã??ï¼¼
		ï¼¼ã??ï¼?ï¼¼ã??ï¼?ï¼¼ã??ï¼?
		ã??><ã??ã??><ã??ã??><ã??
		ï¼?ã??ï¼¼ï¼?ã??ï¼¼ï¼?ã??ï¼¼
	*/
	int C = H * W, V = C + (H+1) * (W+1);
	int D = V + (H-1) * W, VandF = D + H * (W-1) + 1;
	int outerPlane = VandF - 1;
	primalEdges.resize(H * W * 4);
	dualEdges.resize(H * W * 4);
	rep(y, H) rep(x, W) {
		rep(dy, 2) rep(dx, 2) {
			int i = (y * W + x) * 4 + dy * 2 + dx;
			int yy = y + dy, xx = x + dx;
			int a = y * W + x;
			int b = C + yy * (W+1) + xx;
			primalEdges[i] = make_pair(a, b);
			int c = yy == 0 || yy == H ? outerPlane : V + (yy-1) * W + x;
			int d = xx == 0 || xx == W ? outerPlane : D + y * (W-1) + (xx-1);
			dualEdges[i] = make_pair(c, d);
		}
	}
	resV = V, resF = VandF - V;
}
 
struct GridDynaCon {
	vector<vector<bool> > grid;
	DynamicPlaneMST dynaMST;
	int H, W;
	int numCC;
	static char table[1 << 8][4];
	static const int dy[8], dx[8];
 
	GridDynaCon(): H(0), W(0) { }
	void init(int H_, int W_) {
		H = H_, W = W_;
		grid.assign(H, vector<bool>(W, false));
		vpii primalEdges, dualEdges;
		int V, F;
		createDiagontalGridGraph(H, W, primalEdges, dualEdges, V, F);
		vector<int> initWeights(H * W * 4, 1);
		dynaMST.init(V, F, primalEdges, dualEdges, initWeights);
		numCC = 0;
	}
	int insert(int i, int j) {
		assert(!grid[i][j]);
 
		int l = getneighbors(i, j);
		numCC -= l - 1;
 
		grid[i][j] = true;
		rep(d, 4)
			dynaMST.changeWeight((i * W + j) * 4 + d, 0);
		return -(l - 1);
	}
	int remove(int i, int j) {
		assert(grid[i][j]);
 
		grid[i][j] = false;
		rep(d, 4)
			dynaMST.changeWeight((i * W + j) * 4 + d, 1);
 
		int l = getneighbors(i, j);
		numCC += l - 1;
		return l - 1;
	}
	int numComponents() const {
		return numCC;
	}
 
	int getneighbors(int i, int j) {
		int bits = getbits(i, j);
		const char *t = table[bits];
		int k = find(t, t + 4, -1) - t, l = 0;
		int vs[4];
		rep(p, k) {
			bool ok = true;
			int v = (i + dy[t[p]]) * W + (j + dx[t[p]]);
			rep(q, l)
				ok &= dynaMST.findMaxWeightTreeEdgeBetweenVertices(v, vs[q]) > 0;
			if(ok)
				vs[l ++] = v;
		}
		return l;
	}
 
	int getbits(int i, int j) {
		int bits = 0;
		rep(d, 8) {
			int yy = i + dy[d], xx = j + dx[d];
			if(0 <= yy && yy < H && 0 <= xx && xx < W)
				bits |= grid[yy][xx] << d;
		}
		return bits;
	}
 
	static void initTable() {
		UnionFind uf;
		rep(i, 1 << 8) {
			uf.init(8);
			rep(j, 8) if((i >> j) & (i >> ((j+1)%8)) & 1)
				uf.unionSet(j, (j+1)%8);
			rep(j, 4) if((i >> (j*2+1)) & (i >> ((j*2+3)%8)) & 1)
				uf.unionSet(j*2+1, (j*2+3)%8);
			int k = 0;
			rep(j, 8) if((i >> j & 1) && uf.root(j) == j)
				table[i][k ++] = j;
			while(k < 4)
				table[i][k ++] = -1;
		}
	}
};
const int GridDynaCon::dy[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
const int GridDynaCon::dx[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
char GridDynaCon::table[1 << 8][4];
 
double calculateLocalScore(const Grid &grid, int y, int x) {
	return grid(y, x) == -1 ? 0 : calculateLocalScore(grid, grid(y, x), y, x);
}
 
void joinCC(Grid &grid, vi &poses, const vi &cca, double &movecost, vpii &swapseq) {
	int C = cca.size();
	vi idx(K, -1);
	vi as(C);
	UnionFind uf;
	const int D = 7, A = 24 / D + 1;
	vector<bool> vis;
	vector<pair<int,int> > ixord(C);
 
	rep(ix, C) {
		int a = grid[cca[ix]];
		as[ix] = a;
		idx[a] = ix;
		ixord[ix] = mp(-powers[a], ix);
	}
	sort(all(ixord));
 
	movecost = 0;
	for(int k = 0, iters = 0; ; ++ iters) {
		uf.init(C + 1);
		rep(ix, C) {
			int a = as[ix];
			if(idx[a] == -1) {
				uf.unionSet(ix, C);
				continue;
			}
			int i = cca[ix];
			rer(dy, -1, 1) rer(dx, -1, 1) if(dy || dx) {
				int yy = i / N + dy, xx = i % N + dx;
				if(0 <= yy && yy < N && 0 <= xx && xx < N) {
					int b = grid(yy, xx);
					if(b == -1) continue;
					if(idx[b] == -1) {
						uf.unionSet(ix, C);
						goto brk;
					}else {
						uf.unionSet(ix, idx[b]);
					}
				}
			}
			brk:;
		}
 
		bool okok = true;
		rep(ix, C) if(idx[as[ix]] != -1) {
			if(uf.findSet(ix, C)) {
				idx[as[ix]] = -1;
			}else {
				okok = false;
			}
		}
		if(okok) {
//			cerr << "iters = " << iters << endl;
			break;
		}
 
		pair<double,pii> minCost(1e99,mp(-1,-1));
 
		pii maxpower(-1,-1);
		rep(ix, as.size()) if(idx[as[ix]] != -1)
			amax(maxpower, mp(powers[as[ix]], ix));
		static const int dyx3[4][2][2] = {
			{ { -1, 1 }, { 0, 1 } },
			{ { 1, 1 }, { 1, 0 } },
			{ { 1, -1 }, { 0, -1 } },
			{ { -1, -1 }, { -1, 0 } }
		};
		rep(ixx, C) {
			int ix = ixord[ixx].second;
			if(idx[as[ix]] == -1) continue;
			int y0 = cca[ix] / N, x0 = cca[ix] % N;
			int maxk = minCost.first == 1e99 ? N+N-1 : (int)(minCost.first / invpowers[as[ix]] - 1e-6);
			for(int k = 1; k <= maxk; ++ k) {
				int y = y0 - k, x = x0;
				rep(d, 4) {
					int cdy = d / 2 == 0 ? 1 : -1;
					int cdx = d == 0 || d == 3 ? 1 : -1;
					rep(l, k) {
//						cerr << y - y0 << ", " << x - x0 << endl;
						if(0 <= y && y < N && 0 <= x && x < N) {
							rep(e, 2) {
								int yy = y + dyx3[d][e][0], xx = x + dyx3[d][e][1];
								if(!(0 <= yy && yy < N && 0 <= xx && xx < N)) continue;
								int b = grid(yy, xx);
								if(b != -1 && idx[b] == -1) goto oklabel;
							}
							if(l == 0) {
								rep(e, 2) {
									int yy = y + dyx3[(d+3)%4][e][0], xx = x + dyx3[(d+3)%4][e][1];
									if(!(0 <= yy && yy < N && 0 <= xx && xx < N)) continue;
									int b = grid(yy, xx);
									if(b != -1 && idx[b] == -1) goto oklabel;
								}
							}
							if(0) {
								oklabel:;
								amin(minCost, mp(k * invpowers[as[ix]], mp(ix, y * N + x)));
								goto brk2;
							}
						}
						y += cdy, x += cdx;
					}
				}
			}
			brk2:;
		}
 
		movecost += minCost.first;
		int ix = minCost.second.first, i = cca[ix];
		int j = minCost.second.second;
		idx[as[ix]] = -1;
		swapseq.push_back(mp(i, j));
		grid[i] = -1;
		grid[j] = as[ix];
//		dynaCon.remove(i / N, i % N);
//		dynaCon.insert(j / N, j % N);
		poses[as[ix]] = j;
	}
}
 
double calculateScoreAlpha(const Grid &grid, int occs) {
	double s = calculateScore(grid);
	int ccs = (int)floor(s / 1e7) + 1;
	double t = s - (ccs - 1) * 1e7;
	return t + (occs <= ccs ? 1e7 : 0);
}
 
int countCCs(const Grid &grid) {
	return (int)(calculateScore(grid) / 1e7) + 1;
}
 
void applySwapseq(Grid &grid, vi &poses, const vpii &swapseq, bool rev) {
	int n = swapseq.size();
	rep(i, n) {
		pii p = swapseq[!rev ? i : n - 1 - i];
		bool a = grid[p.first] != -1;
		bool b = grid[p.second] != -1;
		/*
		if(a != b) {
			if(!a) {
				dynaCon.insert(p.first / N, p.first % N);
				dynaCon.remove(p.second / N, p.second % N);
			}else {
				dynaCon.remove(p.first / N, p.first % N);
				dynaCon.insert(p.second / N, p.second % N);
			}
		}*/
		if(a) poses[grid[p.first]] = p.second;
		if(b) poses[grid[p.second]] = p.first;
		swap(grid[p.first], grid[p.second]);
	}
}
 
Grid solveSpecial(const Grid &initgrid) {
	Grid grid = initgrid;
//	GridDynaCon dynaCon;
//	dynaCon.init(N, N);
//	rep(i, N) rep(j, N) if(initgrid(i, j) != -1)
//		dynaCon.insert(i, j);
	vi poses(K, -1);
	rep(i, N) rep(j, N) if(grid(i, j) != -1)
		poses[grid(i, j)] = i * N + j;
 
	while(1) {
//		int numcc = dynaCon.numComponents();
//		if(numcc <= 1)
//			break;
 
//		rep(a, K) assert(grid[poses[a]] == a);
 
		vector<bool> vis(N * N);
		pair<double,int> sizes[2];
		sizes[0].first = sizes[1].first = 1e99;
		sizes[0].second = sizes[1].second = -1;
		vi ccs0, ccs1, curcc;
 
		vi v;
		int aaa = 0;
		rep(si, N * N) if(grid[si] != -1 && !vis[si]) {
			++ aaa;
			vis[si] = true;
			double invsum = 0;
			curcc.clear();
			v.push_back(si);
			while(!v.empty()) {
				int t = v.back(); v.pop_back();
				invsum += invpowers[grid[t]];
				curcc.push_back(t);
				int i = t / N, j = t % N;
				rer(dy, -1, 1) rer(dx, -1, 1) {
					int yy = i + dy, xx = j + dx;
					if(yy < 0 || yy >= N || xx < 0 || xx >= N) continue;
					int u = yy * N + xx;
					if(grid[u] == -1 || vis[u]) continue;
					vis[u] = true;
					v.push_back(u);
				}
			}
			if(sizes[0].first > invsum) {
				sizes[1] = sizes[0];
				ccs1.swap(ccs0);
				sizes[0] = mp(invsum, si);
				ccs0.swap(curcc);
			}else if(sizes[1].first > invsum) {
				sizes[1] = mp(invsum, si);
				ccs1.swap(curcc);
			}
		}
 
		if(aaa <= 1) break;
 
//		assert(aaa == dynaCon.numComponents());
 
//		cerr << "solveSpecial: " << aaa << endl;
/*
		rep(i, N) {
			rep(j, N)
				cerr << grid(i, j)+1 << " ";
			cerr << endl;
		}
//		*/
 
		assert(sizes[1].second != -1);
 
//		cerr << numcc << ": " << ccs[sizes[0].second].size() << ", " << ccs[sizes[1].second].size() << endl;
		double score1; vpii swapseq1;
		{	double movecost;
			joinCC(grid, poses, ccs1, movecost, swapseq1);
			score1 = movecost;
			applySwapseq(grid, poses, swapseq1, true);
		}
		{	double movecost;
			vpii swapseq2;
			joinCC(grid, poses, ccs0, movecost, swapseq2);
			if(movecost > score1) {
				applySwapseq(grid, poses, swapseq2, true);
				applySwapseq(grid, poses, swapseq1, false);
			}
		}
	}
 
	return grid;
}
 
pii getSumNeighbors(const Grid &grid, const vi &neighbors, int a) {
	int s = 0, n = 0;
	each(i, neighbors) {
		int b = grid[*i];
		s += abs(powers[a] - powers[b]);
		++ n;
	}
	return mp(s, n);
}
 
void getNeighbors(const Grid &grid, int i, vi &neighbors) {
	int y = i / N, x = i % N;
	rer(dy, -1, 1) rer(dx, -1, 1) if(dy || dx) {
		int yy = y + dy, xx = x + dx;
		if(yy < 0 || yy >= N || xx < 0 || xx >= N || grid(yy, xx) == -1) continue;
		neighbors.push_back(yy * N + xx);
	}
}
 
Grid hillClimbing2(Grid grid, double timeLimit, const int GetTimeInterval = 100) {
	double startTime = getTime(), endTime = startTime + timeLimit, currentTime = startTime;
	long long iterates;
 
	vi poses(K, -1);
	rep(i, N * N) if(grid[i] != -1)
		poses[grid[i]] = i;
 
	vector<vi> neighbors(N * N);
	rep(a, K)
		getNeighbors(grid, poses[a], neighbors[poses[a]]);
 
	double curScore = 0;
	vector<pair<int,int> > neighborsums(K);
	rep(a, K) {
		int y = poses[a] / N, x = poses[a] % N;
		neighborsums[a] = getSumNeighbors(grid, neighbors[poses[a]], a);
		curScore += neighborsums[a].first * 1. / neighborsums[a].second * 10;
		curScore += (abs(initpos[a].first - y) + abs(initpos[a].second - x)) * invpowers[a] * 1000;
	}
 
	bool naiveDynaCon = K < 500, testDynaCon = false;
 
	GridDynaCon dynaCon;
	if(testDynaCon || !naiveDynaCon) {
		dynaCon.init(N, N);
		rep(i, N) rep(j, N) if(grid(i, j) != -1)
			dynaCon.insert(i, j);
	}
 
	vector<char> tmpcnt(N * N, 0);
	vi tmpv;
	UnionFind tmpuf; tmpuf.init(N * N);
	vi tmpstartposes;
	vector<vi> tmpqs(N + N + 2);
	vector<bool> tmpvis(N * N);
	vi tmpw, tmpneighbors;
 
	int updates[2] = {}, rejects[2] = {};
	for(iterates = 0; ; iterates ++) {
		if(iterates % GetTimeInterval == 0)
			if((currentTime = getTime()) >= endTime) break;
 
		int a1, a2, swap1, swap2, y1, x1, y2, x2;
		while(1) {
			a1 = miscxor128(K), a2;
			swap1 = poses[a1], swap2;
			y1 = swap1 / N, x1 = swap1 % N, y2, x2;
			while(1) {
				int dy = miscxor128(-1, 1), dx = miscxor128(-1, 1);
				int yy = y1 + dy, xx = x1 + dx;
				if((dy || dx) && 0 <= yy && yy < N && 0 <= xx && xx < N) {
					swap2 = yy * N + xx;
					a2 = grid[swap2];
					if(a2 == -1 && miscxor128(4) != 0) continue;
					y2 = yy, x2 = xx;
					break;
				}
			}
			int t = 0, u = 0;
			t += abs(y1 - initpos[a1].first) + abs(x1 - initpos[a1].second);
			if(a2 != -1) t += abs(y2 - initpos[a2].first) + abs(x2 - initpos[a2].second);
			u += abs(y2 - initpos[a1].first) + abs(x2 - initpos[a1].second);
			if(a2 != -1) u += abs(y1 - initpos[a2].first) + abs(x1 - initpos[a2].second);
			if(pow(0.3, u - t + 1) > miscxor128() * 2.3283064365386963e-10) break;
		}
 
		if(a2 == -1 && (testDynaCon || !naiveDynaCon)) {
			dynaCon.remove(y1, x1);
			dynaCon.insert(y2, x2);
			if(!naiveDynaCon && dynaCon.numComponents() != 1) {
				dynaCon.insert(y1, x1);
				dynaCon.remove(y2, x2);
				++ rejects[1];
				continue;
			}
		}
 
		tmpv.clear();
		each(i, neighbors[swap1]) {
			if(tmpcnt[*i] == 0) tmpv.push_back(*i);
			tmpcnt[*i] |= 1;
		}
		if(a2 != -1) {
			each(i, neighbors[swap2]) {
				if(tmpcnt[*i] == 0) tmpv.push_back(*i);
				tmpcnt[*i] |= 2;
			}
		}else {
			rer(dy, -1, 1) rer(dx, -1, 1) if(dy || dx) {
				int yy = y2 + dy, xx = x2 + dx, t = yy * N + xx;
				if(0 <= yy && yy < N && 0 <= xx && xx < N && grid[t] != -1) {
					if(tmpcnt[t] == 0) tmpv.push_back(t);
					tmpcnt[t] |= 2;
				}
			}
		}
 
		if(a2 == -1 && naiveDynaCon) {
			bool isolated = true;
 
			tmpstartposes.clear();
			each(i, tmpv) if(*i != swap1) {
				isolated &= (tmpcnt[*i] & 2) == 0;
				if((tmpcnt[*i] & 1) != 0) {
					bool newneighbor = true;
					each(j, tmpstartposes) {
						newneighbor = max(abs(*i / N - *j / N), abs(*i % N - *j % N)) > 1;
						if(!newneighbor) {
							break;
						}
					}
					if(newneighbor)
						tmpstartposes.push_back(*i);
				}
			}
			if(isolated) {
				++ rejects[1];
				if(testDynaCon) {
					assert(dynaCon.numComponents() > 1);
					dynaCon.insert(y1, x1);
					dynaCon.remove(y2, x2);
				}
				each(i, tmpv) tmpcnt[*i] = 0;
				continue;
			}
 
			tmpw.clear();
 
			tmpvis[swap1] = true;
			tmpw.push_back(swap1);
 
			each(i, tmpstartposes) {
				tmpvis[*i] = true;
				tmpqs[1].push_back(*i);
				tmpw.push_back(*i);
			}
 
			bool connected = false;
			int h = 1, t = 1;
			while(h <= t) {
				if(tmpqs[h].empty()) {
					++ h;
					continue;
				}
				int i = tmpqs[h].back(); tmpqs[h].pop_back();
 
				tmpneighbors.clear();
				if(i == swap2) {
					getNeighbors(grid, i, tmpneighbors);
				}else{ 
					tmpneighbors = neighbors[i];
					if((tmpcnt[i] & 2) != 0)
						tmpneighbors.push_back(swap2);
				}
 
				each(j, tmpneighbors) {
					if(*j != swap1) tmpuf.unionSet(i, *j);
					if(tmpvis[*j]) continue;
					tmpvis[*j] = true;
					tmpw.push_back(*j);
 
					int d = max(abs(*j / N - y1), abs(*j % N - x1));
					tmpqs[d].push_back(*j);
 
					if(d > t) t = d;
					else if(d < h) h = d;
				}
 
				rep(ix, tmpstartposes.size()) {
					bool ok = true;
					rep(jx, ix) {
						ok = !tmpuf.findSet(tmpstartposes[ix], tmpstartposes[jx]);
						if(!ok) break;
					}
					if(!ok) {
						tmpstartposes.erase(tmpstartposes.begin() + ix);
						-- ix;
					}
				}
				if(tmpstartposes.size() == 1) {
					connected = true;
					break;
				}
			}
 
			each(i, tmpw) {
				tmpvis[*i] = false;
				tmpuf.data[*i] = -1;
			}
 
			rer(p, h, t) tmpqs[p].clear();
 
			/*
			assert(count(all(tmpvis), true) == 0);
			assert(count(all(tmpuf.data), -1) == N * N);
			rep(p, tmpqs.size()) assert(tmpqs[p].empty());
			*/
 
			if(!connected) {
				++ rejects[1];
				if(testDynaCon) {
					assert(dynaCon.numComponents() > 1);
					dynaCon.insert(y1, x1);
					dynaCon.remove(y2, x2);
				}
				each(i, tmpv) tmpcnt[*i] = 0;
				continue;
			}else {
				if(testDynaCon) {
					assert(dynaCon.numComponents() == 1);
				}
			}
		}
 
		double prevScore = curScore;
		bool currejected = false;
		if(a2 != -1) {
			curScore -= calculateLocalScore(grid, y1, x1);
			curScore -= calculateLocalScore(grid, y2, x2);
			swap(grid[swap1], grid[swap2]);
			poses[a1] = swap2;
			poses[a2] = swap1;
			curScore += calculateLocalScore(grid, y1, x1);
			curScore += calculateLocalScore(grid, y2, x2);
 
			each(i, tmpv) {
				int m = tmpcnt[*i];
				int a = grid[*i];
				if(a != a1 && a != a2) {
					if(m == 1) {
						int diff = abs(powers[a] - powers[a2]) - abs(powers[a] - powers[a1]);
						curScore += diff * 10. / neighborsums[a].second;
					}else if(m == 2) {
						int diff = abs(powers[a] - powers[a1]) - abs(powers[a] - powers[a2]);
						curScore += diff * 10. / neighborsums[a].second;
					}else {
						assert(m == 3);
					}
				}
			}
 
			if(prevScore < curScore) {
				swap(grid[swap1], grid[swap2]);
				poses[a1] = swap1;
				poses[a2] = swap2;
				curScore = prevScore;
				++ rejects[0];
				currejected = true;
			}else {
				++ updates[0];
 
				neighborsums[a1] = getSumNeighbors(grid, neighbors[poses[a1]], a1);
				neighborsums[a2] = getSumNeighbors(grid, neighbors[poses[a2]], a2);
				each(i, tmpv) {
					int m = tmpcnt[*i], a = grid[*i];
					if(a == a1 || a == a2) continue;
					if(m == 1) {
						int diff = abs(powers[a] - powers[a2]) - abs(powers[a] - powers[a1]);
						neighborsums[a].first += diff;
					}else if(m == 2) {
						int diff = abs(powers[a] - powers[a1]) - abs(powers[a] - powers[a2]);
						neighborsums[a].first += diff;
					}
				}
			}
		}else {
			curScore -= calculateLocalScore(grid, y1, x1);
			swap(grid[swap1], grid[swap2]);
			poses[a1] = swap2;
			curScore += calculateLocalScore(grid, y2, x2);
 
			each(i, tmpv) {
				int m = tmpcnt[*i];
				int a = grid[*i];
				if(a != -1) {
					pii p = neighborsums[a];
					if(m == 1) {
						curScore -= p.first * 10. / p.second;
						curScore += (p.first - abs(powers[a] - powers[a1])) * 10. / (p.second - 1);
					}else if(m == 2) {
						curScore -= p.first * 10. / p.second;
						curScore += (p.first + abs(powers[a] - powers[a1])) * 10. / (p.second + 1);
					}else {
						assert(m == 3);
					}
				}
			}
 
			if(prevScore < curScore) {
				swap(grid[swap1], grid[swap2]);
				poses[a1] = swap1;
 
				if(testDynaCon || !naiveDynaCon) {
					dynaCon.insert(y1, x1);
					dynaCon.remove(y2, x2);
				}
				curScore = prevScore;
				++ rejects[1];
				currejected = true;
			}else {
				++ updates[1];
 
				neighbors[swap1].clear();
				neighbors[swap2].clear();
				getNeighbors(grid, swap2, neighbors[swap2]);
				neighborsums[a1] = getSumNeighbors(grid, neighbors[poses[a1]], a1);
 
				each(i, tmpv) if(grid[*i] != -1) {
					int m = tmpcnt[*i], a = grid[*i];
					if(m == 1) {
						neighborsums[a].first -= abs(powers[a] - powers[a1]);
						neighborsums[a].second -= 1;
 
						neighbors[*i].erase(find(all(neighbors[*i]), swap1));
					}else if(m == 2) {
						neighborsums[a].first += abs(powers[a] - powers[a1]);
						neighborsums[a].second += 1;
 
						neighbors[*i].push_back(swap2);
					}else {
						*find(all(neighbors[*i]), swap1) = swap2;
					}
				}
			}
		}
 
/*
		rep(a, K) assert(grid[poses[a]] == a);
		rep(i, N * N) {
			int a = grid[i];
			if(a == -1) {
				assert(neighbors[i].empty());
			}else {
				vi tmp, tmp2 = neighbors[i];
				getNeighbors(grid, i, tmp);
				sort(all(tmp)); sort(all(tmp2));
				assert(tmp == tmp2);
			}
		}
		rep(a, K) {
			pii p = getSumNeighbors(grid, neighbors[poses[a]], a);
			assert(neighborsums[a] == p);
		}
		double actualScore = calculateScore(grid, true);
		assert(abs(curScore - actualScore) < 1e-9);
//		*/
 
		each(i, tmpv) tmpcnt[*i] = 0;
	}
#ifdef MY_LOCAL_RUN
	assert(updates[0] + rejects[0] + updates[1] + rejects[1] == iterates);
	cerr << "timeLimit: " << timeLimit<< ", total iter = " << iterates;
	cerr << "; " << updates[0] << ", " << rejects[0] << "; " << updates[1] << ", " << rejects[1] << endl;
#endif
	return grid;
}
 
 
#ifdef MY_LOCAL_RUN
#define MY_TEST
#define MY_RANDGEN
#endif
 
#ifdef MY_TEST
#include "C:\Dropbox\backup\implements\Util\CPUTime.hpp"
#endif
 
int main() {
	miscxor128.z = time(0);
	double startTime = getTime(), endTime = startTime + 4.9;
	double scoreSum = 0;
	GridDynaCon::initTable();
#ifndef MY_TEST
	int T;
	scanf("%d", &T);
	rep(ii, T) {
		double caseEndTime = getTime() + (endTime - getTime()) / (T - ii);
#else
	for(int ii = 0; ; ++ ii) {
		double caseEndTime = getTime() + 5. / 60;
#endif
#ifndef MY_RANDGEN
		scanf("%d%d", &N, &K);
#else
		{	const int MaxN = 60;
			int x = genxor128(2, MaxN);
			N = genxor128(x, MaxN);
			int y = genxor128(2, min(2000, N * N));
			K = genxor128(2, y);
		}
//		cerr << "N = " << N << ", K = " << K << endl;
#endif
		Grid initgrid(N);
#ifndef MY_RANDGEN
		rep(i, N) rep(j, N) {
			int g;
			scanf("%d", &g), -- g;
			initgrid(i, j) = g;
		}
#else
		rep(k, K) {
			int y, x;
			do {
				y = genxor128(N), x = genxor128(N);
			}while(initgrid(y, x) != -1);
			initgrid(y, x) = k;
		}
#endif
 
		powers.resize(K);
		invpowers.resize(K);
		rep(i, K) {
#ifndef MY_RANDGEN
			scanf("%d", &powers[i]);
#else
			powers[i] = genxor128(1, 25);
#endif
			invpowers[i] = 1. / powers[i];
		}
 
//		if(ii != 1343) continue;
		initpos.assign(K, mp(-1, -1));
		rep(i, N) rep(j, N) {
			int a = initgrid(i, j);
			if(a == -1) continue;
			assert(initpos[a].first == -1);
			initpos[a] = mp(i, j);
		}
		assert(count(all(initpos), mp(-1, -1)) == 0);
 
//		solveMST(initgrid);
 
		Grid ansgrid;
 
		ansgrid = solveSpecial(initgrid);
 
		double timeLimit = caseEndTime - getTime();
		ansgrid = hillClimbing2(ansgrid, timeLimit);
 
//		Grid greedygrid = solveGreedy();
//		double greedyScore = calculateScore(greedygrid);
//		greedySum += greedyScore;
 
//		if(score > greedyScore) {
//			ansgrid = greedygrid;
//			score = greedyScore;
//		}
#ifndef MY_RANDGEN
		rep(i, N) {
			rep(j, N) {
				if(j != 0) putchar(' ');
				printf("%d", (int)ansgrid(i, j) + 1);
			}
			puts("");
		}
#else
#endif
	}
	return 0;
} 
