#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <string>
using namespace std;

int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };
int food[11][11], additional[11][11], dead[11][11];
vector<int> v[11][11]; // (i,j)칸의 나무 나이 정보
int n, m, c;

bool range(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= n;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> c;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			food[i][j] = 5;
			cin >> additional[i][j];
		}
	}

	for (int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a][b].push_back(c);
	}

	while (c--) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				sort(v[i][j].begin(), v[i][j].end());
				for (int k = 0; k < v[i][j].size(); k++) {
					if (v[i][j][k] <= food[i][j]) {
						food[i][j] -= v[i][j][k];
						v[i][j][k]++;
					}
					else {
						while (v[i][j].size() > k) {
							dead[i][j] += v[i][j].back() / 2;
							v[i][j].pop_back();
						}
						break;
					}
				}
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k = 0; k < v[i][j].size(); k++) {
					if (v[i][j][k] % 5 == 0) {
						for (int l = 0; l < 8; l++) {
							int nx = i + dx[l];
							int ny = j + dy[l];
							if (range(nx, ny)) {
								v[nx][ny].push_back(1);
							}
						}
					}
				}
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				food[i][j] += additional[i][j] + dead[i][j];
				dead[i][j] = 0;
			}
		}
	}
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			answer += v[i][j].size();
		}
	}

	cout << answer;
}