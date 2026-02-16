#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ask(int i, int j) {
    cout << "? " << i << " " << j << endl;
    int res;
    cin >> res;
    if (res == -1) exit(0);
    return res;
}

void solve() {
    int n;
    cin >> n;

    int impostor = -1;
    for (int i = 1; i < n; i += 2) {
        int r1 = ask(i, i + 1);
        int r2 = ask(i + 1, i);

        if (r1 != r2) {

            int k = (i == 1) ? n : 1;

            int c_sees_i = ask(k, i);
            int c_sees_j = ask(k, i + 1);

            if (c_sees_i != c_sees_j) {

                if (r1 == 1) impostor = i;
                else impostor = i + 1;
            } else {

                if (r1 == 0) impostor = i;
                else impostor = i + 1;
            }
            break;
        }
    }

    if (impostor == -1) {
        impostor = n;
    }

    cout << "! " << impostor << endl;
}

int main() {
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
