#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int totalInsertions = 0;

        for (int i = 0; i < n - 1; ++i) {
            int smaller = min(a[i], a[i + 1]);
            int larger = max(a[i], a[i + 1]);

            int insertions = 0;
            while (larger > smaller * 2) {
                smaller *= 2;
                ++insertions;
            }

            totalInsertions += insertions;
        }

        cout << totalInsertions << '\n';
    }

    return 0;
}

