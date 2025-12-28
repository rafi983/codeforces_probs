#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Cow {
    int id;
    vector<int> cards;
};

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<Cow> cows(n);
    for (int i = 0; i < n; ++i) {
        cows[i].id = i + 1;
        cows[i].cards.resize(m);
        for (int j = 0; j < m; ++j) {
            cin >> cows[i].cards[j];
        }
        sort(cows[i].cards.begin(), cows[i].cards.end());
    }

    // Check if each cow's cards form an arithmetic progression with difference n
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (cows[i].cards[j] != cows[i].cards[0] + j * n) {
                cout << -1 << endl;
                return;
            }
        }
    }

    // Sort cows based on their smallest card
    sort(cows.begin(), cows.end(), [](const Cow& a, const Cow& b) {
        return a.cards[0] < b.cards[0];
    });

    // Check if the smallest cards are 0, 1, ..., n-1
    for (int i = 0; i < n; ++i) {
        if (cows[i].cards[0] != i) {
            cout << -1 << endl;
            return;
        }
    }

    // Output the permutation
    for (int i = 0; i < n; ++i) {
        cout << cows[i].id << (i == n - 1 ? "" : " ");
    }
    cout << endl;
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

