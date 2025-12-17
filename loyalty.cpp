#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    long long X;
    if (!(cin >> n >> X)) return;
    vector<long long> a(n);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    sort(a.rbegin(), a.rend());

    long long K = sum / X;
    // Bonus candidates: first K elements
    // Fillers: remaining n - K elements

    vector<long long> result_order;
    result_order.reserve(n);

    long long current_bonus = 0;
    long long cur_rem = 0;

    int ptrB = 0;
    int ptrF = K; // Start of fillers in sorted array

    for (int i = 0; i < n; ++i) {
        // Try to pick from B if it triggers a bonus
        bool pickB = false;

        if (ptrB < K) {
            if (cur_rem + a[ptrB] >= X) {
                pickB = true;
            } else {
                // Can't trigger bonus with B.
                // Must pick filler if available.
                if (ptrF < n) {
                    pickB = false;
                } else {
                    // No fillers left, forced to pick B (and fail bonus)
                    pickB = true;
                }
            }
        } else {
            // No B left, pick F
            pickB = false;
        }

        long long val;
        if (pickB) {
            val = a[ptrB++];
        } else {
            val = a[ptrF++];
        }

        if (cur_rem + val >= X) {
            current_bonus += val;
        }
        cur_rem = (cur_rem + val) % X;
        result_order.push_back(val);
    }

    cout << current_bonus << "\n";
    for (int i = 0; i < n; ++i) {
        cout << result_order[i] << (i == n - 1 ? "" : " ");
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

