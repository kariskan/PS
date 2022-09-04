#include <iostream>
#include <cstring>
using namespace std;

int n, m, r, map[100][100];

void upDown() {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n / 2; j++) {
			int c = map[j][i];
			map[j][i] = map[n - j - 1][i];
			map[n - j - 1][i] = c;
		}
	}
}

void leftRight() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m / 2; j++) {
			int c = map[i][j];
			map[i][j] = map[i][m - j - 1];
			map[i][m - j - 1] = c;
		}
	}
}

void rightRotate() {
	int newArr[100][100] = { 0, };

	for (int j = 0; j < m; j++) {
		for (int i = n - 1; i >= 0; i--) {
			newArr[j][n - i - 1] = map[i][j];
		}
	}

	memset(map, 0, sizeof(map));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = newArr[i][j];
		}
	}

	int k = n;
	n = m;
	m = k;
}

void leftRotate() {
	int newArr[100][100] = { 0, };

	for (int j = m - 1; j >= 0; j--) {
		for (int i = 0; i < n; i++) {
			newArr[m - j - 1][i] = map[i][j];
		}
	}

	memset(map, 0, sizeof(map));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = newArr[i][j];
		}
	}

	int k = n;
	n = m;
	m = k;
}

void five() {
	int newArr[100][100] = { 0, };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i < n / 2 && j < m / 2) {
				newArr[i][j] = map[i + n / 2][j];
			}
			else if (i < n / 2 && j >= m / 2) {
				newArr[i][j] = map[i][j - m / 2];
			}
			else if (i >= n / 2 && j >= m / 2) {
				newArr[i][j] = map[i - n / 2][j];
			}
			else {
				newArr[i][j] = map[i][j + m / 2];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			map[i][j] = newArr[i][j];
		}
	}
}

void six() {

	int newArr[100][100] = { 0, };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i < n / 2 && j < m / 2) {
				newArr[i][j] = map[i][j + m / 2];
			}
			else if (i < n / 2 && j >= m / 2) {
				newArr[i][j] = map[i + n / 2][j];
			}
			else if (i >= n / 2 && j >= m / 2) {
				newArr[i][j] = map[i][j - m / 2];
			}
			else {
				newArr[i][j] = map[i - n / 2][j];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			map[i][j] = newArr[i][j];
		}
	}
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> r;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < r; i++) {
		int a; cin >> a;
		if (a == 1) {
			upDown();
		}
		else if (a == 2) {
			leftRight();
		}
		else if (a == 3) {
			rightRotate();
		}
		else if (a == 4) {
			leftRotate();
		}
		else if (a == 5) {
			five();
		}
		else {
			six();
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}