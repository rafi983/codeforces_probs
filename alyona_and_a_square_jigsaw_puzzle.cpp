#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    int current_sum = 0;
    int happy_days = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        current_sum += a;

        int root = round(sqrt(current_sum));
        if (root * root == current_sum && root % 2 != 0) {
            happy_days++;
        }
    }
    cout << happy_days << endl;
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

