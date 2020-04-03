/*Given a network of servers and the connections between them with their latency, find the fastest path for sending a message.

A straight-forward path finding problem. Dijkstra will do and Bellman Ford will get TLE. */

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
#include <queue>
#include <map>
using namespace std;
 
vector<map<int, int> > graph;
 
vector<int> dijkstraD, dijkstraP;
void dijkstra(int s) {
    dijkstraD = vector<int>(graph.size(), numeric_limits<int>::max());
    dijkstraP = vector<int>(graph.size(), -1);
    priority_queue<pair<int, int> > q;
    dijkstraP[s] = -s - 1;
    dijkstraD[s] = 0;
    q.push(make_pair(dijkstraD[s], s));
    while (!q.empty()) {
        pair<int, int> p = q.top();
        q.pop();
        if (dijkstraP[p.second] < 0) {
            dijkstraP[p.second] = -dijkstraP[p.second] - 1;
            for (map<int, int>::iterator itr = graph[p.second].begin();
                itr != graph[p.second].end(); ++itr)
                if (dijkstraP[itr->first] < 0
                && dijkstraD[p.second] + graph[p.second][itr->first] < dijkstraD[itr->first]) {
                    dijkstraP[itr->first] = -p.second - 1;
                    dijkstraD[itr->first] = dijkstraD[p.second] + graph[p.second][itr->first];
                    q.push(pair<int, int>(-dijkstraD[itr->first], itr->first));
                }
        }
    }
}
 
int main() {
    int N, n, m, s, t;
    cin >> N;
    for (int caseI = 0; caseI < N; ++caseI) {
        // input
        cin >> n >> m >> s >> t;
        graph.clear();
        for (int i = 0; i < n; ++i)
            graph.push_back(map<int, int>());
        for (int i = 0, a, b, w; i < m; ++i)
            cin >> a >> b >> w, graph[a][b] = graph[b][a] = w;
        // solve
        dijkstra(s);
        cout << "Case #" << (caseI + 1) << ": ";
        if (dijkstraD[t] == numeric_limits<int>::max())
            cout << "unreachable";
        else
            cout << dijkstraD[t];
        cout << endl;
    }
    return 0;
}