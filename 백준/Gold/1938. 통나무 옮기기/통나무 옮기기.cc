#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;
char map[50][50];
vector<pair<int, int>> t;
vector<pair<int, int>> ans;
int visit[50][50][2]; //0이 가로, 1이 세로
int n, rot;
bool ok(vector<pair<int, int>> temp, int up, int down, int left, int right) {
	for (int i = 0; i < 3; i++) {
		if (temp[i].first - up < 0 || temp[i].first + down >= n || temp[i].second - left < 0 || temp[i].second + right >= n) {
			return false;
		}
		if (map[temp[i].first - up + down][temp[i].second - left + right] == '1')return false;
	}

	return true;
}
bool rotate(vector<pair<int, int>> temp) {
	for (int i = temp[1].first - 1; i < temp[1].first + 2; i++) {
		for (int j = temp[1].second - 1; j < temp[1].second + 2; j++) {
			if (!(i >= 0 && i < n && j >= 0 && j < n))return false;
			if (map[i][j] == '1')return false;
		}
	}
	return true;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'B') {
				t.push_back({ i,j });
			}
			if (map[i][j] == 'E') {
				ans.push_back({ i,j });
			}
		}
	}
	rot = ans[0].first - ans[1].first == 0 ? 0 : 1;
	sort(t.begin(), t.end());
	queue<tuple<int, int, int>> q;
	q.push({ t[0].first,t[0].second,t[0].first - t[1].first == 0 ? 0 : 1 });
	visit[t[0].first][t[0].second][t[0].first - t[1].first == 0 ? 0 : 1] = 1;
	while (!q.empty()) {
		int a, b, c;
		tie(a, b, c) = q.front();
		q.pop();

		if (a == ans[0].first && b == ans[0].second && c == rot) {
			cout << visit[a][b][c] - 1;
			return 0;
		}

		vector<pair<int, int>> temp;
		if (c == 0) { //가로
			for (int i = 0; i < 3; i++) {
				temp.push_back({ a,b + i });
			}
		}
		else {
			for (int i = 0; i < 3; i++) {
				temp.push_back({ a + i,b });
			}
		}
		if (ok(temp, 1, 0, 0, 0) && !visit[a - 1][b][c]) {
			q.push({ a - 1,b,c });
			visit[a - 1][b][c] = visit[a][b][c] + 1;
		}
		if (ok(temp, 0, 1, 0, 0) && !visit[a + 1][b][c]) {
			q.push({ a + 1,b,c });
			visit[a + 1][b][c] = visit[a][b][c] + 1;
		}
		if (ok(temp, 0, 0, 1, 0) && !visit[a][b - 1][c]) {
			q.push({ a,b - 1,c });
			visit[a][b - 1][c] = visit[a][b][c] + 1;
		}
		if (ok(temp, 0, 0, 0, 1) && !visit[a][b + 1][c]) {
			q.push({ a,b + 1,c });
			visit[a][b + 1][c] = visit[a][b][c] + 1;
		}
		if (rotate(temp)) {
			if (c == 0) {
				if (!visit[a - 1][b + 1][1 - c]) {
					q.push({ a - 1,b + 1,1 - c });
					visit[a - 1][b + 1][1 - c] = visit[a][b][c] + 1;
				}
			}
			else {
				if (!visit[a + 1][b - 1][1 - c]) {
					q.push({ a + 1,b - 1,1 - c });
					visit[a + 1][b - 1][1 - c] = visit[a][b][c] + 1;
				}
			}
		}
	}
	cout << 0;
}