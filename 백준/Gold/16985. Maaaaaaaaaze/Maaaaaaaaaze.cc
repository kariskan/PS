#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int x[6] = { 0,0,0,0,1,-1 };
int y[6] = { 0,0,1,-1,0,0 };
int z[6] = { 1,-1,0,0,0,0 };
vector<vector<vector<int>>> map(5, vector<vector<int>>(5, vector<int>(5)));

vector<vector<int>> rotate(vector<vector<int>>& a) {
	vector<vector<int>> t(a);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			t[i][j] = a[5 - j - 1][i];
		}
	}
	return t;
}
int bfs(vector<vector<vector<int>>>& t) {
	if (t[0][0][0] == 0)return -1;
	int visit[5][5][5] = { 1, };
	queue<tuple<int, int, int>> q;
	q.push({ 0,0,0 });
	while (!q.empty()) {
		int a, b, c;
		tie(a, b, c) = q.front();
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nx = b + x[i];
			int ny = c + y[i];
			int nz = a + z[i];
			if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && nz >= 0 && nz < 5 && t[nz][nx][ny] != 0 && !visit[nz][nx][ny]) {
				q.push({ nz,nx,ny });
				visit[nz][nx][ny] = visit[a][b][c] + 1;
			}
		}
	}
	return visit[4][4][4] - 1;
}
int ans = -1;
int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				cin >> map[i][j][k];
			}
		}
	}
	int seq[5] = { 1,2,3,4,5 };
	vector<vector<vector<int>>> t(map);
	do {
		for (int i = 0; i < 5; i++) {
			t[i] = map[seq[i] - 1];
		}
		for (int i = 0; i < 4; i++) {
			if(i)t[0] = rotate(t[0]);
			for (int j = 0; j < 4; j++) {
				if(j)t[1] = rotate(t[1]);
				for (int k = 0; k < 4; k++) {
					if(k)t[2] = rotate(t[2]);
					for (int l = 0; l < 4; l++) {
						if(l)t[3] = rotate(t[3]);
						for (int m = 0; m < 4; m++) {
							if(m)t[4] = rotate(t[4]);
							int v = bfs(t);
							if (v != -1) {
								if (ans == -1 || ans > v)ans = v;
							}
						}
					}
				}
			}
		}
	} while (next_permutation(seq, seq + 5));
	cout << ans;
}