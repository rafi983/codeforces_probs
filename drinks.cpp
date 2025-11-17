#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    double sum = 0;

    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        sum += p;
    }

    // The average percentage is the sum divided by n
    double average = sum / n;

    cout << fixed << setprecision(12) << average << '\n';

    return 0;
}

