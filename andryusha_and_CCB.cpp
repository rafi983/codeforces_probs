#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    string s;
    cin >> s;

    vector<int> t_indices;
    t_indices.reserve(n);
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] != s[i+1]) {
            t_indices.push_back(i + 1);
        }
    }

    int M = t_indices.size();
    vector<bool> bad(M + 1, false);
    for (int j = 0; j < M - 1; ++j) {
        if (t_indices[j+1] == t_indices[j] + 1) {
            bad[j + 1] = true;
        }
    }

    vector<int> D(M + 2, 0);

    for (int B = 1; B <= M; ++B) {
        int curr_L = 0;
        int k = 1;
        while (true) {
            long long cost = (long long)k * B + curr_L;
            if (cost > M) break;

            long long end_val = (long long)k * (B + 1) - 1;
            int start = (int)cost;
            int end = (end_val > M) ? M : (int)end_val;

            if (start <= end) {
                D[start]++;
                if (end + 1 <= M) D[end + 1]--;
            }

            if (cost >= M) break;

            if (bad[start]) {
                curr_L++;
            }
            k++;
        }
    }

    int current_val = 0;
    for (int i = 1; i <= M; ++i) {
        current_val += D[i];
        D[i] = current_val;
    }

    int v = 0;
    for (int i = 1; i <= n; ++i) {
        if (i > 1 && s[i-2] != s[i-1]) {
            v++;
        }

        int ans = (v <= M ? D[v] : 0);
        if (i > v) {
            ans += (i - v);
        }
        cout << ans << (i == n ? "" : " ");
    }
    cout << "\n";
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
