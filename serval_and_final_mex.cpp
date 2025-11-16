#include <bits/stdc++.h>
using namespace std;

int mex2(int a, int b) {
    if (a != 0 && b != 0) return 0;
    if ((a == 0 && b == 1) || (a == 1 && b == 0)) return 2;
    if (a == 0 || b == 0) return 1;
    if (a == 1 && b == 1) return 0;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<pair<int, int>> ops;
        bool has0 = find(a.begin(), a.end(), 0) != a.end();

        if (!has0) {
            ops.push_back({1, n});
        } else {
            while (true) {
                int idx = -1;
                for (int i = 0; i < (int)a.size(); i++) {
                    if (a[i] == 0) {
                        idx = i;
                        break;
                    }
                }
                if (idx == -1) break;

                int m = a.size();
                if (m == 1) break;

                int l, r;
                if (idx == m - 1) {
                    l = idx - 1;
                    r = idx;
                } else {
                    l = idx;
                    r = idx + 1;
                }

                int x = mex2(a[l], a[r]);
                ops.push_back({l + 1, r + 1});
                a.erase(a.begin() + l, a.begin() + r + 1);
                a.insert(a.begin() + l, x);
            }

            if (a.size() > 1) {
                bool zero = false;
                for (int v : a) {
                    if (v == 0) {
                        zero = true;
                        break;
                    }
                }

                if (!zero) {
                    ops.push_back({1, (int)a.size()});
                } else {
                    int idx = -1;
                    for (int i = 0; i < (int)a.size(); i++) {
                        if (a[i] == 0) {
                            idx = i;
                            break;
                        }
                    }

                    if (idx != -1) {
                        int m = a.size();
                        int l, r;
                        if (idx == m - 1) {
                            l = idx - 1;
                            r = idx;
                        } else {
                            l = idx;
                            r = idx + 1;
                        }
                        int x = mex2(a[l], a[r]);
                        ops.push_back({l + 1, r + 1});
                        a.erase(a.begin() + l, a.begin() + r + 1);
                        a.insert(a.begin() + l, x);
                    }

                    bool z = false;
                    for (int v : a) {
                        if (v == 0) {
                            z = true;
                            break;
                        }
                    }
                    if (!z) ops.push_back({1, (int)a.size()});
                }
            }
        }

        cout << ops.size() << "\n";
        for (auto &p : ops) {
            cout << p.first << " " << p.second << "\n";
        }
    }

    return 0;
}

