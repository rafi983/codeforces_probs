#include <stdio.h>

int main(void){
	int t; if (scanf("%d", &t)!=1) return 0;
	while(t--){
		long long n; scanf("%lld", &n);
		long long a = n/3;
		long long r = n%3;
		long long c1=a, c2=a;
		if (r==1) c1++;
		else if (r==2) c2++;
		printf("%lld %lld\n", c1, c2);
	}
	return 0;
}
