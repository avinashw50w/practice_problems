
/*Determining the inconsistently weighted object
Given N objects numbered from 1 to N out of which all are of the same weights except only one object which is not 
known beforehand. We are also given Q comparisons, in each of which an equal number of objects are placed on both sides 
of a balance scale, and we are told the heavier side.

The task is to find the inconsistently weighted object or determine if the data is not sufficient enough.

Examples:

Input : N = 6
Q = 3
1 2 = 5 6
1 2 3 > 4 5 6
3 4 < 5 6
Output : 4
Explanation: Object 4 is lighter than all other objects.

Input : N = 10
Q = 4
1 2 3 4 < 7 8 9 10
1 = 9
2 3 4 > 1 5 10
6 = 2
Output : Insufficient data
Recommended: Please try your approach on {IDE} first, before moving on to the solution.


It is told that except only one element, the rest of the elements are of the same weights. 
So, if we observe carefully, it can be said that:

In a ‘=’ comparison, none of the objects on both sides is the inconsistently weighted one.
If an object appears on the heavier side in one comparison and on the lighter side in another, 
then it is not the inconsistently weighted object. This is because, if an object appears on 
the heavier side then it is of the maximum weight and if it appears on the lighter side then it is 
of the minimum weight. Since a single element can’t be both maximum and minimum at the same time. So, this case will never occur.
The inconsistently weighted object must appear in all of the non-balanced (‘>’ or ‘<') comparisons.
We can use the above three observations to narrow down the potential candidates for the inconsistently weighted object. 
We will consider only those objects which are either on the heavier side or the lighter side; if there is only one 
such object then it is the required one. If there is no such object, then we will consider all those objects which 
do not appear in any comparison. If there is only one such object then it is the inconsistently weighted object. 
If none of these scenarios arises, the data is insufficient.*/

#include <bits/stdc++.h>
using namespace std;

int N;

struct Comparison {
	vector<int> a;
	char comp;
	vector<int> b;
};

vector<int> _union(vector<int> A, vector<int> B) {
	vector<int> res;
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int n = A.size(), m = B.size();
	int i = 0, j = 0;

	while(i < n and j < m) {

		if (A[i] == B[j]) {
			i++; j++;
		}
		else if (A[i] < B[j]) res.push_back(A[i++]);
		else res.push_back(B[j++]);
	}

	while(i < n) res.push_back(A[i++]);
	while(j < m) res.push_back(B[j++]);

	return res;
}

vector<int> intersection(vector<int> A, vector<int> B) {
	vector<int> res;
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int n = A.size(), m = B.size();
	int i = 0, j = 0;

	while(i < n and j < m) {

		if (A[i] == B[j]) {
			res.push_back(A[i++]);
			res.push_back(B[j++]);
		}
		else if (A[i] < B[j]) i++;
		else j++;
	}

	return res;
}

vector<int> difference(vector<int> A, vector<int> B) {
	vector<int> res;

	set<int> a(A.begin(), A.end());
	set<int> b(B.begin(), B.end());
	set<int> c;

	for (auto i: a)
		if (b.count(i) == 0) c.insert(i);

	for (auto i: c) res.push_back(i);

	return res;
}

int getInconsistentlyObject(vector<Comparison> comparisons) {

	vector<int> equalObj(N), lesserObj(N), greaterObj(N), objNotCompared(N);

	for (int i = 0; i < N; ++i) {
		lesserObj[i] = i+1;
		greaterObj[i] = i+1;
		objNotCompared[i] = i+1;
	}

	for (auto c: comparisons) {
		vector<int> left = c.a;
		vector<int> right = c.b;

		objNotCompared = difference(objNotCompared, _union(left, right));

		if (c.comp == '=')
			equalObj = _union(equalObj, _union(left, right));
		else if (c.comp == '>') {
			lesserObj = intersection(lesserObj, right);
			greaterObj = intersection(greaterObj, left);
		}
		else {
			lesserObj = intersection(lesserObj, left);
		}	greaterObj = intersection(greaterObj, right);
	}

	vector<int> possAns = difference(_union(greaterObj, lesserObj), equalObj);

	if (possAns.size() == 1) {
		return possAns[0];
	} 
	else if (objNotCompared.size() == 1) {
		return objNotCompared[0];
	}
	else return -1;
}

int main() {

	N = 6;

	vector<Comparison> c(3);
	c[0] = {
		{1, 2}, '=', {5, 6}
	};

	c[1] = {
		{1, 2, 3}, '>', {4, 5, 6}
	};

	c[2] = {
		{3, 4}, '<', {5, 6}
	};
	
	cout << getInconsistentlyObject(c);
}