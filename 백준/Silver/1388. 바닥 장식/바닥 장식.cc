#include <iostream>

using namespace std;

int n, m;
char map[50][50];
int visit[50][50];

void go(int i, int j) {

	visit[i][j] = 1;
	
	if (map[i][j] == '-') {
		int right = j, left = j;
		while (right < m && map[i][right] == '-') {
			visit[i][right] = 1;
			right++;
		}
		while (left >= 0 && map[i][left] == '-') {
			visit[i][left] = 1;
			left--;
		}
	}
	else {
		int top = i, bottom = i;
		while (top >= 0 && map[top][j] == '|') {
			visit[top][j] = 1;
			top--;
		}
		while (bottom < n && map[bottom][j] == '|') {
			visit[bottom][j] = 1;
			bottom++;
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visit[i][j]) {
				go(i, j);
				ans++;
			}
		}
	}

	cout << ans;
}