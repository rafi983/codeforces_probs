#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;

    if (n % 2 == 0) {
        for (int i = 1; i <= n / 2; ++i) {
            cout << i << " " << i << (i == n / 2 ? "" : " ");
        }
        cout << "\n";
        return;
    }

    if (n < 27) {
        cout << "-1\n";
        return;
    }

    vector<int> kernel = {1, 2, 3, 3, 1, 4, 4, 5, 5, 6, 2, 7, 7, 6, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12, 13, 13, 2};
    for (int i = 0; i < 27; ++i) {
        cout << kernel[i] << " ";
    }

    int remaining = n - 27;
    int current_fill = 14;
    for (int i = 0; i < remaining / 2; ++i) {
        cout << current_fill << " " << current_fill << (i == remaining / 2 - 1 ? "" : " ");
        current_fill++;
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
