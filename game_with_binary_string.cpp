#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int OFFSET = 1000005;
const int MAX_VAL = 2000005;

int bit[MAX_VAL];
int freq[MAX_VAL];

void update(int idx, int val) {
    for (; idx < MAX_VAL; idx += idx & -idx)
        bit[idx] += val;
}

int query(int idx) {
    int sum = 0;
    for (; idx > 0; idx -= idx & -idx)
        sum += bit[idx];
    return sum;
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    string s;
    cin >> s;

    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cnt[i + 1] = cnt[i] + (s[i] - '0');
    }

    long long ans = 0;


    int val0 = 0 + OFFSET;
    update(val0, 1);
    freq[val0]++;

    for (int i = 1; i <= n; ++i) {
        int val = (i - 4 * cnt[i]) + OFFSET;

        // Condition 1: val[x] == val[y] + 1
        if (val + 1 < MAX_VAL) {
            ans += freq[val + 1];
        }

        // Condition 2: val[x] <= val[y] - 2
        if (val - 2 > 0) {
            ans += query(val - 2);
        }

        update(val, 1);
        freq[val]++;
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

