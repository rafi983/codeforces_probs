#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        long long a;
        cin >> n >> a;

        int left = 0, right = 0;
        for (int i = 0; i < n; ++i) {
            long long x;
            cin >> x;

            if (x < a) {
                left++;
            } else if (x > a) {
                right++;
            }
        }

        long long b;
        if (right > left) {
            b = a + 1;
        } else {
            b = a - 1;
        }

        b = max(0LL, min(b, 2000000000LL));

        cout << b << '\n';
    }

    return 0;
}

