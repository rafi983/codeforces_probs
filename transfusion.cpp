#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<long long> a(n);
    long long sum_odd_pos = 0;
    long long sum_even_pos = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if ((i + 1) % 2 != 0) {
            sum_odd_pos += a[i];
        } else {
            sum_even_pos += a[i];
        }
    }

    long long total_sum = sum_odd_pos + sum_even_pos;
    if (total_sum % n != 0) {
        cout << "NO" << endl;
        return;
    }

    long long target = total_sum / n;
    long long count_odd_pos = (n + 1) / 2;
    long long count_even_pos = n / 2;

    if (sum_odd_pos == target * count_odd_pos && sum_even_pos == target * count_even_pos) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
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

