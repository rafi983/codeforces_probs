#include <iostream>
using namespace std;

int main() {
    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int n;
        cin >> n;

        bool seen[55] = {false};
        bool first = true;

        for (int i = 0; i < 2 * n; ++i) {
            int x;
            cin >> x;

            if (!seen[x]) {
                if (!first) cout << " ";
                first = false;
                cout << x;
                seen[x] = true;
            }
        }
        cout << endl;
    }

    return 0;
}

