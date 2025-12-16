#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Option {
    long long r, e;
};

int n;
long long b;
vector<vector<Option>> projects;
long long max_revenue = 0;
vector<long long> suffix_max_r;

void dfs(int idx, long long current_cost, long long current_revenue) {
    if (current_revenue > max_revenue) {
        max_revenue = current_revenue;
    }

    if (current_revenue + suffix_max_r[idx] <= max_revenue) {
        return;
    }

    if (idx == n) {
        return;
    }


    for (const auto& opt : projects[idx]) {
        if (current_cost + opt.e <= b) {
            dfs(idx + 1, current_cost + opt.e, current_revenue + opt.r);
        }
    }

    dfs(idx + 1, current_cost, current_revenue);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> b)) return 0;

    projects.resize(n);
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        projects[i].resize(k);
        for (int j = 0; j < k; ++j) {
            cin >> projects[i][j].r >> projects[i][j].e;
        }
        sort(projects[i].begin(), projects[i].end(), [](const Option& a, const Option& b) {
            return a.r > b.r;
        });
    }

    suffix_max_r.assign(n + 1, 0);
    for (int i = n - 1; i >= 0; --i) {
        long long current_proj_max = 0;
        for (const auto& opt : projects[i]) {
            current_proj_max = max(current_proj_max, opt.r);
        }
        suffix_max_r[i] = suffix_max_r[i + 1] + current_proj_max;
    }

    dfs(0, 0, 0);

    cout << max_revenue << endl;

    return 0;
}

