#include <iostream>
#include <cstring>
using namespace std;
int r, c;
int map[500][500];
pair<int, int> a[500][500];
int ans[500][500];
int x[8] = { 0,-1,-1,-1,0,1,1,1 };
int y[8] = { 1,1,0,-1,-1,-1,0,1 };

pair<int, int> find(pair<int, int> p) {
	if (!(a[p.first][p.second].first == -1 && a[p.first][p.second].second == -1))return { a[p.first][p.second].first, a[p.first][p.second].second };
	int minNum = map[p.first][p.second];
	int minX = p.first;
	int minY = p.second;
	bool ok = false;
	for (int k = 0; k < 8; k++) {
		int nx = p.first + x[k];
		int ny = p.second + y[k];
		if (nx < 0 || nx >= r || ny < 0 || ny >= c)continue;
		if (minNum > map[nx][ny]) {
			minNum = map[nx][ny];
			minX = nx;
			minY = ny;
		}
		if (map[p.first][p.second] > map[nx][ny]) {
			ok = true;
		}
	}
	if (ok) {
		return a[p.first][p.second] = find({ minX,minY });
	}
	else return a[p.first][p.second] = { p.first,p.second };
}
int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
		}
	}

	memset(a, -1, sizeof(a));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (a[i][j].first == -1 && a[i][j].second == -1) a[i][j] = find({ i,j });
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			ans[a[i][j].first][a[i][j].second]++;
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
}