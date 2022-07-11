#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, f;
int map[20][20];
int r, c;
int pVisit[400];
pair<int, int> source[400], des[400];
int x[4] = { -1,0,1,0 };
int y[4] = { 0,-1,0,1 };
bool compare(pair<int, int> p1, pair<int, int> p2) {
	if (p1.second == p2.second) {
		if (source[p1.first].first == source[p2.first].first) {
			return source[p1.first].second < source[p2.first].second;
		}
		return source[p1.first].first < source[p2.first].first;
	}
	return p1.second < p2.second;
}
int getMin(int dx, int dy) {
	queue<pair<int, int>> q;
	int visit[20][20] = { 0, };
	vector<pair<int, int>> v;
	visit[dx][dy] = 1;
	q.push({ dx,dy });
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		for (int k = 0; k < m; k++) {
			if (pVisit[k])continue;
			if (source[k].first == a && source[k].second == b) {
				v.push_back({ k,visit[a][b] });
			}
		}

		for (int k = 0; k < 4; k++) {
			int nx = a + x[k];
			int ny = b + y[k];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visit[nx][ny] && !map[nx][ny]) {
				visit[nx][ny] = visit[a][b] + 1;
				q.push({ nx,ny });
			}
		}
	}
	sort(v.begin(), v.end(), compare);
	if (v.empty())return -1;
	else {
		pVisit[v[0].first] = 1;
		return v[0].first;
	}
}
int main() {
	cin >> n >> m >> f;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	cin >> r >> c;
	r--; c--;
	for (int i = 0; i < m; i++) {
		cin >> source[i].first >> source[i].second >> des[i].first >> des[i].second;
		source[i].first--;
		source[i].second--;
		des[i].first--;
		des[i].second--;
	}
	for (int idx = 0; idx < m; idx++) {
		int cnt = 0;
		int p = getMin(r, c); //승객 번호
		if (p == -1) {
			cout << -1;
			return 0;
		}
		queue<pair<int, int>> q;
		int visit[20][20] = { 0, };
		q.push({ r,c });
		visit[r][c] = 1;
		while (!q.empty()) {
			int a = q.front().first;
			int b = q.front().second;
			q.pop();

			if (a == source[p].first && b == source[p].second) {
				r = source[p].first;
				c = source[p].second;
				f -= (visit[r][c] - 1);
				break;
			}

			for (int k = 0; k < 4; k++) {
				int nx = a + x[k];
				int ny = b + y[k];
				if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visit[nx][ny] && !map[nx][ny]) {
					visit[nx][ny] = visit[a][b] + 1;
					q.push({ nx,ny });
				}
			}
		}
		if (f < 0) {
			cout << -1;
			return 0;
		}
		while (!q.empty())q.pop();
		memset(visit, 0, sizeof(visit));
		q.push({ r,c });
		visit[r][c] = 1;
		int ok = 0;
		while (!q.empty()) {
			int a = q.front().first;
			int b = q.front().second;
			q.pop();

			if (a == des[p].first && b == des[p].second) {
				r = des[p].first;
				c = des[p].second;
				cnt += visit[r][c] - 1;
				f -= (visit[r][c] - 1);
				ok = 1;
				break;
			}

			for (int k = 0; k < 4; k++) {
				int nx = a + x[k];
				int ny = b + y[k];
				if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visit[nx][ny] && !map[nx][ny]) {
					visit[nx][ny] = visit[a][b] + 1;
					q.push({ nx,ny });
				}
			}
		}
		if (f < 0 || !ok) {
			cout << -1;
			return 0;
		}
		f += cnt * 2;
	}
	cout << f;
}