#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        long long k;
        cin >> k;

        cout << ((k % 3 == 1) ? "YES" : "NO") << '\n';
    }

    return 0;
}

