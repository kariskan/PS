#include <stdio.h>
#include <string.h>
char stack[1000001] = { 0, };
int top = -1;
int j[1000001] = { 0, };
int topj = -1;
char a[1000001] = { 0, };
void push(char c) {
	top++;
	stack[top] = c;
}
int pop() {
	return stack[top--];
}
void pushj() {
	topj++;
	j[topj] = j[topj - 1] + 1;
}
int popj() {
	return j[topj--];
}
int main() {
	scanf("%s", a);
	int lena = strlen(a);
	char b[37] = { 0, };
	scanf("%s", b);
	int lenb = strlen(b);
	for (int i = 0; i < lena; i++) {
		push(a[i]);
		topj++;
		if (a[i] == b[j[topj - 1]]) {
			j[topj] = j[topj - 1] + 1;
		}
		else {
			j[i] = 0;
		}
		if (a[i] == b[0]) {
			j[topj] = 1;
		}
		if (j[topj] == lenb) {
			int temp = j[topj];
			for (int k = 0; k < temp; k++) {
				pop(); 
				j[topj] = 0;
				topj--;
			}
		}
	}
	if (top == -1)printf("FRULA");
	else
	for (int i = 0; i <= top;i++)printf("%c", stack[i]);
}