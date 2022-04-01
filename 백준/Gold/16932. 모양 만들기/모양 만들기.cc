#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };
int map[1000][1000];
int g[1000][1000];
int gSize[1000000];
int n, m;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	queue<pair<int, int>>q;
	int gI = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] && !g[i][j]) {
				q.push({ i,j });
				g[i][j] = gI;
				int tempSize = 1;
				while (!q.empty()) {
					int a, b;
					a = q.front().first;
					b = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = a + x[k];
						int ny = b + y[k];
						if (nx >= 0 && nx < n && ny >= 0 && ny < m && !g[nx][ny] && map[nx][ny]) {
							q.push({ nx,ny });
							g[nx][ny] = gI;
							tempSize++;
						}
					}
				}
				gSize[gI] = tempSize;
				gI++;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!map[i][j]) {
				vector<int> t;
				int temp = 0;
				for (int k = 0; k < 4; k++) {
					int nx = i + x[k];
					int ny = j + y[k];
					if (nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] && map[nx][ny]) {
						t.push_back(g[nx][ny]);
					}
				}
				sort(t.begin(), t.end());
				t.erase(unique(t.begin(), t.end()), t.end());
				for (int k : t) {
					temp += gSize[k];
				}
				ans = max(ans, temp + 1);
			}
		}
	}
	cout << ans;
}