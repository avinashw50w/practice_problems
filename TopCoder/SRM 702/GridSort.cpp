/*      
Charlie has a grid of n rows by m columns. The rows are numbered 0 through n-1 from top to bottom. The columns are numbered 0 through m-1 from left to right.

Each cell of the grid contains a positive integer. The integers in Charlie's grid are a permutation of the numbers 1 through n*m. (I.e., each of these numbers occurs in the grid exactly once.)

Given a grid, its value list is a sequence constructed by listing all values in the grid in row major order. That is, we first list the values in row 0 from left to right, then the values in row 1 from left to right, and so on.

You are given the ints n and m: the dimensions of Charlie's grid. You are also given a int[] grid: the value list for Charlie's grid. (Formally, grid[i*m+j] is the value stored in row i, column j of the grid.)

Charlie can modify his grid in two ways: He may swap any two rows, and he may swap any two columns. Charlie now wonders whether there is a sequence of swaps that would sort his grid - that is, rearrange its elements in such a way that the value list of the new grid will be the ordered sequence (1,2,3,...,n*m).

If it is possible to sort Charlie's grid, return "Possible". Otherwise, return "Impossible".*/

/*we can check that every value in a row has the same value when divided by m and floored, and every value in a column has the same value modulo m.*/

string solve(int n, int m, string grid) {
    for (int i = 0; i < n; ++i) {
        unordered_set<int,int> st;
        for (int j = 0; j < m; ++j)
            st.insert((grid[i*m+j] - 1) / m);

        if (st.size() != 1) return "Impossible";
    }

    for (int j = 0; j < m; ++j) {
        unordered_set<int,int> st;
        for (int i = 0; i < n; ++i)
            st.insert((grid[i*m+j] - 1) % m);

        if (st.size() != 1) return "Impossible";
    }

    return "Possible";
}