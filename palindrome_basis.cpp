#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 40005;
const int MOD = 1e9 + 7;

int dp[MAXN];
vector<int> palindromes;

bool isPalindrome(int x) {
    int original = x;
    int reversed = 0;
    while (x > 0) {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }
    return original == reversed;
}

void precompute() {
    for (int i = 1; i < MAXN; ++i) {
        if (isPalindrome(i)) {
            palindromes.push_back(i);
        }
    }

    dp[0] = 1;
    for (int p : palindromes) {
        for (int j = p; j < MAXN; ++j) {
            dp[j] = (dp[j] + dp[j - p]) % MOD;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    cout << dp[n] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}

