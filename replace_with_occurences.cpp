#include <iostream>
#include <vector>
#include <map>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> b(n);
    map<int, vector<int>> groups;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        groups[b[i]].push_back(i);
    }

    vector<int> a(n);
    int current_val = 1;

    for (auto const& [val, indices] : groups) {
        if (indices.size() % val != 0) {
            cout << -1 << endl;
            return;
        }

        for (size_t i = 0; i < indices.size(); i += val) {
            for (int j = 0; j < val; ++j) {
                a[indices[i + j]] = current_val;
            }
            current_val++;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << a[i] << (i == n - 1 ? "" : " ");
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

