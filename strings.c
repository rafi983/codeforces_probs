
#include <stdio.h>
#include <string.h>

int main(void) {
	char A[11], B[11];

	if (scanf("%10s", A) != 1) return 0;
	if (scanf("%10s", B) != 1) return 0;

	int lenA = (int)strlen(A);
	int lenB = (int)strlen(B);
	printf("%d %d\n", lenA, lenB);

	printf("%s%s\n", A, B);

	char tmp = A[0];
	A[0] = B[0];
	B[0] = tmp;
	printf("%s %s\n", A, B);

	return 0;
}

