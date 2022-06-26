#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;
int map[50][50]; //종류(3은 g, 4는 r), 시간
vector<pair<int, int>> can;
vector<pair<int, int>> can2;
int n, m, g, r;
int ans;
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };
int canVisit[10], canVisit2[10];
vector<pair<int, int>> tt;
void go() {
	queue<tuple<int, int, int>> q; //x, y, 종류
	pair<int, int> visit[50][50]; //종류, 시간
	memset(visit, 0, sizeof(visit));
	int sum = 0;
	for (int i = 0; i < can2.size(); i++) {
		int x1 = can2[i].first;
		int y1 = can2[i].second;
		q.push({ x1,y1,map[x1][y1] });
		visit[x1][y1].first = map[x1][y1];
		visit[x1][y1].second = 1;
	}
	while (!q.empty()) {
		int a, b, c;
		tie(a, b, c) = q.front();
		q.pop();
		if (visit[a][b].first == -1)continue;
		for (int k = 0; k < 4; k++) {
			int nx = a + x[k];
			int ny = b + y[k];
			if (visit[nx][ny].first != -1 && map[nx][ny] != 0 && nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if(visit[nx][ny].first) { //방문 햇으면
					if (visit[nx][ny].second && visit[nx][ny].second == visit[a][b].second + 1) { //같은 시각인데
						if (visit[nx][ny].first != c) { //다른 종류이면
							visit[nx][ny] = { -1, -1 };
							sum++;
							tt.push_back({ nx,ny });
						}
					}
				}
				else {
					q.push({ nx,ny,visit[a][b].first });
					visit[nx][ny] = { visit[a][b].first, visit[a][b].second + 1 };
				}
			}
		}
	}
	
	if (ans < sum) {
		ans = sum;
	}
	tt.clear();
}

void seed2(int cnt, int idx) {
	if (cnt == g) {
		for (int i = 0; i < can2.size(); i++) {
			if (!canVisit2[i]) {
				map[can2[i].first][can2[i].second] = 4;
			}
		}
		go();
		for (int i = 0; i < can2.size(); i++) {
			if (!canVisit2[i]) {
				map[can2[i].first][can2[i].second] = 2;
			}
		}
		return;
	}

	for (int i = idx; i < can2.size(); i++) {
		if (!canVisit2[i]) {
			map[can2[i].first][can2[i].second] = 3;
			canVisit2[i] = 1;
			seed2(cnt + 1, i + 1);
			map[can2[i].first][can2[i].second] = 2;
			canVisit2[i] = 0;
		}
	}
}

void seed(int cnt, int idx) {
	if (cnt == g + r) {
		seed2(0, 0);
		return;
	}

	for (int i = idx; i < can.size(); i++) {
		if (!canVisit[i]) {
			can2.push_back({ can[i].first,can[i].second });
			canVisit[i] = 1;
			seed(cnt + 1, i + 1);
			canVisit[i] = 0;
			can2.pop_back();
		}
	}
}

int main() {
	cin >> n >> m >> g >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				can.push_back({ i,j });
			}
		}
	}
	seed(0, 0);
	cout << ans;
}