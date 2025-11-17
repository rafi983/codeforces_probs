#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		long long x, n;
		cin >> x >> n;

		long long limit = x / n;
		long long best = 1;

		for (long long i = 1; i * i <= x; ++i) {
			if (x % i == 0) {
				if (i <= limit && i > best) {
					best = i;
				}
				long long pair = x / i;
				if (pair <= limit && pair > best) {
					best = pair;
				}
			}
		}

		cout << best << '\n';
	}

	return 0;
}

