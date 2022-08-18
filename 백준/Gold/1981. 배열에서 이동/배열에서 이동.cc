#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n, map[100][100], visit[100][100];
vector<int> seq;
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };

bool bfs(int left, int right) {

	if (map[0][0] < left || map[0][0] > right) return false;

	memset(visit, 0, sizeof(visit));
	queue<pair<int, int>> q;

	q.push({ 0,0 });
	visit[0][0] = 1;

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = a + x[k];
			int ny = b + y[k];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visit[nx][ny] && map[nx][ny] >= left && map[nx][ny] <= right) {
				visit[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
	}

	return visit[n - 1][n - 1];
}

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			seq.push_back(map[i][j]);
		}
	}

	sort(seq.begin(), seq.end());
	seq.erase(unique(seq.begin(), seq.end()), seq.end());

	int left = 0, right = 0, ans = seq[seq.size() - 1] - seq[0];

	while (left <= right && right < seq.size()) {

		if (bfs(seq[left], seq[right])) {
			ans = min(ans, seq[right] - seq[left]);
			left++;
		}
		else {
			right++;
		}
	}

	cout << ans;
}    