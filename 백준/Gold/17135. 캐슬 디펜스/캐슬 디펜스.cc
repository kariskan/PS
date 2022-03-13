#include <iostream>
#include <vector>
using namespace std;
int n, m, d;
int board[16][16];
vector<pair<int, int>> bow;
int ans;
void run() {
	int temp[16][16] = { 0, };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			temp[i][j] = board[i][j];
		}
	}

	int cnt = 0;
	while (1) {
		pair<int, int> nextEnemy[3] = { {100,100},{100,100},{100,100} };
		int noEnemy = 1;
		int ok[3] = { 0, };
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (temp[i][j] == 1) {
					noEnemy = 0;
					for (int k = 0; k < 3; k++) {
						if (abs(i - bow[k].first) + abs(j - bow[k].second) <= d
							&& abs(nextEnemy[k].first - bow[k].first) + abs(nextEnemy[k].second - bow[k].second) >=
							abs(i - bow[k].first) + abs(j - bow[k].second)) {
							if ((abs(nextEnemy[k].first - bow[k].first) + abs(nextEnemy[k].second - bow[k].second) ==
								abs(i - bow[k].first) + abs(j - bow[k].second)) && (i <= nextEnemy[k].first || j >= nextEnemy[k].second)) continue;
							nextEnemy[k].first = i;
							nextEnemy[k].second = j;
							ok[k] = 1;

						}
					}
				}
			}
		}
		if (noEnemy)break;
		for (int i = 0; i < 3; i++) {
			if (ok[i] && temp[nextEnemy[i].first][nextEnemy[i].second]) {
				temp[nextEnemy[i].first][nextEnemy[i].second] = 0;
				cnt++;
			}
		}
		for (int i = n - 1; i >= 1; i--) {
			for (int j = 0; j < m; j++) {
				temp[i][j] = 0;
				temp[i][j] = temp[i - 1][j];
				temp[i - 1][j] = 0;
			}
		}
	}
	ans = max(ans, cnt);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < m - 2; i++) {
		for (int j = i + 1; j < m - 1; j++) {
			for (int k = j + 1; k < m; k++) {
				bow.push_back({ n,i });
				bow.push_back({ n,j });
				bow.push_back({ n,k });
				run();
				bow.clear();
			}
		}
	}
	cout << ans;
}