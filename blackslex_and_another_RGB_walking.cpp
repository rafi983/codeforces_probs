#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

char get_char(int d) {
    int m = d % 3;
    if (m == 0) return 'r';
    if (m == 1) return 'g';
    return 'b';
}

int get_val(char c) {
    if (c == 'r') return 0;
    if (c == 'g') return 1;
    return 2;
}

void solve_agent() {
    int n, m;
    if (!(cin >> n >> m)) return;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(n + 1, -1);
    queue<int> q;

    dist[1] = 0;
    q.push(1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    string res = "";
    for (int i = 1; i <= n; ++i) {
        res += get_char(dist[i]);
    }
    cout << res << endl;
}

void solve_blackslex() {
    int q_count;
    if (!(cin >> q_count)) return;
    for (int k = 0; k < q_count; ++k) {
        int d;
        cin >> d;
        string c;
        cin >> c;

        bool has_r = false, has_g = false, has_b = false;
        for (char x : c) {
            if (x == 'r') has_r = true;
            else if (x == 'g') has_g = true;
            else if (x == 'b') has_b = true;
        }

        char target = ' ';
        if (has_r && !has_g && !has_b) target = 'r';
        else if (!has_r && has_g && !has_b) target = 'g';
        else if (!has_r && !has_g && has_b) target = 'b';

        else if (has_r && has_g) target = 'g'; // r->g
        else if (has_g && has_b) target = 'b'; // g->b
        else if (has_b && has_r) target = 'r'; // b->r

        // Find index
        int ans = -1;
        for (int i = 0; i < d; ++i) {
            if (c[i] == target) {
                ans = i + 1;
                break;
            }
        }
        cout << ans << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string mode;
    if (cin >> mode) {
        int t;
        cin >> t;
        while (t--) {
            if (mode == "first") {
                solve_agent();
            } else {
                solve_blackslex();
            }
        }
    }
    return 0;
}
