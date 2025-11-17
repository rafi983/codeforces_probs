#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long M, N;
    cin >> M >> N;

    long long ans = (M * N) / 2;
    cout << ans << '\n';

    return 0;
}

