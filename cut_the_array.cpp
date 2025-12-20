#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> p(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        p[i + 1] = p[i] + a[i];
    }

    for (int l = 1; l < n; ++l) {
        for (int r = l + 1; r < n; ++r) {
            int s1 = p[l] % 3;
            int s2 = (p[r] - p[l]) % 3;
            int s3 = (p[n] - p[r]) % 3;

            bool all_same = (s1 == s2 && s2 == s3);
            bool all_diff = (s1 != s2 && s1 != s3 && s2 != s3);

            if (all_same || all_diff) {
                cout << l << " " << r << endl;
                return;
            }
        }
    }

    cout << "0 0" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}

