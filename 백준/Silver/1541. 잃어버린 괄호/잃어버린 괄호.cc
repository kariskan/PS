#include <stdio.h>
#include <string.h>
int main() {
	char a; int b;
	int j = 0;
	int arr;
	int i = 0;
	for (scanf("%d", &b); scanf("%c", &a), a != 10;) {
		if (a == '-')i = 1;
		scanf("%d", &arr);
		if (i == 1)b = b - arr;
		else b += arr;
	}
	printf("%d", b);
}