#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<pair<int, int>> buttons(n);
    for (int i = 0; i < n; ++i) {
        cin >> buttons[i].first;
        buttons[i].second = i + 1;
    }

    sort(buttons.rbegin(), buttons.rend());

    vector<bool> visited(n + 2, false);

    int clones = 0;

    int i = 0;
    while (i < n) {
        int j = i;
        while (j < n && buttons[j].first == buttons[i].first) {
            j++;
        }

        vector<int> current_indices;
        for (int k = i; k < j; ++k) {
            current_indices.push_back(buttons[k].second);
        }
        sort(current_indices.begin(), current_indices.end());

        if (!current_indices.empty()) {
            int start = current_indices[0];
            int end = current_indices[0];

            for (size_t k = 1; k < current_indices.size(); ++k) {
                if (current_indices[k] == end + 1) {
                    end = current_indices[k];
                } else {
                    bool touches = false;
                    if (visited[start - 1]) touches = true;
                    if (visited[end + 1]) touches = true;

                    if (!touches) {
                        clones++;
                    }

                    start = current_indices[k];
                    end = current_indices[k];
                }
            }
            bool touches = false;
            if (visited[start - 1]) touches = true;
            if (visited[end + 1]) touches = true;

            if (!touches) {
                clones++;
            }
        }

        for (int k = i; k < j; ++k) {
            visited[buttons[k].second] = true;
        }

        i = j;
    }

    cout << clones << "\n";
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

