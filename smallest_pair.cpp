#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        long long a[105];
        for (int i = 0; i < N; ++i) {
            cin >> a[i];
        }

        long long best = a[0] - 0;
        long long ans = best + (a[1] + 1);
        for (int j = 1; j < N; ++j) {
            long long cand = best + (a[j] + j);
            if (cand < ans) ans = cand;
            long long val = a[j] - j;
            if (val < best) best = val;
        }

        cout << ans << endl;
    }

    return 0;
}

