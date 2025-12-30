#include <iostream>
#include <algorithm>

using namespace std;

void zaman() {
    long long a, b;
    if (!(cin >> a >> b)) return;

    long long req_top_color = 0;
    long long req_other_color = 0;

    int layer = 1;
    while(true) {
        long long size = 1LL << (layer - 1);

        if (layer % 2 != 0) {
            req_top_color += size;
        } else {
            req_other_color += size;
        }

        bool can_white_top = (a >= req_top_color && b >= req_other_color);

        bool can_dark_top = (a >= req_other_color && b >= req_top_color);

        if (!can_white_top && !can_dark_top) {
            cout << layer - 1 << endl;
            return;
        }

        layer++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            zaman();
        }
    }
    return 0;
}
