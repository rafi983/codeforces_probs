#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }

    vector<int> d(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }

    vector<int> cycle_id(n + 1, 0);
    vector<int> cycle_len;
    vector<bool> visited(n + 1, false);
    int current_cid = 0;

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            int curr = i;
            int len = 0;
            while (!visited[curr]) {
                visited[curr] = true;
                cycle_id[curr] = current_cid;
                curr = p[curr];
                len++;
            }
            cycle_len.push_back(len);
            current_cid++;
        }
    }

    vector<bool> cycle_intact(current_cid, true);
    int intact_sum = n;

    for (int i = 0; i < n; ++i) {
        int idx = d[i];
        int cid = cycle_id[idx];

        if (cycle_intact[cid]) {
            cycle_intact[cid] = false;
            intact_sum -= cycle_len[cid];
        }

        cout << (n - intact_sum) << (i == n - 1 ? "" : " ");
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

