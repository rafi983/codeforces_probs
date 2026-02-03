#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<vector<int>> perms(3, vector<int>(n + 1));
    for (int p = 0; p < 3; ++p) {
        for (int i = 1; i <= n; ++i) {
            cin >> perms[p][i];
        }
    }

    char players[] = {'q', 'k', 'j'};

    vector<int> best_source(3, 1);

    vector<pair<int, int>> parent(n + 1, {0, -1});


    for (int i = 2; i <= n; ++i) {
        bool reachable = false;
        int used_player = -1;
        int source = -1;

        for (int p = 0; p < 3; ++p) {
            int u = best_source[p];

            if (perms[p][u] > perms[p][i]) {
                reachable = true;
                used_player = p;
                source = u;
                break;
            }
        }

        if (reachable) {
            parent[i] = {source, used_player};

            for (int p = 0; p < 3; ++p) {
                int curr_best_u = best_source[p];
                if (perms[p][i] > perms[p][curr_best_u]) {
                    best_source[p] = i;
                }
            }
        }
    }

    if (parent[n].first != 0) {
        cout << "YES" << "\n";
        vector<pair<char, int>> path;
        int curr = n;
        while (curr != 1) {
            int p_idx = parent[curr].second;
            int prev = parent[curr].first;
            path.push_back({players[p_idx], curr});
            curr = prev;
        }
        reverse(path.begin(), path.end());

        cout << path.size() << "\n";
        for (const auto& move : path) {
            cout << move.first << " " << move.second << "\n";
        }
    } else {
        cout << "NO" << "\n";
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
