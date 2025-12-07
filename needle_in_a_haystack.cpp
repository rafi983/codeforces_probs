#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;

        int n = s.size(), m = t.size();

        vector<int> cntT(26, 0), cntS(26, 0);
        for (char c : t) cntT[c - 'a']++;
        for (char c : s) cntS[c - 'a']++;

        bool possible = true;
        for (int i = 0; i < 26; i++) {
            if (cntT[i] < cntS[i]) {
                possible = false;
                break;
            }
        }

        if (!possible) {
            cout << "Impossible\n";
            continue;
        }

        vector<int> extra(26);
        for (int i = 0; i < 26; i++) {
            extra[i] = cntT[i] - cntS[i];
        }

        string result;
        int sPtr = 0;

        while (sPtr < n) {
            char need = s[sPtr];
            bool placed = false;

            for (int c = 0; c < (need - 'a'); c++) {
                if (extra[c] > 0) {
                    result += ('a' + c);
                    extra[c]--;
                    placed = true;
                    break;
                }
            }

            if (!placed) {
                result += need;
                sPtr++;
            }
        }

        for (int c = 0; c < 26; c++) {
            while (extra[c] > 0) {
                result += ('a' + c);
                extra[c]--;
            }
        }

        cout << result << '\n';
    }
    return 0;
}

