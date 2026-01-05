#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct Segment {
    int id;
    int u, v;
    int weight;
    long long val;
    double density;
};

bool compareSegments(const Segment& a, const Segment& b) {
    return a.density > b.density;
}

long long f[100005][12];
int b_vals[12];
long long combined_b[1024];
int popcounts[1024];

void solve() {
    int n, m;
    long long k;
    cin >> n >> m >> k;

    vector<long long> a(n);
    long long initial_sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        initial_sum += a[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> b_vals[i];
    }

    // Precompute combined masks
    int num_masks = 1 << m;
    for (int mask = 0; mask < num_masks; ++mask) {
        long long combined = (1LL << 30) - 1;
        int cnt = 0;
        for (int j = 0; j < m; ++j) {
            if ((mask >> j) & 1) {
                combined &= b_vals[j];
                cnt++;
            }
        }
        combined_b[mask] = combined;
        popcounts[mask] = cnt;
    }

    vector<Segment> segments;
    segments.reserve(n * m);

    for (int i = 0; i < n; ++i) {
        // Compute f[i][c]
        for (int c = 0; c <= m; ++c) f[i][c] = 0;

        for (int mask = 0; mask < num_masks; ++mask) {
            int c = popcounts[mask];
            long long val = a[i] & combined_b[mask];
            long long reduction = a[i] - val;
            if (reduction > f[i][c]) {
                f[i][c] = reduction;
            }
        }

        for (int c = 1; c <= m; ++c) {
            if (f[i][c] < f[i][c-1]) f[i][c] = f[i][c-1];
        }

        // Concave Hull
        vector<int> hull;
        hull.push_back(0);
        for (int c = 1; c <= m; ++c) {
            while (hull.size() >= 2) {
                int p1 = hull[hull.size() - 2];
                int p2 = hull.back();
                int p3 = c;

                long long dy1 = f[i][p2] - f[i][p1];
                long long dx1 = p2 - p1;
                long long dy2 = f[i][p3] - f[i][p2];
                long long dx2 = p3 - p2;

                if (dy1 * dx2 <= dy2 * dx1) { // Use <= to remove collinear points too
                    hull.pop_back();
                } else {
                    break;
                }
            }
            hull.push_back(c);
        }

        // Create segments
        for (size_t j = 0; j < hull.size() - 1; ++j) {
            int u = hull[j];
            int v = hull[j+1];
            if (f[i][v] > f[i][u]) {
                segments.push_back({i, u, v, v - u, f[i][v] - f[i][u], (double)(f[i][v] - f[i][u]) / (v - u)});
            }
        }
    }

    sort(segments.begin(), segments.end(), compareSegments);

    long long total_reduction = 0;
    int seg_idx = 0;
    while (seg_idx < segments.size()) {
        if (k >= segments[seg_idx].weight) {
            k -= segments[seg_idx].weight;
            total_reduction += segments[seg_idx].val;
            seg_idx++;
        } else {
            break;
        }
    }

    // End game DP
    if (k > 0 && seg_idx < segments.size()) {
        vector<Segment> candidates;
        vector<bool> seen_id(n, false);

        int limit = min((int)segments.size(), seg_idx + 200);
        for (int j = seg_idx; j < limit; ++j) {
            if (!seen_id[segments[j].id]) {
                candidates.push_back(segments[j]);
                seen_id[segments[j].id] = true;
            }
        }

        vector<long long> dp(k + 1, -1);
        dp[0] = 0;

        for (const auto& seg : candidates) {
            vector<long long> next_dp = dp;
            int u = seg.u;
            int v = seg.v;
            int id = seg.id;

            for (int step = 1; step <= v - u; ++step) {
                if (step > k) break;
                long long gain = f[id][u + step] - f[id][u];
                int cost = step;

                for (int w = 0; w <= k - cost; ++w) {
                    if (dp[w] != -1) {
                        next_dp[w + cost] = max(next_dp[w + cost], dp[w] + gain);
                    }
                }
            }
            dp = next_dp;
        }

        long long max_extra = 0;
        for (long long val : dp) max_extra = max(max_extra, val);
        total_reduction += max_extra;
    }

    cout << initial_sum - total_reduction << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

