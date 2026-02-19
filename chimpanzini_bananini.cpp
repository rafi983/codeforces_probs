#include <iostream>
#include <vector>
#include <numeric>
#include <deque>

using namespace std;

void solve() {
    int q;
    cin >> q;

    deque<long long> dq;
    bool is_reversed = false;
    long long current_R = 0;
    long long current_S = 0;
    long long n = 0;

    for(int i=0; i<q; ++i) {
        int type;
        cin >> type;
        if (type == 1) { // Cyclic Shift
            if (n > 0) {
                long long last_val;
                if (!is_reversed) {
                    last_val = dq.back();
                    dq.pop_back();
                    dq.push_front(last_val);
                } else {

                    last_val = dq.front();
                    dq.pop_front();
                    dq.push_back(last_val);
                }
                current_R = current_R + current_S - n * last_val;
            }
        } else if (type == 2) { // Reverse
            if (n > 0) {
                is_reversed = !is_reversed;
                current_R = (n + 1) * current_S - current_R;
            }
        } else if (type == 3) { // Append k
            long long k;
            cin >> k;
            current_R += k * (n + 1);
            current_S += k;
            n++;

            if (!is_reversed) {
                dq.push_back(k);
            } else {

                dq.push_front(k);
            }
        }
        cout << current_R << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
         while(t--) {
            solve();
        }
    }
    return 0;
}

