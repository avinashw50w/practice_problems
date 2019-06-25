/*Given n positive real numbers, find whether there exists a triplet among this set such that, the sum of the triplet is in the range (1, 2). 
Do it in linear time and O (1) space.

Consider the following buckets: (0..0.5), [0.5..1), [1..2), [2..inf). 
Obviously, we ignore numbers in [2..inf). 

Now basically we need to treat all cases of choosing 3 numbers from the 3 buckets. 

We only need to look at the following cases (the other cases are "worse" or are covered by these): 
1. If possible, choose the smallest element from bucket [1..2) => for the 2nd and 3rd we need to take the smallest 2 elements available. 
If sum < 2 then return true. 

2. If possible, choose the two smallest elements from bucket [0.5 .. 1) => for the 3rd we need to take the smallest element available. 
If sum < 2 then return true; 

3. If possible, choose the highest element from bucket [0.5 .. 1) => if possible, for the 2nd and 3rd take the highest and 
the second highest from bucket (0 .. 0.5). If sum > 1 then return true. 

4. If possible, choose the highest 3 elements from bucket (0..0.5). If sum > 1 then return true. 

If none of the cases above found a solution then return false. 

Space complexity: O(1), you don't need to explicitly store numbers in buckets. 
Time complexity: each operation (e.g.: find smallest element from bucket [1..2), etc.) can be done in O(N). 
There is a constant number of these operations => overall complexity O(N) 

LATER EDIT: 

Since the answer was down-graded without any question or explanation why it would be wrong, here is the 
actual code and the associated tests. Hopefully I didn't forget any relevant test case. 

The code could be optimized more and be more condensed, but I tried to make it as clear as possible 
(regarding to the explanations above and the space and time requirements).*/

const float INF = 1000;

bool inInterval(float x, float st, float end) { return x >= st && x < end; }

bool findFirstSmallest(const vector<float>& a, float start, float end, float &res) {
    int found = 0;

    res = INF;
    for (int i = 0; i < a.size(); ++i)
        if (inInterval(a[i], start, end)) {
            ++found;
            res = min(res, a[i]);
        }

    return found >= 1;
}

bool findFirstHighest(const vector<float>& a, float start, float end, float &res) {
    int found = 0;

    res = -INF;
    for (int i = 0; i < a.size(); ++i)
        if (inInterval(a[i], start, end)) {
            ++found;
            res = max(res, a[i]);
        }

    return found >= 1;
}

bool findSecondSmallest(const vector<float>& a, float start, float end, float &res) {
    int found = 0;

    float first = INF, second = INF;

    for (int i = 0; i < a.size(); ++i)
        if (inInterval(a[i], start, end)) {
            ++found;
            if (a[i] <= first) {
                second = first;
                first = a[i];
            } else if (a[i] <= second)
                second = a[i];
        }

    res = second;
    return found >= 2;
}

bool findSecondHighest(const vector<float>& a, float start, float end, float &res) {
    int found = 0;

    float first = -INF, second = -INF;

    for (int i = 0; i < a.size(); ++i)
        if (inInterval(a[i], start, end)) {
            ++found;
            if (a[i] >= first) {
                second = first;
                first = a[i];
            } else if (a[i] >= second)
                second  = a[i];
        }

    res = second;
    return found >= 2;
}

bool findThirdSmallest(const vector<float>& a, float start, float end, float &res) {
    int found = 0;

    float first = INF, second = INF, third = INF;

    for (int i = 0; i < a.size(); ++i)
        if (inInterval(a[i], start, end)) {
            ++found;
            if (a[i] <= first) {
                third = second;
                second = first;
                first = a[i];
            } else if (a[i] <= second) {
                third = second;
                second  = a[i];
            } else if (a[i] <= third)
                third = a[i];
        }

    res = third;
    return found >= 3;
}

bool findThirdHighest(const vector<float>& a, float start, float end, float &res) {
    int found = 0;

    float first = -INF, second = -INF, third = -INF;

    for (int i = 0; i < a.size(); ++i)
        if (inInterval(a[i], start, end)) {
            ++found;
            if (a[i] >= first) {
                third = second;
                second = first;
                first = a[i];
            } else if (a[i] >= second) {
                third = second;
                second  = a[i];
            } else if (a[i] >= third)
                third = a[i];
        }

    res = third;
    return found >= 3;
}

bool solve(const vector<float>& a, float& x, float &y, float& z) {
   if (findFirstSmallest(a, 1, 2, x) && 
       findFirstSmallest(a, 0, 1, y) &&
       findSecondSmallest(a, 0, 1, z))
        if (x + y + z < 2) return true;

   if (findFirstSmallest(a, 0.5, 1, x) &&
       findSecondSmallest(a, 0.5, 1, y) &&
       (findFirstSmallest(a, 0, 0.5, z) || findThirdSmallest(a, 0.5, 1, z) ))
        if (x + y + z < 2) return true;

   if (findFirstSmallest(a, 0.5, 1, x) &&
       findFirstHighest(a, 0, 0.5, y) &&
       findSecondHighest(a, 0, 0.5, z))
        if (x + y + z >= 1) return true;

   if (findFirstHighest(a, 0, 0.5, x) &&
       findSecondHighest(a, 0, 0.5, y) &&
       findThirdHighest(a, 0, 0.5, z))
        if (x + y + z >= 1) return true;

   return false;
}

void test(const vector<float>& a) {
    cout << "Test: ";
    copy(a.begin(), a.end(), ostream_iterator<float>(cout, " "));
    cout << endl;

    float x, y, z;
    if (solve(a, x, y, z))
        cout << "Solution: " << x << " " << y << " " << z << endl;
    else
        cout << "Solution not found!" << endl;

    cout << endl;
}

#define arrSize(a) (sizeof(a) / sizeof(a[0]))

int main() {
    float test1[] = {0.1, 0.2, 0.2, 0.3, 2.0, 3.0};
    test(vector<float>(test1, test1 + arrSize(test1)));

    float test2[] = {0.1, 0.3, 0.3, 0.4, 2.0, 3.0};
    test(vector<float>(test2, test2 + arrSize(test2)));

    float test3[] = {0.1, 0.1, 0.2, 0.6, 2.0, 3.0};
    test(vector<float>(test3, test3 + arrSize(test3)));

    float test4[] = {0.5, 0.6, 0.6, 2.0, 3.0};
    test(vector<float>(test4, test4 + arrSize(test4)));

    float test5[] = {0.6, 0.6, 2.0, 3.0};
    test(vector<float>(test5, test5 + arrSize(test5)));

    float test6[] = {0.6, 0.6, 1.0, 2.0, 3.0};
    test(vector<float>(test6, test6 + arrSize(test6)));

    float test7[] = {0.1, 0.2, 0.5, 1.0, 2.0, 3.0};
    test(vector<float>(test7, test7 + arrSize(test7)));

    float test8[] = {0.1, 0.7, 0.6, 1.0, 2.0, 3.0};
    test(vector<float>(test8, test8 + arrSize(test8)));

    float test9[] = {0.5, 0.5, 0.6, 1.0, 2.0, 3.0};
    test(vector<float>(test9, test9 + arrSize(test8)));

    float test10[] = {1.6, 1.2, 1.0, 2.0, 3.0};
    test(vector<float>(test10, test10 + arrSize(test10)));

    return 0;
}

