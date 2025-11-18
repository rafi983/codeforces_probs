#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	int a[105], b[105];
	int max_a = 0, min_a = 101;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] > max_a) max_a = a[i];
		if (a[i] < min_a) min_a = a[i];
	}

	int min_b = 101;
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
		if (b[i] < min_b) min_b = b[i];
	}

	int v = max_a;
	if (2 * min_a > v) v = 2 * min_a;

	if (v < min_b) {
		cout << v << endl;
	} else {
		cout << -1 << endl;
	}

	return 0;
}

