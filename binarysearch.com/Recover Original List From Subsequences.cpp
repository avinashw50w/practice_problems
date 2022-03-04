/*Given a two-dimensional list of integers lists, where each list is a subsequence of an 
original list, return the original list. The original list contains unique numbers. There is 
guaranteed to be one unique solution.

Constraints

n * m ≤ 100,000 where n and m are the number of rows and columns in lists
Example 1
Input
lists = [
    [1, 3],
    [2, 3],
    [1, 2]
]
Output
[1, 2, 3]
IDEA: We can treat this problem as a sorting problem - we know that for some pairs of values x 
and y, x must appear before y - what ordering respects these constraints?

More specifically, if we construct a graph where each number correspond to a vertex and we have 
a directed edge from x to y if and only if, in some list, x appears directly beforey, then we 
can run topological sort on this directed graph in order to extract the original ordering.

Implementation
We construct the graph as follows - we loop over each list and throw all the numbers we see into 
an unordered_set. We loop over all pairs of elements and write in a directed edge for all pairs 
(x, y) where x appears directly before y. We also keep track of how many unprocessed parent 
vertices a current vertex has to process in numParents.

After that, we run topological sort. We loop over all vertices to find any that do not have any 
unprocessed parent vertices. After that, we scan over the vertices and "process" them by 
decrementing the number of unprocessed parent vertices for each child vertex - if a child vertex 
has no more unprocessed parent nodes, then it is eligible to be enqueued.
*/
vector<int> solve(vector<vector<int>>& lists) {
    unordered_map<int, vector<int>> adj;
    unordered_set<int> nodes;
    unordered_map<int, int> in;

    for (auto list: lists) {
        nodes.insert(list[0]);
        for (int i = 1; i < list.size(); ++i) {
            nodes.insert(list[i]);
            in[list[i]]++;
            adj[list[i-1]].push_back(list[i]);
        }
    }

    vector<int> res;

    for (int u: nodes) {
        if (in[u] == 0) res.push_back(u);
    }

    for (int i = 0; i < res.size(); ++i) {
        int u = res[i];
        for (int v: adj[u]) {
            --in[v];
            if (in[v] == 0) res.push_back(v);
        }
    }

    return res;
}
