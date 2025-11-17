#include <iostream>
#include <cstdint>
using namespace std;

static int bitlen_uint32(uint32_t x) {
    if (x == 0) return 0;
    int l = 32 - __builtin_clz(x);
    return l;
}

static int trailing_zeros_uint32(uint32_t x) {
    if (x == 0) return 32;
    return __builtin_ctz(x);
}

static int get_bit(uint32_t n, int i) {
    return (n >> i) & 1u;
}

int main() {
    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        uint32_t n;
        cin >> n;

        if (n == 0) {
            cout << "YES" << endl;
            continue;
        }

        int m = bitlen_uint32(n);
        int tz = trailing_zeros_uint32(n);
        bool ok = false;

        for (int add = 0; add <= tz && !ok; ++add) {
            int L = m + add;

            if ((L & 1) && get_bit(n, L / 2)) {
                continue;
            }

            bool pal = true;
            for (int i = 0; i < L / 2; ++i) {
                int bi = get_bit(n, i);
                int bj = get_bit(n, L - 1 - i);
                if (bi != bj) {
                    pal = false;
                    break;
                }
            }
            if (pal) ok = true;
        }

        cout << (ok ? "YES" : "NO") << endl;
    }

    return 0;
}

