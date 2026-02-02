#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Cell {
    long long dist;
    int x, y;
    bool operator>(const Cell& other) const {
        if (dist != other.dist) return dist > other.dist;
        if (x != other.x) return x > other.x;
        return y > other.y;
    }
};

struct CompareCell {
    bool operator()(const Cell& a, const Cell& b) {
        return a > b; // returns true if a is worse than b -> a goes down, b goes up.
    }
};

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> t(n);
    for (int i = 0; i < n; ++i) cin >> t[i];

    priority_queue<Cell, vector<Cell>, CompareCell> pq;

    long long current_S = 0;
    int current_X = 0;

    auto add_rest_of_table = [&](int X, int Y, long long S) {
        pq.push({3 * S + 3, 3 * X + 1, 3 * Y + 2});
        pq.push({3 * S + 3, 3 * X + 2, 3 * Y + 1});
        pq.push({3 * S + 6, 3 * X + 2, 3 * Y + 2});
    };

    auto advance_fresh = [&]() {
        current_X++;
        if (current_X > current_S) {
            current_S++;
            current_X = 0;
        }
    };

    for (int i = 0; i < n; ++i) {
        int curr_Y = current_S - current_X;
        Cell fresh_C0 = {3 * current_S + 2, 3 * current_X + 1, 3 * curr_Y + 1};

        bool take_fresh = false;

        if (t[i] == 0) {
            take_fresh = true;
        } else {
            if (pq.empty()) {
                take_fresh = true;
            } else {
                Cell best_pq = pq.top();
                if (best_pq > fresh_C0) {
                    take_fresh = true;
                } else {
                    take_fresh = false;
                }
            }
        }

        if (take_fresh) {
            cout << fresh_C0.x << " " << fresh_C0.y << "\n";
            add_rest_of_table(current_X, curr_Y, current_S);
            advance_fresh();
        } else {
            Cell best = pq.top();
            pq.pop();
            cout << best.x << " " << best.y << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    if (cin >> q) {
        while (q--) {
            solve();
        }
    }
    return 0;
}
