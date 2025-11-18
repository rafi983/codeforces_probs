#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, h;
	cin >> n >> h;

	int width = 0;

	for (int i = 0; i < n; i++) {
		int height;
		cin >> height;

		if (height > h) {
			width += 2;
		} else {
			width += 1;
		}
	}

	cout << width << endl;

	return 0;
}

