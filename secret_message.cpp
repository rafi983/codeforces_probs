#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>

using namespace std;

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return; // Check for read failure

    vector<string> strips(k);
    for (int i = 0; i < k; ++i) {
        cin >> strips[i];
    }

    vector<int> available(n, 0);
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < k; ++i) {
            available[j] |= (1 << (strips[i][j] - 'a'));
        }
    }

    vector<int> divisors;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i * i != n) {
                divisors.push_back(n / i);
            }
        }
    }
    sort(divisors.begin(), divisors.end());

    for (int d : divisors) {
        string pattern = "";
        bool possible = true;

        for (int j = 0; j < d; ++j) {
            int common_mask = (1 << 26) - 1; // All ones for 26 bits

            for (int pos = j; pos < n; pos += d) {
                common_mask &= available[pos];
                if (common_mask == 0) break;
            }

            if (common_mask == 0) {
                possible = false;
                break;
            } else {
                int char_idx = 0;
                while ((common_mask & (1 << char_idx)) == 0) {
                    char_idx++;
                }
                pattern += (char)('a' + char_idx);
            }
        }

        if (possible) {
            string res = "";
            for (int i = 0; i < n / d; ++i) {
                res += pattern;
            }
            cout << res << endl;
            return;
        }
    }
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


