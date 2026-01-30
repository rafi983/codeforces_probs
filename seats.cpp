#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int calc_middle(int k) {
    return k / 3;
}

int calc_boundary(int k) {
    if (k < 2) return 0;
    return 1 + (k - 2) / 3;
}

void zaman() {
    int n;
    if (!(cin >> n)) return;
    string s;
    cin >> s;

    vector<int> p;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            p.push_back(i);
        }
    }

    if (p.empty()) {
        int ans = n + 5;

        for (int start_idx : {0, 1}) {
            for (int end_idx : {n - 1, n - 2}) {
                if (start_idx >= n || end_idx < 0) continue;
                if (start_idx > end_idx) continue;

                int students = 0;
                if (start_idx == end_idx) {
                    students = 1;
                } else if (end_idx - start_idx >= 2) {

                    students = (end_idx - start_idx + 2) / 3 + 1;
                } else {
                    continue;
                }
                ans = min(ans, students);
            }
        }
        cout << ans << "\n";
    } else {
        int added = 0;
        added += calc_boundary(p[0]);

        for (size_t i = 0; i < p.size() - 1; i++) {
            int gap = p[i+1] - p[i] - 1;
            added += calc_middle(gap);
        }

        int last_zeros = n - 1 - p.back();
        added += calc_boundary(last_zeros);

        cout << (added + (int)p.size()) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while(t--) {
            zaman();
        }
    }
    return 0;
}
