/*Implement a hit counter which keeps track of number of the number of hits in the last 60 seconds.

add(int timestamp) which adds timestamp in seconds in the hit counter
count(int timestamp) which returns the number of hits that have been made in the last 60 seconds, given the current time is timestamp.
You can assume that the timestamps passed into add and count are monotonically increasing.

Constraints

n ≤ 100,000 where n is the number of calls that are made to add and count
Example 1
Input
methods = ["constructor", "add", "add", "count", "add", "count"]
arguments = [[], [10], [40], [40], [70], [100]]`
Output
[null, null, null, 2, null, 2]*/
class HitCounter {
    queue<int> q;
    public:
    HitCounter() {
    }

    void add(int timestamp) {
        q.push(timestamp);
    }

    int count(int timestamp) {
        resizeQueue(timestamp);
        return q.size();
    }

    void resizeQueue(int timestamp) {
        while (q.size() and timestamp - q.front() > 60) q.pop();
    }
};