/*There are 8 prison cells in a row, and each cell is either occupied or vacant.

Each day, whether the cell is occupied or vacant changes according to the following rules:

If a cell has two adjacent neighbors that are both occupied or both vacant, then the cell becomes occupied.
Otherwise, it becomes vacant.
(Note that because the prison is a row, the first and the last cells in the row can't have two adjacent neighbors.)

We describe the current state of the prison in the following way: cells[i] == 1 if the i-th cell is occupied, else cells[i] == 0.

Given the initial state of the prison, return the state of the prison after N days (and N such changes described above.)



Example 1:

Input: cells = [0,1,0,1,1,0,0,1], N = 7
Output: [0,0,1,1,0,0,0,0]
Explanation:
The following table summarizes the state of the prison on each day:
Day 0: [0, 1, 0, 1, 1, 0, 0, 1]
Day 1: [0, 1, 1, 0, 0, 0, 0, 0]
Day 2: [0, 0, 0, 0, 1, 1, 1, 0]
Day 3: [0, 1, 1, 0, 0, 1, 0, 0]
Day 4: [0, 0, 0, 0, 0, 1, 0, 0]
Day 5: [0, 1, 1, 1, 0, 1, 0, 0]
Day 6: [0, 0, 1, 0, 1, 1, 0, 0]
Day 7: [0, 0, 1, 1, 0, 0, 0, 0]

Example 2:

Input: cells = [1,0,0,1,0,0,1,0], N = 1000000000
Output: [0,0,1,1,1,1,1,0] */

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        map<vector<int>, int> mp;
        int cnt = 0;

        for (int i = 0; i < N; ++i) {
            cells = nextRow(cells);

            if (mp.count(cells)) {
                break;
            }

            mp[cells] = i + 1;
            cnt++;
        }

        N -= mp[cells];
        N = cnt > 0 ? (N % cnt) : 0;

        for (int i = 0; i < N; ++i)
            cells = nextRow(cells);

        return cells;
    }

    vector<int> nextRow(vector<int> row) {
        int n = row.size();
        vector<int> tmp(n, 0);
        for (int i = 1; i < n - 1; ++i)
            if (row[i - 1] == row[i + 1])
                tmp[i] = 1;

        return tmp;
    }
};