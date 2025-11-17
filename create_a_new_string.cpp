#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string S, T;
    getline(cin, S);
    getline(cin, T);

    cout << S.length() << ' ' << T.length() << '\n';
    cout << S << ' ' << T << '\n';

    return 0;
}

