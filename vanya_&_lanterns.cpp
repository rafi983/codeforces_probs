#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	long long l;
	cin >> n >> l;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	double max_gap = 0.0;

	if (a[0] > max_gap) max_gap = (double)a[0];
	if ((double)l - a[n-1] > max_gap) max_gap = (double)l - a[n-1];

	for (int i = 1; i < n; i++) {
		double gap = (a[i] - a[i-1]) / 2.0;
		if (gap > max_gap) max_gap = gap;
	}

	cout << fixed << setprecision(10) << max_gap << endl;

	return 0;
}

