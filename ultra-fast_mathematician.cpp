#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string num1, num2;
	cin >> num1 >> num2;

	int len = num1.length();

	for (int i = 0; i < len; i++) {
		if (num1[i] != num2[i]) {
			cout << "1";
		} else {
			cout << "0";
		}
	}
	cout << endl;

	return 0;
}

