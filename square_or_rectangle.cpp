#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int w, h;
        cin >> w >> h;
        cout << (w == h ? "Square" : "Rectangle") << endl;
    }

    return 0;
}

