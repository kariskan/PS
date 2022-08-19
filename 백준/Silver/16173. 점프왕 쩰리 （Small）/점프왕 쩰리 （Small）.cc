#include <iostream>
#include <vector>
#include <queue>
using namespace std;

queue<pair<int, int>> q;
vector<vector<int>> v;
int n, visit[3][3], map[3][3];

int main() {
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	q.push({0, 0});
	visit[0][0] = 1;

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		if (a + map[a][b] < n && !visit[a + map[a][b]][b]) {
			visit[a + map[a][b]][b] = 1;
			q.push({ a + map[a][b],b });
		}

		if (b + map[a][b] < n && !visit[a][b + map[a][b]]) {
			visit[a][b + map[a][b]] = 1;
			q.push({ a,b + map[a][b] });
		}
	}

	if (visit[n - 1][n - 1])cout << "HaruHaru";
	else cout << "Hing";
}