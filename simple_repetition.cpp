#include <iostream>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

bool is_prime(ll n) {
    if (n <= 1) return false;
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

void solve() {
    ll x;
    int k;
    cin >> x >> k;

    if (k == 1) {
        if (is_prime(x)) cout << "YES\n";
        else cout << "NO\n";
        return;
    }


    if (x > 1) {
        cout << "NO\n";
        return;
    }

    ll y = 0;
    for(int i=0; i<k; ++i){
        y = y * 10 + 1;
    }

    if (is_prime(y)) cout << "YES\n";
    else cout << "NO\n";
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

