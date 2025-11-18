#include <iostream>
#include <cstring>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		long long ans = 0;
		long long cntFirst[11] = {0};
		long long cntSecond[11] = {0};
		long long cntPair[11][11];
		memset(cntPair, 0, sizeof(cntPair));

		for (int i = 0; i < n; ++i) {
			string s;
			cin >> s;
			int a = s[0] - 'a';
			int b = s[1] - 'a';

			ans += cntFirst[a] - cntPair[a][b];
			ans += cntSecond[b] - cntPair[a][b];

			cntFirst[a]++;
			cntSecond[b]++;
			cntPair[a][b]++;
		}

		cout << ans << endl;
	}

	return 0;
}

