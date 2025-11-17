#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        vector<vector<char>> grid(n, vector<char>(n));
        vector<int> twos;

        for (int i = 0; i < n; ++i) {
            if (s[i] == '2') {
                twos.push_back(i);
            }
        }

        int count = twos.size();

        if (count == 1 || count == 2) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                grid[i][j] = (i == j) ? 'X' : '=';
            }
        }

        if (count > 0) {
            for (int i = 0; i < count; ++i) {
                int a = twos[i];
                int b = twos[(i + 1) % count];
                grid[a][b] = '+';
                grid[b][a] = '-';
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << grid[i][j];
            }
            cout << '\n';
        }
    }

    return 0;
}

