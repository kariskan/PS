#include <stdio.h>
#include <string.h>
char wp1[1001][11] = { 0, };
char wp2[1001][11] = { 0, };
char dkagh[1001][11] = { 0, };
int a[1001][2] = { 0, };//0이 start, 1이 end
void init() {
	for (int i = 0; i < 1001; i++) {
		a[i][0] = 0;
		a[i][1] = 0;
		for (int j = 0; j < 11; j++) {
			wp1[i][j] = 0;
			wp2[i][j] = 0;
			dkagh[i][j] = 0;
		}
	}
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%s", wp1[i]);
		}
		for (int i = 0; i < n; i++) {
			scanf("%s", wp2[i]);
		}
		for (int i = 0; i < n; i++) {
			scanf("%s", dkagh[i]);
		}
		int k = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!strcmp(wp2[i], wp1[j])) {
					a[k][0] = i;
					a[k][1] = j;
					k++;
					break;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[j][1] == -1)continue;
				if (a[j][1] == i) {
					printf("%s ", dkagh[a[j][0]]);
					a[j][0] = -1;
					a[j][1] = -1;
				}
			}
		}
		printf("\n");
		init();
	}
}