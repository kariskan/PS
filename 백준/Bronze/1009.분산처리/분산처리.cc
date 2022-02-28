#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int a, b;
		scanf("%d %d", &a, &b);
		int temp = a % 10;
		for (int i = 1; i < b; i++) {
			temp *= a;
			temp %= 10;
		}
		if (temp == 0)printf("10\n");
		else
		printf("%d\n", temp);
	}
}