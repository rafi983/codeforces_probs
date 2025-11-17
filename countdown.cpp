#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        long long sum = 0;
        int extra = 0;

        for (int i = 0; i < n; ++i) {
            int d = s[i] - '0';
            sum += d;
            if (i < n - 1 && d != 0) {
                ++extra;
            }
        }

        long long ans = sum + extra;
        cout << ans << '\n';
    }

    return 0;
}

