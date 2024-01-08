#include <iostream>
#include <vector>
using namespace std;

int n, map[20][20];
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };

vector<pair<int, vector<int>>> v;
vector<vector<int>> v2;

int main() {

	cin >> n;
	v2.resize(n * n + 1);

	for (int i = 0; i < n * n; i++) {
		int num; cin >> num;

		vector<int> temp;
		for (int j = 0; j < 4; j++) {
			int k; cin >> k;
			v2[num].push_back(k);
			temp.push_back(k);
		}

		v.push_back({ num,temp });
	}

	for (int c = 0; c < n * n; c++) {

		int num = v[c].first;

		int cnt[20][20] = { 0, };
		int clear[20][20] = { 0, };

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j]) continue;
				for (int k = 0; k < 4; k++) {
					int nx = i + x[k];
					int ny = j + y[k];
					if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
						for (int l = 0; l < 4; l++) {
							if (map[nx][ny] == v[c].second[l]) cnt[i][j]++;
							if (map[nx][ny] == 0) {
								clear[i][j]++;
								break;
							}
						}
					}
				}
			}
		}

		int maxCnt = -1, maxI, maxJ, maxClear = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j]) continue;

				if (cnt[i][j] >= maxCnt) {
					if (cnt[i][j] == maxCnt && clear[i][j] <= maxClear) continue;

					maxCnt = cnt[i][j];
					maxClear = clear[i][j];
					maxI = i;
					maxJ = j;
				}
			}
		}

		map[maxI][maxJ] = v[c].first;
	}

	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int num = map[i][j];
			int cnt = 0;
			for (int k = 0; k < v2[num].size(); k++) {
				for (int l = 0; l < 4; l++) {
					int nx = i + x[l];
					int ny = j + y[l];
					if (nx >= 0 && nx < n && ny >= 0 && ny < n && map[nx][ny] == v2[num][k]) {
						cnt++;
					}
				}
			}
			if (cnt == 1)ans += 1;
			else if (cnt == 2)ans += 10;
			else if (cnt == 3)ans += 100;
			else if (cnt == 4)ans += 1000;
		}
	}

	cout << ans;
}