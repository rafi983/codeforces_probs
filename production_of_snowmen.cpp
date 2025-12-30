#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void zaman() {
    int n;
    if (!(cin >> n)) return;

    vector<int> a(n), b(n), c(n);
    for(int i=0; i<n; ++i) cin >> a[i];
    for(int i=0; i<n; ++i) cin >> b[i];
    for(int i=0; i<n; ++i) cin >> c[i];

    vector<int> bb = b;
    bb.insert(bb.end(), b.begin(), b.end());

    vector<int> cc = c;
    cc.insert(cc.end(), c.begin(), c.end());

    long long ways_ab = 0;
    for(int s = 0; s < n; ++s) {
        bool possible = true;
        for(int i = 0; i < n; ++i) {
            if(a[i] >= bb[i + s]) {
                possible = false;
                break;
            }
        }
        if(possible) ways_ab++;
    }

    long long ways_bc = 0;
    for(int s = 0; s < n; ++s) {
        bool possible = true;
        for(int i = 0; i < n; ++i) {
            if(b[i] >= cc[i + s]) {
                possible = false;
                break;
            }
        }
        if(possible) ways_bc++;
    }

    cout << (long long)n * ways_ab * ways_bc << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while(t--) {
            zaman();
        }
    }
    return 0;
}
