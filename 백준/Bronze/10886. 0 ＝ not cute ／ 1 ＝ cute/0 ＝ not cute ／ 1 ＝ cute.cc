#include <stdio.h>

int main() {
	int a[2] = { 0, };
	int n;
	scanf("%d", &n);
	int b;
	for (int i = 0; i < n; i++) {
		scanf("%d", &b);
		if (b == 0)a[0]++;
		if (b == 1)a[1]++;
	}
	if (a[1] > a[0])printf("Junhee is cute!");
	else printf("Junhee is not cute!");
}