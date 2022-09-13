#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int ans, visit[1000];
void go(vector<vector<char>> v, int cnt, int bit) {
	int ok = 1;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 0 && j == 0)continue;
			if (v[i][j] != v[0][0])ok = 0;
		}
	}
	if (ok) {
		if (ans == -1 || ans > cnt) ans = cnt;
	}
	vector<vector<char>> temp;
	for (int i = 0; i < 3; i++) {
		temp = v;
		if (visit[bit | (1 << i)])continue;
		visit[bit | (1 << i)] = 1;
		for (int j = 0; j < 3; j++) {
			if (temp[i][j] == 'H')temp[i][j] = 'T';
			else temp[i][j] = 'H';
		}
		go(temp, cnt + 1, bit | (1 << i));
	}
	for (int i = 0; i < 3; i++) {
		temp = v;
		if (visit[bit | (1 << (i + 3))])continue;
		visit[bit | (1 << (i + 3))] = 1;
		for (int j = 0; j < 3; j++) {
			if (temp[j][i] == 'H')temp[j][i] = 'T';
			else temp[j][i] = 'H';
		}
		go(temp, cnt + 1, bit | (1 << (i + 3)));
	}

	if (!visit[bit | (1 << 6)]) {
		temp = v;
		visit[bit | (1 << 6)] = 1;
		for (int i = 0; i < 3; i++) {
			if (temp[i][i] == 'H') temp[i][i] = 'T';
			else temp[i][i] = 'H';
		}
		go(temp, cnt + 1, bit | (1 << 6));
	}

	if (!visit[bit | (1 << 7)]) {
		temp = v;
		visit[bit | (1 << 7)] = 1;
		for (int i = 0; i < 3; i++) {
			if (temp[i][2 - i] == 'H')temp[i][2 - i] = 'T';
			else temp[i][2 - i] = 'H';
		}
		go(temp, cnt + 1, bit | (1 << 7));
	}
}

int main() {
	int t; cin >> t;
	while (t--) {
		vector<vector<char>> v(3);
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				char c; cin >> c;
				v[i].push_back(c);
			}
		}
		ans = -1;
		memset(visit, 0, sizeof(visit));
		visit[0] = 1;
		go(v, 0, 0);

		cout << ans << "\n";
	}
}