#include <iostream>
#include <vector>
using namespace std;

int n, m;
int board[201][201], inp[201][201];

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		board[a][b] = board[b][a] = c;
		inp[a][b] = b;
		inp[b][a] = a;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j)continue;
				if (board[i][k] && board[k][j]) {
					if (board[i][j] == 0 || board[i][j] > board[i][k] + board[k][j]) {
						board[i][j] = board[i][k] + board[k][j];
						if (i != k) {
							inp[i][j] = inp[i][k];
						}
					}
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)cout << "- ";
			else {
				if (inp[i][j] == 0)cout << j << ' ';
				else cout << inp[i][j] << ' ';
			}
		}
		cout << '\n';
	}
}