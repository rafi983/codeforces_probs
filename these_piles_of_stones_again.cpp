#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int calculate_mex(const set<int>& s) {
    int mex = 0;
    while (s.count(mex)) {
        mex++;
    }
    return mex;
}

int main() {
    int n1, n2, n3;
    if (!(cin >> n1 >> n2 >> n3)) return 0;

    int k;
    cin >> k;
    vector<int> a(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
    }

    int max_n = max({n1, n2, n3});
    vector<int> g(max_n + 1);


    for (int i = 1; i <= max_n; ++i) {
        set<int> reachable_grundy_values;
        for (int move : a) {
            if (i - move >= 0) {
                reachable_grundy_values.insert(g[i - move]);
            }
        }
        g[i] = calculate_mex(reachable_grundy_values);
    }

    int xor_sum = g[n1] ^ g[n2] ^ g[n3];

    if (xor_sum != 0) {
        cout << "Peter" << endl;
    } else {
        cout << "Vasya" << endl;
    }

    return 0;
}

