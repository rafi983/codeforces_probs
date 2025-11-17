#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<long long> v(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }

    // Prefix sum for original array
    vector<long long> pref(n + 1);
    pref[0] = 0;
    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1] + v[i];
    }

    // Sorted array
    vector<long long> u(n + 1);
    for (int i = 1; i <= n; ++i) {
        u[i] = v[i];
    }
    sort(u.begin() + 1, u.end());

    // Prefix sum for sorted array
    vector<long long> pref_u(n + 1);
    pref_u[0] = 0;
    for (int i = 1; i <= n; ++i) {
        pref_u[i] = pref_u[i - 1] + u[i];
    }

    int m;
    cin >> m;

    while (m--) {
        int type, l, r;
        cin >> type >> l >> r;

        if (type == 1) {
            cout << pref[r] - pref[l - 1] << endl;
        } else {
            cout << pref_u[r] - pref_u[l - 1] << endl;
        }
    }

    return 0;
}

