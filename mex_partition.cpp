#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> freq(101, 0);

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            freq[x]++;
        }

        int min_freq = n + 1;
        int mex = 0;

        for (int i = 0; i <= 100; i++) {
            if (freq[i] == 0) {
                mex = i;
                break;
            }
            if (freq[i] < min_freq) {
                min_freq = freq[i];
            }
        }

        cout << mex << endl;
    }

    return 0;
}

