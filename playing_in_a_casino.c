#include <stdio.h>
#include <stdlib.h>

static int cmp_int(const void *lhs, const void *rhs) {
	int a = *(const int *)lhs;
	int b = *(const int *)rhs;
	return (a > b) - (a < b);
}

int main(void) {
	int t;
	if (scanf("%d", &t) != 1) {
		return 0;
	}

	while (t--) {
		int n, m;
		if (scanf("%d %d", &n, &m) != 2) {
			return 0;
		}

		int total = n * m;
		int *cards = (int *)malloc((size_t)total * sizeof(int));
		int *col = (int *)malloc((size_t)n * sizeof(int));
		if (!cards || !col) {
			free(cards);
			free(col);
			return 0;
		}

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (scanf("%d", &cards[i * m + j]) != 1) {
					free(cards);
					free(col);
					return 0;
				}
			}
		}

		long long answer = 0;
		for (int j = 0; j < m; ++j) {
			for (int i = 0; i < n; ++i) {
				col[i] = cards[i * m + j];
			}

			qsort(col, (size_t)n, sizeof(int), cmp_int);

			long long col_sum = 0;
			long long prefix_sum = 0;
			for (int i = 0; i < n; ++i) {
				col_sum += (long long)col[i] * i - prefix_sum; /* sum over pairs ending at i */
				prefix_sum += col[i];
			}
			answer += col_sum;
		}

		printf("%lld\n", answer);

		free(cards);
		free(col);
	}

	return 0;
}
