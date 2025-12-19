#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

struct Monster {
    int b;
    int c;

    Monster() : b(0), c(0) {}
    Monster(int b_val, int c_val) : b(b_val), c(c_val) {}
};

bool cmp_pos(const Monster& x, const Monster& y) {
    if (x.b != y.b)
        return x.b < y.b;
    return x.c > y.c;
}

bool cmp_zero(const Monster& x, const Monster& y) {
    return x.b < y.b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<int> b(m);
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }

        vector<int> c(m);
        for (int i = 0; i < m; ++i) {
            cin >> c[i];
        }

        multiset<int> s;
        for (int x : a) {
            s.insert(x);
        }

        vector<Monster> pos;
        vector<Monster> zero;

        for (int i = 0; i < m; ++i) {
            if (c[i] > 0) {
                pos.push_back(Monster(b[i], c[i]));
            } else {
                zero.push_back(Monster(b[i], 0));
            }
        }

        if (!pos.empty()) {
            sort(pos.begin(), pos.end(), cmp_pos);
        }
        if (!zero.empty()) {
            sort(zero.begin(), zero.end(), cmp_zero);
        }

        int kills = 0;

        for (const Monster& monster : pos) {
            auto it = s.lower_bound(monster.b);
            if (it == s.end())
                continue;
            int x = *it;
            s.erase(it);
            int nw = max(x, monster.c);
            s.insert(nw);
            ++kills;
        }

        for (const Monster& monster : zero) {
            auto it = s.lower_bound(monster.b);
            if (it == s.end())
                continue;
            s.erase(it);
            ++kills;
        }

        cout << kills << '\n';
    }

    return 0;
}

