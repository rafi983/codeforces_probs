#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solve_for_2026(int len, const string& str) {
    if (len < 4) return 100;
    int min_changes = 100;
    string target = "2026";

    for (int i = 0; i <= len - 4; ++i) {
        int changes = 0;
        for (int j = 0; j < 4; ++j) {
            if (str[i + j] != target[j]) {
                changes++;
            }
        }
        if (changes < min_changes) {
            min_changes = changes;
        }
    }
    return min_changes;
}

int solve_avoid_2025(const string& str) {


    vector<int> costs(4, 100);
    costs[0] = 0;

    char allowed_chars[] = {'0', '2', '5', '6'};

    for (char current_char : str) {
        vector<int> next_costs(4, 100);

        for (int state = 0; state < 4; ++state) {
            if (costs[state] >= 100) continue;

            for (char c : allowed_chars) {
                int cost_increment = (c == current_char ? 0 : 1);
                int next_state = 0;

                // KMP-style transitions for "2025"
                if (state == 0) {
                    if (c == '2') next_state = 1;
                    else next_state = 0;
                } else if (state == 1) { // "2"
                    if (c == '0') next_state = 2;
                    else if (c == '2') next_state = 1;
                    else next_state = 0;
                } else if (state == 2) { // "20"
                    if (c == '2') next_state = 3;
                    else if (c == '0') next_state = 0;
                    else next_state = 0;
                } else if (state == 3) { // "202"
                    if (c == '5') next_state = 4; // "2025" - Forbidden
                    else if (c == '2') next_state = 1;
                    else if (c == '0') next_state = 2;
                    else next_state = 0;
                }

                if (next_state != 4) {
                    next_costs[next_state] = min(next_costs[next_state], costs[state] + cost_increment);
                }
            }
        }
        costs = next_costs;
    }

    int result = 100;
    for (int c : costs) {
        result = min(result, c);
    }
    return result;
}

void zaman() {
    int n;
    if (!(cin >> n)) return;
    string s;
    cin >> s;

    int opt1 = solve_for_2026(n, s);
    int opt2 = solve_avoid_2025(s);

    cout << min(opt1, opt2) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            zaman();
        }
    }
    return 0;
}
