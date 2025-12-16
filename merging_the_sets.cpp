#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <set>

using namespace std;

const int MAXN = 50005;
const int MAXM = 100005;

int n, m;
vector<int> sets[MAXN];
vector<int> element_in_sets[MAXM];
int set_status[MAXN]; // 0: undecided, 1: IN, -1: OUT
int el_freq[MAXM]; // number of non-OUT sets covering element
int el_covered[MAXM]; // number of IN sets covering element
int uncovered_cnt;
int undecided_cnt;
long long solutions_found;

struct Change {
    int type; // 0: set_status, 1: el_freq, 2: el_covered, 3: uncovered_cnt, 4: undecided_cnt
    int idx;
    int old_val;
};

set<pair<int, int>> priority_elements;

void add_change(vector<Change>& log, int type, int idx, int old_val) {
    log.push_back({type, idx, old_val});
}

void update_priority(int el, int old_freq, int new_freq, bool was_uncovered, bool is_uncovered) {
    if (was_uncovered) {
        priority_elements.erase({old_freq, el});
    }
    if (is_uncovered) {
        priority_elements.insert({new_freq, el});
    }
}

void set_in(int u, vector<Change>& log) {
    if (set_status[u] != 0) return; // Already set

    add_change(log, 0, u, 0);
    set_status[u] = 1;

    add_change(log, 4, 0, undecided_cnt);
    undecided_cnt--;

    for (int el : sets[u]) {
        int old_cov = el_covered[el];
        add_change(log, 2, el, old_cov);
        el_covered[el]++;

        if (old_cov == 0) {
            // Was uncovered, now covered
            add_change(log, 3, 0, uncovered_cnt);
            uncovered_cnt--;

            // Remove from priority
            update_priority(el, el_freq[el], el_freq[el], true, false);
        }
    }
}

void set_out(int u, vector<Change>& log) {
    if (set_status[u] != 0) return;

    add_change(log, 0, u, 0);
    set_status[u] = -1;

    add_change(log, 4, 0, undecided_cnt);
    undecided_cnt--;

    for (int el : sets[u]) {
        int old_freq = el_freq[el];
        add_change(log, 1, el, old_freq);
        el_freq[el]--;

        if (el_covered[el] == 0) {
            // Still uncovered, update priority
            update_priority(el, old_freq, el_freq[el], true, true);
        }
    }
}

bool propagate(vector<Change>& log) {
    while (true) {
        if (priority_elements.empty()) return true; // All covered

        pair<int, int> top = *priority_elements.begin();
        if (top.first == 0) return false; // Impossible

        if (top.first == 1) {
            int el = top.second;
            // Find the single available set
            int forced_set = -1;
            for (int s : element_in_sets[el]) {
                if (set_status[s] != -1) {
                    forced_set = s;
                    break;
                }
            }
            if (forced_set == -1) return false; // Should not happen if freq is 1

            // Force this set IN
            set_in(forced_set, log);
        } else {
            break; // No forced moves
        }
    }
    return true;
}

void backtrack(vector<Change>& log) {
    while (!log.empty()) {
        Change c = log.back();
        log.pop_back();
        if (c.type == 0) {
            set_status[c.idx] = c.old_val;
        } else if (c.type == 1) {
            // freq changed
            int el = c.idx;
            int old_f = c.old_val;
            int cur_f = el_freq[el];
            el_freq[el] = old_f;
            if (el_covered[el] == 0) {
                update_priority(el, cur_f, old_f, true, true);
            }
        } else if (c.type == 2) {
            // covered changed
            int el = c.idx;
            int old_cov = c.old_val;
            int cur_cov = el_covered[el];
            el_covered[el] = old_cov;

            if (cur_cov > 0 && old_cov == 0) {
                // Became uncovered
                update_priority(el, el_freq[el], el_freq[el], false, true);
            }
        } else if (c.type == 3) {
            uncovered_cnt = c.old_val;
        } else if (c.type == 4) {
            undecided_cnt = c.old_val;
        }
    }
}

void solve_rec() {
    if (solutions_found >= 3) return;

    vector<Change> log;
    if (!propagate(log)) {
        backtrack(log);
        return;
    }

    if (uncovered_cnt == 0) {
        // Found a solution
        long long ways = 1;
        // 2^undecided_cnt
        if (undecided_cnt >= 2) ways = 4;
        else if (undecided_cnt == 1) ways = 2;

        solutions_found += ways;
        backtrack(log);
        return;
    }

    // Branching
    // Pick uncovered element with min freq
    pair<int, int> top = *priority_elements.begin();
    int el = top.second;

    // Find a candidate set
    int candidate = -1;
    for (int s : element_in_sets[el]) {
        if (set_status[s] == 0) {
            candidate = s;
            break;
        }
    }

    // Branch 1: IN
    vector<Change> log_in;
    set_in(candidate, log_in);
    solve_rec();
    backtrack(log_in);

    if (solutions_found >= 3) {
        backtrack(log);
        return;
    }

    // Branch 2: OUT
    vector<Change> log_out;
    set_out(candidate, log_out);
    solve_rec();
    backtrack(log_out);

    backtrack(log);
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        sets[i].clear();
        set_status[i] = 0;
    }
    for (int i = 1; i <= m; ++i) {
        element_in_sets[i].clear();
        el_freq[i] = 0;
        el_covered[i] = 0;
    }

    for (int i = 1; i <= n; ++i) {
        int l;
        cin >> l;
        sets[i].resize(l);
        for (int j = 0; j < l; ++j) {
            cin >> sets[i][j];
            element_in_sets[sets[i][j]].push_back(i);
        }
    }

    priority_elements.clear();
    uncovered_cnt = m;
    undecided_cnt = n;
    solutions_found = 0;

    for (int i = 1; i <= m; ++i) {
        el_freq[i] = element_in_sets[i].size();
        if (el_freq[i] == 0) {
            cout << "NO" << endl;
            return;
        }
        priority_elements.insert({el_freq[i], i});
    }

    solve_rec();

    if (solutions_found >= 3) cout << "YES" << endl;
    else cout << "NO" << endl;
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

