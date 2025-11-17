#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countFibonacciness(int a1, int a2, int a3, int a4, int a5) {
    int cnt = 0;
    if (a3 == a1 + a2) ++cnt;
    if (a4 == a2 + a3) ++cnt;
    if (a5 == a3 + a4) ++cnt;
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int a1, a2, a4, a5;
        cin >> a1 >> a2 >> a4 >> a5;

        vector<int> candidates = {
            a1 + a2,   // a3 = a1 + a2
            a4 - a2,   // a3 = a4 - a2
            a5 - a4    // a3 = a5 - a4
        };

        int best = 0;
        for (int a3 : candidates) {
            int c = countFibonacciness(a1, a2, a3, a4, a5);
            best = max(best, c);
        }

        cout << best << '\n';
    }

    return 0;
}

