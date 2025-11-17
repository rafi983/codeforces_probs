#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> welfare(n);
    int max_welfare = 0;

    for (int i = 0; i < n; i++) {
        cin >> welfare[i];
        if (welfare[i] > max_welfare) {
            max_welfare = welfare[i];
        }
    }

    long long total_burles = 0;
    for (int i = 0; i < n; i++) {
        total_burles += max_welfare - welfare[i];
    }

    cout << total_burles << endl;

    return 0;
}

