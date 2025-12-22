#include <iostream>

using namespace std;

void solve() {
    int n;
    cin >> n;

    cout << "1 1 " << n << endl;
    long long sum_p_total;
    cin >> sum_p_total;

    cout << "2 1 " << n << endl;
    long long sum_a_total;
    cin >> sum_a_total;

    long long len = sum_a_total - sum_p_total;



    int low = 1, high = n - len + 1;
    int l = high; // Default to the upper bound if loop doesn't narrow it down (e.g. range size 1)

    while (low < high) {
        int mid = low + (high - low) / 2;

        cout << "1 1 " << mid << endl;
        long long s1;
        cin >> s1;

        cout << "2 1 " << mid << endl;
        long long s2;
        cin >> s2;

        if (s2 - s1 > 0) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    l = low;
    int r = l + len - 1;

    cout << "! " << l << " " << r << endl;
}

int main() {
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}

