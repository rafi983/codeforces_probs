#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

struct FenwickTree {
    int n;
    vector<int> tree;
    FenwickTree(int n) : n(n), tree(n + 1, 0) {}
    void add(int i, int delta) {
        for (++i; i <= n; i += i & -i) tree[i] += delta;
    }
    int query(int i) {
        int sum = 0;
        for (++i; i > 0; i -= i & -i) sum += tree[i];
        return sum;
    }
};

struct Block {
    int type;
    int len;
};

vector<Block> get_blocks(const string& s) {
    vector<Block> blocks;
    if (s.empty()) return blocks;
    int current_len = 0;
    char current_char = s[0];
    for (char c : s) {
        if (c == current_char) {
            current_len++;
        } else {
            blocks.push_back({current_char - '0', current_len});
            current_char = c;
            current_len = 1;
        }
    }
    blocks.push_back({current_char - '0', current_len});
    return blocks;
}

void solve() {
    string s, t_str;
    cin >> s >> t_str;

    if (s.length() != t_str.length()) {
        cout << -1 << endl;
        return;
    }

    int s0 = 0, s1 = 0;
    for(char c : s) if(c=='0') s0++; else s1++;
    int t0 = 0, t1 = 0;
    for(char c : t_str) if(c=='0') t0++; else t1++;
    if(s0 != t0 || s1 != t1) {
        cout << -1 << endl;
        return;
    }

    vector<Block> s_blocks = get_blocks(s);
    vector<Block> t_blocks = get_blocks(t_str);

    int n_blocks = s_blocks.size();
    vector<int> len(n_blocks);
    vector<int> type(n_blocks);
    vector<int> L(n_blocks), R(n_blocks);
    set<int> pos[2];
    FenwickTree bit(n_blocks);

    for (int i = 0; i < n_blocks; ++i) {
        len[i] = s_blocks[i].len;
        type[i] = s_blocks[i].type;
        L[i] = i - 1;
        R[i] = i + 1;
        if (i == n_blocks - 1) R[i] = -1;
        pos[type[i]].insert(i);
        bit.add(i, 1);
    }

    long long ops = 0;

    for (const auto& target : t_blocks) {
        int needed_len = target.len;
        int target_type = target.type;

        while (needed_len > 0) {
            if (pos[target_type].empty()) {
                cout << -1 << endl;
                return;
            }

            int idx = *pos[target_type].begin();

            if (len[idx] > needed_len) {
                cout << -1 << endl;
                return;
            }

            needed_len -= len[idx];

            ops += bit.query(idx - 1);

            bit.add(idx, -1);
            pos[target_type].erase(idx);

            int l = L[idx];
            int r = R[idx];

            if (l != -1) R[l] = r;
            if (r != -1) L[r] = l;

            if (l != -1 && r != -1) {
                len[l] += len[r];

                bit.add(r, -1);
                pos[1 - target_type].erase(r);

                int rr = R[r];
                R[l] = rr;
                if (rr != -1) L[rr] = l;
            }
        }
    }

    cout << ops << endl;
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

