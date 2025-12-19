#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int target[10] = {0};
    target[0] = 3;
    target[1] = 1;
    target[2] = 2;
    target[3] = 1;
    target[5] = 1;

    int current[10] = {0};

    for (int i = 0; i < n; ++i) {
        current[a[i]]++;

        bool ok = true;
        for (int d = 0; d <= 9; ++d) {
            if (current[d] < target[d]) {
                ok = false;
                break;
            }
        }

        if (ok) {
            cout << (i + 1) << "\n";
            return;
        }
    }

    cout << 0 << "\n";
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

