#include <iostream>
using namespace std;

int main() {
    int n = 0;
    int k = 0;
    if (!(cin >> n >> k)) {
        return 0;
    }

    int problems[100];
    for (int i = 0; i < n; ++i) {
        if (!(cin >> problems[i])) {
            problems[i] = 0;
        }
    }

    int left = 0;
    int right = n - 1;
    int solved = 0;

    while (left <= right) {
        bool left_ok = problems[left] <= k;
        bool right_ok = problems[right] <= k;
        if (!left_ok && !right_ok) {
            break;
        }
        if (left_ok) {
            ++left;
            ++solved;
        } else if (right_ok) {
            --right;
            ++solved;
        }
    }

    cout << solved << endl;
    return 0;
}

