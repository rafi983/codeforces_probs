#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int N;
long long current_idx;
vector<int> cached_path;
long long cached_idx = -1;
set<pair<int, int>> edges;
long long memo_N[20];

// Returns empty vector if length is 0 (no path)
vector<int> query(long long k) {
    if (k == cached_idx) {
        return cached_path;
    }
    cout << "? " << k << endl;
    int len;
    if (!(cin >> len)) exit(0);
    if (len == -1) exit(0);
    vector<int> path;
    if (len == 0) {
        // empty
    } else {
        path.resize(len);
        for (int i = 0; i < len; ++i) cin >> path[i];
    }
    cached_idx = k;
    cached_path = path;
    return path;
}

long long solve(int u, int depth) {
    vector<int> path = query(current_idx);

    if (path.empty() || path.size() <= depth || path[depth] != u) {
        return 0;
    }

    long long count = 1;
    current_idx++;

    while (true) {
        path = query(current_idx);

        if (path.empty()) break;
        if (path.size() <= depth) break;
        if (path[depth] != u) break;

        if (path.size() <= depth + 1) {
             break;
        }

        int v = path[depth + 1];
        edges.insert({u, v});

        if (memo_N[v] > 0) {
            count += memo_N[v];
            current_idx += memo_N[v];
        } else {
            long long child_cnt = solve(v, depth + 1);
            memo_N[v] = child_cnt;
            count += child_cnt;
        }
    }
    return count;
}

void run_case() {
    if (!(cin >> N)) return;

    current_idx = 1;
    cached_idx = -1;
    cached_path.clear();
    edges.clear();
    for(int i=0; i<=N; ++i) memo_N[i] = 0;

    for (int i = 1; i <= N; ++i) {
        if (memo_N[i] > 0) {
            current_idx += memo_N[i];
        } else {
            long long c = solve(i, 0);
            memo_N[i] = c;
        }
    }

    cout << "! " << edges.size() << endl;
    for (auto p : edges) {
        cout << p.first << " " << p.second << endl;
    }
}

int main() {
    int t;
    if (cin >> t) {
        while(t--) {
            run_case();
        }
    }
    return 0;
}

