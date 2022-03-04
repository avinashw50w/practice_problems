/*You are given a two-dimensional list of integers transfers containing [source, dest, amount], 
which means that person source lent person dest a dollar amount equal to amount. Return the 
minimum number of person-to-person transfers that are required so that all debts are paid.

Constraints

n ≤ 13 where n is the number of participants
Example 1
Input
transfers = [
    [0, 1, 50],
    [1, 2, 50]
]
Output
1
Explanation
Person 0 gave person 1 $50 and person 1 gave person 2 $50.
So person 2 can directly give $50 to person 0.

IDEA: store the debts of each person and do backtracking to resolve the debts to 0
in the eg. above, the debts of all the persons 0, 1 and 2 are:
0 : -50
1 : 50   
1 : -50 
2 : 50
overall 0 : -50, 1: 0, 2: 50
*/

int dfs(vector<int> &balance, int pos) {
    if (pos == balance.size()) return 0;
    int curr = balance[pos];

    if (curr == 0) return dfs(balance, 1 + pos);

    int ret = INT_MAX;
    
    for (int i = pos + 1; i < balance.size(); ++i) {
        int next = balance[i];
        if (curr * next < 0) {
            balance[i] = curr + next;
            ret = min(ret, 1 + dfs(balance, pos + 1));
            balance[i] = next;
        }
        if (curr + next == 0) break;
    }
    return ret;
}

int solve(vector<vector<int>>& transfers) {
    unordered_map<int, int> mp;
    for (auto transfer: transfers) {
        mp[transfer[0]] -= transfer[2];
        mp[transfer[1]] += transfer[2];
    }

    vector<int> balance;
    for (auto p: mp) {
        balance.push_back(p.second);
    }

    int bal = 0;
    return dfs(balance, 0);
}