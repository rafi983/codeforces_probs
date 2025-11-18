#include <iostream>
#include <cstdint>
using namespace std;

typedef unsigned long long ull;

static ull gcd_ull(ull a, ull b) {
	while (b) {
		ull t = a % b;
		a = b;
		b = t;
	}
	return a;
}

static bool is_prime_ull(ull x) {
	if (x < 2) return false;
	if (x % 2ULL == 0ULL) return x == 2ULL;
	for (ull d = 3ULL; d * d <= x; d += 2ULL) {
		if (x % d == 0ULL) return false;
	}
	return true;
}

static ull next_prime_after(ull p) {
	if (p < 2ULL) return 2ULL;
	ull x = p + 1ULL;
	if (x % 2ULL == 0ULL) x++;
	while (!is_prime_ull(x)) x += 2ULL;
	return x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		ull g = 0ULL;
		for (int i = 0; i < n; ++i) {
			ull a;
			cin >> a;
			if (g == 0ULL) g = a;
			else g = gcd_ull(g, a);
		}

		ull p = 2ULL;
		while (g % p == 0ULL) {
			p = next_prime_after(p);
		}

		cout << p << endl;
	}

	return 0;
}

