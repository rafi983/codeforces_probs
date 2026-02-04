#include <iostream>
#include <vector>
#include <deque>
#include <numeric>

using namespace std;

int query(int a, int b) {
    cout << "? " << a << " " << b << endl;
    int res;
    cin >> res;
    return res;
}

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> p(n);

    p[1] = 0;
    int child_of_1 = -1;

    for (int i = 2; i < n; ++i) {
        int res = query(1, i);
        if (res == 0) {

            p[i] = 1;
            child_of_1 = i;
            break;
        } else {

            p[i] = 0;
        }
    }

    deque<int> Q;

    for (int i = 2; i <= child_of_1; ++i) {
        Q.push_back(i);
    }

    for (int j = child_of_1 + 1; j < n; ++j) {
        while (!Q.empty()) {
            int u = Q.front();
            int res = query(u, j);
            if (res == 0) {
                p[j] = u;
                Q.pop_front(); // u used
                Q.push_back(j); // j is new leaf
                break;
            } else {
                Q.pop_front();
            }
        }
    }

    cout << "! ";
    for (int i = 1; i < n; ++i) {
        cout << p[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
