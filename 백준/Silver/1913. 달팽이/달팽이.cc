#include <iostream>
using namespace std;

int map[1001][1001];
int x[4] = { 0,1,0,-1 };
int y[4] = { 1,0,-1,0 };
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	int num = 1;
	int nx = (n + 1) / 2;
	int ny = (n + 1) / 2;
	map[nx][ny] = 1;
	int ansx = nx, ansy = ny;
	for (int i = 1; i <= (n + 1) / 2; i++) {
		nx--;
		ny--;
		int cnt = i * 2;
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < cnt; k++) {
				nx += x[j];
				ny += y[j];
				map[nx][ny] = ++num;
				if (map[nx][ny] == m) {
					ansx = nx;
					ansy = ny;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << ansx << " " << ansy;
}