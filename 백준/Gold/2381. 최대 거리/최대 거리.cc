#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int x, y;
	long long maxpxy = -100000000, minpxy = 100000000;
	long long maxdxy = -100000000, mindxy = 100000000;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		if (maxpxy < x + y)
			maxpxy = x + y;
		if (minpxy > x + y)
			minpxy = x + y;
		if (maxdxy < x - y)
			maxdxy = x - y;
		if (mindxy > x - y)
			mindxy = x - y;
	}
	printf("%lld", (maxpxy - minpxy) > (maxdxy - mindxy) ? maxpxy - minpxy : maxdxy - mindxy);
}