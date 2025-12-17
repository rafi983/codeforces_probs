#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    string s;
    cin >> s;

    int count_a = 0;
    int count_b = 0;
    for (char c : s) {
        if (c == 'a') count_a++;
        else count_b++;
    }

    int D = count_a - count_b;

    if (D == 0) {
        cout << 0 << "\n";
        return;
    }


    vector<int> last_pos(2 * n + 1, -2);
    int current_sum = 0;

    // Base case: prefix sum 0 at index 0
    last_pos[0 + n] = 0;

    int min_len = n + 1;

    for (int k = 1; k <= n; ++k) {
        if (s[k - 1] == 'a') {
            current_sum++;
        } else {
            current_sum--;
        }

        int target = current_sum - D;

        // Check if target is within valid range of prefix sums [-n, n]
        if (target >= -n && target <= n) {
            if (last_pos[target + n] != -2) {
                int i = last_pos[target + n];
                int len = k - i;
                if (len < min_len) {
                    min_len = len;
                }
            }
        }

        // Update the last position of the current prefix sum
        last_pos[current_sum + n] = k;
    }

    if (min_len >= n) {
        cout << -1 << "\n";
    } else {
        cout << min_len << "\n";
    }
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

