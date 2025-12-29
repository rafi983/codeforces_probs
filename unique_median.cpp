#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int OFFSET = 100005;
const int BIT_SIZE = 400005;
int bit[BIT_SIZE];

void update(int idx, int val) {
    for (; idx < BIT_SIZE; idx += idx & -idx)
        bit[idx] += val;
}

int query(int idx) {
    int sum = 0;
    for (; idx > 0; idx -= idx & -idx)
        sum += bit[idx];
    return sum;
}

struct Point {
    int x, y;
};

void count_pairs_optimized(vector<Point>& points, int l, int r, long long& res) {
    if (l >= r) return;
    int mid = l + (r - l) / 2;
    count_pairs_optimized(points, l, mid, res);
    count_pairs_optimized(points, mid + 1, r, res);



    int p1 = l;
    for (int p2 = mid + 1; p2 <= r; ++p2) {
        while (p1 <= mid && points[p1].x > points[p2].x) {
            update(points[p1].y, 1);
            p1++;
        }
        res += query(points[p2].y - 1);
    }

    // Cleanup BIT
    for (int k = l; k < p1; ++k) {
        update(points[k].y, -1);
    }

    // Merge step to keep sorted by x descending
    inplace_merge(points.begin() + l, points.begin() + mid + 1, points.begin() + r + 1,
        [](const Point& a, const Point& b) {
            return a.x > b.x;
        });
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    long long total_good = 0;
    // Count odd length subarrays
    for (int len = 1; len <= n; len += 2) {
        total_good += (long long)(n - len + 1);
    }

    // For each v from 1 to 10
    for (int v = 1; v <= 10; ++v) {
        vector<int> P(n + 1, 0);
        vector<int> Q(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            int val = 0;
            if (a[i] > v) val = 1;
            else if (a[i] < v) val = -1;

            P[i+1] = P[i] + val;
            Q[i+1] = Q[i] + (a[i] == v ? 1 : 0);
        }

        vector<Point> even_points, odd_points;
        even_points.reserve(n/2 + 2);
        odd_points.reserve(n/2 + 2);

        for (int i = 0; i <= n; ++i) {
            int X = P[i] - Q[i];
            int Y = P[i] + Q[i];
            Y += OFFSET;

            if (i % 2 == 0) {
                even_points.push_back({X, Y});
            } else {
                odd_points.push_back({X, Y});
            }
        }

        if (!even_points.empty())
            count_pairs_optimized(even_points, 0, even_points.size() - 1, total_good);
        if (!odd_points.empty())
            count_pairs_optimized(odd_points, 0, odd_points.size() - 1, total_good);
    }

    cout << total_good << endl;
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

