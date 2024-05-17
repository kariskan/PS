#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
using namespace std;

int n, k, vis[2][100000];
char board[2][100000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k >> board[0] >> board[1];

	queue<pair<int, int>> q;

	q.push({ 0,0 });
	vis[0][0] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (y + k >= n) {
			cout << 1;
			return 0;
		}

		if (!vis[x][y + 1] && board[x][y + 1] == '1') {
			q.push({ x,y + 1 });
			vis[x][y + 1] = vis[x][y] + 1;
		}
		if (y - 1 >= 0 && !vis[x][y - 1] && board[x][y - 1] == '1' && vis[x][y] <= y - 1) {
			q.push({ x,y - 1 });
			vis[x][y - 1] = vis[x][y] + 1;
		}
		if (!vis[1 - x][y + k] && board[1 - x][y + k] == '1') {
			q.push({ 1 - x,y + k });
			vis[1 - x][y + k] = vis[x][y] + 1;
		}
	}

	cout << 0;
}