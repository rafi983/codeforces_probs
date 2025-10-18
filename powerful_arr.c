#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int l;
	int r;
	int idx;
} Query;

static int block_size;

static int cmp_query(const void *a, const void *b) {
	const Query *qa = (const Query *)a;
	const Query *qb = (const Query *)b;
	int block_a = qa->l / block_size;
	int block_b = qb->l / block_size;
	if (block_a != block_b) {
		return block_a - block_b;
	}
	if (block_a & 1) {
		return qb->r - qa->r;
	}
	return qa->r - qb->r;
}

int main(void) {
	int n, t;
	if (scanf("%d %d", &n, &t) != 2) {
		return 0;
	}

	int *arr = (int *)malloc((size_t)n * sizeof(int));
	if (!arr) {
		return 0;
	}

	for (int i = 0; i < n; ++i) {
		if (scanf("%d", &arr[i]) != 1) {
			free(arr);
			return 0;
		}
	}

	Query *queries = (Query *)malloc((size_t)t * sizeof(Query));
	long long *answers = (long long *)malloc((size_t)t * sizeof(long long));
	if (!queries || !answers) {
		free(arr);
		free(queries);
		free(answers);
		return 0;
	}

	for (int i = 0; i < t; ++i) {
		int l, r;
		if (scanf("%d %d", &l, &r) != 2) {
			free(arr);
			free(queries);
			free(answers);
			return 0;
		}
		--l;
		--r;
		queries[i].l = l;
		queries[i].r = r;
		queries[i].idx = i;
	}

	block_size = 1;
	while ((long long)block_size * block_size < n) {
		++block_size;
	}

	qsort(queries, (size_t)t, sizeof(Query), cmp_query);

	int *freq = (int *)calloc(1000001, sizeof(int));
	if (!freq) {
		free(arr);
		free(queries);
		free(answers);
		return 0;
	}

	int cur_l = 0;
	int cur_r = -1;
	long long cur_ans = 0;

	for (int qi = 0; qi < t; ++qi) {
		Query q = queries[qi];
		while (cur_l > q.l) {
			--cur_l;
			int x = arr[cur_l];
			long long f = freq[x];
			cur_ans += (2 * f + 1) * (long long)x;
			++freq[x];
		}
		while (cur_r < q.r) {
			++cur_r;
			int x = arr[cur_r];
			long long f = freq[x];
			cur_ans += (2 * f + 1) * (long long)x;
			++freq[x];
		}
		while (cur_l < q.l) {
			int x = arr[cur_l];
			long long f = freq[x];
			cur_ans -= (2 * f - 1) * (long long)x;
			--freq[x];
			++cur_l;
		}
		while (cur_r > q.r) {
			int x = arr[cur_r];
			long long f = freq[x];
			cur_ans -= (2 * f - 1) * (long long)x;
			--freq[x];
			--cur_r;
		}
		answers[q.idx] = cur_ans;
	}

	for (int i = 0; i < t; ++i) {
		printf("%I64d\n", answers[i]);
	}

	free(freq);
	free(arr);
	free(queries);
	free(answers);
	return 0;
}
