#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    string s;
    cin >> s;

    vector<pair<int, int>> blocks;
    int i = 0;
    while (i < n) {
        if (s[i] == '0') {
            int start = i;
            while (i < n && s[i] == '0') i++;
            blocks.push_back({start + 1, i}); // 1-based indices
        } else {
            i++;
        }
    }

    if (blocks.empty()) {
        cout << (n > 0 ? 1 : 0) << "\n";
        return;
    }

    vector<int> seps;
    // Before first block
    seps.push_back(blocks[0].first - 1);

    // Between blocks
    for (size_t k = 0; k < blocks.size() - 1; ++k) {
        seps.push_back(blocks[k + 1].first - blocks[k].second - 1);
    }

    // After last block
    seps.push_back(n - blocks.back().second);

    long long max_size = 0;
    bool has_ones = false;
    for (char c : s) {
        if (c == '1') {
            has_ones = true;
            break;
        }
    }
    if (has_ones) max_size = 1;

    auto get_U = [&](int L, int R) {
        long long count = R - L + 1;
        return (1LL * (L - 1 + R - 1) * count) / 2;
    };

    auto get_D = [&](int L, int R) {
        long long count = R - L + 1;
        return (1LL * (n - L + n - R) * count) / 2;
    };

    // Process first block
    long long current_U = get_U(blocks[0].first, blocks[0].second);
    long long comp_size = current_U;
    if (seps[0] > 0) {
        comp_size += 1;
    }
    max_size = max(max_size, comp_size);

    long long current_D = get_D(blocks[0].first, blocks[0].second);
    long long pending_size = current_D;

    for (size_t k = 0; k < blocks.size() - 1; ++k) {
        int sep_len = seps[k + 1];
        long long next_U = get_U(blocks[k + 1].first, blocks[k + 1].second);
        long long next_D = get_D(blocks[k + 1].first, blocks[k + 1].second);

        if (sep_len == 1) {
            // Merge D of current block with U of next block
            long long merged = pending_size + 1 + next_U;
            max_size = max(max_size, merged);
            // The chain breaks here for the next step, next component starts with next_D
            pending_size = next_D;
        } else {
            // sep_len > 1
            // Current D connects to first 1
            max_size = max(max_size, pending_size + 1);

            // Next U connects to last 1
            max_size = max(max_size, 1 + next_U);

            // Next D starts new component
            pending_size = next_D;
        }
    }

    // Process last block D
    if (seps.back() > 0) {
        pending_size += 1;
    }
    max_size = max(max_size, pending_size);

    cout << max_size << "\n";
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

