#include <stdio.h>

int main() {
	long long k2, k3, k5, k6;
	if (scanf("%lld %lld %lld %lld", &k2, &k3, &k5, &k6) != 4) {
		return 0;
	}

	long long count256 = k2;
	if (k5 < count256) count256 = k5;
	if (k6 < count256) count256 = k6;

	k2 -= count256;
	k5 -= count256;
	k6 -= count256;

	long long count32 = k2;
	if (k3 < count32) count32 = k3;

	long long sum = count256 * 256 + count32 * 32;
	printf("%lld\n", sum);

	return 0;
}
