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

        for (char& c : s) {
            if (c == 'U') {
                c = 'D';
            } else if (c == 'D') {
                c = 'U';
            }
            // L and R remain unchanged
        }

        cout << s << '\n';
    }

    return 0;
}

