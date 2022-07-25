#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int map[5][5];
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };
vector<int> v(25);
bool b1() {
	int ret = 0;
	for (int i = 0; i < 25; i++) {
		if (v[i] && map[i / 5][i % 5])ret++;
	}
	return ret >= 4;
}
bool b2() {
	int cnt = 0;
	queue<int> q;
	int visit[25] = { 0, };
	for (int i = 0; i < 25; i++) {
		if (v[i]) {
			q.push(i);
			visit[i] = 1;
			break;
		}
	}
	while (!q.empty()) {
		int a = q.front(); q.pop();
		cnt++;
		for (int k = 0; k < 4; k++) {
			int nx = a / 5 + x[k];
			int ny = a % 5 + y[k];
			if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && !visit[nx * 5 + ny] && v[nx * 5 + ny]) {
				visit[nx * 5 + ny] = 1;
				q.push(nx * 5 + ny);
			}
		}
	}
	return cnt == 7;
}
int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			char c; cin >> c;
			if (c == 'Y')map[i][j] = 0;
			else map[i][j] = 1;
		}
	}
	v[0] = v[1] = v[2] = v[3] = v[4] = v[5] = v[6] = 1;
	sort(v.begin(), v.end());
	int ans = 0;
	do {

		if (b1() && b2()) {
			ans++;
		}

	} while (next_permutation(v.begin(), v.end()));
	cout << ans;
}