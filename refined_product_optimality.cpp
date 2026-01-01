#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long MOD = 998244353;

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, MOD - 2);
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    vector<pair<int, int>> sortedA(n), sortedB(n);
    for(int i=0; i<n; ++i) sortedA[i] = {a[i], i};
    for(int i=0; i<n; ++i) sortedB[i] = {b[i], i};

    sort(sortedA.begin(), sortedA.end());
    sort(sortedB.begin(), sortedB.end());

    vector<int> A_val(n), B_val(n);
    vector<int> A_id(n), B_id(n);
    vector<int> posA(n), posB(n);

    for(int i=0; i<n; ++i) {
        A_val[i] = sortedA[i].first;
        A_id[i] = sortedA[i].second;
        posA[A_id[i]] = i;

        B_val[i] = sortedB[i].first;
        B_id[i] = sortedB[i].second;
        posB[B_id[i]] = i;
    }

    long long current_prod = 1;
    for(int i=0; i<n; ++i) {
        current_prod = (current_prod * min(A_val[i], B_val[i])) % MOD;
    }

    cout << current_prod << " ";

    for(int k=0; k<q; ++k) {
        int o, x;
        cin >> o >> x;
        --x;

        if (o == 1) {
            int p = posA[x];
            int val = A_val[p];

            auto it = upper_bound(A_val.begin(), A_val.end(), val);
            int r = (int)(it - A_val.begin()) - 1;

            if (p != r) {
                int id_p = A_id[p];
                int id_r = A_id[r];

                swap(A_id[p], A_id[r]);
                posA[id_p] = r;
                posA[id_r] = p;

                p = r;
            }

            long long old_min = min(A_val[p], B_val[p]);
            long long new_val = val + 1;
            long long new_min = min((int)new_val, B_val[p]);

            A_val[p] = new_val;

            if (old_min != new_min) {
                current_prod = (current_prod * modInverse(old_min)) % MOD;
                current_prod = (current_prod * new_min) % MOD;
            }

        } else {
            int p = posB[x];
            int val = B_val[p];

            auto it = upper_bound(B_val.begin(), B_val.end(), val);
            int r = (int)(it - B_val.begin()) - 1;

            if (p != r) {
                int id_p = B_id[p];
                int id_r = B_id[r];

                swap(B_id[p], B_id[r]);
                posB[id_p] = r;
                posB[id_r] = p;

                p = r;
            }

            long long old_min = min(A_val[p], B_val[p]);
            long long new_val = val + 1;
            long long new_min = min(A_val[p], (int)new_val);

            B_val[p] = new_val;

            if (old_min != new_min) {
                current_prod = (current_prod * modInverse(old_min)) % MOD;
                current_prod = (current_prod * new_min) % MOD;
            }
        }
        cout << current_prod << (k == q - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

