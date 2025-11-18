#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, d;
	cin >> n >> d;

	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		if (x + y >= d && x - y <= d && x + y <= 2*n - d && y - x <= d) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	return 0;
}

