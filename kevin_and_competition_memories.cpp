#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> b(m);
    for (int i = 0; i < m; ++i) cin >> b[i];

    long long kevin_rating = a[0];

    vector<int> hard_problems;
    hard_problems.reserve(m);
    for (int x : b) {
        if (x > kevin_rating) {
            hard_problems.push_back(x);
        }
    }
    sort(hard_problems.begin(), hard_problems.end());

    sort(a.begin(), a.end());

    vector<int> hard_ranks;
    hard_ranks.reserve(hard_problems.size());
    for (int h : hard_problems) {
        auto it = lower_bound(a.begin(), a.end(), h);
        int count = distance(it, a.end());
        hard_ranks.push_back(1 + count);
    }

    int num_hard = hard_ranks.size();

    for (int k = 1; k <= m; ++k) {
        int num_contests = m / k;

        int rem = m % k;
        long long total_rank = 0;

        if (rem >= num_hard) {
            total_rank = num_contests;
        } else {
            int current_idx = rem;
            int hard_contests_count = 0;

            while (current_idx < num_hard) {
                total_rank += hard_ranks[current_idx];
                hard_contests_count++;
                current_idx += k;
            }

            int easy_contests_count = num_contests - hard_contests_count;
            total_rank += easy_contests_count;
        }

        cout << total_rank << (k == m ? "" : " ");
    }
    cout << "\n";
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
