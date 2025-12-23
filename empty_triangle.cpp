#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <random>
#include <chrono>
#include <cstdlib>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int query(int i, int j, int k) {
    cout << "? " << i << " " << j << " " << k << endl;
    int res;
    cin >> res;
    if (res == -1) exit(0);
    return res;
}

void answer(int i, int j, int k) {
    cout << "! " << i << " " << j << " " << k << endl;
}

void solve() {
    int n;
    if (!(cin >> n)) exit(0);
    if (n == -1) exit(0);

    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    shuffle(p.begin(), p.end(), rng);

    int a = p[0];
    int b = p[1];
    int c = p[2];

    for (int q = 0; q < 75; ++q) {
        int res = query(a, b, c);
        if (res == 0) {
            answer(a, b, c);
            return;
        } else {
            int choice = rng() % 3;
            if (choice == 0) a = res;
            else if (choice == 1) b = res;
            else c = res;
        }
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

