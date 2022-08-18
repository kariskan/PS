#include <iostream>
#include <cstring>
using namespace std;

int n, map[10][10];
int visit[10][10] = { 0, };
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };
int t;

bool ok(int i) {

	if (visit[i / n][i % n])return false;

	t += map[i / n][i % n];
	visit[i / n][i % n] = 1;

	for (int l = 0; l < 4; l++) {

		int nx = i / n + x[l];
		int ny = i % n + y[l];

		if (visit[nx][ny] || !(nx >= 0 && nx < n && ny >= 0 && ny < n)) {
			return false;
		}

		visit[nx][ny] = 1;
		t += map[nx][ny];
	}
	
	return true;
}

int main() {

	cin >> n;
	
	int ans = 1000000000;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}


	for (int i = 0; i < n * n; i++) {
		for (int j = i + 1; j < n * n; j++) {
			for (int k = j + 1; k < n * n; k++) {

				memset(visit, 0, sizeof(visit));
				t = 0;
				
				if (ok(i) && ok(j) && ok(k)) {
					ans = min(ans, t);
				}
			}
		}
	}

	cout << ans;
}