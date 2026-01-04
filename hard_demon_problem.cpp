#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, q;
    if (!(cin >> n >> q)) return;

    vector<vector<long long>> M(n + 1, vector<long long>(n + 1));
    vector<vector<long long>> P(n + 1, vector<long long>(n + 1, 0));
    vector<vector<long long>> PR(n + 1, vector<long long>(n + 1, 0));
    vector<vector<long long>> PC(n + 1, vector<long long>(n + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> M[i][j];
            P[i][j] = M[i][j] + P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1];
            PR[i][j] = M[i][j] * i + PR[i - 1][j] + PR[i][j - 1] - PR[i - 1][j - 1];
            PC[i][j] = M[i][j] * j + PC[i - 1][j] + PC[i][j - 1] - PC[i - 1][j - 1];
        }
    }

    for (int k = 0; k < q; ++k) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        long long totalSum = P[x2][y2] - P[x1 - 1][y2] - P[x2][y1 - 1] + P[x1 - 1][y1 - 1];
        long long weightedRowSum = PR[x2][y2] - PR[x1 - 1][y2] - PR[x2][y1 - 1] + PR[x1 - 1][y1 - 1];
        long long weightedColSum = PC[x2][y2] - PC[x1 - 1][y2] - PC[x2][y1 - 1] + PC[x1 - 1][y1 - 1];

        long long w = y2 - y1 + 1;
        long long ans = w * weightedRowSum + weightedColSum - (w * x1 + y1 - 1) * totalSum;
        cout << ans << (k == q - 1 ? "" : " ");
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
