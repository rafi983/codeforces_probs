#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Op {
    int type;
    int idx;
};

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];

    vector<Op> ops;

    auto swap_a = [&](int i) {
        swap(a[i], a[i + 1]);
        ops.push_back({1, i});
    };

    auto swap_b = [&](int i) {
        swap(b[i], b[i + 1]);
        ops.push_back({2, i});
    };

    auto swap_ab = [&](int i) {
        swap(a[i], b[i]);
        ops.push_back({3, i});
    };

    for (int i = 1; i <= n; ++i) {
        // Target for a[i] is 2*i - 1
        int target_a = 2 * i - 1;
        int pos = -1;
        char arr = ' ';

        // Find target_a
        for (int j = i; j <= n; ++j) {
            if (a[j] == target_a) {
                pos = j;
                arr = 'a';
                break;
            }
            if (b[j] == target_a) {
                pos = j;
                arr = 'b';
                break;
            }
        }

        if (arr == 'a') {
            while (pos > i) {
                swap_a(pos - 1);
                pos--;
            }
        } else { // arr == 'b'
            while (pos > i) {
                swap_b(pos - 1);
                pos--;
            }
            swap_ab(i);
        }

        // Target for b[i] is 2*i
        int target_b = 2 * i;
        pos = -1;
        arr = ' ';

        // Find target_b
        // Note: a[i] is now fixed with 2*i-1, so we search from i+1 in a, and i in b
        for (int j = i + 1; j <= n; ++j) {
            if (a[j] == target_b) {
                pos = j;
                arr = 'a';
                break;
            }
        }
        if (pos == -1) {
            for (int j = i; j <= n; ++j) {
                if (b[j] == target_b) {
                    pos = j;
                    arr = 'b';
                    break;
                }
            }
        }

        if (arr == 'b') {
            while (pos > i) {
                swap_b(pos - 1);
                pos--;
            }
        } else { // arr == 'a'
            while (pos > i + 1) {
                swap_a(pos - 1);
                pos--;
            }
            // Now at a[i+1]
            swap_ab(i + 1); // Move to b[i+1]
            swap_b(i);      // Move to b[i]
        }
    }

    cout << ops.size() << "\n";
    for (const auto& op : ops) {
        cout << op.type << " " << op.idx << "\n";
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

