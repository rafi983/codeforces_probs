#include <stdio.h>
#include <stdint.h>

static int bitlen_uint32(uint32_t x) {
	if (x == 0) return 0;
	int l = 32 - __builtin_clz(x);
	return l;
}

static int trailing_zeros_uint32(uint32_t x) {
	if (x == 0) return 32; // not used for x==0 path
	return __builtin_ctz(x);
}

static int get_bit(uint32_t n, int i) {
	return (n >> i) & 1u;
}

int main(void) {
	int t;
	if (scanf("%d", &t) != 1) return 0;
	while (t--) {
		uint32_t n;
		scanf("%u", &n);
		if (n == 0) {
			puts("YES");
			continue;
		}
		int m = bitlen_uint32(n);
		int tz = trailing_zeros_uint32(n);
		int ok = 0;
		for (int add = 0; add <= tz && !ok; ++add) {
			int L = m + add;
			// For odd L, middle bit must be 0
			if ((L & 1) && get_bit(n, L / 2)) {
				continue;
			}
			int pal = 1;
			for (int i = 0; i < L / 2; ++i) {
				int bi = get_bit(n, i);
				int bj = get_bit(n, L - 1 - i);
				if (bi != bj) { pal = 0; break; }
			}
			if (pal) ok = 1;
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}
