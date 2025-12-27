#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Function to count characters in range [l, r] using prefix sums
int get_count(const vector<vector<int>>& pref, int l, int r, int char_idx) {
    if (l > r) return 0;
    return pref[r + 1][char_idx] - pref[l][char_idx];
}

int solve_side(const string& s) {
    int n = s.length();
    int L = -1, R = -1;

    // Find first and last mismatch in the first half
    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != s[n - 1 - i]) {
            if (L == -1) L = i;
            R = i;
        }
    }

    if (L == -1) return 0; // Already a palindrome

    // Precompute prefix sums
    vector<vector<int>> pref(n + 1, vector<int>(26, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 26; ++j) {
            pref[i + 1][j] = pref[i][j];
        }
        pref[i + 1][s[i] - 'a']++;
    }

    // Binary search for the smallest r
    int low = R, high = n - 1 - L;
    int ans = high - L + 1;

    while (low <= high) {
        int r = low + (high - low) / 2;
        bool ok = true;

        int target_start = max(r + 1, n - 1 - r);
        int target_end = n - 1 - L;

        for (int c = 0; c < 26; ++c) {
            int have = get_count(pref, L, r, c);
            int need = get_count(pref, target_start, target_end, c);
            if (have < need) {
                ok = false;
                break;
            }
        }

        if (ok) {
            ans = r - L + 1;
            high = r - 1;
        } else {
            low = r + 1;
        }
    }
    return ans;
}

void solve() {
    string s;
    cin >> s;

    int ans1 = solve_side(s);

    string rs = s;
    reverse(rs.begin(), rs.end());
    int ans2 = solve_side(rs);

    cout << min(ans1, ans2) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

