#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Candidate {
    int score;
    long long L, R;
};

// Function to check if A dominates B
bool dominates(const Candidate& a, const Candidate& b) {
    return a.score >= b.score && a.L <= b.L && a.R >= b.R;
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<long long> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    if (n == 1) {
        cout << 0 << "\n";
        return;
    }

    vector<long long> d(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        d[i] = x[i+1] - x[i];
    }



    // Initial candidates corresponding to r_1
    // We can think of this as: we have a candidate {0, 0, 2e18} (effectively infinity)
    vector<Candidate> candidates;
    candidates.push_back({0, 0, 2000000000000000000LL});

    for (int i = 0; i < n - 1; ++i) {
        long long dist = d[i];
        vector<Candidate> next_candidates;



        vector<pair<int, long long>> best_skips; // score -> max_K

        for (const auto& cand : candidates) {

            long long nL = max(0LL, dist - cand.R);
            long long nR = dist - cand.L;

            if (nL < nR) {
                next_candidates.push_back({cand.score + 1, nL, nR});
            }

            long long K = dist - cand.L;
            if (K > 0) {
                bool found = false;
                for(auto& p : best_skips) {
                    if (p.first == cand.score) {
                        p.second = max(p.second, K);
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    best_skips.push_back({cand.score, K});
                }
            }
        }

        // Add best skips to next_candidates
        for (const auto& p : best_skips) {
            next_candidates.push_back({p.first, 0, p.second});
        }

        // Pruning
        if (next_candidates.empty()) {
            candidates = {};
            break;
        }

        sort(next_candidates.begin(), next_candidates.end(), [](const Candidate& a, const Candidate& b) {
            if (a.score != b.score) return a.score > b.score;
            if (a.L != b.L) return a.L < b.L;
            return a.R > b.R;
        });

        vector<Candidate> pruned;
        for (const auto& cand : next_candidates) {
            bool dominated = false;
            for (const auto& p : pruned) {
                if (dominates(p, cand)) {
                    dominated = true;
                    break;
                }
            }
            if (!dominated) {
                pruned.push_back(cand);
            }
        }
        candidates = pruned;
    }

    int max_score = 0;
    for (const auto& cand : candidates) {
        max_score = max(max_score, cand.score);
    }
    cout << max_score << "\n";
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
