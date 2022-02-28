#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		int n;
		scanf("%d", &n);
		int cx[50], cy[50], r[50];
		int count = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d %d %d", &cx[i], &cy[i], &r[i]);
			if (r[i] * r[i] > (x1 - cx[i]) * (x1 - cx[i]) + (y1 - cy[i]) * (y1 - cy[i]) || r[i] * r[i] > (x2 - cx[i]) * (x2 - cx[i]) + (y2 - cy[i]) * (y2 - cy[i])) {
				if (r[i] * r[i] > (x1 - cx[i]) * (x1 - cx[i]) + (y1 - cy[i]) * (y1 - cy[i]) && r[i] * r[i] > (x2 - cx[i]) * (x2 - cx[i]) + (y2 - cy[i]) * (y2 - cy[i]))continue;
				count++;
			}
		}
		printf("%d\n", count);
	}
}