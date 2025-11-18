#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	int uppercase_count = 0, lowercase_count = 0;

	for (int i = 0; i < s.length(); i++) {
		if (isupper(s[i])) {
			uppercase_count++;
		} else {
			lowercase_count++;
		}
	}

	if (uppercase_count > lowercase_count) {
		transform(s.begin(), s.end(), s.begin(), ::toupper);
	} else {
		transform(s.begin(), s.end(), s.begin(), ::tolower);
	}

	cout << s << endl;

	return 0;
}

