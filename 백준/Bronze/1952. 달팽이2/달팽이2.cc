#include <iostream>
using namespace std;
int x[4] = { 0,1,0,-1 };
int y[4] = { 1,0,-1,0 };
int map[100][100];
int main() {
	int n, m;
	cin >> n >> m;
	int nx = 0, ny = 0;
	map[nx][ny] = 1;
	int ans = 0;
	int j = 0;
	for (int i = 1; i < n * m; i++) {
		nx += x[j];
		ny += y[j];
		if (!(!map[nx][ny] && nx >= 0 && nx < n && ny >= 0 && ny < m)) {
			nx -= x[j];
			ny -= y[j];
			j = (j + 1) % 4;
			ans++;
			i--;
		}
		map[nx][ny] = 1;
	}
	cout << ans;
}