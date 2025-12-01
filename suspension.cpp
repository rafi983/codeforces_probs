#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int n;
        long long y, r;
        cin >> n >> y >> r;

        long long maxSuspensions = min<long long>(n, r + (y / 2));
        cout << maxSuspensions << "\n";
    }

    return 0;
}

