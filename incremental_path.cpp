#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

map<long long, long long> parent;

long long find_next_white(long long i) {
    if (parent.find(i) == parent.end()) return i;

    // Iterative find with path compression
    long long root = i;
    vector<long long> path;
    while (parent.find(root) != parent.end()) {
        path.push_back(root);
        root = parent[root];
    }

    for (long long node : path) {
        parent[node] = root;
    }

    return root;
}

void make_black(long long i) {
    if (parent.find(i) != parent.end()) return; // Already black
    parent[i] = find_next_white(i + 1);
}

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;
    string s;
    cin >> s;

    parent.clear();
    set<long long> black_cells;

    for (int i = 0; i < m; ++i) {
        long long a;
        cin >> a;
        black_cells.insert(a);

        parent[a] = a + 1;
    }



    vector<long long> x(n + 1);
    x[0] = 1;

    for (int i = 1; i <= n; ++i) {
        char cmd = s[i-1];
        long long prev = x[i-1];

        if (cmd == 'A') {
            x[i] = prev + 1;
        } else {
            x[i] = find_next_white(prev + 1);
        }

        long long current_pos = x[i];
        if (black_cells.find(current_pos) == black_cells.end()) {
            black_cells.insert(current_pos);
            make_black(current_pos);
        }

        if (cmd == 'B') {
            // Update x[i] for future iterations
            x[i] = find_next_white(current_pos + 1);
        }
    }

    cout << black_cells.size() << endl;
    bool first = true;
    for (long long cell : black_cells) {
        if (!first) cout << " ";
        cout << cell;
        first = false;
    }
    cout << endl;
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

