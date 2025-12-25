#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool solve() {
    int n;
    if (!(cin >> n)) return false;
    map<int, int> counts;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        counts[a]++;
    }

    vector<pair<int, int>> sorted_counts;
    for (auto const& [day, count] : counts) {
        sorted_counts.push_back({day, count});
    }

    int num_days = sorted_counts.size();
    int i = 0;
    while (i < num_days) {
        int current_state = 2;
        int j = i;

        while (j < num_days) {
            if (j > i && sorted_counts[j].first != sorted_counts[j-1].first + 1) {
                break;
            }

            int count = sorted_counts[j].second;
            if (count >= 2 * current_state) {
                current_state = 0;
            } else if (count >= current_state) {
                current_state = 1;
            } else {
                current_state = 2;
            }

            if (current_state == 0) return true;

            j++;
        }
        i = j;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            if (solve()) {
                cout << "Yes" << "\n";
            } else {
                cout << "No" << "\n";
            }
        }
    }
    return 0;
}

