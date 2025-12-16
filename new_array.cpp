#include <iostream>
#include <vector>

using namespace std;

vector<int> concatenate_arrays(int n, const vector<int>& a, const vector<int>& b) {
    vector<int> c;
    c.reserve(2 * n);
    for (int i = 0; i < n; ++i) {
        c.push_back(b[i]);
    }
    for (int i = 0; i < n; ++i) {
        c.push_back(a[i]);
    }
    return c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        vector<int> c = concatenate_arrays(n, a, b);

        for (int i = 0; i < c.size(); ++i) {
            cout << c[i] << (i == c.size() - 1 ? "" : " ");
        }
        cout << endl;
    }
    return 0;
}

