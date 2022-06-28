#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, ans;
vector<vector<int>> map;

void left(vector<vector<int>>& v) {
	queue<int> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i][j]) {
				q.push(v[i][j]);
				v[i][j] = 0;
			}
		}
		int idx = 0;
		while (!q.empty()) {
			int c = q.front();
			q.pop();

			if (v[i][idx] == 0) {
				v[i][idx] = c;
			}
			else if (v[i][idx] == c) {
				v[i][idx++] += c;
			}
			else {
				v[i][++idx] = c;
			}
		}
	}
}

void right(vector<vector<int>>& v) {
	queue<int> q;
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j >= 0; j--) {
			if (v[i][j]) {
				q.push(v[i][j]);
				v[i][j] = 0;
			}
		}
		int idx = n - 1;
		while (!q.empty()) {
			int c = q.front();
			q.pop();

			if (v[i][idx] == 0) {
				v[i][idx] = c;
			}
			else if (v[i][idx] == c) {
				v[i][idx--] += c;
			}
			else {
				v[i][--idx] = c;
			}
		}
	}
}
void up(vector<vector<int>>& v) {
	queue<int> q;
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++) {
			if (v[i][j]) {
				q.push(v[i][j]);
				v[i][j] = 0;
			}
		}
		int idx = 0;
		while (!q.empty()) {
			int c = q.front();
			q.pop();

			if (v[idx][j] == 0) {
				v[idx][j] = c;
			}
			else if (v[idx][j] == c) {
				v[idx++][j] += c;
			}
			else {
				v[++idx][j] = c;
			}
		}
	}
}
void down(vector<vector<int>>& v) {
	queue<int> q;
	for (int j = 0; j < n; j++) {
		for (int i = n - 1; i >= 0; i--) {
			if (v[i][j]) {
				q.push(v[i][j]);
				v[i][j] = 0;
			}
		}
		int idx = n - 1;
		while (!q.empty()) {
			int c = q.front();
			q.pop();

			if (v[idx][j] == 0) {
				v[idx][j] = c;
			}
			else if (v[idx][j] == c) {
				v[idx--][j] += c;
			}
			else {
				v[--idx][j] = c;
			}
		}
	}
}

int maxNum(vector<vector<int>>& t) {
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (ret < t[i][j])ret = t[i][j];
		}
	}
	return ret;
}

void go(int cnt, string dir, vector<vector<int>>& t) {
	if (cnt == 5) {
		int ca = maxNum(t);
		if (ans < ca) {
			ans = ca;
		}
		return;
	}
	vector<vector<int>> temp = t;
	left(temp);
	go(cnt + 1, dir + "0", temp);
	temp = t;
	right(temp);
	go(cnt + 1, dir + "1", temp);
	temp = t;
	up(temp);
	go(cnt + 1, dir + "2", temp);
	temp = t;
	down(temp);
	go(cnt + 1, dir + "3", temp);
	temp = t;
}

int main() {
	cin >> n;
	map.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	go(0, "", map);
	cout << ans;
}