#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, height[50][50];
char map[50][50];
int x[8] = { -1,-1,-1,0,1,1,1,0 };
int y[8] = { -1,0,1,1,1,0,-1,-1 };
int sx, sy;
vector<int> seq;

bool bfs(int left, int right) {
	if (height[sx][sy] < left || height[sx][sy] > right) return false;

	queue<pair<int, int>> q;
	int visit[50][50] = { 0, };

	q.push({ sx,sy });
	visit[sx][sy] = 1;
	int cnt = 0;

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		for (int k = 0; k < 8; k++) {
			int nx = a + x[k];
			int ny = b + y[k];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n && height[nx][ny] >= left && height[nx][ny] <= right && !visit[nx][ny]) {
				q.push({ nx,ny });
				visit[nx][ny] = 1;
			} 
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 'K' && !visit[i][j])return false;
		}
	}

	return true;
}

int main() {

	cin >> n;

	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'P') {
				sx = i;
				sy = j;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> height[i][j];
			seq.push_back(height[i][j]);
		}
	}

	sort(seq.begin(), seq.end());
	seq.erase(unique(seq.begin(), seq.end()), seq.end());

	int left = 0;
	int right = 0;
	int ans = seq[seq.size() - 1] - seq[left];

	while (right < seq.size()) {

		bool ok = bfs(seq[left], seq[right]);

		if (ok) {
			ans = min(ans, seq[right] - seq[left]);
			left++;
		}
		else {
			right++;
		}
	}

	cout << ans;
}