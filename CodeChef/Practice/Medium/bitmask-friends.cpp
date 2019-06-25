/*After IOI Ilya decided to make a business. He found a social network called "TheScorpyBook.com". It currently has N registered users. As in any social network 
two users can be friends. Ilya wants the world to be as connected as possible, so he wants to suggest friendship to some pairs of users. He will suggest user 
u to have a friendship with user v if they are not friends yet and there is a user w who is friends of both of them. Note that u, v and w are different users. 
Ilya is too busy with IPO these days, so he asks you to count how many friendship suggestions he has to send over his social network.

 

Input

The first line contains an integer number N — the number of users in the network. Next N lines contain N characters each denoting friendship relations. 
jth character if the ith lines equals one, if users i and j are friends and equals to zero otherwise. This relation is symmetric, i.e. if user a is friend of b 
then b is also a friend of a.

 

Output

Output a single integer — number of friendship suggestions Ilya has to send.

 

Constraints

1 ≤ N ≤ 2000
 

Example

Input:
4
0111
1000
1000
1000

Output:
6
 

Explanation

Each of users [2, 3, 4] should receive two friendship suggestions, while user 1 does not need any, since he already has all other users in his friend-list*/
/*PROBLEM:
Find out number of pairs of vertices u, v which are connected to each other not directly by an edge but by another vertex w such that w is a neighbour of both u and v.

Explanation
NOTE: I have done a slight experiment in the editorial. The editorial is presented as a process of two persons asking each other questions and solving the problem with help of each other. First person's words are written in italic while that of second are in normal text.

Hey, I am not able to figure out anything. What is the trivial algorithm that I can have here?

As n <= 2000. O(n^3) is a trivial algorithm. For each pair of vertices u, v not having an edge between them, we will find the vertices which are neighbour of both u and v. Let set neigh[u] denotes the neighbours of u except v. Similarly set neigh[v] denotes of v except u. Checking whether u and v are connected is same as checking whether intersection of set neigh[u] and neigh[v] is empty or not. We can implement this intersection step in O(n) easily.

Oh, yes, I got it. Can we do it faster?

Yes, Note that for each set neigh[v], we need to maintain binary n values, i^th of them represents whether the vertex u have an edge with vertex v.

Can we make use of the fact that the values in the set are binary, can we somehow reduce the size of set and represent the information more succinctly?.

Yes, As each of the value is binary, we can store them ceil(n / 32) groups where each group is of integer data type. Note that we are here making use of bits to encode the information of set in compressed form.

Note the size of each set will reduce by a factor of 32 (as integer data type has size 4 bytes = 32 bits).

Now you need to check whether two sets intersect or not.

I think that we can make use of bitwise operations for this.

Yes, Finding whether intersection of sets represented by two integers x and y is empty or not, can be done by checking their bitwise AND. If their bitwise AND is non-zero, they have an intersection, otherwise not.

ANOTHER SOLUTION
Let us try to think in terms of powers of adjacency matrices. I think it can help us. What does i,j th element of powers of adjacency matrix denote?

As the entries of the adjacency matrix gives you the connections between the vertices. If you take powers of adjacency matrix, then you are really combining the walks. So the i,j th entry of the k^th power of the adjacency matrix tells you the number of walks of length k from vertex i to vertex j.

I understood it, but Where is the proof?

You can prove it using induction. To form a walk of length k+1 from vertex i to j, you must first have a walk of length k from vertex i to some vertex v and then a walk of length 1 from vertex v to vertex j.

Now relate these terms with matrix powers and you are done :)

How can powers help me here? I am not able to exactly formulate this.

You can note that i, j th entry of square of adjacency matrix will denote the number of walks of length 2 from vertex i to vertex j. So you can notice that if i,j the entry is non-zero, then we can say that vertex i and j are connected with each other by another vertex w.

I can do the matrix multiplication of two square matrices of dimension n in O(n^3) time, which will get TLE, do you have some faster algorithm??

Well, there is an algorithm called Strassen_algorithm which can solve the problem in O(n log 2 7 ).

Yes, that's cool. :)

In our case, the matirces are boolean matrices, can we somehow compute their product faster?

Fortunately Yes, there is a technique called Method of Four Russians which will help us.*/
int main() {
	#if 0
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int N;
	cin>>N;
	vector<int> v[N+1];
	string s[N+1]; 
	rep(i,0,N) {
		cin>>s[i];
		rep(j,0,s[i].size())
			if(s[i][j] == '1') 
				v[i].push_back(j);
	}

	int cnt = 0;
	rep(i,0,N){
		rep(j,i+1,N) {
			// if i is not connected to j
			if(s[i][j] == '0') {
				// if any neighbour of i is connected to j then increament the counter
				for(auto k: v[i]) {
					if(s[k][j] == '1') { cnt++; break; }
				}
			}
		}
	}
	cout<< ( cnt<<1 ) <<endl;
	return 0;
}
