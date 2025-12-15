#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

long long cnt[6][50];

void solve() {
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 50; ++j) {
            cnt[i][j] = 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        int len = s[i].length();
        int sum = 0;
        for (char c : s[i]) {
            sum += c - '0';
        }
        cnt[len][sum]++;
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int len = s[i].length();
        int sum = 0;
        for (char c : s[i]) {
            sum += c - '0';
        }

        ans += cnt[len][sum];

        for (int l = 1; l < len; l++) {
            if ((len + l) % 2 != 0) continue;

            int total_len = len + l;
            int half = total_len / 2;



            int sum_prefix = 0;
            int sum_suffix = 0;

            // Calculate sum of prefix of s of length (half - l)
            for (int k = 0; k < half - l; ++k) {
                sum_prefix += s[i][k] - '0';
            }
            // Calculate sum of suffix of s (remaining part)
            for (int k = half - l; k < len; ++k) {
                sum_suffix += s[i][k] - '0';
            }

            int req = sum_suffix - sum_prefix;
            if (req >= 0) {
                ans += cnt[l][req];
            }



            sum_prefix = 0;
            sum_suffix = 0;

            for (int k = 0; k < half; ++k) {
                sum_prefix += s[i][k] - '0';
            }
            for (int k = half; k < len; ++k) {
                sum_suffix += s[i][k] - '0';
            }

            req = sum_prefix - sum_suffix;
            if (req >= 0) {
                ans += cnt[l][req];
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

