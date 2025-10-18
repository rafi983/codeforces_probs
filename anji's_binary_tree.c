#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void) {
	int T;
	if (scanf("%d", &T) != 1) {
		return 0;
	}

	while (T--) {
		int n;
		if (scanf("%d", &n) != 1) {
			return 0;
		}

		char *s = (char *)malloc((size_t)n + 1);
		if (!s) {
			return 0;
		}
		if (scanf("%s", s) != 1) {
			free(s);
			return 0;
		}

		int *left = (int *)malloc((size_t)(n + 1) * sizeof(int));
		int *right = (int *)malloc((size_t)(n + 1) * sizeof(int));
		if (!left || !right) {
			free(s);
			free(left);
			free(right);
			return 0;
		}

		for (int i = 1; i <= n; ++i) {
			if (scanf("%d %d", &left[i], &right[i]) != 2) {
				free(s);
				free(left);
				free(right);
				return 0;
			}
		}

		int *stack_v = (int *)malloc((size_t)n * sizeof(int));
		int *stack_c = (int *)malloc((size_t)n * sizeof(int));
		if (!stack_v || !stack_c) {
			free(s);
			free(left);
			free(right);
			free(stack_v);
			free(stack_c);
			return 0;
		}

		int top = 0;
		stack_v[top] = 1;
		stack_c[top] = 0;

		int answer = INT_MAX;

		while (top >= 0) {
			int v = stack_v[top];
			int cost = stack_c[top];
			--top;

			if (left[v] == 0 && right[v] == 0) {
				if (cost < answer) {
					answer = cost;
				}
				continue;
			}

			if (left[v] != 0) {
				int add = (s[v - 1] == 'L') ? 0 : 1;
				++top;
				stack_v[top] = left[v];
				stack_c[top] = cost + add;
			}

			if (right[v] != 0) {
				int add = (s[v - 1] == 'R') ? 0 : 1;
				++top;
				stack_v[top] = right[v];
				stack_c[top] = cost + add;
			}
		}

		if (answer == INT_MAX) {
			answer = 0;
		}

		printf("%d\n", answer);

		free(s);
		free(left);
		free(right);
		free(stack_v);
		free(stack_c);
	}

	return 0;
}
