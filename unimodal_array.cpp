#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int a[100];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int phase = 0;

	for (int i = 1; i < n; i++) {
		if (a[i] > a[i-1]) {
			if (phase >= 1) {
				cout << "NO" << endl;
				return 0;
			}
		} else if (a[i] == a[i-1]) {
			if (phase == 0) {
				phase = 1;
			} else if (phase == 2) {
				cout << "NO" << endl;
				return 0;
			}
		} else {
			if (phase == 2) {
				phase = 2;
			} else {
				phase = 2;
			}
		}
	}

	cout << "YES" << endl;
	return 0;
}

