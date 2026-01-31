#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

char get_missing(char a, char b) {
    if (a > b) swap(a, b);
    if (a == 'I' && b == 'L') return 'T';
    if (a == 'I' && b == 'T') return 'L';
    if (a == 'L' && b == 'T') return 'I';
    return ' ';
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    set<char> distinct_chars;
    for (char c : s) distinct_chars.insert(c);

    if (distinct_chars.size() < 2) {
        cout << -1 << endl;
        return;
    }

    vector<int> ops;


    while (true) {
        map<char, int> counts;
        counts['L'] = 0;
        counts['I'] = 0;
        counts['T'] = 0;
        for (char c : s) counts[c]++;

        int max_c = max({counts['L'], counts['I'], counts['T']});
        if (counts['L'] == max_c && counts['I'] == max_c && counts['T'] == max_c) {
            break;
        }

        if (ops.size() >= 2 * n) {
             cout << -1 << endl;
             return;
        }

        char best_needed = ' ';
        int best_idx = -1;


        bool found = false;

        for (int i = 0; i < s.length() - 1; ++i) {
            if (s[i] == s[i+1]) continue;

            char produced = get_missing(s[i], s[i+1]);
            if (counts[produced] < max_c) {
                best_idx = i;
                best_needed = produced;
                found = true;
                break;
            }
        }

        if (!found) {
             for (int i = 0; i < s.length() - 1; ++i) {
                 if (s[i] != s[i+1]) {
                     best_idx = i;
                     best_needed = get_missing(s[i], s[i+1]);
                     found = true;
                     break;
                 }
             }
        }

        if (!found) {
            cout << -1 << endl;
            return;
        }

        ops.push_back(best_idx + 1);

        string next_s = s.substr(0, best_idx + 1);
        next_s += best_needed;
        next_s += s.substr(best_idx + 1);
        s = next_s;
    }

    cout << ops.size() << endl;
    for (int op : ops) {
        cout << op << endl;
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
