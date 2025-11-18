#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;

		int size = 2 * n + 1;

		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				int d = abs(i - n) + abs(j - n);
				cout << ((d % 3 == 0) ? 'b' : 'w');
			}
			cout << '\n';
		}
	}

	return 0;
}

