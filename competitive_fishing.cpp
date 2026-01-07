#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

void solve() {
    int n;
    long long k;
    if (!(cin >> n >> k)) return;
    string s;
    cin >> s;

    vector<long long> suffixes;
    suffixes.reserve(n);

    long long current_suff = 0;

    for (int i = n - 1; i >= 1; --i) {
        if (s[i] == '1') {
            current_suff += 1;
        } else {
            current_suff -= 1;
        }
        suffixes.push_back(current_suff);
    }

    sort(suffixes.begin(), suffixes.end(), greater<long long>());

    long long current_score = 0;
    int cuts = 0;

    for (long long val : suffixes) {
        if (current_score >= k) break;
        if (val <= 0) break;
        current_score += val;
        cuts++;
    }

    if (current_score >= k) {
        cout << cuts + 1 << "\n";
    } else {
        cout << "-1\n";
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

