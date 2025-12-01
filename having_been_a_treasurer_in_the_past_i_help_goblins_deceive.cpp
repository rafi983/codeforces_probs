#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        string s;
        cin >> n;
        cin >> s;
        long long a = 0; // count of '-'
        for (char c : s) if (c == '-') ++a;
        long long b = (long long)n - a; // count of '_'
        long long x = a / 2;          // floor(a/2)
        long long y = a - x;          // ceil(a/2)
        long long bestPairs = x * y;  // floor(a^2/4)
        long long ans = b * bestPairs;
        cout << ans << '\n';
    }
    return 0;
}

