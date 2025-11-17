#include <iostream>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) {
        return 0;
    }

    int free_officers = 0;
    int untreated = 0;

    for (int i = 0; i < n; ++i) {
        int event;
        if (!(cin >> event)) {
            event = 0;
        }
        if (event == -1) {
            if (free_officers > 0) {
                --free_officers;
            } else {
                ++untreated;
            }
        } else {
            free_officers += event;
        }
    }

    cout << untreated << endl;
    return 0;
}

