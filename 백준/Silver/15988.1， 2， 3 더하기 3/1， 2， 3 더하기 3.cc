#include <stdio.h>
int ans[1000001] = { 0, };
#define mod 1000000009
int main() {
	int t;
	scanf("%d", &t);
	ans[1] = 1;
	ans[2] = 2;
	ans[3] = 4;
	for (int i = 4; i <= 1000000; i++)
		for (int j = 1; j <= 3; j++)
			ans[i] = ans[i] % mod + ans[i - j] % mod;
	while (t--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", ans[n] % mod);
	}
}