#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int x = 0;

    for (int i = 0; i < n; ++i) {
        string statement;
        cin >> statement;

        // Check if the statement contains "++" or "--"
        if (statement.find("++") != string::npos) {
            ++x;
        } else if (statement.find("--") != string::npos) {
            --x;
        }
    }

    cout << x << '\n';

    return 0;
}

