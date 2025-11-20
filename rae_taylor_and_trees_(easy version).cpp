#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T))
        return 0;

    while (T--) {
        int n;
        cin >> n;

        vector<int> p(n), pos(n + 1);
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
            pos[p[i]] = i + 1;
        }

        vector<int> prefMin(n + 1), suffMax(n + 2);
        prefMin[1] = pos[1];
        for (int k = 2; k <= n; ++k)
            prefMin[k] = min(prefMin[k - 1], pos[k]);

        suffMax[n] = pos[n];
        for (int k = n - 1; k >= 1; --k)
            suffMax[k] = max(suffMax[k + 1], pos[k]);

        bool ok = true;
        for (int k = 1; k < n; ++k) {
            int maxPosGreater = suffMax[k + 1];
            int minPosSmall = prefMin[k];
            if (maxPosGreater < minPosSmall) {
                ok = false;
                break;
            }
        }

        cout << (ok ? "Yes" : "No") << '\n';
    }

    return 0;
}

