/*Some of the secret doors contain a very interesting word puzzle. The team of archaeologists has to solve it to open that doors. Because there is no other way to open 
the doors, the puzzle is very important for us.

There is a large number of magnetic plates on every door. Every plate has one word written on it. The plates must be arranged into a sequence in such a way that 
every word begins with the same letter as the previous word ends. For example, the word ``acm'' can be followed by the word ``motorola''. Your task is to write a 
computer program that will read the list of words and determine whether it is possible to arrange all of the plates in a sequence (according to the given rule) 
and consequently to open the door.

Input

The input consists of T test cases. The number of them (T, equal to about 500) is given on the first line of the input file. Each test case begins with a line 
containing a single integer number N that indicates the number of plates (1 <= N <= 100000). Then exactly Nlines follow, each containing a single word. Each 
word contains at least two and at most 1000 lowercase characters, that means only letters 'a' through 'z' will appear in the word. The same word may appear 
several times in the list.

Output

Your program has to determine whether it is possible to arrange all the plates in a sequence such that the first letter of each word is equal to the last letter 
of the previous word. All the plates from the list must be used, each exactly once. The words mentioned several times must be used that number of times.

If there exists such an ordering of plates, your program should print the sentence "Ordering is possible.". Otherwise, output the sentence "The door cannot be 
opened.". */
/*The problem might seem to have an easy O(N) solution:-
Input the first string. Keep first and last letters.
Input the next string. Insert it at any free end. Update the first and the last available letters.
But, this is WRONG!!

One approach is to convert this in a graph theory problem and then solve it by finding whether a euler path exists in a graph or not.

PART - 1 (Making the graph)
Lets first make the graph. Suppose the input is :
acm
math
icpc
hi
tic

Now the problem says us to connect the strings. Just think of the alphabets as nodes of the graph. Now connect the first and the last alphabet of each string by and edges. Store the graph as adjacency matrix (it will be easier later). So the graph looks like:

a-->m-->h-->i-->c<--t    (as if each edge represents a word) 

The problem is to find wether a path exists that visits all the edges in the graph without visiting any edges more than 1 time. (Eulerian path)(Page on ku.edu) Also make 2 26 size arrays that store the indegree and outdegree of each node. Now key point to note here is that there can be two cases:
1. Exactly two nodes in the graph have  
|inDeg[a]−outDeg[a]|=1 . (Think about it and you will know why, if you enter a node , you also must exit it (you use two edges once you enter a node) unless that node is the start or the end of the ordering).
2. All the nodes have inDeg[a]==outDeg[a]. (The starting node of the path and the ending are the same).
3. If none of the above, then the answer is already no.

But just the above conditions are not sufficient because there can be two disconnected components in a graph each having its own path but the whole graph has no euler path.

START Node- The node that has  |inDeg[a]−outDeg[a]|=1, or a random node (with outDeg[a]>0 ) if no such node exists

PART-2 (Finding the path)
Now, how do we find the eulerian path for the graph.
You can find an explanation here :- If a graph has an Euler path or circuit, how do we find it?
How to do it in this question:
Store the graph as an adjacency matrix ( bool adj[26][26]; ). Now choose our START node and do dfs. Move to the first node to which it is connected and delete 
the edge between them( adj[from][to] = 0). Now after the dfs is over. Just check that no single edge exists in the graph. If no edge exists, it means that we 
have walked over all the edges in the graph without repeating any one , which means that the answer is yes. Else the answer is no.*/
#include <bits/stdc++.h>
using namespace std;

#define gc getchar_unlocked

void scanString(char str[]) {
	int x;
	register char c = gc();
	for(; (c<'a' || c>'z'); c=gc());

	str[0] = c-'a';

	for(; (c>='a' && c<='z'); c=gc()) { x = c; }

	str[1] = x-'a';
}

int g[26][26], Start[26], End[26], check[26], vis[26];

void init() {
	for(int i=0;i<26;++i){
		Start[i] = End[i] = check[i] = vis[i] = 0;
	}
	memset(g, 0, sizeof(g));
}

void dfs(int i) {
	vis[i] = 1;
	for(int j=0; j<26; ++j) 
		if(!vis[j] && g[i][j])
			dfs(j);
}

int checkEulerian() {
	int ret = 1, odd_degree = 0;
	for(int i=0;i<26;++i) {
		if(check[i]) {
			if(!vis[i]) { ret = 0; break; }

			int degree = Start[i] - End[i];

			if(odd_degree > 2) { ret = 0; break; }

			if(degree == 0) continue;
			else if(degree == 1 || degree == -1) { odd_degree++; continue; }
			else { ret = 0; break; }
		}
	}

	return ret;
}


int main() {
	int t, n;
	char s[2];
	cin>>t;
	while(t--) {

		init();

		cin>>n;
		for(int i=0;i<n;++i) {
			scanString(s);
			g[s[0]][s[1]] = 1;
			g[s[1]][s[0]] = 1;
			check[s[0]] = check[s[1]] = 1;
			Start[s[0]]++;
			End[s[1]]++;
		}

		dfs(s[1]);

		int res = checkEulerian();

		(res)? puts("Ordering is possible."): puts("The door cannot be opened.");
	}
}

