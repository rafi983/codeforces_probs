#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long x;
        cin >> x;

        vector<long long> path;
        long long val = x;

        while (val > 0) {
            path.push_back(val);
            val = val / 2;
        }

        // Reverse the path
        reverse(path.begin(), path.end());

        long long actions = 2 * path.size() + 1;

        cout << actions << '\n';
    }

    return 0;
}

