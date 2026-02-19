#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

long long ask_add(long long y) {
    cout << "add " << y << endl;
    string response;
    cin >> response;
    if (response == "-1") exit(0);
    if (response == "0") return 0;
    if (response == "1") return 1;
    return 0;
}

void ask_digit() {
    cout << "digit" << endl;
    string response;
    cin >> response;
    if (response == "-1") exit(0);
}

void solve() {
    long long n;
    if (!(cin >> n)) return;

    ask_digit();
    ask_digit();

    long long low = 1, high = 16;
    long long offset = 0;


    for (int i = 0; i < 4; ++i) {
        long long mid = (low + high) / 2;


        long long Y = 1000000000000000000LL - (mid + offset);
        long long res = ask_add(Y);

        if (res == 0) {

            low = mid + 1;
        } else {

            high = mid;
            offset += Y;
        }
    }

    long long current_x = low + offset;

    long long diff = n - current_x;
    ask_add(diff);

    cout << "! " << endl;
    string verify;
    cin >> verify;
    if (verify == "-1") exit(0);
}

int main() {

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}

