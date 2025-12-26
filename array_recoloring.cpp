#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long max_cost = 0;

    for (int L = 0; L < n; ++L) {

        if (L > 0 && L < n - 1 && k < 2) continue;

        vector<pair<long long, int>> others;
        others.reserve(n - 1);
        for (int i = 0; i < n; ++i) {
            if (i == L) continue;
            others.push_back({a[i], i});
        }


        if (k < (int)others.size()) {
            nth_element(others.begin(), others.begin() + k, others.end(), greater<pair<long long, int>>());
        }

        long long current_sum = 0;
        bool hasLeft = false;
        bool hasRight = false;
        long long min_chosen_val = -1;

        for (int i = 0; i < k; ++i) {
            current_sum += others[i].first;
            if (others[i].second < L) hasLeft = true;
            if (others[i].second > L) hasRight = true;

            if (i == 0 || others[i].first < min_chosen_val) {
                min_chosen_val = others[i].first;
            }
        }

        if (L == 0 || L == n - 1) {
            max_cost = max(max_cost, current_sum + a[L]);
        } else {
            // L is in the middle. We need at least one from Left and one from Right.
            if (hasLeft && hasRight) {
                max_cost = max(max_cost, current_sum + a[L]);
            } else if (!hasLeft) {

                long long max_left = -1;
                for (int i = 0; i < L; ++i) {
                    max_left = max(max_left, a[i]);
                }
                max_cost = max(max_cost, current_sum - min_chosen_val + max_left + a[L]);
            } else { // !hasRight
                long long max_right = -1;
                for (int i = L + 1; i < n; ++i) {
                    max_right = max(max_right, a[i]);
                }
                max_cost = max(max_cost, current_sum - min_chosen_val + max_right + a[L]);
            }
        }
    }

    cout << max_cost << endl;
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

