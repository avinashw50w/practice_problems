/*For this problem we will consider a type of binary tree that we will call a boolean tree. 
In this tree, every row is completely filled, except possibly the last (deepest) row, 
and the nodes in the last row are as far to the left as possible. Additionally, every
node in the tree will either have 0 or 2 children.
What makes a boolean tree special is that each node has a boolean value associated with it, 1 or 0. 
In addition, each interior node has either an "AND" or an "OR" gate associated with it. 
The value of an "AND" gate node is given by the logical AND of its two children's values. 
The value of an "OR" gate likewise is given by the logical OR of its two children's values. The value
of all of the leaf nodes will be given as input so that the value of all nodes can be calculated up the tree.
The root of the tree is of particular interest to us. We would really like for the root to have the value V, 
either 1 or 0. Unfortunately, this may not be the value the root actually has. Luckily for us, we can cheat and 
change the type of gate for some of the nodes; we can change an AND gate to an OR gate or an OR gate to an AND gate.
Given a description of a boolean tree and what gates can be changed, find the minimum number of gates that need to be
changed to make the value of the root node V. If this is impossible, output "IMPOSSIBLE" (quotes for clarity).
Input
The first line of the input file contains the number of cases, N. N test cases follow.
Each case begins with M and V. M represents the number of nodes in the tree and will be odd to ensure all nodes have 
0 or 2 children. V is the desired value for the root node, 0 or 1.
M lines follow describing each of the tree's nodes. The Xth line will describe node X, 
starting with node 1 on the first line. The first (M−1)/2 lines describe the interior nodes. 
Each line contains G and C, each being either 0 or 1. If G is 1 then the gate for this node is an AND gate, 
otherwise it is an OR gate. If C is 1 then the gate for this node is changeable, otherwise it is not.
Interior node X has nodes 2X and 2X+1 as children. The next (M+1)/2 lines describe the leaf nodes. 
Each line contains one value I, 0 or 1, the value of the leaf node.
To help visualize, here is a picture of the tree in the first sample input.*/

const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}

const int oo=1000000;
const int maxsize=50000;

int n;
int f[maxsize][2];
int G[maxsize],C[maxsize],X[maxsize];

int calc(int x,int y,int op)
{
	if (op==1) return x&y;
	else return x|y;
}

int solve(int id,int V)
{
	if (id > (n-1)/2) 
		return (V == X[id]) ? 0 : oo;
	
	int &ret = f[id][V];
	
	if (ret != -1) return ret;
	
	ret = oo;
	for (int left=0; left<2; left++)
		for (int right=0; right<2; right++)
		{
			if (calc(left, right, G[id]) == V)
				checkmin(ret, solve(id*2, left) + solve(id*2+1, right));
	
			if (C[id] == 1 && calc(left, right, 1-G[id]) == V)
				checkmin(ret, solve(id*2, left) + solve(id*2+1, right) + 1);
		}
	return ret;
}

int main()
{
	freopen("..\\A-small-attempt0.in","r",stdin);
	freopen("..\\A-small-attempt0.out","w",stdout);

	int testcase;
	scanf("%d",&testcase);
	int V;
	for (int caseId=1;caseId<=testcase;caseId++)
	{
		printf("Case #%d:",caseId);
		
		scanf("%d%d",&n,&V);
		
		for (int i=1;i<=(n-1)/2;i++)
			scanf("%d%d",&G[i],&C[i]);
		
		for (int i=(n-1)/2+1;i<=n;i++)
			scanf("%d",&X[i]);
		
		memset(f,255,sizeof(f));
		
		int ret=solve(1,V);
		
		if (ret==oo) 
			printf(" IMPOSSIBLE\n");
		else
			printf(" %d\n",ret);
		
	}
}