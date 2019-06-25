/*Cat Noku has just finished writing his first computer program. Noku's computer has m memory cells. The cells have addresses 0 through m-1. Noku's program consists of n instructions. The instructions have mutually independent effects and therefore they may be executed in any order. The instructions must be executed sequentially (i.e., one after another) and each instruction must be executed exactly once.

You are given a description of the n instructions as a String[] with n elements. Each instruction is a String of m characters. For each i, 
character i of an instruction is '1' if this instruction accesses memory cell i, or '0' if it does not.

Noku's computer uses caching, which influences the time needed to execute an instruction. More precisely, executing an instruction takes k^2 
units of time, where k is the number of new memory cells this instruction accesses. (I.e., k is the number of memory cells that are accessed 
by this instruction but have not been accessed by any previously executed instruction. Note that k may be zero, in which case the current 
instruction is indeed executed in 0 units of time.)

Noku's instructions can be executed in many different orders. Clearly, different orders may lead to a different total time of execution. 
Find and return the shortest amount of time in which it is possible to execute all instructions.

 
Definition
    	
Class:	OrderOfOperations
Method:	minTime
Parameters:	String[]
Returns:	int
Method signature:	int minTime(String[] s)
(be sure your method is public)
    
 
Constraints
-	n will be between 1 and 50, inclusive.
-	m will be between 1 and 20, inclusive.
-	s will have exactly n elements.
-	Each element of s will have exactly m characters.
-	Each character of s[i] will be either '0' or '1' for all valid i.
 
Examples
0)	
    	
{
 "111",
 "001",
 "010"
}
Returns: 3
Cat Noku has 3 instructions. The first instruction ("111") accesses all three memory cells. The second instruction ("001") accesses only 
memory cell 2. The third instruction ("010") accesses only memory cell 1. If Noku executes these three instructions in the given order, 
it will take 3^2 + 0^2 + 0^2 = 9 units of time. However, if he executes them in the order "second, third, first", it will take only 
1^2 + 1^2 + 1^2 = 3 units of time. This is one optimal solution. Another optimal solution is to execute the instructions in the order 
"third, second, first".

It's tempting to try a Greedy approach but as the high challenge rate in this problem indicates, it's best not to implement a solution without
a proper proof.

Filling the cache
Imagine the cache already had all memory positions. Then any operation we did would take 0 seconds. So we can consider that the objective 
is to put all the positions in the cache. Once this state is reached, we can assume it costs zero additional seconds to finish any pending operation.

There is a small corner case when using this logic: It might happen that one or more memory positions are never used by any of the operations, 
then we don't need to add them to the cache, but it's safe to ignore those positions altogether.

Adding memory positions
We start with an empty cache and the objective is to fill it with all positions. How do we add positions? Simply run an operation. 
Each of the kk memory positions not in cache is added and the cost is k2k2. The nice thing is that since k≠0k≠0 we can tell that the 
instruction was not executed yet. So we only need to keep track of the cache as a state, we don't need to keep track of which instructions 
we already ran.

Keeping track of only the cache is useful because if you see the contents of the cache as a subset of the mm available positions, we have a 
limit of 2m2m possible states for the cache. mm is at most 20 which suggests that a non-polynomial solution might be used in this problem.

Dynamic programming
Let f(S)f(S) be the minimum cost to fill the cache with all memory positions in set SS. When implementing these ideas in code it is often 
useful to think of bit masks. So the set SS would be represented by a number between 0 and 2m−12m-1 such that its i-th bit is 1 if the i-th 
memory position is in the set. We want to find f(111..11)f(111..11) for the set of all needed memory positions. Initially, we know that f(0)
 (the empty set) is 0, because it costs nothing to start with an empty cache.

We can find the costs to add some new memory positions to the empty set. For each of the nn instructions , find the cost of adding the memory 
positions in that instruction to the cache. As a result you will have candidate f(S)f(S) values for some sets. Pick the smallest set S 
(smallest bit mask that isn&t 0, so for example, 1), once again you can use one of the nn available operations to add memory to a cache 
consisting of SS:

Find the union S'S′ between the old SS and the new positions. (In bit masks this is the binary or.
Count the kk positions in instruction ii that are not in SS. In fact, this is the subtraction between S'S′ and SS. Counting the number of 
bits in the subtraction can be fast using your language's functions or with precalculation.
A candidate cost for S'S′ is: f(S)+k2f(S)+k2
By updating costs iteratively from smaller sets to the larger ones we can find the best cost for the final set. There are O(2m)O(2m) sets 
and for each we need an O(n)O(n) loop to visit all the instructions. Note that this approach is similar to Bellman-Ford.*/

int minTime(vector<string> s)
{
    int fmask = 0;
    int n=s.size(), m = s[0].size();
    // get the bit masks for each instruction and the final needed mask
    vector<int> masks(n);
    for (int i=0; i<n; i++) {
        for (int j = 0; j < m ; j++) {
            if (s[i][j]=='1') {
                masks[i] |= (1 << j);
            }
            fmask |= masks[i];
        }
    }
    // fmask might have some zeros in it. Contains all relevant positions
    // (Some can be irrelevant)
     
    const int INF = 1000000000; 
    vector<int> dist(1 << m, INF);
    dist[0] = 0;
    for (int mask = 0; mask < (1 << m); mask++) {
        for (int i = 0; i < n; i++) {
            // union:
            int nmask = mask | masks[i];
            // set subtraction:
            int emask = nmask - mask;
            int k = __builtin_popcount(emask); //quickly count 1 bits in C
             
            //update as needed:
            dist[nmask] = std::min(dist[nmask], dist[mask] + k*k); 
             
        }
    }
     
    return dist[fmask];
}