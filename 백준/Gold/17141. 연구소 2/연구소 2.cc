#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> pos;
int map[50][50];
int n, m;
int answer = -1;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void go(int idx, vector<pair<int, int>> selected) {
	if (selected.size() == m) {
		int vis[50][50] = { 0, };
		queue<pair<int, int>> q;
		for (auto& i : selected) {
			q.push({ i.first,i.second });
			vis[i.first][i.second] = 1;
		}

		int cnt = 0;
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			cnt = max(cnt, vis[x][y] - 1);

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny] && map[nx][ny] != 1) {
					vis[nx][ny] = vis[x][y] + 1;
					q.push({ nx,ny });
				}
			}
		}
		bool flag = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] != 1 && !vis[i][j]) {
					flag = false;
				}
			}
		}
		if (flag) {
			if (answer == -1 || answer > cnt) {
				answer = cnt;
			}
		}
		return;
	}
	if (idx >= pos.size()) {
		return;
	}

	go(idx + 1, selected);
	selected.push_back(pos[idx]);
	go(idx + 1, selected);
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				pos.push_back({ i,j });
			}
		}
	}
	go(0, {});
	cout << answer;
}