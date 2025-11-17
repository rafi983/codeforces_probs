#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string str;
    cin >> str;

    int remove_count = 0;
    int i = 0;

    while (i <= n - 3) {
        if (str[i] == 'x' && str[i+1] == 'x' && str[i+2] == 'x') {
            ++remove_count;
            ++i;
        } else {
            ++i;
        }
    }

    cout << remove_count << '\n';

    return 0;
}

