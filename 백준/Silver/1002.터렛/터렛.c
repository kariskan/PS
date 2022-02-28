#include <stdio.h>
#include <math.h>
int main() {
	int x1, y1, r1, x2, y2, r2;
	int t;
	for (scanf("%d", &t); t > 0; t--) {
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

		int D = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
		int R;
		if (r2 - r1 < 0)R = r1 - r2; else R = r2 - r1;
		if (D > R * R && D < (r1 + r2) * (r1 + r2))printf("2\n");
		else if ((D == (r1 + r2) * (r1 + r2)) || (D != 0 && D == R * R))printf("1\n");
		else if ((D < R * R) || (D > (r1 + r2) * (r1 + r2)))printf("0\n");
		else printf("-1\n");
	}
	return 0;
}