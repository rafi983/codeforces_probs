#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    if (!(cin >> t)) {
        return 0;
    }

    while (t--) {
        int n;
        if (!(cin >> n)) {
            return 0;
        }

        vector<long long> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        vector<long long> pref(n + 1);
        pref[0] = 0;
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] + a[i];
        }

        long long bestB = -(1LL << 60);
        long long maxInc = 0;

        for (int r = 1; r <= n; r++) {
            long long Br = r - (long long)r * r + pref[r - 1];
            if (Br > bestB) {
                bestB = Br;
            }

            long long Ar = (long long)r * r + r - pref[r];
            long long inc = Ar + bestB;
            if (inc > maxInc) {
                maxInc = inc;
            }
        }

        long long total = pref[n] + (maxInc > 0 ? maxInc : 0);
        cout << total << endl;
    }

    return 0;
}

