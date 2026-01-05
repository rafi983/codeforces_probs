#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    map<int, int> counts;
    long long sum_a = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        counts[x]++;
        sum_a += x;
    }

    priority_queue<int> pq;
    long long sum_b = 0;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        pq.push(x);
        sum_b += x;
    }

    if (sum_a != sum_b) {
        cout << "No" << endl;
        return;
    }

    int rem_a = n;
    while (!pq.empty()) {
        if ((int)pq.size() > rem_a) {
            cout << "No" << endl;
            return;
        }

        int x = pq.top();
        pq.pop();

        if (counts.count(x)) {
            counts[x]--;
            if (counts[x] == 0) {
                counts.erase(x);
            }
            rem_a--;
        } else {
            if (x <= 1) {
                cout << "No" << endl;
                return;
            }
            if (!counts.empty() && x < counts.begin()->first) {
                cout << "No" << endl;
                return;
            }

            pq.push(x / 2);
            pq.push((x + 1) / 2);
        }
    }

    cout << "Yes" << endl;
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

