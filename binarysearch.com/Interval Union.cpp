/*Given a two-dimensional integer list intervals representing unsorted inclusive intervals, return their union in sorted order.

Constraints

n ≤ 100,000 where n is the length of intervals
Example 1
Input
intervals = [
    [0, 5],
    [4, 6]
]
Output
[
    [0, 6]
]*/
vector<vector<int>> solve(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> st;
    st.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); ++i) {
        auto top = st.back();
        // prev end < curr start => no overlapping => include in set
        if (top[1] < intervals[i][0]) 
            st.push_back(intervals[i]);
        // prev end < curr end => overlapping => update prev end and store in set
        else if (top[1] < intervals[i][1]) {
            top[1] = intervals[i][1];
            st.pop_back();
            st.push_back(top);
        }
    }
    return st;
}