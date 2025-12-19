#include <iostream>
#include <vector>
#include <map>

using namespace std;

long long count_subarrays(const vector<int>& a, int n, long long s, int limit) {
    long long total_count = 0;
    int i = 0;
    while (i < n) {
        if (a[i] > limit) {
            i++;
            continue;
        }

        // Found a segment starting at i
        int j = i;
        while (j < n && a[j] <= limit) {
            j++;
        }
        // Segment is [i, j-1]

        map<long long, int> freq;
        freq[0] = 1;
        long long current_sum = 0;

        for (int k = i; k < j; ++k) {
            current_sum += a[k];
            long long target = current_sum - s;
            auto it = freq.find(target);
            if (it != freq.end()) {
                total_count += it->second;
            }
            freq[current_sum]++;
        }

        i = j;
    }
    return total_count;
}

void solve() {
    int n;
    long long s;
    int x;
    if (!(cin >> n >> s >> x)) return;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long cnt1 = count_subarrays(a, n, s, x);
    long long cnt2 = count_subarrays(a, n, s, x - 1);

    cout << cnt1 - cnt2 << "\n";
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

