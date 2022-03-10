#include <stdio.h>
int map[10001][4] = { 0, };
int main() {
	map[0][3] = 1;
	for (int i = 1; i < 10001; i++) {
		map[i][1] = 1;
		map[i][2] = i / 2;
		map[i][3] = map[i - 3][1] + map[i - 3][2] + map[i - 3][3];
	}

	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", map[n][1] + map[n][2] + map[n][3]);
	}
}