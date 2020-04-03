// We will be solving this challenge in ~12.10 IST. Meanwhile you can go through
// the statement.  
/* 
Hi, Abhiranjan here (https://www.hackerrank.com/abhiranjan). I will be solving today's challenge.

There were few requests regarding language limitations. Therefore I have duplicated this challenge
in our algo section (https://www.hackerrank.com/challenges/matrix-rotation-algo). Feel free to submit
there in any language.

As most of the people are not that comfortable with haskell, or another fp (functional programming)
language, I will be solving this in C++.

This challenge was originally used in one of the FP contests (https://www.hackerrank.com/lambda-calculi-jul14).
Since I was the tester/editorialist of this challenge, I will use some of the tid-bits from there itself.
*/

/*
[Editorial]

Suppose we have following 4x5 matrix.

    a11  a12  a13  a14  a15

    a21  a22  a23  a24  a25

    a31  a32  a33  a34  a35

    a41  a42  a43  a44  a45

In order to rotate it, we create strips of various levels. In the above example 3 strips will be created and they are as follows.
Outer strip:

    a11  a12  a13  a14  a15

    a21                 a25

    a31                 a35

    a41  a42  a43  a44  a45

->

    a11 <- a12 <- a13 <- a14 <- a15 <- a25 <- a35 <- a45 <- a44 <- a43 <- a42 <- a41 <- a31 <- a21

Inner strip:

    a22  a23  a24

    a32  a33  a34

->

    a22 <- a23 <- a24 <- a34 <- a33 <- a32
    
Since R can be very large, we will rotate each strip, of length k, by R%k times. After rotating each strips we will recreate the original matrix.
Let's rotate above strip by one step, R = 1, and the creating the matrix will involve the following steps.

Outer strip:

    a12 <- a13 <- a14 <- a15 <- a25 <- a35 <- a45 <- a44 <- a43 <- a42 <- a41 <- a31 <- a21 <- a11

->

    a12  a13  a14  a15  a25

    a11                 a35

    a21                 a45

    a31  a41  a42  a43  a44


Inner strip:

    a23 <- a24 <- a34 <- a33 <- a32 <- a22

->

     a23  a24  a34

     a22  a32  a33
     
So the final configuration of the above matrix after 1 rotation will be:

    a12  a13  a14  a15  a25

    a11  a23  a24  a34  a35

    a21  a22  a32  a33  a45

    a31  a41  a42  a43  a44
*/

 
#include <bits/stdc++.h>
using namespace std;

/*
So, this challenge can be broken into following parts:
1. Seperate each strip/layers from the original matrix.
2. Rotate each strip by R times.
3. Reformulate the matrix from the strip.

*/

typedef pair<int, int> coord;   // Defining a new type to represent each coordinates

int M, N, R;

void addLayer(vector<coord> &layer, int r, int c, int len, int rAdd, int cAdd) {
    while(len-- > 0) {
        layer.push_back(make_pair(r, c));
        r += rAdd;
        c += cAdd;
    }
}

// `rotate` function will read a MxN matrix and rotate it by R times.
vector<vector<int>> rotate(vector<vector<int>> matrix) {
    vector<vector<int>> ret(M, vector<int>(N));
    
    // Since minimum of `M` and `N` is even, it is guaranteed that there will be
    // `min(M, N)/2` layers.
    int nLayers = min(M, N)/2;
    
    // Now, we will rip all the strips. The i = 0 represents the first strip,
    // i = 1 represents second, and so on.
    
    int m = M, n = N;
    for(int i = 0; i < nLayers; i++) {
        vector<coord> strip;

        // Top layer
        int r = i, c = i;
        addLayer(strip, r, c, n-1, +0, +1);
       
        // Right layer
        r = strip.back().first;
        c = strip.back().second+1;
        addLayer(strip, r, c, m-1, +1, +0);

        // Bottom layer
        r = strip.back().first+1;
        c = strip.back().second;
        addLayer(strip, r, c, n-1, 0, -1);
        
        // Left layer
        r = strip.back().first;
        c = strip.back().second-1;
        addLayer(strip, r, c, m-1, -1, 0);

        // Checking
        /*
        for(auto x: strip)
            printf("(%d, %d) ", x.first, x.second);
        cout << endl;
        */
        
        int sz = strip.size();
        for(int id = 0; id < sz; id++) {
            int r1 = strip[id].first, c1 = strip[id].second;
            int r2 = strip[(id+R)%sz].first, c2 = strip[(id+R)%sz].second;
            ret[r1][c1] = matrix[r2][c2];
            //printf("[(%d, %d) <- (%d, %d): %d], ", r1, c1, r2, c2, ret[r1][c1]);
        }
        //cout << endl << endl;
        
        m -= 2;
        n -= 2;
    }

    return ret;
}

int main()
{
    // Reading the matrix.
    cin >> M >> N >> R;
    vector < vector<int> > matrix(M, vector<int>(N));
    
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }
    
    vector<vector<int> > ans = rotate(matrix);
    
    // Procedure to print output
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
