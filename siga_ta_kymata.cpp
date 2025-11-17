#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> p(n + 1);
        int pos1 = -1, posn = -1;

        for (int i = 1; i <= n; ++i) {
            cin >> p[i];
            if (p[i] == 1) pos1 = i;
            if (p[i] == n) posn = i;
        }

        string x;
        cin >> x;

        int impossible = 0;
        if (x[0] == '1' || x[n-1] == '1' || x[pos1-1] == '1' || x[posn-1] == '1') {
            impossible = 1;
        }

        if (impossible) {
            cout << -1 << endl;
            continue;
        }

        int ops[5][2];
        int k = 0;

        int l, r;
        l = pos1; r = posn; if (l > r) { int tmp = l; l = r; r = tmp; } ops[k][0] = l; ops[k][1] = r; k++;
        l = 1; r = pos1; if (l > r) { int tmp = l; l = r; r = tmp; } ops[k][0] = l; ops[k][1] = r; k++;
        l = 1; r = posn; if (l > r) { int tmp = l; l = r; r = tmp; } ops[k][0] = l; ops[k][1] = r; k++;
        l = pos1; r = n; if (l > r) { int tmp = l; l = r; r = tmp; } ops[k][0] = l; ops[k][1] = r; k++;
        l = posn; r = n; if (l > r) { int tmp = l; l = r; r = tmp; } ops[k][0] = l; ops[k][1] = r; k++;

        cout << k << endl;
        for (int i = 0; i < k; ++i) {
            cout << ops[i][0] << " " << ops[i][1] << endl;
        }
    }

    return 0;
}

