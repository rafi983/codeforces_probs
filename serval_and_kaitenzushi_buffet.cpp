#include <iostream>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;
    vector<long long> d(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }

    priority_queue<long long, vector<long long>, greater<long long>> pq;
    long long current_sum = 0;
    int L = k + 1;

    for (int i = n - 1; i >= 0; --i) {
        int limit = (n - i) / L;

        pq.push(d[i]);
        current_sum += d[i];

        while (pq.size() > limit) {
            current_sum -= pq.top();
            pq.pop();
        }
    }
    cout << current_sum << "\n";
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

