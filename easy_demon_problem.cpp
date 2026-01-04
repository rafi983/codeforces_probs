#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

const int MAX_VAL = 200000;
const int OFFSET = 200000;
const int ARR_SIZE = 400005;

bool presentA[ARR_SIZE];
bool presentB[ARR_SIZE];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    if (!(cin >> n >> m >> q)) return 0;

    vector<long long> a(n);
    long long sum_a = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum_a += a[i];
    }

    vector<long long> b(m);
    long long sum_b = 0;
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        sum_b += b[i];
    }

    for (int i = 0; i < n; ++i) {
        long long val = sum_a - a[i];
        if (val >= -MAX_VAL && val <= MAX_VAL) {
            presentA[val + OFFSET] = true;
        }
    }

    for (int i = 0; i < m; ++i) {
        long long val = sum_b - b[i];
        if (val >= -MAX_VAL && val <= MAX_VAL) {
            presentB[val + OFFSET] = true;
        }
    }

    while (q--) {
        int x;
        cin >> x;

        bool found = false;

        if (x == 0) {
            if (presentA[0 + OFFSET] || presentB[0 + OFFSET]) found = true;
        } else {
            int abs_x = abs(x);
            for (int d = 1; d * d <= abs_x; ++d) {
                if (abs_x % d == 0) {
                    int d1 = d;
                    int d2 = abs_x / d;

                    if (x > 0) {
                        if ((presentA[d1 + OFFSET] && presentB[d2 + OFFSET]) ||
                            (presentA[-d1 + OFFSET] && presentB[-d2 + OFFSET]) ||
                            (presentA[d2 + OFFSET] && presentB[d1 + OFFSET]) ||
                            (presentA[-d2 + OFFSET] && presentB[-d1 + OFFSET])) {
                            found = true;
                            break;
                        }
                    } else {
                        if ((presentA[d1 + OFFSET] && presentB[-d2 + OFFSET]) ||
                            (presentA[-d1 + OFFSET] && presentB[d2 + OFFSET]) ||
                            (presentA[d2 + OFFSET] && presentB[-d1 + OFFSET]) ||
                            (presentA[-d2 + OFFSET] && presentB[d1 + OFFSET])) {
                            found = true;
                            break;
                        }
                    }
                }
            }
        }

        if (found) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
