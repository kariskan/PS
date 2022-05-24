#include <stdio.h>
#define mod 1000000007
long long map[5001] = { 0, };

int main() {
	map[0] = map[2] = 1;
	for (int i = 4; i <= 5001; i += 2) {
		for (int j = 2; j <= i; j += 2) {
			if (i >= j) {
				map[i] = (map[i] % mod + (map[j - 2] * map[i - j]) % mod) % mod;
			}
		}
	}

	int t; scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		printf("%lld\n", map[n]);
	}
}