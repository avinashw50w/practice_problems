#include <iostream>
using namespace std;

int main() {
    int n,t; string s; cin >> n >> t;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'B') {
            int j = 0;
            while(j <= t and s[i+j] == 'G') j++;
            swap(s[i], s[i+j-1]);
        }
    }

    cout << s << endl;
}