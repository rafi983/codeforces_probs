#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

struct Segment {
    int L, R;
    mutable int missing_cnt;
    mutable vector<int> counts; // Only if R - L + 1 >= target_size

    bool operator<(const Segment& other) const {
        return L < other.L;
    }
};

int N, Q;
vector<int> A;

struct Level {
    int k;
    int target; // 2^k
    set<Segment> segments;
    multiset<int> good_lengths;

    void add_good(int len) {
        good_lengths.insert(len);
    }

    void remove_good(int len) {
        auto it = good_lengths.find(len);
        if (it != good_lengths.end()) {
            good_lengths.erase(it);
        }
    }

    void init(const vector<int>& a) {
        int n = a.size();
        int l = 0;
        while (l < n) {
            if (a[l] >= target) {
                l++;
                continue;
            }
            int r = l;
            while (r + 1 < n && a[r + 1] < target) {
                r++;
            }
            create_segment(l, r, a);
            l = r + 1;
        }
    }

    void create_segment(int l, int r, const vector<int>& a) {
        Segment seg;
        seg.L = l;
        seg.R = r;
        int len = r - l + 1;
        if (len >= target) {
            seg.counts.assign(target, 0);
            seg.missing_cnt = target;
            for (int i = l; i <= r; ++i) {
                if (seg.counts[a[i]] == 0) {
                    seg.missing_cnt--;
                }
                seg.counts[a[i]]++;
            }
            if (seg.missing_cnt == 0) {
                add_good(len);
            }
        } else {
            seg.missing_cnt = -1;
        }
        segments.insert(move(seg));
    }

    void update(int idx, int old_val, int new_val);

    // Helper for in-place update
    void update_inplace(const set<Segment>::iterator& it, int old_val, int new_val) {
        if (it->missing_cnt != -1) {
            bool was_good = (it->missing_cnt == 0);
            if (was_good) remove_good(it->R - it->L + 1);

            if (it->counts[old_val] == 1) it->missing_cnt++;
            it->counts[old_val]--;

            if (it->counts[new_val] == 0) it->missing_cnt--;
            it->counts[new_val]++;

            if (it->missing_cnt == 0) add_good(it->R - it->L + 1);
        }
    }
};

// Need to fix the update method to use update_inplace
void Level::update(int idx, int old_val, int new_val) {
    auto it = segments.upper_bound({idx, 0, 0, {}});
    if (it == segments.begin()) return;
    --it;

    if (it->R < idx) return;

    if (new_val < target) {
        update_inplace(it, old_val, new_val);
    } else {
        // Split logic (same as before)
        auto node = segments.extract(it);
        Segment& seg = node.value();

        if (seg.missing_cnt == 0) {
            remove_good(seg.R - seg.L + 1);
        }

        int left_len = idx - seg.L;
        int right_len = seg.R - idx;

        if (seg.missing_cnt == -1) {
            if (left_len > 0) segments.insert({seg.L, idx - 1, -1, {}});
            if (right_len > 0) segments.insert({idx + 1, seg.R, -1, {}});
        } else {
            seg.counts[old_val]--;
            if (seg.counts[old_val] == 0) seg.missing_cnt++;

            bool left_big = (left_len >= target);
            bool right_big = (right_len >= target);

            if (left_big && right_big) {
                if (left_len >= right_len) {
                    Segment left_seg;
                    left_seg.L = seg.L;
                    left_seg.R = idx - 1;
                    left_seg.counts = move(seg.counts);
                    left_seg.missing_cnt = seg.missing_cnt;

                    for (int i = idx + 1; i <= seg.R; ++i) {
                        int val = A[i];
                        if (left_seg.counts[val] == 1) left_seg.missing_cnt++;
                        left_seg.counts[val]--;
                    }
                    if (left_seg.missing_cnt == 0) add_good(left_len);
                    segments.insert(move(left_seg));
                    create_segment(idx + 1, seg.R, A);
                } else {
                    Segment right_seg;
                    right_seg.L = idx + 1;
                    right_seg.R = seg.R;
                    right_seg.counts = move(seg.counts);
                    right_seg.missing_cnt = seg.missing_cnt;

                    for (int i = seg.L; i < idx; ++i) {
                        int val = A[i];
                        if (right_seg.counts[val] == 1) right_seg.missing_cnt++;
                        right_seg.counts[val]--;
                    }
                    if (right_seg.missing_cnt == 0) add_good(right_len);
                    segments.insert(move(right_seg));
                    create_segment(seg.L, idx - 1, A);
                }
            } else if (left_big) {
                Segment left_seg;
                left_seg.L = seg.L;
                left_seg.R = idx - 1;
                left_seg.counts = move(seg.counts);
                left_seg.missing_cnt = seg.missing_cnt;

                for (int i = idx + 1; i <= seg.R; ++i) {
                    int val = A[i];
                    if (left_seg.counts[val] == 1) left_seg.missing_cnt++;
                    left_seg.counts[val]--;
                }
                if (left_seg.missing_cnt == 0) add_good(left_len);
                segments.insert(move(left_seg));

                if (right_len > 0) segments.insert({idx + 1, seg.R, -1, {}});
            } else if (right_big) {
                Segment right_seg;
                right_seg.L = idx + 1;
                right_seg.R = seg.R;
                right_seg.counts = move(seg.counts);
                right_seg.missing_cnt = seg.missing_cnt;

                for (int i = seg.L; i < idx; ++i) {
                    int val = A[i];
                    if (right_seg.counts[val] == 1) right_seg.missing_cnt++;
                    right_seg.counts[val]--;
                }
                if (right_seg.missing_cnt == 0) add_good(right_len);
                segments.insert(move(right_seg));

                if (left_len > 0) segments.insert({seg.L, idx - 1, -1, {}});
            } else {
                if (left_len > 0) segments.insert({seg.L, idx - 1, -1, {}});
                if (right_len > 0) segments.insert({idx + 1, seg.R, -1, {}});
            }
        }
    }
}

vector<Level> levels;

void solve() {
    cin >> N >> Q;
    A.resize(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    levels.clear();
    for (int k = 0; k < 20; ++k) {
        if ((1 << k) > N) break;
        Level lvl;
        lvl.k = k;
        lvl.target = 1 << k;
        lvl.init(A);
        levels.push_back(move(lvl));
    }

    for (int q = 0; q < Q; ++q) {
        int idx, x;
        cin >> idx >> x;
        --idx;
        int old_val = A[idx];
        A[idx] += x;
        int new_val = A[idx];

        for (auto& lvl : levels) {
            lvl.update(idx, old_val, new_val);
        }

        int max_len = 0;
        for (auto& lvl : levels) {
            if (!lvl.good_lengths.empty()) {
                max_len = max(max_len, *lvl.good_lengths.rbegin());
            }
        }
        cout << max_len << "\n";
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

