#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        string a;
        int m;
        string b, c;
        cin >> n;
        cin >> a;
        cin >> m;
        cin >> b;
        cin >> c;

        deque<char> res;
        for (char ch : a) res.push_back(ch);

        for (int i = 0; i < m; ++i) {
            if (c[i] == 'V') {
                res.push_front(b[i]);
            } else { // 'D'
                res.push_back(b[i]);
            }
        }

        string out;
        out.reserve(res.size());
        while (!res.empty()) {
            out.push_back(res.front());
            res.pop_front();
        }
        cout << out << '\n';
    }
    return 0;
}

