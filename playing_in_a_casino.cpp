#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    if (!(cin >> t)) {
        return 0;
    }

    while (t--) {
        int n, m;
        if (!(cin >> n >> m)) {
            return 0;
        }

        int total = n * m;
        vector<int> cards(total);
        vector<int> col(n);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!(cin >> cards[i * m + j])) {
                    return 0;
                }
            }
        }

        long long answer = 0;
        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                col[i] = cards[i * m + j];
            }

            sort(col.begin(), col.end());

            long long col_sum = 0;
            long long prefix_sum = 0;
            for (int i = 0; i < n; ++i) {
                col_sum += (long long)col[i] * i - prefix_sum;
                prefix_sum += col[i];
            }
            answer += col_sum;
        }

        cout << answer << endl;
    }

    return 0;
}

