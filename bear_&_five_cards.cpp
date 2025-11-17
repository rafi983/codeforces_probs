#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> a(5);
    long long sum = 0;

    for (int i = 0; i < 5; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    vector<int> cnt(101, 0);
    for (int i = 0; i < 5; ++i) {
        if (a[i] >= 1 && a[i] <= 100) {
            cnt[a[i]]++;
        }
    }

    int best = 0;
    for (int v = 1; v <= 100; ++v) {
        if (cnt[v] >= 2) {
            int take = (cnt[v] >= 3) ? 3 : 2;
            int reduction = v * take;
            best = max(best, reduction);
        }
    }

    cout << sum - best << '\n';

    return 0;
}

