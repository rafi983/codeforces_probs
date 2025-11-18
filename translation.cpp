#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s, t;
	cin >> s >> t;

	if (s.length() != t.length()) {
		cout << "NO" << endl;
		return 0;
	}

	bool match = true;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] != t[s.length() - 1 - i]) {
			match = false;
			break;
		}
	}

	if (match) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

	return 0;
}

