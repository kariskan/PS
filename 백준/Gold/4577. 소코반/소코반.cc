#include <iostream>
using namespace std;
char map[16][15] = { 0, };
int x, y;
int n, m;
bool check() {
	int g = 0, b = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == '+')g++;
			if (map[i][j] == 'b')b++;
		}
	}
	return (g==0&&b==0);
}
void run(int dx, int dy) {
	if (map[x + dx][y + dy] == '#')return;
	else if (map[x + dx][y + dy] == '.' || map[x + dx][y + dy] == '+') {
		if (map[x + dx][y + dy] == '+') {
			map[x + dx][y + dx] = 'W';
		}
		else {
			map[x + dx][y + dy] = 'w';
		}
		if (map[x][y] == 'W')map[x][y] = '+';
		else map[x][y] = '.';
	}
	else if (map[x + dx][y + dy] == 'b' || map[x + dx][y + dy] == 'B') {
		if (map[x + dx * 2][y + dy * 2] == '#' || map[x + dx * 2][y + dy * 2] == 'b' || map[x + dx * 2][y + dy * 2] == 'B')return;
		if (map[x + dx][y + dy] == 'b') {
			if (map[x + dx * 2][y + dy * 2] == '+') {
				map[x + dx * 2][y + dy * 2] = 'B';
			}
			else {
				map[x + dx * 2][y + dy * 2] = 'b';
			}
			if (map[x][y] == 'w') {
				map[x][y] = '.';
			}
			else {
				map[x][y] = '+';
			}
			map[x + dx][y + dy] = 'w';
		}
		else {
			if (map[x + dx * 2][y + dy * 2] == '+') {
				map[x + dx * 2][y + dy * 2] = 'B';
			}
			else {
				map[x + dx * 2][y + dy * 2] = 'b';
			}
			if (map[x][y] == 'w') {
				map[x][y] = '.';
			}
			else {
				map[x][y] = '+';
			}
			map[x + dx][y + dy] = 'W';
		}
	}
	x += dx;
	y += dy;
}
int main() {
	int cnt = 1;
	while (cnt) {
		cin >> n >> m;
		if (!n && !m)break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> map[i][j];
				if (map[i][j] == 'w' || map[i][j] == 'W') {
					x = i;
					y = j;
				}
			}
		}
		string s;
		cin >> s;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'L') {
				run(0, -1);
			}
			else if (s[i] == 'R') {
				run(0, 1);
			}
			else if (s[i] == 'U') {
				run(-1, 0);
			}
			else run(1, 0);
			if (check())break;
		}

		cout << "Game " << cnt << ": " << (check() ? "complete" : "incomplete") << "\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << map[i][j];
			}
			cout << "\n";
		}
		cnt++;
	}
}