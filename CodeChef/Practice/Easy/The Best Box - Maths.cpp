#include <cstdio>
#include <cstdlib>
#include <cmath>


using namespace std;

// Formula: V = P^3/1728 - P(P^2/24-S)/24 + Sqrt(P^2/24-S)^3 * Sqrt(6)/18
int main() {
	int t, p, s;
	scanf("%d", &t);

	while(t--) {
		scanf("%d %d", &p, &s);

		float x = pow(p, 2)/24.0 - s;

		float ans = pow(p, 3)/1728.0 - p*x/24.0 + sqrt(pow(x, 3)) * sqrt(6) / 18.0;

		printf("%.2f", ans);
	}
}