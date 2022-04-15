#include <stdio.h>
int d[10001] = { 0, };
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int a[21] = { 0, };
		int n;
		int m;
		for (int i = 0; i < 10001; i++)
			d[i] = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		scanf("%d", &m);
		d[0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = a[i]; j <= m; j++) {
				d[j] += d[j - a[i]];
			}
		}
		printf("%d\n", d[m]);
	}
}    
