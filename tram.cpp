#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int current_passengers = 0;
	int max_capacity = 0;

	for (int i = 0; i < n; i++) {
		int exit, enter;
		cin >> exit >> enter;

		current_passengers -= exit;
		current_passengers += enter;

		if (current_passengers > max_capacity) {
			max_capacity = current_passengers;
		}
	}

	cout << max_capacity << endl;

	return 0;
}

