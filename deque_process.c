#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
 
static inline bool is_strict_inc4(int *q, int m) {
	return q[m-4] < q[m-3] && q[m-3] < q[m-2] && q[m-2] < q[m-1];
}
 
static inline bool is_strict_dec4(int *q, int m) {
	return q[m-4] > q[m-3] && q[m-3] > q[m-2] && q[m-2] > q[m-1];
}
 
static inline bool safe_append(int *q, int m, int x) {
	if (m < 4) return true;
	if (is_strict_inc4(q, m) && x > q[m-1]) return false;
	if (is_strict_dec4(q, m) && x < q[m-1]) return false;
	return true;
}
 
int main(void) {
	int t;
	if (scanf("%d", &t) != 1) return 0;
	while (t--) {
		int n;
		if (scanf("%d", &n) != 1) return 0;
		int *p = (int*)malloc(sizeof(int)*n);
		for (int i = 0; i < n; ++i) scanf("%d", &p[i]);
 
		int *q = (int*)malloc(sizeof(int)*n);
		int m = 0;
		char *ans = (char*)malloc((size_t)n + 1);
		int ai = 0;
		int l = 0, r = n - 1;
 
		while (l <= r) {
			int left = p[l];
			int right = p[r];
			bool safeL = safe_append(q, m, left);
			bool safeR = safe_append(q, m, right);
 
			if (safeL && !safeR) {
				ans[ai++] = 'L';
				q[m++] = left; l++;
			} else if (safeR && !safeL) {
				ans[ai++] = 'R';
				q[m++] = right; r--;
			} else if (safeL && safeR) {
				bool chooseLeft = (left <= right);
				if (m >= 3) {
					int a = q[m-3], b = q[m-2], c = q[m-1];
					bool riskL = false, riskR = false;
					{
						int x = left;
						int nl = l + 1, nr = r;
						if (a < b && b < c && c < x) {
							int nleft = (nl <= nr) ? p[nl] : -1000000007;
							int nright = (nl <= nr) ? p[nr] : -1000000007;
							if (nleft > x && nright > x) riskL = true;
						} else if (a > b && b > c && c > x) {
							int nleft = (nl <= nr) ? p[nl] : 1000000007;
							int nright = (nl <= nr) ? p[nr] : 1000000007;
							if (nleft < x && nright < x) riskL = true;
						}
					}
					{
						int x = right;
						int nl = l, nr = r - 1;
						if (a < b && b < c && c < x) {
							int nleft = (nl <= nr) ? p[nl] : -1000000007;
							int nright = (nl <= nr) ? p[nr] : -1000000007;
							if (nleft > x && nright > x) riskR = true;
						} else if (a > b && b > c && c > x) {
							int nleft = (nl <= nr) ? p[nl] : 1000000007;
							int nright = (nl <= nr) ? p[nr] : 1000000007;
							if (nleft < x && nright < x) riskR = true;
						}
					}
					if (riskL && !riskR) chooseLeft = false;
					else if (riskR && !riskL) chooseLeft = true;
				}
				if (chooseLeft) {
					ans[ai++] = 'L';
					q[m++] = left; l++;
				} else {
					ans[ai++] = 'R';
					q[m++] = right; r--;
				}
			} else {
				ans[ai++] = 'L';
				q[m++] = left; l++;
			}
		}
 
		ans[ai] = '\0';
		puts(ans);
 
		free(p); free(q); free(ans);
	}
	return 0;
}
