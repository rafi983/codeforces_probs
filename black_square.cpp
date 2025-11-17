#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> a(4);
    for (int i = 0; i < 4; ++i) {
        cin >> a[i];
    }

    string s;
    cin >> s;

    long long total = 0;
    for (char c : s) {
        if (c >= '1' && c <= '4') {
            total += a[c - '1'];
        }
    }

    cout << total << '\n';

    return 0;
}

