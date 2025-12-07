#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;

        int awake = 0;
        int lastImportant = -k - 1;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                lastImportant = i;
                awake++;
            } else if (i - lastImportant <= k) {
                awake++;
            }
        }

        cout << n - awake << "\n";
    }

    return 0;
}

