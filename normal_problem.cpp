#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    string a;
    cin >> a;
    string b = "";
    for (int i = a.length() - 1; i >= 0; i--) {
        if (a[i] == 'p') {
            b += 'q';
        } else if (a[i] == 'q') {
            b += 'p';
        } else {
            b += 'w';
        }
    }
    cout << b << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
