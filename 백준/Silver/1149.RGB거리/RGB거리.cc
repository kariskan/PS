#include <stdio.h>
int min(int a, int b) {
	return a < b ? a : b;
}
int main() {
	int n;
	int r[3];
	int dp1[3], dp2[3];
	dp1[0] = dp1[1] = dp1[2] = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &r[0], &r[1], &r[2]);
		dp2[0] = dp1[0];
		dp2[1] = dp1[1];
		dp2[2] = dp1[2];
		dp1[0] = r[0]+min(dp2[1], dp2[2]);
		dp1[1] = r[1]+min(dp2[0], dp2[2]);
		dp1[2] = r[2]+min(dp2[0], dp2[1]);
	}
	int min0 = min(min(dp1[0], dp1[1]), min(dp1[0], dp1[2]));
	printf("%d", min0);
}