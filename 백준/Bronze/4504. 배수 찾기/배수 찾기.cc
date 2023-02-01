#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	while (1) {
		int a;
		scanf("%d", &a);
		if (a == 0)break;
		if (a % n != 0)printf("%d is NOT a multiple of %d.\n", a, n);
		else printf("%d is a multiple of %d.\n", a, n);
	}
}