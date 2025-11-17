#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int n;
        if (!(cin >> n)) return 0;

        vector<int> top(n + 2);
        vector<int> bot(n + 2);

        for (int i = 1; i <= n; ++i) cin >> top[i];
        for (int i = 1; i <= n; ++i) cin >> bot[i];

        vector<int> prefMinTop(n + 2);
        vector<int> prefMaxTop(n + 2);
        prefMinTop[1] = top[1];
        prefMaxTop[1] = top[1];

        for (int i = 2; i <= n; ++i) {
            prefMinTop[i] = min(prefMinTop[i-1], top[i]);
            prefMaxTop[i] = max(prefMaxTop[i-1], top[i]);
        }

        vector<int> sufMinBot(n + 3);
        vector<int> sufMaxBot(n + 3);
        const int INF = 1000000000;
        sufMinBot[n+1] = INF;
        sufMaxBot[n+1] = 0;

        for (int i = n; i >= 1; --i) {
            sufMinBot[i] = min(bot[i], sufMinBot[i+1]);
            sufMaxBot[i] = max(bot[i], sufMaxBot[i+1]);
        }

        vector<int> bestB(2*n + 4, INF);

        for (int k = 1; k <= n; ++k) {
            int A = min(prefMinTop[k], sufMinBot[k]);
            int B = max(prefMaxTop[k], sufMaxBot[k]);
            bestB[A] = min(bestB[A], B);
        }

        for (int L = 2*n; L >= 1; --L) {
            bestB[L] = min(bestB[L], bestB[L+1]);
        }

        long long ans = 0;
        for (int l = 1; l <= 2*n; ++l) {
            int b = bestB[l];
            if (b >= INF) continue;
            int start = max(l, b);
            if (start <= 2*n) {
                ans += (long long)(2*n - start + 1);
            }
        }

        cout << ans << endl;
    }

    return 0;
}

