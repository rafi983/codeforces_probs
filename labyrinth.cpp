#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int traps = 0;
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < m; j++) {
            if (row[j] == 'x') {
                traps++;
            }
        }
    }

    cout << traps << endl;
    return 0;
}

