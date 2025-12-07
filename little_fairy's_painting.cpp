#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        set<int> colors;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            colors.insert(a);
        }

        while (true) {
            int d = colors.size();
            if (colors.count(d)) {
                cout << d << '\n';
                break;
            }
            colors.insert(d);
        }
    }
    return 0;
}

