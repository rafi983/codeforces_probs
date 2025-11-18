#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string word;
	cin >> word;

	if (word[0] >= 'a' && word[0] <= 'z') {
		word[0] = word[0] - 'a' + 'A';
	}

	cout << word << endl;

	return 0;
}

