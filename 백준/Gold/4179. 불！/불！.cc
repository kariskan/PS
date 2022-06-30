#include <iostream>
#include <queue>
using namespace std;

int n, m;
char map[1000][1000];
int fvisit[1000][1000], jvisit[1000][1000];
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };
int cx, cy;
typedef struct c {
	int x;
	int y;
	char c;
};
int main() {
	cin >> n >> m;
	queue<c> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'J') {
				jvisit[i][j] = 1;
				cx = i; cy = j;
			}
			if (map[i][j] == 'F') {
				fvisit[i][j] = 1;
				q.push({ i,j,'F' });
			}
		}
	}
	q.push({ cx,cy,'J' });

	while (!q.empty()) {
		int a = q.front().x;
		int b = q.front().y;
		char c = q.front().c;
		q.pop();
		if ((a == 0 || a == n - 1 || b == 0 || b == m - 1) && c == 'J') {
			cout << jvisit[a][b];
			return 0;
		}
		for (int k = 0; k < 4; k++) {
			int nx = a + x[k];
			int ny = b + y[k];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] != '#') {
				if ((c == 'J' && !fvisit[nx][ny] && !jvisit[nx][ny]) || (c == 'F' && fvisit[nx][ny] == 0)) {
					q.push({ nx,ny,c });
					if (c == 'J') {
						jvisit[nx][ny] = jvisit[a][b] + 1;
					}
					else {
						fvisit[nx][ny] = fvisit[a][b] + 1;
					}
				}
			}
		}
	}
	cout << "IMPOSSIBLE";
}