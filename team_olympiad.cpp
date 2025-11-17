#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int prog[5000], math[5000], pe[5000];
    int count_prog = 0, count_math = 0, count_pe = 0;

    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            prog[count_prog++] = i;
        } else if (t == 2) {
            math[count_math++] = i;
        } else if (t == 3) {
            pe[count_pe++] = i;
        }
    }

    int teams = count_prog;
    if (count_math < teams) {
        teams = count_math;
    }
    if (count_pe < teams) {
        teams = count_pe;
    }

    cout << teams << endl;
    for (int i = 0; i < teams; i++) {
        cout << prog[i] << " " << math[i] << " " << pe[i] << endl;
    }

    return 0;
}

