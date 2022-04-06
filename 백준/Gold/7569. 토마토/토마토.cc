#include <stdio.h>
int tomato[100][100][100] = { 0, };
int n, m, h;
int x[6] = { 0,0,1,-1,0,0 };
int y[6] = { 1,-1,0,0,0,0 };
int z[6] = { 0,0,0,0,1,-1 };
int queuex[1000001];
int queuey[1000001];
int queuez[1000001];
int front = -1, rear = -1;
int count = 0;
void push(int i, int j, int k) {
	rear++;
	queuex[rear] = i;
	queuey[rear] = j;
	queuez[rear] = k;
}
int popx() {
	front++;
	return queuex[front];
}
int popy() {
	return queuey[front];
}
int popz() {
	return queuez[front];
}
int empty() {
	if (front == rear)return 1;
	else return 0;
}
int BFS() {
	int nextX, nextY, nextZ;
	int x_, y_, z_;
	while (!empty()) {
		x_ = popx();
		y_ = popy();
		z_ = popz();
		for (int i = 0; i < 6; i++) {
			nextX = x_ + x[i];
			nextY = y_ + y[i];
			nextZ = z_ + z[i];
			if (nextX >= 0 && nextY >= 0 && nextZ >= 0 && nextY < n && nextX < m && nextZ < h) {
				if (tomato[nextZ][nextX][nextY] == 0 ) {
					tomato[nextZ][nextX][nextY] = tomato[z_][x_][y_] + 1;
					push(nextX, nextY, nextZ);
					count--;
				}
			}
		}
	}
	if (count == 0)return tomato[z_][x_][y_] - 1;
	return -1;
}
int main() {
	scanf("%d %d %d", &n, &m, &h);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				scanf("%d", &tomato[i][j][k]);
				if (tomato[i][j][k] == 1) {
					push(j, k, i);
				}
				else if (tomato[i][j][k] == 0)count++;
			}
		}
	}
	printf("%d", BFS());
}