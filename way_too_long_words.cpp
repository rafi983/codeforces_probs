#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		string word;
		cin >> word;

		int length = word.length();

		if (length > 10) {
			cout << word[0] << length - 2 << word[length - 1] << endl;
		} else {
			cout << word << endl;
		}
	}

	return 0;
}

