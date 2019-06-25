/*Given a list of ascending three-digits integers representing a binary with the depth smaller than 5. You need to return 
the sum of all paths from the root towards the leaves.
If the depth of a tree is smaller than 5, then this tree can be represented by a list of three-digits integers.
For each integer in this list:
The hundreds digit represents the depth D of this node, 1 <= D <= 4.
The tens digit represents the position P of this node in the level it belongs to, 1 <= P <= 8. 
The position is the same as that in a full binary tree.
The units digit represents the value V of this node, 0 <= V <= 9.
Example 1:
Input: [113, 215, 221]
Output: 12
Explanation: 
The tree that the list represents is:
    3
   / \
  5   1

The path sum is (3 + 5) + (3 + 1) = 12.*/
class Solution {

	map<int, int> tree;

	int sum = 0;

public:
	int findSum(int a[]) {
		int n = sizeof(a)/sizeof(a[0]);

		for(int i = 0; i < n; ++i) {
			int key = a[i] / 10;
			int value = a[i] % 10;

			tree[key] = value;
		}

		traverse(tree[0] / 10, 0);

		return sum;
	}

	void traverse(int key, int preSum) {
		int level = key / 10;
		int pos = key % 10;

		int left = (level + 1) * 10 + ( 2 * pos - 1 );
		int right = (level + 1) * 10 + ( 2 * pos );

		int currSum = preSum + tree[key];

		if(!tree.count(left) and !tree.count(right)) {
			sum += currSum;
			return;
		}

		if(tree.count(left)) traverse(left, currSum);
		if(tree.count(right)) traverse(right, currSum);
	}
};

