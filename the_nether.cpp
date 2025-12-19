#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cstdlib>

using namespace std;

int query(int start_node, const vector<int>& subset) {
    cout << "? " << start_node << " " << subset.size();
    for (int x : subset) {
        cout << " " << x;
    }
    cout << endl;
    int res;
    cin >> res;
    if (res == -1) exit(0);
    return res;
}

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> dp(n + 1);
    vector<int> all_nodes(n);
    iota(all_nodes.begin(), all_nodes.end(), 1);

    for (int i = 1; i <= n; ++i) {
        dp[i] = query(i, all_nodes);
    }

    int max_len = 0;
    int start_node = -1;
    for (int i = 1; i <= n; ++i) {
        if (dp[i] > max_len) {
            max_len = dp[i];
            start_node = i;
        }
    }

    vector<int> path;
    path.push_back(start_node);
    int curr = start_node;

    for (int target = max_len - 1; target >= 1; --target) {
        vector<int> candidates;
        for (int i = 1; i <= n; ++i) {
            if (dp[i] == target) {
                candidates.push_back(i);
            }
        }

        int next_node = -1;
        if (candidates.size() == 1) {
            next_node = candidates[0];
        } else {
            int low = 0;
            int high = candidates.size() - 1;
            while (low < high) {
                int mid = low + (high - low) / 2;
                vector<int> subset;
                subset.push_back(curr);
                for (int i = low; i <= mid; ++i) {
                    subset.push_back(candidates[i]);
                }

                int res = query(curr, subset);
                if (res >= 2) {
                    high = mid;
                } else {
                    low = mid + 1;
                }
            }
            next_node = candidates[low];
        }
        path.push_back(next_node);
        curr = next_node;
    }

    cout << "! " << path.size();
    for (int x : path) {
        cout << " " << x;
    }
    cout << endl;
}

int main() {
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}

