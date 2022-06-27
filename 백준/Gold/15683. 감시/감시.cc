#include <iostream>
#include <vector>
using namespace std;
int n, m;
int map[8][8];
int visit[8];
int ans = 65;

vector<pair<int, int>> cctv;

int left(int i, int j) {
	int ret = 0;
	for (int k = j - 1; k >= 0; k--) {
		if (map[i][k] == 6)break;
		else if (map[i][k] >= 1 && map[i][k] <= 5)continue;
		else {
			if (!map[i][k])ret++;
			map[i][k]--;
		}
	}
	return ret;
}

int right(int i, int j) {
	int ret = 0;
	for (int k = j + 1; k < m; k++) {
		if (map[i][k] == 6)break;
		else if (map[i][k] >= 1 && map[i][k] <= 5)continue;
		else {
			if (!map[i][k])ret++;
			map[i][k]--;
		}
	}
	return ret;
}

int up(int i, int j) {
	int ret = 0;
	for (int k = i - 1; k >= 0; k--) {
		if (map[k][j] == 6)break;
		else if (map[k][j] >= 1 && map[k][j] <= 5)continue;
		else {
			if (!map[k][j])ret++;
			map[k][j]--;
		}
	}
	return ret;
}

int down(int i, int j) {
	int ret = 0;
	for (int k = i + 1; k < n; k++) {
		if (map[k][j] == 6)break;
		else if (map[k][j] >= 1 && map[k][j] <= 5)continue;
		else {
			if (!map[k][j])ret++;
			map[k][j]--;
		}
	}
	return ret;
}

void left2(int i, int j) {
	for (int k = j - 1; k >= 0; k--) {
		if (map[i][k] == 6)break;
		else if (map[i][k] >= 1 && map[i][k] <= 5)continue;
		else {
			map[i][k]++;
		}
	}
}

void right2(int i, int j) {
	for (int k = j + 1; k < m; k++) {
		if (map[i][k] == 6)break;
		else if (map[i][k] >= 1 && map[i][k] <= 5)continue;
		else {
			map[i][k]++;
		}
	}
}

void up2(int i, int j) {
	for (int k = i - 1; k >= 0; k--) {
		if (map[k][j] == 6)break;
		else if (map[k][j] >= 1 && map[k][j] <= 5)continue;
		else {
			map[k][j]++;
		}
	}
}

void down2(int i, int j) {
	for (int k = i + 1; k < n; k++) {
		if (map[k][j] == 6)break;
		else if (map[k][j] >= 1 && map[k][j] <= 5)continue;
		else {
			map[k][j]++;
		}
	}
}

void go(int cnt, int idx) {
	if (ans > n * m - cnt) {
		ans = n * m - cnt;
	}
	int t = 0;
	for (int k = idx; k < cctv.size(); k++) {
		int i = cctv[k].first;
		int j = cctv[k].second;
		if (!visit[k] && map[i][j] >= 1 && map[i][j] <= 5) {
			visit[k] = 1;
			if (map[i][j] == 1) {
				t = left(i, j);
				go(cnt + t, k + 1);
				left2(i, j);

				t = right(i, j);
				go(cnt + t, k + 1);
				right2(i, j);

				t = up(i, j);
				go(cnt + t, k + 1);
				up2(i, j);

				t = down(i, j);
				go(cnt + t, k + 1);
				down2(i, j);
			}
			else if (map[i][j] == 2) {
				t = left(i, j);
				t += right(i, j);
				go(cnt + t, k + 1);
				left2(i, j);
				right2(i, j);

				t = up(i, j);
				t += down(i, j);
				go(cnt + t, k + 1);
				up2(i, j);
				down2(i, j);
			}
			else if (map[i][j] == 3) {
				t = up(i, j);
				t += right(i, j);
				go(cnt + t, k + 1);
				right2(i, j);
				up2(i, j);

				t = down(i, j);
				t += right(i, j);
				go(cnt + t, k + 1);
				right2(i, j);
				down2(i, j);

				t = down(i, j);
				t += left(i, j);
				go(cnt + t, k + 1);
				left2(i, j);
				down2(i, j);

				t = up(i, j);
				t += left(i, j);
				go(cnt + t, k + 1);
				left2(i, j);
				up2(i, j);
			}
			else if (map[i][j] == 4) {
				t = left(i, j);
				t += right(i, j);
				t += up(i, j);
				go(cnt + t, k + 1);
				left2(i, j);
				right2(i, j);
				up2(i, j);

				t = right(i, j);
				t += up(i, j);
				t += down(i, j);
				go(cnt + t, k + 1);
				right2(i, j);
				down2(i, j);
				up2(i, j);

				t = left(i, j);
				t += right(i, j);
				t += down(i, j);
				go(cnt + t, k + 1);
				left2(i, j);
				right2(i, j);
				down2(i, j);

				t = left(i, j);
				t += up(i, j);
				t += down(i, j);
				go(cnt + t, k + 1);
				left2(i, j);
				up2(i, j);
				down2(i, j);
			}
			else if (map[i][j] == 5) {
				t = left(i, j);
				t += right(i, j);
				t += up(i, j);
				t += down(i, j);
				go(cnt + t, k + 1);
				left2(i, j);
				right2(i, j);
				up2(i, j);
				down2(i, j);
			}
			visit[k] = 0;
		}
	}
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	int ccCnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] >= 1 && map[i][j] <= 6) {
				if (map[i][j] >= 1 && map[i][j] <= 5) {
					cctv.push_back({ i,j });
				}
				ccCnt++;
			}
		}
	}

	go(0, 0);

	cout << ans - ccCnt;

}