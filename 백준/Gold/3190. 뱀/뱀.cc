#include <stdio.h>

int map[101][101] = { 0, };
int visit[101][101] = { 0, };
char mapdirection[101][101] = { 0, };

typedef struct head {
	int x;
	int y;
}head;
typedef struct tail {
	int x;
	int y;
}tail;
typedef struct direction {
	int up;
	int down;
	int left;
	int right;
}direction;

int main() {
	int n;
	scanf("%d", &n);
	struct head head = { 1,1 };
	struct tail tail = { 1,1 };
	struct direction direction = { 0,0,0,1 };
	int k;
	scanf("%d", &k);//사과의 개수
	for (int i = 1; i <= k; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		map[a][b] = 1;
	}

	visit[1][1] = 1;
	int ans = 0;
	mapdirection[1][1] = 'r';

	int a;
	scanf("%d", &a); //방향 전환 정보
	int countarr[101] = { 0, };
	char carr[101] = { 0, };
	for (int i = 0; i < a; i++) {
		scanf("%d %c", &countarr[i], &carr[i]);
	}
	int i = 0;
	int count = countarr[i]; char c = carr[i];
	for (int j = 0;; j++) {
		if (j == count) {
			if (direction.up == 1) {
				if (c == 'L') {
					direction.up = 0;
					direction.left = 1;
				}
				else if (c == 'D') {
					direction.up = 0;
					direction.right = 1;
				}
			}
			else if (direction.down == 1) {
				if (c == 'L') {
					direction.down = 0;
					direction.right = 1;
				}
				else if (c == 'D') {
					direction.down = 0;
					direction.left = 1;
				}
			}
			else if (direction.left == 1) {
				if (c == 'L') {
					direction.left = 0;
					direction.down = 1;
				}
				else if (c == 'D') {
					direction.left = 0;
					direction.up = 1;
				}
			}
			else {
				if (c == 'L') {
					direction.right = 0;
					direction.up = 1;
				}
				else if (c == 'D') {
					direction.right = 0;
					direction.down = 1;
				}
			}
			i++;
			count = countarr[i];
			c = carr[i];
		}
		if (direction.up == 1) {
			if (head.x - 1 < 1 || visit[head.x - 1][head.y] == 1) break;
			if (map[head.x - 1][head.y] == 1) {
				mapdirection[head.x][head.y] = 'u';
				head.x--;
				visit[head.x][head.y] = 1;
				map[head.x][head.y] = 0;
				ans++;
			}
			else {
				mapdirection[head.x][head.y] = 'u';
				if (mapdirection[tail.x][tail.y] == 'u') {
					visit[tail.x][tail.y] = 0;
					tail.x--;
				}
				else if (mapdirection[tail.x][tail.y] == 'd') {
					visit[tail.x][tail.y] = 0;
					tail.x++;
				}
				else if (mapdirection[tail.x][tail.y] == 'l') {
					visit[tail.x][tail.y] = 0;
					tail.y--;
				}
				else if (mapdirection[tail.x][tail.y] == 'r') {
					visit[tail.x][tail.y] = 0;
					tail.y++;
				}
				head.x--;
				visit[head.x][head.y] = 1;
				ans++;
			}
		}
		if (direction.down == 1) {
			if (head.x + 1 > n || visit[head.x + 1][head.y] == 1) break;
			if (map[head.x + 1][head.y] == 1) {
				mapdirection[head.x][head.y] = 'd';
				head.x++;
				visit[head.x][head.y] = 1;
				map[head.x][head.y] = 0;
				ans++;
			}
			else {
				mapdirection[head.x][head.y] = 'd';
				if (mapdirection[tail.x][tail.y] == 'u') {
					visit[tail.x][tail.y] = 0;
					tail.x--;
				}
				else if (mapdirection[tail.x][tail.y] == 'd') {
					visit[tail.x][tail.y] = 0;
					tail.x++;
				}
				else if (mapdirection[tail.x][tail.y] == 'l') {
					visit[tail.x][tail.y] = 0;
					tail.y--;
				}
				else if (mapdirection[tail.x][tail.y] == 'r') {
					visit[tail.x][tail.y] = 0;
					tail.y++;
				}
				head.x++;
				visit[head.x][head.y] = 1;
				ans++;
			}
		}
		if (direction.left == 1) {
			if (head.y - 1 < 1 || visit[head.x][head.y - 1] == 1) break;
			if (map[head.x][head.y - 1] == 1) {
				mapdirection[head.x][head.y] = 'l';
				head.y--;
				visit[head.x][head.y] = 1;
				map[head.x][head.y] = 0;
				ans++;
			}
			else {
				mapdirection[head.x][head.y] = 'l';
				if (mapdirection[tail.x][tail.y] == 'u') {
					visit[tail.x][tail.y] = 0;
					tail.x--;
				}
				else if (mapdirection[tail.x][tail.y] == 'd') {
					visit[tail.x][tail.y] = 0;
					tail.x++;
				}
				else if (mapdirection[tail.x][tail.y] == 'l') {
					visit[tail.x][tail.y] = 0;
					tail.y--;
				}
				else if (mapdirection[tail.x][tail.y] == 'r') {
					visit[tail.x][tail.y] = 0;
					tail.y++;
				}
				head.y--;
				visit[head.x][head.y] = 1;
				ans++;
			}
		}
		if (direction.right == 1) {
			if (head.y + 1 > n || visit[head.x][head.y + 1] == 1) break;
			if (map[head.x][head.y + 1] == 1) {
				mapdirection[head.x][head.y] = 'r';
				head.y++;
				visit[head.x][head.y] = 1;
				map[head.x][head.y] = 0;
				ans++;
			}
			else {
				mapdirection[head.x][head.y] = 'r';
				if (mapdirection[tail.x][tail.y] == 'u') {
					visit[tail.x][tail.y] = 0;
					tail.x--;
				}
				else if (mapdirection[tail.x][tail.y] == 'd') {
					visit[tail.x][tail.y] = 0;
					tail.x++;
				}
				else if (mapdirection[tail.x][tail.y] == 'l') {
					visit[tail.x][tail.y] = 0;
					tail.y--;
				}
				else if (mapdirection[tail.x][tail.y] == 'r') {
					visit[tail.x][tail.y] = 0;
					tail.y++;
				}
				head.y++;
				visit[head.x][head.y] = 1;
				ans++;
			}
		}
	}
	printf("%d", ans + 1);
}