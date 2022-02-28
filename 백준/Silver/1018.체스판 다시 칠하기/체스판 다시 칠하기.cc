#include <stdio.h>
#define minf(a,b)a<b?a:b
int main() {
	int n, m;
	char a[50][50];
	int min = 80;
	int ca = 0, cb = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", &a[i]);
	for (int i = 0; i < n - 7; i++) {
		for (int j = 0; j < m - 7; j++) {
			ca = 0; cb = 0;
			for (int k = i; k < i + 8; k++) {
				for (int l = j; l < j + 8; l++) {
					if ((k + l) % 2 == 0) {
						if (a[k][l] == 'B')cb++;
						else ca++;
					}
					else {
						if (a[k][l] == 'B')ca++;
						else cb++;
					}
				}
			}
			min = minf(min, ca);
			min = minf(min, cb);
		}
	}
	printf("%d", min);
	return 0;
}