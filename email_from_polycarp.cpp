#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--) {
        string s, t;
        cin >> s >> t;

        int len_s = s.length();
        int len_t = t.length();

        int i = 0, j = 0;
        bool valid = true;

        while (i < len_s && j < len_t) {
            // If characters don't match, it's impossible
            if (s[i] != t[j]) {
                valid = false;
                break;
            }

            char current_char = s[i];
            int count_s = 0, count_t = 0;

            // Count consecutive occurrences in s
            while (i < len_s && s[i] == current_char) {
                ++count_s;
                ++i;
            }

            // Count consecutive occurrences in t
            while (j < len_t && t[j] == current_char) {
                ++count_t;
                ++j;
            }

            // t must have at least as many characters as s
            if (count_t < count_s) {
                valid = false;
                break;
            }
        }

        // Check if we consumed both strings completely
        if (i != len_s || j != len_t) {
            valid = false;
        }

        cout << (valid ? "YES" : "NO") << '\n';
    }

    return 0;
}

