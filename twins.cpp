#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> coins(n);
	int totalSum = 0;

	for (int i = 0; i < n; i++) {
		cin >> coins[i];
		totalSum += coins[i];
	}

	sort(coins.begin(), coins.end(), greater<int>());

	int mySum = 0;
	int coinsCount = 0;

	for (int i = 0; i < n; i++) {
		mySum += coins[i];
		coinsCount++;

		int twinSum = totalSum - mySum;
		if (mySum > twinSum) {
			break;
		}
	}

	cout << coinsCount << endl;

	return 0;
}

