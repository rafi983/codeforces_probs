#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        string s, t;
        if (!(cin >> s >> t)) {
            return 1;
        }

        int len_s = s.length();
        int len_t = t.length();
        int max_len = max(len_s, len_t);

        for (int j = 0; j < max_len; j++) {
            if (j < len_s) {
                cout << s[j];
            }

            if (j < len_t) {
                cout << t[j];
            }
        }

        cout << endl;
    }

    return 0;
}

