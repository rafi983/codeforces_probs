#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void solve() {
    string s;
    cin >> s;
    map<int, int> counts;
    for (char c : s) {
        counts[c - '0']++;
    }

    string result = "";
    for (int i = 1; i <= 10; ++i) {
        int min_val = 10 - i;
        for (int d = 0; d <= 9; ++d) {
            if (counts[d] > 0 && d >= min_val) {
                // Try picking d
                counts[d]--;

                vector<int> remaining;
                for (auto const& [val, count] : counts) {
                    for (int k = 0; k < count; ++k) {
                        remaining.push_back(val);
                    }
                }

                bool possible = true;
                for (int k = 0; k < remaining.size(); ++k) {
                    if (remaining[k] < k) {
                        possible = false;
                        break;
                    }
                }

                if (possible) {
                    result += (char)('0' + d);
                    // counts[d] is already decremented, move to next position
                    goto next_pos;
                } else {
                    // Backtrack
                    counts[d]++;
                }
            }
        }
        next_pos:;
    }
    cout << result << endl;
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

