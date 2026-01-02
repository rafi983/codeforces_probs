#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

long long countPairs(const vector<int>& a, long long limit) {
    long long count = 0;
    int left = 0;
    int right = a.size() - 1;
    while (left < right) {
        if ((long long)a[left] + a[right] <= limit) {
            count += (right - left);
            left++;
        } else {
            right--;
        }
    }
    return count;
}

void solve() {
    int n;
    long long x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    sort(a.begin(), a.end());

    long long min_sum = sum - y;
    long long max_sum = sum - x;

    long long count_max = countPairs(a, max_sum);
    long long count_min = countPairs(a, min_sum - 1);

    cout << count_max - count_min << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

