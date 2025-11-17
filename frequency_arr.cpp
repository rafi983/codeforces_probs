#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    if (!(cin >> n >> m)) {
        return 0;
    }

    // Use vector instead of dynamic allocation
    vector<int> freq(m + 1, 0);

    // Read array and count frequencies
    for (int i = 0; i < n; ++i) {
        int num;
        if (!(cin >> num)) {
            return 0;
        }
        if (num >= 1 && num <= m) {
            freq[num]++;
        }
    }

    // Print the frequency of each number from 1 to m
    for (int i = 1; i <= m; ++i) {
        cout << freq[i] << endl;
    }

    return 0;
}

