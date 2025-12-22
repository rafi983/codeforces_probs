#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Segment {
    int l, r;
    int len() const { return r - l + 1; }
};

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<Segment> segments;
    if (n == 0) {
        cout << "YES" << endl;
        return;
    }

    for (int i = 0; i < n; ) {
        if (s[i] == '0') {
            int j = i;
            while (j < n && s[j] == '0') {
                j++;
            }
            // Segment from i to j-1
            segments.push_back({i + 1, j}); // 1-based indexing
            i = j;
        } else {
            i++;
        }
    }

    if (segments.empty()) {
        cout << "YES" << endl;
        return;
    }



    int idx = 0;
    while (idx < segments.size()) {
        int start_idx = idx;
        // Find end of this super-chain
        while (idx + 1 < segments.size() && segments[idx + 1].l == segments[idx].r + 2) {
            idx++;
        }
        int end_idx = idx;

        // Process this super-chain from start_idx to end_idx
        bool left_safe = (segments[start_idx].l == 1);
        int sub_len = 0;

        for (int k = start_idx; k <= end_idx; ++k) {
            if (segments[k].len() >= 2) {
                // Provider found.
                // Check previous sub-sequence
                bool right_safe = true; // Provider is safe
                if (sub_len > 0) {
                    if (sub_len % 2 != 0) {
                        if (!left_safe && !right_safe) {
                            cout << "NO" << endl;
                            return;
                        }
                    }
                }
                // Reset for next sub-sequence
                sub_len = 0;
                left_safe = true; // Provider is safe
            } else {
                sub_len++;
            }
        }

        // Check last sub-sequence
        if (sub_len > 0) {
            bool right_safe = (segments[end_idx].r == n);
            if (sub_len % 2 != 0) {
                if (!left_safe && !right_safe) {
                    cout << "NO" << endl;
                    return;
                }
            }
        }

        idx++;
    }

    cout << "YES" << endl;
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

