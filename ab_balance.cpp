#include <iostream>
#include <string>
using namespace std;

int countAB(const string& s) {
    int count = 0;
    int len = s.length();
    for (int i = 0; i < len - 1; i++) {
        if (s[i] == 'a' && s[i+1] == 'b') {
            count++;
        }
    }
    return count;
}

int countBA(const string& s) {
    int count = 0;
    int len = s.length();
    for (int i = 0; i < len - 1; i++) {
        if (s[i] == 'b' && s[i+1] == 'a') {
            count++;
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int ab = countAB(s);
        int ba = countBA(s);

        if (ab == ba) {
            cout << s << '\n';
            continue;
        }

        char original_first = s[0];
        s[0] = (s[0] == 'a') ? 'b' : 'a';
        if (countAB(s) == countBA(s)) {
            cout << s << '\n';
            s[0] = original_first;
            continue;
        }
        s[0] = original_first;

        int len = s.length();
        char original_last = s[len-1];
        s[len-1] = (s[len-1] == 'a') ? 'b' : 'a';
        if (countAB(s) == countBA(s)) {
            cout << s << '\n';
            s[len-1] = original_last;
            continue;
        }
        s[len-1] = original_last;

        cout << s << '\n';
    }

    return 0;
}

