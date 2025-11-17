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

        int l = -1;
        int r = -1;

        for (int i = 0; i + 1 < n; ++i) {
            if (s[i] != s[i + 1]) {
                l = i + 1;
                r = i + 2;
                break;
            }
        }

        if (l == -1) {
            cout << "-1 -1\n";
        } else {
            cout << l << ' ' << r << '\n';
        }
    }

    return 0;
}

