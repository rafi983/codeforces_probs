#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> a(n);
    vector<bool> exists(1002, false);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        exists[a[i]] = true;
    }

    int count = 0;
    for(int i = 0; i < n; ++i) {
        if(a[i] + 1 <= 1001 && exists[a[i] + 1]) {
            count++;
        }
    }
    cout << count << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

