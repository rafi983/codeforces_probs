#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Operation {
    long long l, r, len_before;
};

void solve() {
    int n, c, q;
    if (!(cin >> n >> c >> q)) return;
    string s;
    cin >> s;

    vector<Operation> ops(c);
    long long current_len = n;

    for (int i = 0; i < c; ++i) {
        long long l, r;
        cin >> l >> r;
        ops[i] = {l, r, current_len};
        current_len += (r - l + 1);
    }

    for (int i = 0; i < q; ++i) {
        long long k;
        cin >> k;

        for (int j = c - 1; j >= 0; --j) {
            if (k > ops[j].len_before) {
                long long offset = k - (ops[j].len_before + 1);
                k = ops[j].l + offset;
            }
        }

        cout << s[k - 1] << "\n";
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

