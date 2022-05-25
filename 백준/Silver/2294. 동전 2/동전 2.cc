#include <stdio.h>
int arr[10001] = { 0, };
int k;

int min(int a, int b) {
	if (a > b)return b;
	else return a;
}
int main() {
	int n;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		if (a > 10000)continue;
		arr[a] = 1;
	}

	for (int i = 1; i <= k; i++) {
		if (arr[i] == 1) {
			int p = 2;
			for (int j = i * 2; j <= k; j += i) {
				if (arr[j] < p && arr[j] == 0)arr[j] = p;
				if (arr[j] != 0 && arr[j] > p)arr[j] = p;
				p++;
			}
		}
	}

	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= i / 2; j++) {
			if (arr[j] == 0 || arr[i - j] == 0)continue;
			if (arr[i] == 0)arr[i] = arr[i - j] + arr[j];
			else
			arr[i] = min(arr[i], arr[i - j] + arr[j]);
		}
	}
	if (arr[k] == 0)printf("-1");
	else printf("%d", arr[k]);
}