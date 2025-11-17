#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		string s;
		cin >> n >> s;

		vector<int> freq(26, 0);
		for (char c : s) {
			freq[c - 'a']++;
		}

		bool ok = false;
		if (n >= 3) {
			for (int i = 1; i <= n - 2; ++i) {
				if (freq[s[i] - 'a'] >= 2) {
					ok = true;
					break;
				}
			}
		}

		cout << (ok ? "Yes" : "No") << '\n';
	}

	return 0;
}

