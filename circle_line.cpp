#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> d(n);
    int total = 0;

    for (int i = 0; i < n; ++i) {
        cin >> d[i];
        total += d[i];
    }

    int s, t;
    cin >> s >> t;

    if (s == t) {
        cout << "0\n";
        return 0;
    }

    if (s > t) {
        swap(s, t);
    }

    int dist_clockwise = 0;
    for (int i = s - 1; i < t - 1; ++i) {
        dist_clockwise += d[i];
    }

    int dist_counterclockwise = total - dist_clockwise;

    cout << min(dist_clockwise, dist_counterclockwise) << '\n';

    return 0;
}

