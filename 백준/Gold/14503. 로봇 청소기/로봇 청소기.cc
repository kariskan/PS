#include <stdio.h>
int r, c, direction;
int map[50][50] = { 0, };
int leftroomx() {
	if (direction == 0) {
		return r;
	}
	else if (direction == 1) {
		return r - 1;
	}
	else if (direction == 2) {
		return r;
	}
	else {
		return r + 1;
	}
}
int leftroomy() {
	if (direction == 0) {
		return c - 1;
	}
	else if (direction == 1) {
		return c;
	}
	else if (direction == 2) {
		return c + 1;
	}
	else {
		return c;
	}
}
int nextdirection() {
	if (direction == 0) {
		return 3;
	}
	else if (direction == 1) {
		return 0;
	}
	else if (direction == 2) {
		return 1;
	}
	else {
		return 2;
	}
}
int insu() {
	int count = 0;
	if (map[r - 1][c])count++;
	if (map[r][c - 1])count++;
	if (map[r + 1][c])count++;
	if (map[r][c + 1])count++;
	return count;
}
int backx() {
	if (direction == 0) {
		return r + 1;
	}
	else if (direction == 1) {
		return r;
	}
	else if (direction == 2) {
		return r - 1;
	}
	else {
		return r;
	}
}
int backy() {
	if (direction == 0) {
		return c;
	}
	else if (direction == 1) {
		return c - 1;
	}
	else if (direction == 2) {
		return c;
	}
	else {
		return c + 1;
	}
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	scanf("%d %d %d", &r, &c, &direction);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	int ans = 1;
	map[r][c] = 2;
	while (1) {

		if (map[leftroomx()][leftroomy()] == 0) {
			r = leftroomx();
			c = leftroomy();
			map[r][c] = 2;
			ans++;
			direction = nextdirection();
		}
		else if (insu() == 4) {
			if (map[backx()][backy()] == 1)break;
			r = backx();
			c = backy();
		}
		else if (map[leftroomx()][leftroomy()] == 1 || map[leftroomx()][leftroomy()] == 2) {
			direction = nextdirection();
		}
	}
	printf("%d", ans);
}