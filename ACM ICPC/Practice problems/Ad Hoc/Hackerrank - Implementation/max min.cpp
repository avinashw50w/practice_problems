#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;
 
int main() {
    /* The code required to enter n,k, candies is provided*/
 
    int N, K, unfairness = std::numeric_limits<int>::max();
    cin >> N >> K;
    int candies[N];
    for (int i=0; i<N; i++)
        cin >> candies[i];
     
    sort(candies, candies + N);
         
    for (int i=0; i < N - K + 1; i++){
        unfairness = min(unfairness, candies[i+K-1] - candies[i]);
    }
     
    cout << unfairness << "\n";
    return 0;
}
