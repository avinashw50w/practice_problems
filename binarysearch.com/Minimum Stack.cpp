/*Implement a stack with the following methods:

MinimumStack() constructs a new instance of a minimum stack
append(int val) appends val to the stack
peek() retrieves the last element in the stack
min() retrieves the minimum value in the stack
pop() pops and returns the last element in the stack
Each method should be done in \mathcal{O}(1)O(1) time. You can assume that for peek, min and pop, the stack is non-empty when they are called.

Constraints

n ≤ 100,000 where n is the number of calls to append, peek, min, and pop.
*/
class MinimumStack {
    const int inf = 1e9 + 7;
    stack<array<int,2>> st;
    public:
    MinimumStack() {
    }

    void append(int val) {
        int mn;
        if (st.empty()) mn = val;
        else mn = std::min(val, st.top()[1]);
        st.push({ val, mn });
    }

    int peek() {
        return st.top()[0];
    }

    int min() {
        return st.top()[1];
    }

    int pop() {
        auto top = peek();
        st.pop();
        return top;
    }
};

// another optimised approach
/*although we can implement it with two stack (one for normal operation and one for keeping the 
max so far )  , or a single stack of pairs ({one holding the last element, it's holding the max 
so far.})  , we try it using a single stack with one optimization.

Implementation
Here while pushing a value
we have to check for two cases if the value is less than current minimum we push 
(2*val-current_minimum) ans then we update our current minium with val
else if the val is greater than the current_minimum push it freely
now at the time of popping two case
if the value at s.top() is greater than current_minimum than just pop it freely
else we have to pop of current_minimum but we also have to retrieve our past minimum we can do 
it easily by using (2*mini-s.top()) that is out past minimum*/
class MinimumStack {
    public:
    stack<int> s;
    int mini;
    MinimumStack() {
        mini = -1;
    }

    void append(int val) {
        if (s.empty() || mini == -1) {
            s.push(val);
            mini = val;
        } else if (val < mini) {
            s.push(2 * val - mini);
            mini = val;
        } else {
            s.push(val);
        }
    }
    // it top element is less than mini, then mini store the val
    int peek() {
        if (s.top() < mini) {
            return mini;
        }
        return s.top();
    }

    int min() {
        return mini;
    }

    int pop() {
        if (s.top() < mini) {
            int k = 2 * mini - s.top();
            s.pop();
            int ret = mini;
            mini = k;
            return ret;
        }
        int a = s.top();
        s.pop();
        return a;
    }
};