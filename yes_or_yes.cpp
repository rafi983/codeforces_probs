#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;

		if (toupper(s[0]) == 'Y' && toupper(s[1]) == 'E' && toupper(s[2]) == 'S') {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	return 0;
}

