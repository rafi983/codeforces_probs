#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    int a[1005];
    for (int i = 0; i < n; ++i) cin >> a[i];

    int min_idx = 0, max_idx = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] < a[min_idx]) min_idx = i;
        if (a[i] > a[max_idx]) max_idx = i;
    }

    swap(a[min_idx], a[max_idx]);

    for (int i = 0; i < n; ++i) {
        if (i) cout << " ";
        cout << a[i];
    }
    cout << endl;

    return 0;
}

