#include <bits/stdc++.h>
using namespace std;

static inline bool isBadTriple(long long a, long long b, long long c) {
    return gcd(a, b) == 1 && gcd(a, c) == 1 && gcd(b, c) == 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        cin >> n;
        vector<int> v6, v2, v3, vD;
        for (int x = 1; x <= n; ++x) {
            bool d2 = (x % 2 == 0);
            bool d3 = (x % 3 == 0);
            if (d2 && d3)
                v6.push_back(x);
            else if (d2)
                v2.push_back(x);
            else if (d3)
                v3.push_back(x);
            else
                vD.push_back(x);
        }
        vector<int> res;
        res.reserve(n);
        while (!vD.empty()) {
            vector<int>* g1 = nullptr;
            vector<int>* g2 = nullptr;
            if (v2.size() >= 2) {
                g1 = &v2;
            } else if (v3.size() >= 2) {
                g1 = &v3;
            } else if (v6.size() >= 2) {
                g1 = &v6;
            } else if (!v6.empty() && !v2.empty()) {
                g1 = &v6;
                g2 = &v2;
            } else if (!v6.empty() && !v3.empty()) {
                g1 = &v6;
                g2 = &v3;
            } else
                break;
            if (g2 == nullptr) {
                res.push_back((*g1)[0]);
                res.push_back((*g1)[1]);
                g1->erase(g1->begin());
                g1->erase(g1->begin());
            } else {
                res.push_back((*g1)[0]);
                res.push_back((*g2)[0]);
                g1->erase(g1->begin());
                g2->erase(g2->begin());
            }
            res.push_back(vD.back());
            vD.pop_back();
        }
        for (int x : v6)
            res.push_back(x);
        for (int x : v2)
            res.push_back(x);
        for (int x : v3)
            res.push_back(x);
        for (int x : vD)
            res.push_back(x);

        auto countBad = [&]() {
            int cnt = 0;
            for (int i = 0; i + 2 < n; ++i) {
                if (isBadTriple(res[i], res[i + 1], res[i + 2]))
                    ++cnt;
            }
            return cnt;
        };
        int bad = countBad();
        if (bad > 6) {
            int adjust = 0;
            for (int i = 0; i + 2 < n && bad > 6 && adjust < 30; ++i) {
                if (isBadTriple(res[i], res[i + 1], res[i + 2])) {
                    int target = -1;
                    for (int j = i + 3; j < min(n, i + 15); ++j) {
                        if (gcd(res[i], res[j]) > 1 || gcd(res[i + 1], res[j]) > 1 ||
                            gcd(res[i + 2], res[j]) > 1) {
                            target = j;
                            break;
                        }
                    }
                    if (target != -1) {
                        int val = res[target];
                        for (int k = target; k > i + 2; --k)
                            res[k] = res[k - 1];
                        res[i + 2] = val;
                        bad = countBad();
                    }
                    ++adjust;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (i)
                cout << ' ';
            cout << res[i];
        }
        cout << '\n';
    }
    return 0;
}

