#include <bits/stdc++.h>
using namespace std;

long long countConfigs(int n) {
    if (n & 1)
        return 0;
    return n / 4 + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t))
        return 0;

    while (t--) {
        int n;
        cin >> n;
        cout << countConfigs(n) << '\n';
    }

    return 0;
}
