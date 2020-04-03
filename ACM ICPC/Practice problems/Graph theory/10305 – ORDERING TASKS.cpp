/*Given a set of dependent tasks, find the order in which these tasks have to be executed.

The solution is found via a topological sort. */

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
#include <queue>
#include <map>
using namespace std;
 
vector<map<int, int> > graph;
vector<int> sortedNodes;
 
void topSort() {
    sortedNodes.clear();
    vector<int> inDegree = vector<int>(graph.size(), 0);
    for (size_t i = 0; i < graph.size(); ++i)
        for (map<int, int>::iterator itr = graph[i].begin(); itr != graph[i].end(); ++itr)
            ++inDegree[itr->first];
    queue<int> q;
    for (size_t i = 0; i < graph.size(); ++i)
        if (inDegree[i] == 0)
            q.push(i);
    while (q.size()) {
        int p = q.front();
        sortedNodes.push_back(p), q.pop();
        for (map<int, int>::iterator itr = graph[p].begin(); itr != graph[p].end(); ++itr)
            if (!(--inDegree[itr->first]))
                q.push(itr->first);
    }
}
 
int main() {
    int n, m;
    while (cin >> n >> m && (n || m)) {
        // input
        graph.clear();
        for (int i = 0; i < n; ++i)
            graph.push_back(map<int, int>());
        for (int i = 0, x, y; i < m; ++i)
            cin >> x >> y, --x, --y, graph[x][y] = 1;
        // solve
        topSort();
        cout << (sortedNodes[0] + 1);
        for (int i = 1; i < n; ++i)
            cout << " " << (sortedNodes[i] + 1);
        cout << endl;
    }
    return 0;
}