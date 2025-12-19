#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    string s;
    cin >> s;

    int balloons = 0;
    vector<bool> solved(26, false);

    for (char c : s) {
        int index = c - 'A';
        if (!solved[index]) {
            balloons += 2;
            solved[index] = true;
        } else {
            balloons += 1;
        }
    }

    cout << balloons << "\n";
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

