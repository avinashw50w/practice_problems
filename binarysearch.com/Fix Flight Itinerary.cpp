/*You are given a list of uppercase alphabet strings itinerary and a two-dimensional list of 
uppercase alphabet strings edges. itinerary contains the list of airports you visited in order 
but the airport names may be misspelled. Each element in edges contains [source, dest] meaning 
there is a flight that goes from source to dest. Every airport has the same length of 3.

Return the minimum number of characters you can change in itinerary such that the itinerary becomes valid. You can assume that there is a solution.

Constraints

n * m ≤ 200,000 where n is the length of itinerary, m is the length of edges
Example 1
Input
itinerary = ["YYZ", "SFO", "JFK"]
edges = [
    ["YYZ", "SEA"],
    ["SEA", "JAM"],
    ["SEA", "JFL"]
]
Output
3
Explanation
We change "SFO" to "SEA" for 2 character changes and "JFK" to 'JFL" for 1 character change. In total, we made 3 character changes.*/
int diff(string a, string b) {
    int cnt = 0;
    for (int i = 0; i < a.length(); ++i) {
        cnt += a[i] != b[i];
    }
    return cnt;
}

int solve(vector<string>& itinerary, vector<vector<string>>& edges) {
    // get all unique nodes
    set<string> st;
    vector<string> nodes;
    for (auto edge : edges) {
        st.insert(edge[0]);
        st.insert(edge[1]);
    }
    for (string node: st) nodes.push_back(node);

    int n = itinerary.size(), m = nodes.size();
    // assign a unique integer to each node
    unordered_map<string,int> id;
    for (int i = 0; i < m; ++i) id[nodes[i]] = i;

    // create adj list
    vector<int> adj[m];
    for (auto edge : edges) {
        adj[id[edge[0]]].push_back(id[edge[1]]);
    }

    const int inf = 1e9 + 7;
    // dp[i][j] - min changes for itinerary upto i when i is changed to j
    vector<vector<int>> dp(n+1, vector<int>(m, inf));

    for (int i = 0; i < m; ++i) 
        dp[1][i] = diff(itinerary[0], nodes[i]);

    for (int i = 1; i < n; ++i) {
        for (int curr = 0; curr < m; ++curr) {
            for (int next : adj[curr]) {
                dp[i+1][next] = min(dp[i+1][next], 
                dp[i][curr] + diff(itinerary[i], nodes[next]));
            }
        }
    }

    int ans = inf;
    for (int i = 0; i < m; ++i) {
        ans = min(ans, dp[n][i]);
    }

    return ans;
}