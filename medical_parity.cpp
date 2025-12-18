#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    string x_prime, y_prime;
    if (!(cin >> x_prime >> y_prime)) return;

    int n = x_prime.length();



    int dp0, dp1;


    int cost_y0 = (y_prime[0] == '1');
    int cost_x0 = (x_prime[0] == '1');
    dp0 = cost_y0 + cost_x0;


    int cost_y1 = (y_prime[0] == '0');
    int cost_x1 = (x_prime[0] == '0');
    dp1 = cost_y1 + cost_x1;

    for (int i = 1; i < n; ++i) {
        int next_dp0, next_dp1;


        int cost_from_0 = dp0 + (y_prime[i] == '1') + (x_prime[i] == '1');


        int cost_from_1 = dp1 + (y_prime[i] == '1') + (x_prime[i] == '0');

        next_dp0 = min(cost_from_0, cost_from_1);


        cost_from_0 = dp0 + (y_prime[i] == '0') + (x_prime[i] == '0');


        cost_from_1 = dp1 + (y_prime[i] == '0') + (x_prime[i] == '1');

        next_dp1 = min(cost_from_0, cost_from_1);

        dp0 = next_dp0;
        dp1 = next_dp1;
    }

    cout << min(dp0, dp1) << endl;
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
