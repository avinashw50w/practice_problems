/*Given a string of characters , parse the numeric values in it ,add all of them and return the result.
Lot of discussion regarding the various test cases around this question(e.g, handing of -ve numbers , decimals , overflow etc). */
#include <bits/stdc++.h>
using namespace std;

double solve(string s) {

	int n = s.size();
	double ans = 0.0;

	char c;
	int neg = 0;

	for(int i = 0; i < n; ++i) {

		if(isdigit(s[i])) {
			
			if(i > 0 and s[i-1] == '-') neg = 1;

			string num = "";
			while(isdigit(s[i])) {
				num += s[i];
				i++;
			}

			if(s[i] == '.') {
				string decimal = "";
				i++;
				while(isdigit(s[i])) decimal += s[i], i++;

				if(decimal.size() > 0) decimal = "." + decimal;

				num += decimal;
			}

			stringstream ss(num);
			double tmp;
			ss >> tmp;
			if(neg) ans += tmp * (-1);
			else ans += tmp;
		}
	}

	return ans;
}

int main() {

	string s;
	cin>>s;
	cout << solve(s) << endl;
}