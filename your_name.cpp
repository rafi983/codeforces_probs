#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int q;
	cin >> q;

	while (q--) {
		int n;
		string s, t;
		cin >> n >> s >> t;

		if (s.length() != n || t.length() != n) {
			cout << "NO" << endl;
			continue;
		}

		int cntS[26] = {0}, cntT[26] = {0};
		for (int i = 0; i < n; ++i) {
			cntS[s[i] - 'a']++;
			cntT[t[i] - 'a']++;
		}

		bool ok = true;
		for (int i = 0; i < 26; ++i) {
			if (cntS[i] != cntT[i]) {
				ok = false;
				break;
			}
		}

		cout << (ok ? "YES" : "NO") << endl;
	}

	return 0;
}

