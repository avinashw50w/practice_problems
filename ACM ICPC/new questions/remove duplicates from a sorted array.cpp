// Write code to remove duplicates from a sorted array

// eg. 1 1 2 3 4 4 4 5 6 7 7 8 9

vector<int> solve(vector<int> A) {

    int j = 0;

    REP(i, 1, A.size())
        if(A[i] != A[j])
            A[++j] = A[i];

    A.resize(j+1); // now the size of the array is j+1

    return A;
}
