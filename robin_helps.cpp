#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        int robin_gold = 0;
        int people_helped = 0;

        for (int i = 0; i < n; i++) {
            int ai;
            cin >> ai;

            if (ai >= k) {
                robin_gold += ai;
            } else if (ai == 0) {
                if (robin_gold > 0) {
                    robin_gold--;
                    people_helped++;
                }
            }
        }

        cout << people_helped << endl;
    }

    return 0;
}

