/*A Range Module is a module that tracks ranges of numbers. Your task is to design and implement the following interfaces in an efficient manner.

addRange(int left, int right) Adds the half-open interval [left, right), tracking every real number in that interval. Adding an interval that partially overlaps with currently tracked numbers should add any numbers in the interval [left, right) that are not already tracked.
queryRange(int left, int right) Returns true if and only if every real number in the interval [left, right) is currently being tracked.
removeRange(int left, int right) Stops tracking every real number currently being tracked in the interval [left, right).
Example 1:
addRange(10, 20): null
removeRange(14, 16): null
queryRange(10, 14): true (Every number in [10, 14) is being tracked)
queryRange(13, 15): false (Numbers like 14, 14.03, 14.17 in [13, 15) are not being tracked)
queryRange(16, 17): true (The number 16 in [16, 17) is still being tracked, despite the remove operation)
Note:

A half open interval [left, right) denotes all real numbers left <= x < right.
0 < left < right < 10^9 in all calls to addRange, queryRange, removeRange.
The total number of calls to addRange in a single test case is at most 1000.
The total number of calls to queryRange in a single test case is at most 5000.
The total number of calls to removeRange in a single test case is at most 1000.*/
class RangeModule {
    map<int, int, greater<int>> mp;
public:
    RangeModule() {
        
    }
    // add range [l..r-1]
    void addRange(int l, int r) {
        // it = first range [a..b] such that a <= r
        for (auto it = mp.lower_bound(r); it != mp.end()
            and max(l, it->first) <= min(r, it->second); it = mp.erase(it)) {
            l = min(l, it->first);
            r = max(r, it->second);
        }
        mp[l] = r;
    }
    // query range [l..r-1]
    // find a range [a..b] in mp such that a <= l and r <= b
    bool queryRange(int l, int r) {
        auto it = mp.lower_bound(l);
        return it != mp.end() and r <= it->second;
    }
    // remove range [l..r-1]
    void removeRange(int l, int r) {
        // it = first range [a..b] such that a < r
        for (auto it = mp.upper_bound(r); it != mp.end()
            and max(l, it->first) < min(r, it->second); ) {
            if (r < it->second) mp[r] = it->second;
            if (it->first < l) it->second = l;
            else it = mp.erase(it);
        }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */