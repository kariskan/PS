#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int food[11][11], a[11][11];
vector<int> tree[11][11];
int x[8] = { -1,-1,-1,0,0,1,1,1 };
int y[8] = { -1,0,1,-1,1,-1,0,1 };

int main() {
	int n, m, year;
	cin >> n >> m >> year;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			food[i][j] = 5;
		}
	}

	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		tree[x][y].push_back(z);
	}

	//봄
	while(year--){
		int dead[11][11] = { 0, };
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				sort(tree[i][j].begin(), tree[i][j].end());
				vector<int> temp;
				for (int k = 0; k < tree[i][j].size(); k++) {
					if (tree[i][j][k] > food[i][j]) {
						dead[i][j] += tree[i][j][k] / 2;
					}
					else {
						food[i][j] -= tree[i][j][k];
						temp.push_back(tree[i][j][k] + 1);
					}
				}
				tree[i][j] = temp;
				food[i][j] += dead[i][j];
			}
		}
		//가을
		int add[11][11] = { 0, };
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k = 0; k < tree[i][j].size(); k++) {
					if (tree[i][j][k] % 5 == 0) {
						for (int l = 0; l < 8; l++) {
							int nx = i + x[l];
							int ny = j + y[l];
							if (nx > 0 && nx <= n && ny > 0 && ny <= n) {
								add[nx][ny]++;
							}
						}
					}
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k = 0; k < add[i][j]; k++) {
					tree[i][j].push_back(1);
				}
			}
		}
		//겨울
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				food[i][j] += a[i][j];
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans += tree[i][j].size();
		}
	}
	cout << ans;
}