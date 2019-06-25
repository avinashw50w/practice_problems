/*Sean invented a game involving a 2n x 2n matrix where each cell of the matrix contains an integer. 
He can reverse any of its rows or columns any number of times, 
and the goal of the game is to maximize the sum of the elements in the n x n submatrix 
located in the upper-left corner of the 2n x 2n matrix 
(i.e., its upper-left quadrant).

Given the initial configurations for q matrices, help Sean reverse the rows and columns of each matrix 
in the best possible way so that the sum of the elements in the matrix's upper-left quadrant is maximal. 
For each matrix, print the maximized sum on a new line.*/
const int N = 512;

int mat[N][N];
int test;
int n;
int r1, c1, r2, c2;

int main() {
    cin >> test;
    for(int cas = 1; cas <= test; cas ++) {
        cin >> n;
        for(int i = 0; i < 2*n; i ++)
            for(int j = 0; j < 2*n; j ++)
                cin >> mat[i][j];

        int sum = 0;
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j ++) {
                r1 = i;
                r2 = 2*n-i-1;
                c1 = j;
                c2 = 2*n-j-1;
                sum += max(
                    max(mat[r1][c1], mat[r1][c2]),
                    max(mat[r2][c1], mat[r2][c2])
                );
            }
        cout << sum << endl;
    }

    return 0;
}