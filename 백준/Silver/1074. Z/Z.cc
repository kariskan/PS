#include <stdio.h>
#include <stdlib.h>
int count = 0;
int N1, R1, C1;
void qnsgkf(int N, int r, int c) {
	if (R1 == r && C1 == c) {
		printf("%d", count);
		return;
	}
	if (R1 < r + N && R1 >= r && C1 < c + N && C1 >= c) {
		qnsgkf(N / 2, r, c);
		qnsgkf(N / 2, r, c + N/2);
		qnsgkf(N / 2, r+N/2, c );
		qnsgkf(N / 2, r + N / 2, c + N / 2);
	}
	else {
		count += N * N;
	}
}

int main() {
	scanf("%d %d %d", &N1, &R1, &C1);
	int N = 1;
	for (int i = 0; i < N1; i++)
		N *= 2;
	qnsgkf(N, 0, 0);
}