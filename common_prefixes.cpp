#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        string s(51, 'a');
        int L = 51;

        cout << s << '\n';

        for (int i = 0; i < n; ++i) {
            if (a[i] < L) {
                s[a[i]] = (s[a[i]] == 'a') ? 'b' : 'a';
            } else {
                while (L <= a[i]) {
                    s += 'a';
                    ++L;
                }
            }
            cout << s << '\n';
        }
    }

    return 0;
}

