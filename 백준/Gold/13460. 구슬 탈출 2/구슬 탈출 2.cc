#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <string>
using namespace std;

int n, m;
int ans = -1;

vector<vector<char>> left(vector<vector<char>> t) {

	for (int i = 1; i < n - 1; i++) {
		queue<tuple<char, int, int>> q;
		for (int j = 1; j < m - 1; j++) {
			if (t[i][j] == 'R' || t[i][j] == 'B') {
				q.push({ t[i][j],i,j });
				t[i][j] = '.';
			}
		}
		while (!q.empty()) {
			int x, y;
			char c;
			tie(c, x, y) = q.front();
			q.pop();

			int idx;
			bool deleted = false;
			for (idx = y; idx > 0; idx--) {
				if (t[x][idx - 1] == '#' || t[x][idx - 1] == 'R' || t[x][idx - 1] == 'B')break;
				if (t[x][idx - 1] == 'O') {
					deleted = true;
					break;
				}
			}
			if (!deleted) t[x][idx] = c;
		}
	}
	return t;
}

vector<vector<char>> right(vector<vector<char>> t) {

	for (int i = 1; i < n - 1; i++) {
		queue<tuple<char, int, int>> q;
		for (int j = m - 2; j > 0; j--) {
			if (t[i][j] == 'R' || t[i][j] == 'B') {
				q.push({ t[i][j],i,j });
				t[i][j] = '.';
			}
		}
		while (!q.empty()) {
			int x, y;
			char c;
			tie(c, x, y) = q.front();
			q.pop();

			int idx;
			bool deleted = false;
			for (idx = y; idx < m - 1; idx++) {
				if (t[x][idx + 1] == '#' || t[x][idx + 1] == 'R' || t[x][idx + 1] == 'B')break;
				if (t[x][idx + 1] == 'O') {
					deleted = true;
					break;
				}
			}
			if (!deleted) t[x][idx] = c;
		}
	}
	return t;
}

vector<vector<char>> up(vector<vector<char>> t) {

	for (int j = 1; j < m - 1; j++) {
		queue<tuple<char, int, int>> q;
		for (int i = 1; i < n - 1; i++) {
			if (t[i][j] == 'R' || t[i][j] == 'B') {
				q.push({ t[i][j],i,j });
				t[i][j] = '.';
			}
		}
		while (!q.empty()) {
			int x, y;
			char c;
			tie(c, x, y) = q.front();
			q.pop();

			int idx;
			bool deleted = false;
			for (idx = x; idx > 0; idx--) {
				if (t[idx - 1][y] == '#' || t[idx - 1][y] == 'R' || t[idx - 1][y] == 'B')break;
				if (t[idx - 1][y] == 'O') {
					deleted = true;
					break;
				}
			}
			if (!deleted) t[idx][y] = c;
		}
	}
	return t;
}

vector<vector<char>> down(vector<vector<char>> t) {

	for (int j = 1; j < m - 1; j++) {
		queue<tuple<char, int, int>> q;
		for (int i = n - 2; i > 0; i--) {
			if (t[i][j] == 'R' || t[i][j] == 'B') {
				q.push({ t[i][j],i,j });
				t[i][j] = '.';
			}
		}
		while (!q.empty()) {
			int x, y;
			char c;
			tie(c, x, y) = q.front();
			q.pop();

			int idx;
			bool deleted = false;
			for (idx = x; idx < n - 1; idx++) {
				if (t[idx + 1][y] == '#' || t[idx + 1][y] == 'R' || t[idx + 1][y] == 'B')break;
				if (t[idx + 1][y] == 'O') {
					deleted = true;
					break;
				}
			}
			if (!deleted) t[idx][y] = c;
		}
	}
	return t;
}
pair<int, int> findR(vector<vector<char>> v) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] == 'R') {
				return { i,j };
			}
		}
	}
	return { -1,-1 };
}

pair<int, int> findB(vector<vector<char>> v) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] == 'B') {
				return { i,j };
			}
		}
	}
	return { -1,-1 };
}

void go(vector<vector<char>> v, int cnt, string seq) {
	if (cnt > 10) {
		return;
	}
	vector<vector<char>> t;
	pair<int, int> R, B;
	R = findR(v);
	B = findB(v);
	for (int i = 0; i < 4; i++) {
		if (!i) {
			t = left(v);
		}
		else if (i == 1) {
			t = right(v);
		}
		else if (i == 2) {
			t = up(v);
		}
		else { //i==3
			t = down(v);
		}
		pair<int, int> tB = findB(t);
		pair<int, int> tR = findR(t);
		
		if (tB == B && tR == R || tB.first == - 1)continue;
		if (tR.first == -1 && tB.first != -1 && (ans == -1 || ans > cnt)) {
			ans = cnt;
			return;
		}
		go(t, cnt + 1, seq + to_string(i));
	}
}

int main() {
	cin >> n >> m;

	vector<vector<char>> map;
	map.resize(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	go(map, 1, "");
	cout << ans;
}