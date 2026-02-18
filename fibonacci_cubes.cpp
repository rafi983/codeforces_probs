#include <bits/stdc++.h>
using namespace std;

namespace {
struct StateHash {
    size_t operator()(const vector<array<int,3>>& boxes) const noexcept {
        // Boxes are assumed sorted; hash via FNV-1a.
        uint64_t h = 14695981039346656037ull;
        for (const auto &b : boxes) {
            h ^= static_cast<uint64_t>(b[0]); h *= 1099511628211ull;
            h ^= static_cast<uint64_t>(b[1]); h *= 1099511628211ull;
            h ^= static_cast<uint64_t>(b[2]); h *= 1099511628211ull;
        }
        return static_cast<size_t>(h);
    }
};

struct StateEq {
    bool operator()(const vector<array<int,3>>& a, const vector<array<int,3>>& b) const noexcept {
        return a == b;
    }
};
}

class Packer {
public:
    explicit Packer(const vector<int>& cubes) : cubes_(cubes) {}

    bool canFit(int A, int B, int C) {
        array<int,3> box = {A, B, C};
        sort(box.begin(), box.end(), greater<int>());
        vector<array<int,3>> boxes = {box};
        memo_.clear();
        return dfs(0, boxes);
    }

private:
    const vector<int>& cubes_;
    unordered_set<vector<array<int,3>>, StateHash, StateEq> memo_;

    static void normalizeBox(array<int,3>& b) {
        sort(b.begin(), b.end(), greater<int>());
    }

    static void normalize(vector<array<int,3>>& boxes) {
        for (auto &b : boxes) normalizeBox(b);
        sort(boxes.begin(), boxes.end(), [](const auto &x, const auto &y) {
            if (x[0] != y[0]) return x[0] > y[0];
            if (x[1] != y[1]) return x[1] > y[1];
            return x[2] > y[2];
        });
    }

    bool dfs(int idx, vector<array<int,3>>& boxes) {
        if (idx == static_cast<int>(cubes_.size())) return true;
        int s = cubes_[idx];

        bool possible = false;
        for (const auto &b : boxes) if (b[2] >= s) { possible = true; break; }
        if (!possible) return false;

        normalize(boxes);
        if (memo_.find(boxes) != memo_.end()) return false;

        for (int i = 0; i < static_cast<int>(boxes.size()); ++i) {
            auto b = boxes[i];
            if (b[2] < s) continue;
            vector<array<int,3>> next;
            next.reserve(boxes.size() + 2);
            for (int j = 0; j < static_cast<int>(boxes.size()); ++j) if (j != i) next.push_back(boxes[j]);

            int X = b[0], Y = b[1], Z = b[2];
            if (X > s) next.push_back({X - s, Y, Z});
            if (Y > s) next.push_back({s, Y - s, Z});
            if (Z > s) next.push_back({s, s, Z - s});

            normalize(next);
            if (dfs(idx + 1, next)) return true;
        }

        memo_.insert(boxes);
        return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> fib(11);
    fib[1] = 1; fib[2] = 2;
    for (int i = 3; i <= 10; ++i) fib[i] = fib[i - 1] + fib[i - 2];

    int T; cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        vector<int> cubes;
        for (int i = n; i >= 1; --i) cubes.push_back(fib[i]); // descending sizes
        long long totalVol = 0;
        for (int s : cubes) totalVol += 1LL * s * s * s;

        unordered_map<int, bool> cache; // cache per distinct box dims in this test
        string ans;
        ans.reserve(m);
        for (int i = 0; i < m; ++i) {
            int w, l, h; cin >> w >> l >> h;
            array<int,3> box = {w, l, h};
            sort(box.begin(), box.end(), greater<int>());
            int key = (box[0] << 16) | (box[1] << 8) | box[2];
            auto it = cache.find(key);
            if (it != cache.end()) {
                ans.push_back(it->second ? '1' : '0');
                continue;
            }

            bool ok = true;
            if (box[2] < cubes.back()) ok = false;
            if (ok) {
                long long boxVol = 1LL * box[0] * box[1] * box[2];
                if (boxVol < totalVol) ok = false;
            }
            if (ok) {
                Packer packer(cubes);
                ok = packer.canFit(box[0], box[1], box[2]);
            }
            cache[key] = ok;
            ans.push_back(ok ? '1' : '0');
        }
        cout << ans << '\n';
    }
    return 0;
}

