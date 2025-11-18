#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;

		int freq[26] = {0};
		for (int i = 0; i < s.length(); ++i) {
			int idx = s[i] - 'a';
			if (idx >= 0 && idx < 26) freq[idx]++;
		}

		int pairs = 0;
		int singles = 0;
		for (int i = 0; i < 26; ++i) {
			if (freq[i] >= 2) pairs++;
			else if (freq[i] == 1) singles++;
		}

		int k = pairs + singles / 2;
		cout << k << endl;
	}

	return 0;
}

