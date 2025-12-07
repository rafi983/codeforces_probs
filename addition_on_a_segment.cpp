#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        ll sum = 0;
        int nonZero = 0;

        for (int i = 0; i < n; i++) {
            int b;
            cin >> b;
            sum += b;
            if (b > 0) nonZero++;
        }


        ll maxLen = min((ll)nonZero, sum - n + 1);
        cout << maxLen << "\n";
    }

    return 0;
}

