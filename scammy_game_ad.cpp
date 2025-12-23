#include <iostream>
#include <vector>

using namespace std;

struct Op {
    char type;
    int val;
};

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<pair<Op, Op>> levels(n);
    for (int i = 0; i < n; ++i) {
        cin >> levels[i].first.type >> levels[i].first.val;
        cin >> levels[i].second.type >> levels[i].second.val;
    }

    long long A = 1;
    long long B = 1;
    long long K = 0;

    for (int i = n - 1; i >= 0; --i) {
        Op opL = levels[i].first;
        Op opR = levels[i].second;

        long long next_A, next_B, next_K;

        long long const_gain = 0;
        if (opL.type == '+') const_gain += opL.val;
        if (opR.type == '+') const_gain += opR.val;

        if (A > B) {
            // Prefer Left
            if (opL.type == 'x') {
                next_A = A * opL.val;
            } else {
                next_A = A;
            }

            long long gain_from_R_coeff = 0;
            if (opR.type == 'x') {
                gain_from_R_coeff = opR.val - 1;
            }
            next_B = B + A * gain_from_R_coeff;

            next_K = K + A * const_gain;
        } else {
            // Prefer Right
            long long gain_from_L_coeff = 0;
            if (opL.type == 'x') {
                gain_from_L_coeff = opL.val - 1;
            }
            next_A = A + B * gain_from_L_coeff;

            if (opR.type == 'x') {
                next_B = B * opR.val;
            } else {
                next_B = B;
            }

            next_K = K + B * const_gain;
        }
        A = next_A;
        B = next_B;
        K = next_K;
    }

    cout << A + B + K << "\n";
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
