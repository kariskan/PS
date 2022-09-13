#include <iostream>
#include <queue>
using namespace std;

int w, h, map[102][102], visit[102][102], outside[102][102];

//오른쪽 부터 시계방향으로
int x[6] = { 0,1,1,0,-1,-1 };
int oddy[6] = { 1,1,0,-1,0,1 }; //홀
int eveny[6] = { 1,0,-1,-1,-1,0 };

bool ok(int nx, int ny) {
	return nx > 0 && ny > 0 && nx <= h && ny <= w;
}

int main() {

	cin >> w >> h;

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> map[i][j];
		}
	}

	int ans = 0;

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			if (map[i][j] == 1 && !visit[i][j]) {

				queue<pair<int, int>> q;
				q.push({ i,j });
				visit[i][j] = 1;

				while (!q.empty()) {
					int a = q.front().first;
					int b = q.front().second;
					q.pop();

					for (int k = 0; k < 6; k++) {
						int nx = a + x[k];
						int ny;
						if (a % 2 == 0)ny = b + eveny[k];
						else ny = b + oddy[k];

						if (ok(nx, ny) && map[nx][ny] && !visit[nx][ny]) {
							visit[nx][ny] = 1;
							q.push({ nx,ny });
						}

					}
				}
			}
		}
	}

	queue<pair<int, int>> q;
	q.push({ 0,0 });
	outside[0][0] = 1;

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		for (int k = 0; k < 6; k++) {
			int nx = a + x[k];
			int ny;
			if (a % 2 == 0)ny = b + eveny[k];
			else ny = b + oddy[k];

			if (nx >= 0 && nx <= h + 1 && ny >= 0 && ny <= w + 1 && !map[nx][ny] && !outside[nx][ny]) {
				outside[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
	}

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			if (map[i][j]) {
				for (int k = 0; k < 6; k++) {
					int nx = i + x[k];
					int ny;
					if (i % 2 == 0)ny = j + eveny[k];
					else ny = j + oddy[k];

					if (outside[nx][ny])ans++;
				}
			}
		}
	}

	cout << ans;

	return 0;
}