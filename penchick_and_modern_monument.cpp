#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    map<int, int> freq;
    int max_freq = 0;
    for (int i = 0; i < n; ++i) {
        int h;
        cin >> h;
        freq[h]++;
        max_freq = max(max_freq, freq[h]);
    }
    cout << n - max_freq << endl;
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
