#include <iostream>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    int w = n;
    int l = 0;
    long long total_matches = 0;

    while (w >= 2 || l >= 2) {
        int matches_w = w / 2;
        int matches_l = l / 2;

        total_matches += matches_w + matches_l;

        int next_w = w - matches_w; // Winners stay, losers leave W
        int dropping_to_l = matches_w; // Losers from W go to L next round

        int next_l = l - matches_l; // Winners stay, losers eliminated

        w = next_w;
        l = next_l + dropping_to_l;
    }

    // Final match
    total_matches++;

    cout << total_matches << endl;
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

