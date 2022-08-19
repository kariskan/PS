#include <iostream>
#include <vector>
#include <queue>
using namespace std;

queue<int> q;
vector<vector<int>> v;
int a, b, n, m, visit[1001];

int main() {
	cin >> a >> b >> n >> m;
	v.resize(n + 1);

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	q.push(a);
	visit[a] = 1;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		if (x == b) {
			cout << visit[x] - 1;
			return 0;
		}
		
		for (auto& i : v[x]) {
			if (!visit[i]) {
				visit[i] = visit[x] + 1;
				q.push(i);
			}
		}
	}

	cout << -1;
}