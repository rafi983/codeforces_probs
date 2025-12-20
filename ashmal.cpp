#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void solve() {
    int n;
    if (!(std::cin >> n)) return;
    std::vector<std::string> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::string s = "";
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            s = a[i];
        } else {
            std::string s1 = a[i] + s;
            std::string s2 = s + a[i];
            if (s1 < s2) {
                s = s1;
            } else {
                s = s2;
            }
        }
    }
    std::cout << s << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    if (std::cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
