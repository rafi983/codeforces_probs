#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		vector<int> a(n), b(n);

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}

		sort(a.begin(), a.end());
		sort(b.begin(), b.end(), greater<int>());

		for (int i = 0; i < n && i < k; i++) {
			if (b[i] > a[i]) {
				swap(a[i], b[i]);
			} else {
				break;
			}
		}

		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += a[i];
		}

		cout << sum << endl;
	}

	return 0;
}

