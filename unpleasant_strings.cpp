#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;
    string s;
    cin >> s;

    vector<vector<int>> nxt(n + 2, vector<int>(k, -1));
    for (int i = n - 1; i >= 0; --i) {
        for (int c = 0; c < k; ++c) {
            nxt[i][c] = nxt[i+1][c];
        }
        nxt[i][s[i] - 'a'] = i;
    }

    vector<int> dp(n + 2);
    dp[n] = 1;
    dp[n+1] = 0;


    for (int i = n - 1; i >= 0; --i) {
        int min_len = INF;
        for (int c = 0; c < k; ++c) {
            int next_pos = nxt[i][c];
            if (next_pos == -1) {
                min_len = 1;
            } else {
                min_len = min(min_len, 1 + dp[next_pos + 1]);
            }
        }
        dp[i] = min_len;
    }

    int q;
    cin >> q;
    while (q--) {
        string t;
        cin >> t;

        int curr = -1;
        bool possible = true;
        for (char c : t) {
            if (curr + 1 >= n) {
                possible = false;
                break;
            }
            int next_pos = nxt[curr + 1][c - 'a'];
            if (next_pos == -1) {
                possible = false;
                break;
            }
            curr = next_pos;
        }

        if (!possible) {
            cout << 0 << "\n";
        } else {

            cout << dp[curr + 1] << "\n";
        }
    }

    return 0;
}

