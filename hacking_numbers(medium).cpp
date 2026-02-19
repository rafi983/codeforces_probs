#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void ask_digit() {
    cout << "digit" << endl;
    string res;
    cin >> res;
    if(res == "-1") exit(0);
}

void ask_mul(long long y) {
    cout << "mul " << y << endl;
    string res;
    cin >> res;
    if(res == "-1") exit(0);
}

void ask_add(long long y) {
    cout << "add " << y << endl;
    string res;
    cin >> res;
    if(res == "-1") exit(0);
}

void solve() {
    long long n;
    if (!(cin >> n)) return;


    ask_digit();

    ask_mul(99);

    ask_digit();

    long long diff = n - 18;
    ask_add(diff);

    cout << "! " << endl;
    string res;
    cin >> res;
    if(res == "-1") exit(0);
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

