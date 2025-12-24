#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

struct ArrayInfo {
    int id;
    long long sum;
};

bool compareArrays(const ArrayInfo& a, const ArrayInfo& b) {
    return a.sum > b.sum;
}

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<vector<int>> arrays(n, vector<int>(m));
    vector<ArrayInfo> infos(n);

    for (int i = 0; i < n; ++i) {
        long long current_sum = 0;
        for (int j = 0; j < m; ++j) {
            cin >> arrays[i][j];
            current_sum += arrays[i][j];
        }
        infos[i] = {i, current_sum};
    }

    sort(infos.begin(), infos.end(), compareArrays);

    long long total_score = 0;
    long long total_elements = (long long)n * m;

    for (int k = 0; k < n; ++k) {
        int idx = infos[k].id;

        for (int j = 0; j < m; ++j) {
            long long val = arrays[idx][j];
            long long weight = total_elements - ((long long)k * m + (j + 1)) + 1;
            total_score += val * weight;
        }
    }

    cout << total_score << endl;
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

