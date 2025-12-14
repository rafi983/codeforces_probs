#include <bits/stdc++.h>
using namespace std;

static inline bool isPerfectSquare(long long x) {
    if (x < 0) return false;

    long long r = (long long) sqrtl((long double)x);
    while (r * r < x) ++r;
    while (r * r > x) --r;

    return r * r == x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int n;
        cin >> n;

        long long total = 1LL * n * (n + 1) / 2;
        if (isPerfectSquare(total)) {
            cout << -1 << '\n';
            continue;
        }

        priority_queue<int> pq;
        for (int i = 1; i <= n; ++i) {
            pq.push(i);
        }

        long long S = 0;
        vector<int> ans;
        ans.reserve(n);

        for (int i = 0; i < n; ++i) {
            bool placed = false;
            vector<int> buffer;

            while (!pq.empty()) {
                int v = pq.top();
                pq.pop();

                if (!isPerfectSquare(S + v)) {
                    ans.push_back(v);
                    S += v;
                    placed = true;

                    for (int b : buffer) {
                        pq.push(b);
                    }
                    break;
                } else {
                    buffer.push_back(v);
                }
            }

            if (!placed) {
                for (int b : buffer) {
                    pq.push(b);
                }

                vector<int> tmp;
                while (!pq.empty()) {
                    tmp.push_back(pq.top());
                    pq.pop();
                }
                reverse(tmp.begin(), tmp.end());

                bool ok = false;
                for (int idx = 0; idx < (int)tmp.size(); ++idx) {
                    int v = tmp[idx];
                    if (!isPerfectSquare(S + v)) {
                        ans.push_back(v);
                        S += v;
                        ok = true;

                        for (int j = 0; j < (int)tmp.size(); ++j) {
                            if (j != idx) {
                                pq.push(tmp[j]);
                            }
                        }
                        break;
                    }
                }

                if (!ok) {
                    ans.clear();
                    break;
                }
            }
        }

        if (ans.empty()) {
            cout << -1 << '\n';
        } else {
            for (int i = 0; i < n; ++i) {
                if (i) cout << ' ';
                cout << ans[i];
            }
            cout << '\n';
        }
    }

    return 0;
}

