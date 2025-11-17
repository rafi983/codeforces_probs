#include <iostream>
#include <string>
using namespace std;

int main() {
    string A, B;
    cin >> A >> B;

    int lenA = A.length();
    int lenB = B.length();
    cout << lenA << " " << lenB << endl;

    cout << A << B << endl;

    char tmp = A[0];
    A[0] = B[0];
    B[0] = tmp;
    cout << A << " " << B << endl;

    return 0;
}

