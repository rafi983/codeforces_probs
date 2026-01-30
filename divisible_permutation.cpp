#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void zaman() {
    int n;
    cin >> n;

    vector<int> a(n);
    int left_val = 1;
    int right_val = n;

    for (int i = n - 1; i >= 0; i--) {
        int step = n - 1 - i;

        if (step % 2 == 0) {
            a[i] = left_val++;
        } else {
            a[i] = right_val--;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            zaman();
        }
    }

    return 0;
}
