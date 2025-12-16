#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int i = 0;
    while (i < n) {
        if (s[i] == '0') {
            int j = i;
            while (j < n && s[j] == '0') {
                j++;
            }
            int len = j - i;
            if (len == 1) {
                cout << "NO" << endl;
                return;
            }
            i = j;
        } else {
            i++;
        }
    }

    cout << "YES" << endl;
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);

    i = 0;
    while (i < n) {
        if (s[i] == '0') {
            int j = i;
            while (j < n && s[j] == '0') {
                j++;
            }

            rotate(p.begin() + i, p.begin() + j - 1, p.begin() + j);

            i = j;
        } else {
            i++;
        }
    }

    for (int k = 0; k < n; ++k) {
        cout << p[k] << (k == n - 1 ? "" : " ");
    }
    cout << endl;
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

