#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    priority_queue<long long> pqA;
    priority_queue<long long> pqB;

    for (int i = 0; i < n; ++i) {
        long long a;
        cin >> a;
        pqA.push(a);
    }

    for (int i = 0; i < m; ++i) {
        long long b;
        cin >> b;
        pqB.push(b);
    }

    int turn = 0; // 0 for Alice, 1 for Bob
    while (!pqA.empty() && !pqB.empty()) {
        if (turn == 0) { // Alice
            long long x = pqA.top();
            long long y = pqB.top();
            pqB.pop();

            if (y > x) {
                pqB.push(y - x);
            }
            // else y is destroyed
        } else { // Bob
            long long x = pqB.top();
            long long y = pqA.top();
            pqA.pop();

            if (y > x) {
                pqA.push(y - x);
            }
            // else y is destroyed
        }
        turn = 1 - turn;
    }

    if (pqB.empty()) {
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
    }
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

