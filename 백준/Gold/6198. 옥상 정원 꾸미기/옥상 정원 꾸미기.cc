#include <stdio.h>
int a[80000] = { 0, };
int stack[80000] = { 0, };
int top = -1;

void push(int n) {
	stack[++top] = n;
}
int empty() {
	return top == -1;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		while (!empty() && stack[top] <= a[i]) {
			top--;
		}
		ans += top + 1;
		push(a[i]);
	}
	printf("%lld", ans);
}