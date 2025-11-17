#include <iostream>
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

        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        vector<int> a(n);
        int left = 0;
        int right = n - 1;
        int idx = 0;

        while (left <= right) {
            if (idx % 2 == 0) {
                a[idx] = b[left];
                ++left;
            } else {
                a[idx] = b[right];
                --right;
            }
            ++idx;
        }

        for (int i = 0; i < n; ++i) {
            cout << a[i];
            if (i < n - 1) {
                cout << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}

