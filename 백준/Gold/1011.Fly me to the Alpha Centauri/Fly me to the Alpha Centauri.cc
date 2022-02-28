#include <stdio.h>
#include <math.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		long long x, y;
		scanf("%lld %lld", &x, &y);
		long long dis = y - x;
		long long i = 1;
		for (;; i++) {
			if (i * i >= dis)break;
		}
		if (i * i == dis)printf("%lld\n", i * 2 - 1);
		else {
			if (dis <= i * i - sqrt(dis))printf("%lld\n", i * 2 - 2);
			else printf("%lld\n", i * 2 - 1);
		}
	}
}