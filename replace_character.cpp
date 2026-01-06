#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    string s;
    cin >> s;

    map<char, int> counts;
    for (char c : s) {
        counts[c]++;
    }

    char best_u = s[0];
    char best_v = s[0];
    long long best_num = 1;
    long long best_den = 1;

    for (auto const& [u, count_u] : counts) {
        for (auto const& [v, count_v] : counts) {
            if (u == v) continue;

            long long curr_num = count_v + 1;
            long long curr_den = count_u;

            if (curr_num * best_den > best_num * curr_den) {
                best_num = curr_num;
                best_den = curr_den;
                best_u = u;
                best_v = v;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (s[i] == best_u) {
            s[i] = best_v;
            break;
        }
    }

    cout << s << endl;
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

