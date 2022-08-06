#include <stdio.h>
int a[15000];
int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int count = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] + a[j] == m) { 
				count++;
				break;
			}
		}
	}
	printf("%d", count);
}