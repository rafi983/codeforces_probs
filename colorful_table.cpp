#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<int> head(k + 2, -1);
        vector<int> next(n);
        vector<int> first_ge(k + 2);
        vector<int> last_ge(k + 2);

        for (int i = 0; i < n; ++i) {
            int v = a[i];
            next[i] = head[v];
            head[v] = i;
        }

        int current_min = n + 1;
        int current_max = 0;

        for (int c = k; c >= 1; --c) {
            for (int idx = head[c]; idx != -1; idx = next[idx]) {
                int pos = idx + 1;
                if (pos < current_min) {
                    current_min = pos;
                }
                if (pos > current_max) {
                    current_max = pos;
                }
            }
            first_ge[c] = current_min;
            last_ge[c] = current_max;
        }

        for (int c = 1; c <= k; ++c) {
            if (head[c] == -1) {
                cout << 0;
            } else {
                int width = last_ge[c] - first_ge[c] + 1;
                int ans = 2 * width;
                cout << ans;
            }
            cout << (c == k ? '\n' : ' ');
        }
    }

    return 0;
}

