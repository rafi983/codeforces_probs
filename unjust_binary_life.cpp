#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

struct Element {
    long long val;
    int id; // original index y (1-based)
    long long B_val; // B_y
};

bool compareElements(const Element& a, const Element& b) {
    return a.val < b.val;
}

void solve() {
    int n;
    cin >> n;
    string a_str, b_str;
    cin >> a_str >> b_str;

    vector<long long> A(n + 1, 0);
    vector<long long> B(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        A[i+1] = A[i] + (a_str[i] - '0');
    }
    for (int i = 0; i < n; ++i) {
        B[i+1] = B[i] + (b_str[i] - '0');
    }

    vector<Element> sortedB(n);
    for (int y = 1; y <= n; ++y) {
        sortedB[y-1].val = (long long)y - 2 * B[y];
        sortedB[y-1].id = y;
        sortedB[y-1].B_val = B[y];
    }

    sort(sortedB.begin(), sortedB.end(), compareElements);

    vector<long long> prefB(n + 1, 0);
    vector<long long> prefY(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        prefB[i+1] = prefB[i] + sortedB[i].B_val;
        prefY[i+1] = prefY[i] + sortedB[i].id;
    }

    long long total_ans = 0;

    for (int x = 1; x <= n; ++x) {
        long long valAx = 2 * A[x] - x;

        // Find first element where sortedB[i].val >= valAx
        Element target;
        target.val = valAx;

        auto it = lower_bound(sortedB.begin(), sortedB.end(), target, compareElements);
        int k = distance(sortedB.begin(), it);

        // S2 is indices [0, k-1] (values < valAx)
        // S1 is indices [k, n-1] (values >= valAx)

        long long countS2 = k;
        long long countS1 = n - k;

        // Contribution from S1: A_x + B_y
        long long sumB_S1 = prefB[n] - prefB[k];
        total_ans += countS1 * A[x] + sumB_S1;

        // Contribution from S2: x + y - A_x - B_y
        long long sumY_S2 = prefY[k];
        long long sumB_S2 = prefB[k];
        total_ans += countS2 * (x - A[x]) + sumY_S2 - sumB_S2;
    }

    cout << total_ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

