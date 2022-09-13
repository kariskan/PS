#include <iostream>
using namespace std;

int n;
char map1[10][10], map2[10][10], ans[10][10];
int x[8] = { -1,-1,-1,0,1,1,1,0 };
int y[8] = { -1,0,1,1,1,0,-1,-1 };
int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map1[i][j];
		}
	}
	int open = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map1[i][j] == '*')continue;
			int cnt = 0;
			for (int k = 0; k < 8; k++) {
				int nx = i + x[k];
				int ny = j + y[k];
				if (nx >= 0 && nx < n && ny >= 0 && ny < n && map1[nx][ny] == '*') {
					cnt++;
				}
			}
			ans[i][j] = cnt + '0';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map2[i][j];
			if (map1[i][j] == '*' && map2[i][j] == 'x')open = 1;//지뢰 열림
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (open && map1[i][j] == '*')cout << '*';
			else if (map1[i][j] == '.' && map2[i][j] == 'x') {
				cout << ans[i][j];
			}
			else cout << '.';
		}
		cout << '\n';
	}
}