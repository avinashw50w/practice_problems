#include <iostream>
using namespace std;

bool isBeautiful(int n) {
    int f[10] = {};
    while(n) {
        if (f[n%10]) return false;
        f[n%10] = 1;
        n /= 10;
    }
    return true;
}

int main() {
    int n; cin >> n;
    for (int i = n+1; i < 1e4; ++i)
        if (isBeautiful(i)) {
            cout << i << endl;
            break;
        } 
}