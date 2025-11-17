#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int p[1000];
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }

        int found = 0;
        int i, j, k;

        for (j = 1; j < n - 1; j++) {
            int foundI = -1;
            int foundK = -1;

            for (int x = 0; x < j; x++) {
                if (p[x] < p[j]) {
                    foundI = x;
                    break;
                }
            }

            for (int x = j + 1; x < n; x++) {
                if (p[x] < p[j]) {
                    foundK = x;
                    break;
                }
            }

            if (foundI != -1 && foundK != -1) {
                i = foundI;
                k = foundK;
                found = 1;
                break;
            }
        }

        if (found) {
            cout << "YES" << endl;
            cout << i + 1 << " " << j + 1 << " " << k + 1 << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}

