#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Candidate {
    int start_shift;
    int L;
};

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // qs[v] stores candidates for value v
    vector<vector<Candidate>> qs(n + 1);
    vector<int> head(n + 1, 0);
    vector<int> shift(n + 1, 0);

    int M = 0;

    for (int x : a) {
        int v = x;
        int M_in = M;

        shift[v]++;

        // Check completions
        while (head[v] < qs[v].size()) {
            Candidate& cand = qs[v][head[v]];
            if (shift[v] - cand.start_shift == v) {
                M = max(M, cand.L + v);
                head[v]++;
            } else {
                break;
            }
        }

        // Add new candidate
        bool logically_empty = (head[v] >= qs[v].size());
        if (logically_empty || qs[v].back().L < M_in) {
            qs[v].push_back({shift[v] - 1, M_in});

            // Handle immediate completion for v=1
            if (v == 1) {
                Candidate& cand = qs[v].back();
                M = max(M, cand.L + v);
                head[v]++;
            }
        }
    }

    cout << M << endl;
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

