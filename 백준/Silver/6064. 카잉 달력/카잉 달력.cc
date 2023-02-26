#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {

		int m, n, x, y;
		scanf("%d %d %d %d", &m, &n, &x, &y);//10 12 3 9
		int p = 0;
		for (int i = x; i <= m * n; i += m) {
			if ((i - x) % m == 0 && (i - y) % n == 0) {
				printf("%d\n", i);
				p = 1;
				break;
			}
		}
		if (p == 0)printf("-1\n");
	}
}