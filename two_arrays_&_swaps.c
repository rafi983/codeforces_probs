#include <stdio.h>
#include <stdlib.h>

static int cmp_asc(const void *a, const void *b){
	int x = *(const int*)a, y = *(const int*)b;
	return (x>y)-(x<y);
}
static int cmp_desc(const void *a, const void *b){
	int x = *(const int*)a, y = *(const int*)b;
	return (y>x)-(y<x);
}

int main(void){
	int t; if (scanf("%d", &t)!=1) return 0;
	while(t--){
		int n,k; scanf("%d %d", &n, &k);
		int a[35], b[35];
		for (int i=0;i<n;++i) scanf("%d", &a[i]);
		for (int i=0;i<n;++i) scanf("%d", &b[i]);
		qsort(a, n, sizeof(int), cmp_asc);
		qsort(b, n, sizeof(int), cmp_desc);
		for (int i=0;i<n && i<k;++i){
			if (b[i] > a[i]){
				int tmp=a[i]; a[i]=b[i]; b[i]=tmp;
			} else break;
		}
		int sum=0; for (int i=0;i<n;++i) sum+=a[i];
		printf("%d\n", sum);
	}
	return 0;
}
